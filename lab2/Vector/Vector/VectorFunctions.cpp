#include "VectorFunctions.h"

std::vector<double> FillVector(std::istream& input)
{
	return std::vector<double>(std::istream_iterator<double>(input), (std::istream_iterator<double>()));
}

std::vector<double> DivideAllElementsInVectorByHalfMaximum(std::vector<double>& vect)
{
	const double maxElement = *max_element(vect.begin(), vect.end());
	if (maxElement == 0) 
	{
		vect.clear();
		return vect;
	}
	for (size_t i = 0; i < vect.size(); i++)
	{
		vect[i] /= maxElement / 2;
	}
	return vect;
}

void SortVector(std::vector<double>& vect)
{
	sort(vect.begin(), vect.end());
}

void PrintVector(std::ostream& output, std::vector<double>& vect) 
{
	output << std::setprecision(5);
	for (auto elem : vect) 
	{
		output << elem << " ";
	}
	output << std::endl;
}