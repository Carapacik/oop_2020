#define CATCH_CONFIG_MAIN
#include "../../../catch2/catch.hpp"
#include "../Vector/VectorFunctions.h"
#include "../Vector/stdafx.h"

using namespace std;

TEST_CASE("FillVector should fill vector from istream")
{
	istringstream input("1 2 6 4 3.66 6.23 10");
	vector<double> vect = FillVector(input);
	vector<double> result = { 1, 2, 6, 4, 3.66, 6.23, 10 };

	REQUIRE(result == vect);
	vect.clear();
	result.clear();
}

TEST_CASE("Test divide elements in vector by halfMaximum")
{
	vector<double> vect = { 1, 2, 6, 4, 3.66, 6.23, 10 };
	DivideAllElementsInVectorByHalfMaximum(vect);
	vector<double> result = { (1.0 / 5), (2.0 / 5), (6.0 / 5), (4.0 / 5), (3.66 / 5), (6.23 / 5), (10.0 / 5) };

	REQUIRE(result == vect);
	vect.clear();
	result.clear();
}

TEST_CASE("SortVector should sort vector")
{
	vector<double> vect = { 10, 8.7, 0.2, 1.3 };
	SortVector(vect);
	vector<double> result = { 0.2, 1.3, 8.7, 10 };

	REQUIRE(vect == result);
	vect.clear();
	result.clear();
}

TEST_CASE("Check PrintVector")
{
	ostringstream output;
	vector<double> vect = { 3.66, 6.23, 10 };
	PrintVector(output, vect);

	REQUIRE(output.str() == "3.66 6.23 10 \n");
	vect.clear();
}

TEST_CASE("When the maximum element is 0")
{
	ostringstream output;
	vector<double> vect = { -5, -3, -2.2, 0 };
	vect = DivideAllElementsInVectorByHalfMaximum(vect);
	vector<double> result;

	REQUIRE(vect.size() == result.size());
	vect.clear();
}