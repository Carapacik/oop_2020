#include <iostream>
#include <string>
#include <fstream>
#include <optional>

using namespace std;

const string INVALID_NUMBER_OF_ARGUMENTS = "Invalid number of arguments\nUsage: Replace.exe <input file> <output file> <search string> <replace string>\n";
const string FAILED_TO_OPEN_FOR_READ = "Failed to open for reading ";
const string FAILED_TO_OPEN_FOR_WRITE = "Failed to open for writing ";
const string PROBLEB_WITH_READING = "Problem with reading data from inputFile\n";
const string PROBLEB_WITH_WRITING = "Problem with writing data to outputFile\n";
const string SEARCH_STRING_EMPTY = "<search string> is empty\n";

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
        cout << INVALID_NUMBER_OF_ARGUMENTS;
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

bool Replace(const string& inputFileName, const string& outputFileName, const string& searchString, const string& replaceString)
{
    ifstream input(inputFileName);
    if (!input.is_open())
    {
        cout << FAILED_TO_OPEN_FOR_READ << inputFileName << endl;
        return false;
    }

    ofstream output(outputFileName);
    if (!output.is_open())
    {
        cout << FAILED_TO_OPEN_FOR_WRITE << inputFileName << endl;
        return false;
    }

    string inputString;
    while (getline(input, inputString))
    {
        output << ReplaceString(inputString, searchString, replaceString) << endl;
    }

    if (input.bad())
    {
        cout << PROBLEB_WITH_READING;
        return false;
    }

    if (!output.flush())
    {
        cout << PROBLEB_WITH_WRITING;
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
        cout << SEARCH_STRING_EMPTY;
        return 1;
    }

    if (!Replace(args->inputFileName, args->outputFileName, args->searchString, args->replaceString))
    {
        return 1;
    }

    return 0;
}