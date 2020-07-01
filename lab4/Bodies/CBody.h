#pragma once
#include "stdafx.h"

class CBody
{
public:
	CBody(std::string type, double density);
	virtual ~CBody();
	double GetDensity();
	virtual double GetVolume() const = 0;
	double GetResultingForceInWater();
	double GetMass();
	void Print(std::ostream& output);
private:
	virtual void OtherParameters(std::ostream& output) const = 0;
	double density;
	std::string type;
};

const double GRAVITATIONAL_ACCELERATION = 10;
const double LIQUID_DENSITY = 1000;