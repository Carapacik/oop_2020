#include "stdafx.h"
#include "VectorFunctions.h"

using namespace std;

int main()
{
	try 
	{
		vector<double> inputVector = FillVector(cin);
		if (inputVector.empty())
			throw exception("Vector is empty");
		else
		{
			DivideAllElementsInVectorByHalfMaximum(inputVector);
			SortVector(inputVector);
			PrintVector(cout, inputVector);
			return 0;
		}
	}
	catch(const exception& e)
	{
		cout << e.what() << "\n";
		return 1;
	}
}