#include "PrimeNumberGeneratorFunctionns.h"

int ParseArgs(int argc, char* argv[])
{
	if (argc != 2)
		throw INVALID_NUMBER_OF_ARGUMENTS;
	int border = atoi(argv[1]);
	if (border < MIN_BORDER || border > MAX_BORDER)
		throw INCORRECT_BORDER;

	return border;
}

std::vector<bool> Sieve(int upperBound)
{
	std::vector<bool> result(upperBound + 1, true);
	for (size_t i = MIN_PRIME; i < (int)sqrt(result.size()); i++)
	{
		if (result[i]) 
		{
			for (size_t j = i * i; j < result.size(); j += i)
			{
				result[j] = false;
			}
		}
	}
	return result;
}

std::set<int> GeneratePrimeNumbersSet(int upperBound)
{
	std::vector<bool> primeVector = Sieve(upperBound);
	std::set<int> primeNumbers;
	for (int i = MIN_PRIME; i <= upperBound; i++)
	{
		if (primeVector[i])
			primeNumbers.emplace(i);
	}
	return primeNumbers;
}

void PrintSet(std::ostream& output, std::set<int>& primeNumbers)
{
	for (auto item : primeNumbers) 
	{
		output << item << " ";
	}
	output << std::endl;
}