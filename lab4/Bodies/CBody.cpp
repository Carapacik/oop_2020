#include "CBody.h"

CBody::CBody(std::string type, double density)
{
	CBody::density = density;
	CBody::type = type;
}

CBody::~CBody()
{}

double CBody::GetDensity()
{
	return CBody::density;
}

double CBody::GetResultingForceInWater()
{
	return round((GetDensity() - LIQUID_DENSITY) * GetVolume() * GRAVITATIONAL_ACCELERATION * 1000) / 1000;
}

double CBody::GetMass()
{
	return round(GetDensity() * GetVolume() * 1000) / 1000;
}

void CBody::Print(std::ostream& output)
{
	output << "Type: "
		<< type
		<< "\nDensity: "
		<< GetDensity()
		<< "\nVolume: "
		<< GetVolume()
		<< "\nMass: "
		<< GetMass()
		<< "\nResulting Force in water: "
		<< GetResultingForceInWater()
		<< std::endl;
	OtherParameters(output);
}
