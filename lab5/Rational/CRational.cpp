#include "CRational.h"

int FindGreatestCommandDivisor(int number1, int number2)
{
	while (number2 != 0)
	{
		number1 %= number2;
		std::swap(number1, number2);
	}
	return number1;
}

CRational::CRational(int numerator, int denominator)
{
	if (denominator == 0)
		throw std::runtime_error(DENOMINATOR_NOT_ZERO);
	this->m_numerator = numerator;
	this->m_denominator = denominator;
	ReductionOfFraction();
}


int CRational::GetNumerator() const
{
	return m_numerator;
}

int CRational::GetDenominator() const
{
	return m_denominator;
}

double CRational::ToDouble() const
{
	return ((double)m_numerator / (double)m_denominator);
}

CRational CRational::operator+() const
{
	return { m_numerator, m_denominator };
}

CRational CRational::operator-() const
{
	return { -m_numerator, m_denominator };
}

CRational& CRational::operator+=(const CRational& rational)
{
	m_numerator = rational.GetDenominator() * m_numerator + rational.GetNumerator() * m_denominator;
	m_denominator *= rational.GetDenominator();
	ReductionOfFraction();
	return *this;
}

CRational& CRational::operator-=(const CRational& rational)
{
	m_numerator = rational.GetDenominator() * m_numerator - rational.GetNumerator() * m_denominator;
	m_denominator *= rational.GetDenominator();
	ReductionOfFraction();
	return *this;
}

CRational& CRational::operator*=(const CRational& rational)
{
	m_numerator *= rational.GetNumerator();
	m_denominator *= rational.GetDenominator();
	ReductionOfFraction();
	return *this;
}

CRational& CRational::operator/=(const CRational& rational)
{
	if (rational == 0)
		throw std::runtime_error(DIVISION_BY_ZERO);
	m_numerator *= rational.GetDenominator();
	m_denominator *= rational.GetNumerator();
	ReductionOfFraction();
	return *this;
}

std::pair<int, CRational> CRational::ToCompoundFraction() const
{
	int integerPart = m_numerator / m_denominator;
	int numerator = m_numerator % m_denominator;
	return std::make_pair(integerPart, CRational{ numerator, m_denominator });
}

void CRational::ReductionOfFraction()
{
	int greatestCommandDivisor = FindGreatestCommandDivisor(m_numerator, m_denominator);
	m_numerator /= greatestCommandDivisor;
	m_denominator /= greatestCommandDivisor;
	if (m_denominator < 0)
	{
		m_numerator = -m_numerator;
		m_denominator = abs(m_denominator);
	}
}

bool operator==(const CRational& firstRational, const CRational& secondRational)
{
	return (firstRational.GetNumerator() == secondRational.GetNumerator() && firstRational.GetDenominator() == secondRational.GetDenominator());
}

bool operator!=(const CRational& firstRational, const CRational& secondRational)
{
	return !(firstRational == secondRational);
}

bool operator<(const CRational& firstRational, const CRational& secondRational)
{
	int num = firstRational.GetNumerator() * secondRational.GetDenominator();
	int num1 = secondRational.GetNumerator() * firstRational.GetDenominator();
	return num < num1;
}

bool operator>(const CRational& firstRational, const CRational& secondRational)
{
	int num = firstRational.GetNumerator() * secondRational.GetDenominator();
	int num1 = secondRational.GetNumerator() * firstRational.GetDenominator();
	return num > num1;
}

bool operator<=(const CRational& firstRational, const CRational& secondRational)
{
	int num = firstRational.GetNumerator() * secondRational.GetDenominator();
	int num1 = secondRational.GetNumerator() * firstRational.GetDenominator();
	return num <= num1;
}

bool operator>=(const CRational& firstRational, const CRational& secondRational)
{
	int num = firstRational.GetNumerator() * secondRational.GetDenominator();
	int num1 = secondRational.GetNumerator() * firstRational.GetDenominator();
	return num >= num1;
}

CRational const operator+(const CRational& firstRational, const CRational secondRational)
{
	int denominator = firstRational.GetDenominator() * secondRational.GetDenominator();
	int numerator = (firstRational.GetNumerator() * secondRational.GetDenominator()) + (secondRational.GetNumerator() * firstRational.GetDenominator());
	return CRational(numerator, denominator);
}

CRational const operator-(const CRational& firstRational, const CRational secondRational)
{
	int denominator = firstRational.GetDenominator() * secondRational.GetDenominator();
	int numerator = (firstRational.GetNumerator() * secondRational.GetDenominator()) - (secondRational.GetNumerator() * firstRational.GetDenominator());
	return CRational(numerator, denominator);
}

CRational const operator*(const CRational& firstRational, const CRational secondRational)
{
	int numerator = firstRational.GetNumerator() * secondRational.GetNumerator();
	int denominator = firstRational.GetDenominator() * secondRational.GetDenominator();
	return CRational(numerator, denominator);
}

CRational const operator/(const CRational& firstRational, const CRational secondRational)
{
	if (secondRational == 0)
		throw std::runtime_error(DIVISION_BY_ZERO);
	int resultNumerator = firstRational.GetNumerator() * secondRational.GetDenominator();
	int resultDenominator = firstRational.GetDenominator() * secondRational.GetNumerator();
	return { resultNumerator, resultDenominator };
}

std::ostream& operator<<(std::ostream& ostream, const CRational& rational)
{
	ostream << rational.GetNumerator() << '/' << rational.GetDenominator();
	return ostream;
}

std::istream& operator>>(std::istream& istream, CRational& rational)
{
	int numerator, denominator;
	if (istream >> numerator && istream.get() == '/' && istream >> denominator)
	{
		rational = CRational(numerator, denominator);
	}
	return istream;
}