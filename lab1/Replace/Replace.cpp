#include <iostream>
#include <string>
#include <fstream>
#include <optional>

using namespace std;

struct Arguments
{
    string inputFileName;
    string outputFileName;
    string searchString;
    string replaceString;
};

optional<Arguments> ParseArgs(int argc, char* argv[])
{
    if (argc != 5)
    {
        std::cout
            << "Invalid number of arguments\n"
            << "Usage: Replace.exe <input file> <output file> <search string> <replace string>" << endl;

        return nullopt;
    }

    Arguments args;
    args.inputFileName = argv[1];
    args.outputFileName = argv[2];
    args.searchString = argv[3];
    args.replaceString = argv[4];

    return args;
}

string ReplaceString(const string& tempString, const string& searchString, const string& replaceString)
{
    size_t startPos = 0;
    string replacedStr;
    size_t foundedPos = tempString.find(searchString);
    while (foundedPos != string::npos)
    {
        replacedStr.append(tempString, startPos, foundedPos - startPos);
        replacedStr.append(replaceString);
        startPos = foundedPos + searchString.length();
        foundedPos = tempString.find(searchString, foundedPos + searchString.length());
    }
    replacedStr.append(tempString, startPos, tempString.length() - startPos);

    return replacedStr;
}

bool CopyAndReplace(const string& inputFileName, const string& outputFileName, const string& searchString, const string& replaceString)
{
    ifstream input(inputFileName);
    if (!input.is_open())
    {
        std::cout
            << "Failed to open "
            << inputFileName
            << " for reading\n";

        return false;
    }

    ofstream output(outputFileName);
    if (!output.is_open())
    {
        std::cout
            << "Failed to open "
            << inputFileName
            << " for writing\n";

        return false;
    }

    string tempString;
    while (getline(input, tempString))
    {
        output
            << ReplaceString(tempString, searchString, replaceString)
            << "\n";
    }

    if (input.bad())
    {
        std::cout
            << "Problem with reading data from a inputFile\n";

        return false;
    }

    if (!output.flush())
    {
        std::cout
            << "Problem with writing data to a outputFile\n";

        return false;
    }

    return true;
}

int main(int argc, char* argv[])
{
    auto args = ParseArgs(argc, argv);
    if (args == nullopt)
    {
        return 1;
    }

    if (args->searchString.empty())
    {
        std::cout 
            << "<search string> is empty"
            << '\n';
        return 1;
    }

    if (!CopyAndReplace(args->inputFileName, args->outputFileName, args->searchString, args->replaceString))
    {
        return 1;
    }

    return 0;
}