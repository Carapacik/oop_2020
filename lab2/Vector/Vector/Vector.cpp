#include "stdafx.h"
#include "VectorFunctions.h"

using namespace std;

int main()
{
	try 
	{
		vector<double> inputVector = FillVector(cin);
		if (inputVector.empty())
			throw VECTOR_IS_EMPTY;
		else
		{
			DivideAllElementsInVectorByHalfMaximum(inputVector);
			SortVector(inputVector);
			PrintVector(cout, inputVector);
			return 0;
		}
	}
	catch (const string& errorLine)
	{
		cout << errorLine << "\n";
		return 1;
	}
}