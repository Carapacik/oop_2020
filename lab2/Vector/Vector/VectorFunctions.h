#pragma once
#include "stdafx.h"
std::vector<double> FillVector(std::istream& input);
void DivideAllElementsInVectorByHalfMaximum(std::vector<double>& vect);
void SortVector(std::vector<double>& vect);
void PrintVector(std::ostream& output, std::vector<double>& vect);