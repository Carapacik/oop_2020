#include "Controller.h"


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
		std::shared_ptr<CBody> bodyMax;
		Print(bodyMax->FindMaxWeight(bodies), output);
		output << LIGHTEST_BODY_IN_WATER << std::endl;
		std::shared_ptr<CBody> bodyMin;
		Print(bodyMin->FindMinWeightInWater(bodies), output);
	}
}

void Print(const std::shared_ptr<CBody>& bodies, std::ostream& output)
{
	CBody* body = bodies.get();
	body->Print(output);
	output << std::endl;
}
