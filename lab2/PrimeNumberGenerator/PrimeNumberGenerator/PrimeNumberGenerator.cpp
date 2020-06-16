#include "stdafx.h"
#include "PrimeNumberGeneratorFunctionns.h"

using namespace std;

int main(int argc, char* argv[])
{
	try
	{
		int border = ParseArgs(argc, argv);
		set<int> primeNumbers = GeneratePrimeNumbersSet(border);
		PrintSet(cout, primeNumbers);

		return 0;
	}
	catch (const string& errorLine)
	{
		cout << errorLine;
		return 1;
	}
}