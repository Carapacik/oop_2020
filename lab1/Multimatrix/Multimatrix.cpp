#include <iostream>
#include <optional>
#include <string>
#include <fstream>
#include <iomanip>

using namespace std;

const int SIZE = 3;
const int PRECISION = 3;
const string INVALID_NUMBER_OF_ARGUMENTS = "Invalid number of arguments\nUsage: Replace.exe <input file> <output file> <search string> <replace string>\n";
const string FAILED_TO_OPEN_FOR_READ = "Failed to open for reading ";
const string INVALID_DATA_IN_FILE = "Invalid data in file ";

typedef double MatrixSquare[SIZE][SIZE];

struct Arguments
{
    string fileName1;
    string fileName2;
};

optional<Arguments> ParseArgs(int argc, char* argv[])
{
    if (argc != 3)
    {
        cout << INVALID_NUMBER_OF_ARGUMENTS;
        return nullopt;
    }
    Arguments args;
    args.fileName1 = argv[1];
    args.fileName2 = argv[2];
    return args;
}

bool ReadMatrix(MatrixSquare matrix, string& fileName)
{
    ifstream input;
    input.open(fileName);
    if (!(input.is_open()))
    {
        cout << FAILED_TO_OPEN_FOR_READ << fileName << endl;
        return false;
    }
    for (size_t i = 0; i < SIZE; i++)
    {
        for (size_t j = 0; j < SIZE; j++)
        {
            if (!(input >> matrix[i][j]))
            {
                cout << INVALID_DATA_IN_FILE << fileName << endl;
                return false;
            }
        }
    }

    return true;
}

void Multiplication(MatrixSquare& matrix1, MatrixSquare& matrix2, MatrixSquare& resultMatrix)
{
    for (size_t i = 0; i < SIZE; i++)
    {
        for (size_t j = 0; j < SIZE; j++)
        {
            resultMatrix[i][j] = 0;
            for (size_t k = 0; k < SIZE; k++)
            {
                resultMatrix[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }
}

bool MultiMatrix(string fileName1, string fileName2, MatrixSquare& resultMatrix)
{
    MatrixSquare matrix1, matrix2;
    if (!ReadMatrix(matrix1, fileName1))
        return false;

    if (!ReadMatrix(matrix2, fileName2))
        return false;

    Multiplication(matrix1, matrix2, resultMatrix);

    return true;
}

void PrintMatrix(MatrixSquare matrix)
{
    ofstream output;
    output.open("output.txt");
    for (size_t i = 0; i < SIZE; i++)
    {
        output << fixed << setprecision(PRECISION) << matrix[i][0];
        for (size_t j = 1; j < SIZE; j++) {
            output << "\t";
            output << fixed << setprecision(PRECISION) << matrix[i][j];
        }
        output << endl;
    }
}

int main(int argc, char* argv[])
{
    auto args = ParseArgs(argc, argv);
    if (args == nullopt)
        return 1;
    MatrixSquare matrix;
    if (!MultiMatrix(args->fileName1, args->fileName2, matrix))
        return 1;

    PrintMatrix(matrix);
    return 0;
}