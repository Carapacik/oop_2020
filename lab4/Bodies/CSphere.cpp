#define _USE_MATH_DEFINES
#include <math.h>
#include "CSphere.h"

CSphere::CSphere(double density, double radius) 
	:CBody("Sphere", density), 
	radius(radius)
{}

double CSphere::GetRadius() const
{
	return CSphere::radius;
}

double CSphere::GetVolume() const
{
	return round((4 * M_PI * radius * radius * radius / 3) * 1000) / 1000;
}

void CSphere::OtherParameters(std::ostream& output) const
{
	output << "Radius: " 
		<< GetRadius() 
		<< std::endl;
}