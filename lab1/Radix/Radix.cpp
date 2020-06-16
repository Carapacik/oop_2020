#include <iostream>
#include <optional>
#include <string>
#include <cmath>

using namespace std;

const string INVALID_NUMBER_OF_ARGUMENTS = "Invalid number of arguments\nUsage: Radix.exe <source notation> <destination notation> <value>\n";
const string ERROR_IN_NOTATION = "Error in notations\n";
const string ERROR_IN_VALUE = "Error in <value>\n";

struct Arguments 
{
    int sourceNotation;
    int destinationNotation;
    string value;
};

optional<Arguments> ParseArgs(int argc, char* argv[])
{
    if (argc != 4)
    {
        cout << INVALID_NUMBER_OF_ARGUMENTS;
        return nullopt;
    }
    Arguments args;
    args.sourceNotation = atoi(argv[1]);
    args.destinationNotation = atoi(argv[2]);
    args.value = argv[3];

    return args;
}

bool CheckNotation(int value) 
{
    return value > 1 && value < 37;
}

bool CheckSymbolDigit(char symbol)
{
    return (symbol >= '0' && symbol <= '9') || (symbol >= 'A' && symbol <= 'Z');
}

int CalcDigit(char symbol, int radix, bool& isNegative, bool& wasError)
{
    wasError = true;
    int number;
    if (symbol >= '0' && symbol <= '9')
    {
        number = symbol - '0';
        if (number >= 0 && number <= radix)
            wasError = false;
    }
    else if (symbol >= 'A' && symbol <= 'Z')
    {
        number = symbol - 'A' + 10;
        if (number >= 0 && number <= radix)
            wasError = false;
    }
    else 
    {
        return 1;
    }
    if (!wasError && isNegative)
        return number = -number;

    return number;
}

bool CheckMaxesDigit(int a, int b, int& result)
{
    if (b > 0)
    {
        if (INT_MAX - b >= a)
        {
            result = a + b;
            return true;
        }
    }
    else
    {
        if (INT_MIN - b <= a)
        {
            result = a + b;
            return true;
        }
    }
    return false;
}

bool CheckMaxesRad(int a, int b, int& result)
{
    if (a == 0 || b == 0)
    {
        result = 0;
        return true;
    }
    if (a > 0)
    {
        if (b > 0)
        {
            if (a <= (INT_MAX / b))
            {
                result = a * b;
                return true;
            }
        }
        else
        {
            if (b >= (INT_MIN / a))
            {
                result = a * b;
                return true;
            }
        }
    }
    else
    {
        if (b > 0)
        {
            if (a >= (INT_MIN / b))
            {
                result = a * b;
                return true;
            }
        }
        else
        {
            if (b >= (INT_MAX / a))
            {
                result = a * b;
                return true;
            }
        }
    }
    return false;
}

char DecimalDigitToRadix(int value) 
{
    if (value > 9) 
        return (char)(value + 'A' - 10);
    else 
        return (char)(value + '0');
}

int StringToInt(const string& str, int radix, bool& wasError) 
{
    wasError = false;
    if (str.length() == 0) {
        wasError = true;
        return 0;
    }
    bool isNegative = false;
    size_t i = 0;
    if (str[0] == '-')
    {
        isNegative = true;
        i = 1;
    }
    int digit = 0;
    int number = 0;
    for (i; i < str.length() && !wasError; i++)
    {
        if (!CheckSymbolDigit(str[i]))
        {
            wasError = true;
            return 1;
        }
        digit = CalcDigit(str[i], radix, isNegative, wasError);
        if (wasError)
            return 1;
        if (!CheckMaxesRad(number, radix, number) || !CheckMaxesDigit(number, digit, number))
            wasError = true;
    }
    return number;
}

string IntToString(int n, int radix, bool& wasError)
{
    bool isNegative = false;
    if (n < 0)
        isNegative = true;
    string result;
    int remainderOfN = 0;
    do
    {
        remainderOfN = abs(n % radix);
        result = DecimalDigitToRadix(remainderOfN) + result;
        n = n / radix;
    } while (n != 0);
    if (isNegative) 
        result = "-" + result;

    return result;
}

bool Convert(int sourceNotation, int destinationNotation, const string& value, string& result) 
{
    bool wasError = false;
    if (CheckNotation(sourceNotation) && CheckNotation(destinationNotation))
    {
        int number = StringToInt(value, sourceNotation, wasError);

        if (wasError)
        {
            cout << ERROR_IN_VALUE;
            return false;
        }
        result = IntToString(number, destinationNotation, wasError);
        return true;
    }
    cout << ERROR_IN_NOTATION;
    return false;
}

int main(int argc, char* argv[])
{
    auto args = ParseArgs(argc, argv);
    if (args == nullopt)
        return 1;

    string afterConverResult;
    if (!Convert(args->sourceNotation, args->destinationNotation, args->value, afterConverResult))
        return 1;

    cout << afterConverResult << endl;
    return 0;
}