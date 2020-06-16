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
			inputVector = DivideAllElementsInVectorByHalfMaximum(inputVector);
			if (inputVector.size() == 0) 
				throw MAX_ELEMENT_EQUAL_ZERO;
			SortVector(inputVector);
			PrintVector(cout, inputVector);
			return 0;
		}
	}
	catch (const string& errorLine)
	{
		cout << errorLine << endl;
		return 1;
	}
}