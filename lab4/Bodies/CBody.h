#pragma once
#include "stdafx.h"

class CBody
{
public:
	CBody(std::string type, double density);
	virtual ~CBody();
	double GetDensity();
	virtual double GetVolume() const = 0;
	double GetMass();
	void Print(std::ostream& output);
private:
	virtual void OtherParameters(std::ostream& output) const = 0;
	double density;
	std::string type;
};