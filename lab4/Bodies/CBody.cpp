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
		<< std::endl;
	OtherParameters(output);
}
