#define CATCH_CONFIG_MAIN
#include "../../../catch2/catch.hpp"
#include "../HTMLDecode/HTMLDecodeFunctions.h"
#include "../HTMLDecode/stdafx.h"

using namespace std;

TEST_CASE("Empty string after HTMLDecode be empty")
{
	string htmlDecoded = HTMLDecode("");
	string result = "";

	REQUIRE(htmlDecoded == result);
}

TEST_CASE("String without decoding entities dont't change")
{
	string htmlDecoded = HTMLDecode("Withhout entities");
	string result = "Withhout entities";

	REQUIRE(htmlDecoded == result);
}

TEST_CASE("String with one decoding entity")
{
	string htmlDecoded = HTMLDecode("Love &amp; peace");
	string result = "Love & peace";

	REQUIRE(htmlDecoded == result);
}

TEST_CASE("Exaple string in task")
{
	string htmlDecoded = HTMLDecode("Cat &lt;says&gt; &quot;Meow&quot;. M&amp;M&apos;s ");
	string result = "Cat <says> \"Meow\". M&M's ";

	REQUIRE(htmlDecoded == result);
}