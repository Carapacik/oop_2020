#define CATCH_CONFIG_MAIN
#include "../../catch2/catch.hpp"
#include "../Bodies/Controller.h"
#include "../Bodies/CBody.h"
#include "../Bodies/CCone.h"
#include "../Bodies/CCylinder.h"
#include "../Bodies/CParallelepiped.h"
#include "../Bodies/CSphere.h"
#include "../Bodies/stdafx.h"

using namespace std;

TEST_CASE("CCone Tests")
{
	CCone* cone = new CCone(1110, 1.0004, 0.76);
	SECTION("GetDensity return correct density")
	{
		REQUIRE(1110 == cone->GetDensity());
	}

	SECTION("GetBaseradius return correct baseradius")
	{
		REQUIRE(1.0004 == cone->GetBaseRadius());
	}

	SECTION("GetHeight return correct height")
	{
		REQUIRE(0.76 == cone->GetHeight());
	}

	SECTION("GetVolume return correct calculated volume")
	{
		REQUIRE(0.797 == cone->GetVolume());
	}

	SECTION("GetMass return correct calculated mass")
	{
		REQUIRE(884.67 == cone->GetMass());
	}

	SECTION("GetResultingForceInWater return correct calculated resulting force")
	{
		REQUIRE(876.7 == cone->GetResultingForceInWater());
	}
}

TEST_CASE("CCylinder Tests")
{
	CCylinder* cylinder = new CCylinder(600, 7, 1.99);
	SECTION("GetDensity return correct density")
	{
		REQUIRE(600 == cylinder->GetDensity());
	}

	SECTION("GetBaseradius return correct baseradius")
	{
		REQUIRE(7 == cylinder->GetBaseRadius());
	}

	SECTION("GetHeight return correct height")
	{
		REQUIRE(1.99 == cylinder->GetHeight());
	}

	SECTION("GetVolume return correct calculated volume")
	{
		REQUIRE(306.337 == cylinder->GetVolume());
	}

	SECTION("GetMass return correct calculated mass")
	{
		REQUIRE(183802.2 == cylinder->GetMass());
	}

	SECTION("GetResultingForceInWater return correct calculated resulting force")
	{
		REQUIRE(-1225348 == cylinder->GetResultingForceInWater());
	}
}

TEST_CASE("CParallelepiped Tests")
{
	CParallelepiped* parallelepiped = new CParallelepiped(999.998, 0.88, 0.655, 0.3333);
	SECTION("GetDensity return correct density")
	{
		REQUIRE(999.998 == parallelepiped->GetDensity());
	}

	SECTION("GetWidth return correct width")
	{
		REQUIRE(0.88 == parallelepiped->GetWidth());
	}

	SECTION("GetHeight return correct height")
	{
		REQUIRE(0.655 == parallelepiped->GetHeight());
	}

	SECTION("GetDepth return correct depth")
	{
		REQUIRE(0.3333 == parallelepiped->GetDepth());
	}

	SECTION("GetVolume return correct calculated volume")
	{
		REQUIRE(0.192 == parallelepiped->GetVolume());
	}

	SECTION("GetMass return correct calculated mass")
	{
		REQUIRE(192 == parallelepiped->GetMass());
	}

	SECTION("GetResultingForceInWater return correct calculated resulting force")
	{
		REQUIRE(-0.004 == parallelepiped->GetResultingForceInWater());
	}
}

TEST_CASE("CSphere Tests")
{
	CSphere* sphere = new CSphere(1800, 1.33);
	SECTION("GetDensity return correct density")
	{
		REQUIRE(1800 == sphere->GetDensity());
	}	

	SECTION("GetRadius return correct radius")
	{
		REQUIRE(1.33 == sphere->GetRadius());
	}

	SECTION("GetVolume return correct calculated volume")
	{
		REQUIRE(9.855 == sphere->GetVolume());
	}

	SECTION("GetMass return correct calculated mass")
	{
		REQUIRE(17739 == sphere->GetMass());
	}

	SECTION("GetResultingForceInWater return correct calculated resulting force")
	{
		REQUIRE(78840 == sphere->GetResultingForceInWater());
	}
}

TEST_CASE("FindMaxMass tests")
{
	vector<shared_ptr<CBody>> bodies;
	SECTION("When one body returns it mass")
	{
		bodies.push_back(make_shared<CCone>(228, 1.000001, 0.56));
		shared_ptr<CBody> maxMass = FindMaxMass(bodies);
		REQUIRE(133.608 == maxMass->GetMass());
	}

	SECTION("When two bodies but they're the same type")
	{
		bodies.push_back(make_shared<CCone>(2010, 1.000001, 0.666));
		bodies.push_back(make_shared<CCone>(130, 2, 2));
		shared_ptr<CBody> maxMass = FindMaxMass(bodies);
		REQUIRE(1400.97 == maxMass->GetMass());
	}

	SECTION("When different bodies are of different types")
	{
		bodies.push_back(make_shared<CCone>(23000, 1.000001, 0.666));
		bodies.push_back(make_shared<CCylinder>(100, 1.1, 0.2));
		bodies.push_back(make_shared<CParallelepiped>(1010, 1, 1, 2));
		bodies.push_back(make_shared<CSphere>(400, 2));
		shared_ptr<CBody> maxMass = FindMaxMass(bodies);
		REQUIRE(16031 == maxMass->GetMass());
	}

	SECTION("When identical bodies")
	{
		bodies.push_back(make_shared<CCylinder>(100, 1.1, 0.2));
		bodies.push_back(make_shared<CCylinder>(100, 1.1, 0.2));
		shared_ptr<CBody> maxMass = FindMaxMass(bodies);
		REQUIRE(76 == maxMass->GetMass());
	}
}

TEST_CASE("FindMinResultingForceInWater tests")
{
	vector<shared_ptr<CBody>> bodies;
	SECTION("When one body returns it mass")
	{
		bodies.push_back(make_shared<CCone>(228, 1.000001, 0.56));
		shared_ptr<CBody> minResultingForceInWater = FindMinResultingForceInWater(bodies);
		REQUIRE(-4523.92 == minResultingForceInWater->GetResultingForceInWater());
	}

	SECTION("When two bodies but they're the same type")
	{
		bodies.push_back(make_shared<CCone>(2010, 1.000001, 0.666));
		bodies.push_back(make_shared<CCone>(130, 2, 2));
		shared_ptr<CBody> minResultingForceInWater = FindMinResultingForceInWater(bodies);
		REQUIRE(-72888.6 == minResultingForceInWater->GetResultingForceInWater());
	}

	SECTION("When different bodies are of different types")
	{
		bodies.push_back(make_shared<CCone>(23000, 1.000001, 0.666));
		bodies.push_back(make_shared<CCylinder>(100, 1.1, 0.2));
		bodies.push_back(make_shared<CParallelepiped>(1010, 1, 1, 2));
		bodies.push_back(make_shared<CSphere>(400, 2));
		shared_ptr<CBody> minResultingForceInWater = FindMinResultingForceInWater(bodies);
		REQUIRE(-201060 == minResultingForceInWater->GetResultingForceInWater());
	}

	SECTION("When identical bodies")
	{
		bodies.push_back(make_shared<CCylinder>(100, 1.1, 0.2));
		bodies.push_back(make_shared<CCylinder>(100, 1.1, 0.2));
		shared_ptr<CBody> minResultingForceInWater = FindMinResultingForceInWater(bodies);
		REQUIRE(-6840 == minResultingForceInWater->GetResultingForceInWater());
	}
}
