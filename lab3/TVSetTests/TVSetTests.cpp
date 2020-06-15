#define CATCH_CONFIG_MAIN
#include "../../catch2/catch.hpp"
#include "../TVSet/CTVSet.h"

TEST_CASE("When TV turned on in the first should be 1 channel")
{
	CTVSet TV;
	TV.TurnOn();

	REQUIRE(TV.GetChannel() == 1);
}

TEST_CASE("When the TV is turned off, it must have channel = 0.")
{
	CTVSet TV;
	TV.TurnOff();

	REQUIRE(TV.GetChannel() == 0);
}

TEST_CASE("Check SelectChannel")
{
	CTVSet TV;
	TV.TurnOn();
	TV.SelectChannel(99);

	REQUIRE(TV.GetChannel() == 99);
}

TEST_CASE("When selecting a channel and restarting TV, it must be the same channel.")
{
	CTVSet TV;
	TV.TurnOn();
	TV.SelectChannel(10);
	TV.TurnOff();
	TV.TurnOn();

	REQUIRE(TV.GetChannel() == 10);
}

TEST_CASE("Select a non-existent channel.")
{
	CTVSet TV;
	TV.TurnOn();
	TV.SelectChannel(10);
	TV.SelectChannel(100);

	REQUIRE(TV.GetChannel() == 10);
	TV.SelectChannel(0);

	REQUIRE(TV.GetChannel() == 10);
}

TEST_CASE("Select channel at borders")
{
	CTVSet TV;
	TV.TurnOn();
	TV.SelectChannel(10);
	TV.SelectChannel(99);

	REQUIRE(TV.GetChannel() == 99);
	TV.SelectChannel(10);
	TV.SelectChannel(1);

	REQUIRE(TV.GetChannel() == 1);
}

TEST_CASE("Select a channel on the off TV.")
{
	CTVSet TV;
	TV.TurnOff();
	TV.SelectChannel(2);

	REQUIRE(TV.GetChannel() == 0);
}

TEST_CASE("When selecting the previous channel, it should form a loop between the two channels.")
{
	CTVSet TV ;
	TV.TurnOn();
	TV.SelectChannel(10);
	TV.SelectChannel(99);
	TV.SelectChannel(1);
	TV.SelectPreviousChannel();
	int channel1 = TV.GetChannel();
	TV.SelectPreviousChannel();
	int channel2 = TV.GetChannel();	
	TV.SelectPreviousChannel();
	int channel3 = TV.GetChannel();

	REQUIRE(channel1 == 99);
	REQUIRE(channel2 == 1);
	REQUIRE(channel1 == channel3);
}