#include "Controller.h"

std::shared_ptr<CBody> FindMaxWeight(const std::vector<std::shared_ptr<CBody>>& bodies)
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

std::shared_ptr<CBody> FindMinWeightInWater(const std::vector<std::shared_ptr<CBody>>& bodies)
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

bool IsCorrectType(int& type) 
{
	return type >= 0 && type <= 4;
}

void FillBodiesVector(std::vector<std::shared_ptr<CBody>>& bodies, std::istream& input, std::ostream& output)
{
	int type = -1;
	while (type != 0)
	{
		output << ENTER_BODY_TYPE;
		input >> type;
		if (!IsCorrectType) {
			output << UNKNOWN_TYPE;
		}
		else 
		{
			if (type == 0) {
				output << std::endl;
				break;
			}
			output << ENTER_DENSITY;
			double density;
			input >> density;
			if (type == 1)
			{
				output << ENTER_CONE_BASERADIUS;
				double baseRadius;
				input >> baseRadius;
				output << ENTER_CONE_HEIGHT;
				double height;
				input >> height;
				bodies.push_back(std::make_shared<CCone>(density, baseRadius, height));
			}
			else if (type == 2)
			{
				output << ENTER_CYLINDER_BASERADIUS;
				double baseRadius;
				input >> baseRadius;
				output << ENTER_CYLINDER_HEIGHT;
				double height;
				input >> height;
				bodies.push_back(std::make_shared<CCylinder>(density, baseRadius, height));
			}
			else if (type == 3)
			{
				output << ENTER_PARALLELEPIPED_WIDTH;
				double width;
				input >> width;
				output << ENTER_PARALLELEPIPED_HEIGHT;
				double height;
				input >> height;
				output << ENTER_PARALLELEPIPED_DEPTH;
				double depth;
				input >> depth;
				bodies.push_back(std::make_shared<CParallelepiped>(density, width, height, depth));
			}
			else if (type == 4)
			{
				output << ENTER_SPHERE_RADIUS;
				double radius;
				input >> radius;
				bodies.push_back(std::make_shared<CSphere>(density, radius));
			}
		}
	}
}

void Controller(std::vector<std::shared_ptr<CBody>> bodies, std::istream& input, std::ostream& output)
{
	FillBodiesVector(bodies, input, output);
	for (size_t i = 0; i < bodies.size(); i++)
	{
		Print(bodies[i], output);
	}
	if (bodies.size() != 0) {
		output << BIGGEST_WEIGHT << std::endl;
		Print(FindMaxWeight(bodies), output);
		output << LIGHTEST_BODY_IN_WATER << std::endl;
		Print(FindMinWeightInWater(bodies), output);
	}
}

void Print(const std::shared_ptr<CBody>& bodies, std::ostream& output)
{
	CBody* body = bodies.get();
	body->Print(output);
	output << std::endl;
}
