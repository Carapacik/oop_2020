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
	SECTION("Get density return correct density")
	{
		REQUIRE(1110 == cone->GetDensity());
	}

	SECTION("Get baseradius return correct baseradius")
	{
		REQUIRE(1.0004 == cone->GetBaseRadius());
	}

	SECTION("Get height return correct height")
	{
		REQUIRE(0.76 == cone->GetHeight());
	}

	SECTION("Get volume return correct calculated volume")
	{
		REQUIRE(0.797 == cone->GetVolume());
	}

	SECTION("Get mass return correct calculated mass")
	{
		REQUIRE(884.67 == cone->GetMass());
	}
}

TEST_CASE("CCylinder Tests")
{
	CCylinder* cylinder = new CCylinder(600, 7, 1.99);
	SECTION("Get density return correct density")
	{
		REQUIRE(600 == cylinder->GetDensity());
	}

	SECTION("Get baseradius return correct baseradius")
	{
		REQUIRE(7 == cylinder->GetBaseRadius());
	}

	SECTION("Get height return correct height")
	{
		REQUIRE(1.99 == cylinder->GetHeight());
	}

	SECTION("Get volume return correct calculated volume")
	{
		REQUIRE(306.337 == cylinder->GetVolume());
	}

	SECTION("Get mass return correct calculated mass")
	{
		REQUIRE(183802.2 == cylinder->GetMass());
	}
}

TEST_CASE("CParallelepiped Tests")
{
	CParallelepiped* parallelepiped = new CParallelepiped(999.998, 0.88, 0.655, 0.3333);
	SECTION("Get density return correct density")
	{
		REQUIRE(999.998 == parallelepiped->GetDensity());
	}

	SECTION("Get width return correct width")
	{
		REQUIRE(0.88 == parallelepiped->GetWidth());
	}

	SECTION("Get height return correct height")
	{
		REQUIRE(0.655 == parallelepiped->GetHeight());
	}

	SECTION("Get depth return correct depth")
	{
		REQUIRE(0.3333 == parallelepiped->GetDepth());
	}

	SECTION("Get volume return correct calculated volume")
	{
		REQUIRE(0.192 == parallelepiped->GetVolume());
	}

	SECTION("Get mass return correct calculated mass")
	{
		REQUIRE(192 == parallelepiped->GetMass());
	}
}

TEST_CASE("CSphere Tests")
{
	CSphere* sphere = new CSphere(1800, 1.33);
	SECTION("Get density return correct density")
	{
		REQUIRE(1800 == sphere->GetDensity());
	}	

	SECTION("Get radius return correct radius")
	{
		REQUIRE(1.33 == sphere->GetRadius());
	}

	SECTION("Get volume return correct calculated volume")
	{
		REQUIRE(9.855 == sphere->GetVolume());
	}

	SECTION("Get mass return correct calculated mass")
	{
		REQUIRE(17739 == sphere->GetMass());
	}
}

TEST_CASE("FindMaxWeight tests")
{
	vector<shared_ptr<CBody>> bodies;
	SECTION("When one body returns it mass")
	{
		bodies.push_back(make_shared<CCone>(228, 1.000001, 0.56));
		shared_ptr<CBody> maxMassWeight;
		REQUIRE(133.608 == (maxMassWeight->FindMaxWeight(bodies))->GetMass());
	}

	SECTION("When two bodies but they're the same type")
	{
		bodies.push_back(make_shared<CCone>(2010, 1.000001, 0.666));
		bodies.push_back(make_shared<CCone>(130, 2, 2));
		shared_ptr<CBody> maxMassWeight;
		REQUIRE(1400.97 == (maxMassWeight->FindMaxWeight(bodies))->GetMass());
	}

	SECTION("When different bodies are of different types")
	{
		bodies.push_back(make_shared<CCone>(23000, 1.000001, 0.666));
		bodies.push_back(make_shared<CCylinder>(100, 1.1, 0.2));
		bodies.push_back(make_shared<CParallelepiped>(1010, 1, 1, 2));
		bodies.push_back(make_shared<CSphere>(400, 2));
		shared_ptr<CBody> maxMassWeight;
		REQUIRE(16031 == (maxMassWeight->FindMaxWeight(bodies))->GetMass());
	}

	SECTION("When identical bodies")
	{
		bodies.push_back(make_shared<CCylinder>(100, 1.1, 0.2));
		bodies.push_back(make_shared<CCylinder>(100, 1.1, 0.2));
		shared_ptr<CBody> maxMassWeight;
		REQUIRE(76 == (maxMassWeight->FindMaxWeight(bodies))->GetMass());
	}
}

TEST_CASE("FindMinWeightInWater tests")
{
	vector<shared_ptr<CBody>> bodies;
	SECTION("When one body returns it mass")
	{
		bodies.push_back(make_shared<CCone>(228, 1.000001, 0.56));
		shared_ptr<CBody> minWeightWater;
		REQUIRE(133.608 == (minWeightWater->FindMinWeightInWater(bodies))->GetMass());
	}

	SECTION("When two bodies but they're the same type")
	{
		bodies.push_back(make_shared<CCone>(2010, 1.000001, 0.666));
		bodies.push_back(make_shared<CCone>(130, 2, 2));
		shared_ptr<CBody> minWeightWater;
		REQUIRE(1089.14 == (minWeightWater->FindMinWeightInWater(bodies))->GetMass());
	}

	SECTION("When different bodies are of different types")
	{
		bodies.push_back(make_shared<CCone>(23000, 1.000001, 0.666));
		bodies.push_back(make_shared<CCylinder>(100, 1.1, 0.2));
		bodies.push_back(make_shared<CParallelepiped>(1010, 1, 1, 2));
		bodies.push_back(make_shared<CSphere>(400, 2));
		shared_ptr<CBody> minWeightWater;
		REQUIRE(13404 == (minWeightWater->FindMinWeightInWater(bodies))->GetMass());
	}

	SECTION("When identical bodies")
	{
		bodies.push_back(make_shared<CCylinder>(100, 1.1, 0.2));
		bodies.push_back(make_shared<CCylinder>(100, 1.1, 0.2));
		shared_ptr<CBody> minWeightWater;
		REQUIRE(76 == (minWeightWater->FindMinWeightInWater(bodies))->GetMass());
	}
}
