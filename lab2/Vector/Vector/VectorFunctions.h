#pragma once
#include "stdafx.h"

const std::string MAX_ELEMENT_EQUAL_ZERO = "Max element equal zero. You can't divide by zero";
const std::string VECTOR_IS_EMPTY = "Vector is empty";

std::vector<double> FillVector(std::istream& input);
std::vector<double> DivideAllElementsInVectorByHalfMaximum(std::vector<double>& vect);
void SortVector(std::vector<double>& vect);
void PrintVector(std::ostream& output, std::vector<double>& vect);