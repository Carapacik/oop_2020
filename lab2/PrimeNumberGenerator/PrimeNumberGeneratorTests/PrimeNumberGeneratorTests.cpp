#define CATCH_CONFIG_MAIN
#include "../../../catch2/catch.hpp"
#include "../PrimeNumberGenerator/PrimeNumberGeneratorFunctionns.h"
#include "../PrimeNumberGenerator/stdafx.h"

using namespace std;

TEST_CASE("Correct input")
{
	char* agrv[] = { (char*)"C67", (char*)"158" };
	int afterParse = ParseArgs(2, agrv);
	int result = 158;

	REQUIRE(afterParse == result);
}

TEST_CASE("Check set when upperBound = 158")
{
	set<int> primeNumbers = GeneratePrimeNumbersSet(158);
	set<int> result = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 
		43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 
		103, 107, 109, 113, 127, 131, 137, 139, 149, 151, 157 };

	REQUIRE(primeNumbers == result);
}

TEST_CASE("Check PrintSet")
{
	set<int> primeNumbers = { 1, 3, 7, 8, 10, 44, 67 };
	ostringstream output;
	PrintSet(output, primeNumbers);

	REQUIRE(output.str() == "1 3 7 8 10 44 67 \n");
}

TEST_CASE("Check max time spent on GeneratePrimeNumbersSet")
{
	unsigned int startTime = clock();
	set<int> primeNumbers = GeneratePrimeNumbersSet(MAX_BORDER);
	unsigned int endTime = clock();

	REQUIRE(endTime - startTime < MAX_TIME_SPENT);
}