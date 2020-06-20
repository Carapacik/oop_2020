#define _USE_MATH_DEFINES
#include <math.h>
#include "CCylinder.h"

CCylinder::CCylinder(double density, double baseRadius, double height)
	:CBody("Cylinder", density),
	baseRadius(baseRadius),
	height(height)
{}

double CCylinder::GetBaseRadius() const
{
	return CCylinder::baseRadius;
}

double CCylinder::GetHeight() const
{
	return CCylinder::height;
}

double CCylinder::GetVolume() const
{
	return round(M_PI * baseRadius * baseRadius * height * 1000) / 1000;
}

void CCylinder::OtherParameters(std::ostream& output) const
{
	output << "Height: "
		<< GetHeight()
		<< "\nBase radius: "
		<< GetBaseRadius()
		<< std::endl;
}