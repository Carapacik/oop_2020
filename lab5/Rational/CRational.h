#pragma once
#include "stdafx.h"

class CRational
{
public:
	CRational(int numerator = 0, int denominator = 1);
	int GetNumerator() const;
	int GetDenominator() const;
	double ToDouble() const;
	CRational operator+() const;
	CRational operator-() const;
	CRational& operator+=(const CRational& rational);
	CRational& operator-=(const CRational& rational);
	CRational& operator*=(const CRational& rational);
	CRational& operator/=(const CRational& rational);
	std::pair<int, CRational> ToCompoundFraction() const;
private:
	void ReductionOfFraction();
	int m_numerator;
	int m_denominator;
};

const std::string DENOMINATOR_NOT_ZERO = "The Denominator cannot be equal to 0\n";
const std::string DIVISION_BY_ZERO = "Division by 0\n";

CRational const operator+(const CRational& firstRational, const CRational secondRational);
CRational const operator-(const CRational& firstRational, const CRational secondRational);
CRational const operator*(const CRational& firstRational, const CRational secondRational);
CRational const operator/(const CRational& firstRational, const CRational secondRational);

bool operator ==(const CRational& firstRational, const CRational& secondRational);
bool operator !=(const CRational& firstRational, const CRational& secondRational);
bool operator >(const CRational& firstRational, const CRational& secondRational);
bool operator <(const CRational& firstRational, const CRational& secondRational);
bool operator >=(const CRational& firstRational, const CRational& secondRational);
bool operator <=(const CRational& firstRational, const CRational& secondRational);

std::ostream& operator<<(std::ostream& ostream, const CRational& rational);
std::istream& operator>>(std::istream& istream, CRational& rational);