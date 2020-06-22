#include "CBody.h"

CBody::CBody(std::string type, double density)
{
	CBody::density = density;
	CBody::type = type;
}

std::shared_ptr<CBody> CBody::FindMaxWeight(const std::vector<std::shared_ptr<CBody>>& bodies)
{
	double maxWeight = DBL_MIN;
	int pointer = 0;
	for (size_t i = 0; i < bodies.size(); i++)
	{
		CBody* body = bodies[i].get();
		double currentWeight = body->GetMass();
		if (maxWeight < currentWeight)
		{
			maxWeight = currentWeight;
			pointer = i;
		}
	}
	return bodies[pointer];
}

std::shared_ptr<CBody>  CBody::FindMinWeightInWater(const std::vector<std::shared_ptr<CBody>>& bodies)
{
	double minWeight = DBL_MAX;
	int pointer = 0;
	for (size_t i = 0; i < bodies.size(); i++)
	{
		CBody* body = bodies[i].get();
		double currentWeight = (body->GetDensity() - 1000) * body->GetVolume();
		if (minWeight > currentWeight)
		{
			minWeight = currentWeight;
			pointer = i;
		}
	}
	return bodies[pointer];
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
