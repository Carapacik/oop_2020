#pragma once
#include "stdafx.h"

const int MIN_BORDER = 1;
const int MAX_BORDER = 100000000;
const int MIN_PRIME = 2;
const int MAX_TIME_SPENT = 600000;

const std::string INVALID_NUMBER_OF_ARGUMENTS = "Invalid number of arguments\n";
const std::string INCORRECT_BORDER = "Incorrect border\n";

int ParseArgs(int argc, char* argv[]);
std::vector<bool> Sieve(int upperBound);
std::set<int> GeneratePrimeNumbersSet(int upperBound);
void PrintSet(std::ostream& output, std::set<int>& primeNumbers);