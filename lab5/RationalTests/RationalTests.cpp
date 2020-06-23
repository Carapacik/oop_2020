#define CATCH_CONFIG_MAIN
#include "../../catch2/catch.hpp"
#include "../Rational/CRational.h"
#include "../Rational/stdafx.h"

using namespace std;

TEST_CASE("Creating fraction tests")
{
    SECTION("Creating a fraction 0/1") 
    {
        CRational rational;

        REQUIRE(rational.GetNumerator() == 0);
        REQUIRE(rational.GetDenominator() == 1);
    }

    SECTION("Creating a fraction m/1")
    {
        CRational rational(5);

        REQUIRE(rational.GetNumerator() == 5);
        REQUIRE(rational.GetDenominator() == 1);
    }

    SECTION("Creating a fraction m/n")
    {
        CRational rational(5, 19);

        REQUIRE(rational.GetNumerator() == 5);
        REQUIRE(rational.GetDenominator() == 19);
    }

    SECTION("Division by zero")
    {
        REQUIRE_THROWS(CRational(5, 0));
    }

    SECTION("Negative numerator")
    {
        CRational rational(-5, 14);

        REQUIRE(rational.GetNumerator() == -5);
        REQUIRE(rational.GetDenominator() == 14);
    }

    SECTION("Negative denominator")
    {
        CRational rational(5, -14);

        REQUIRE(rational.GetNumerator() == -5);
        REQUIRE(rational.GetDenominator() == 14);
    }

    SECTION("Both negative")
    {
        CRational rational(-5, -14);

        REQUIRE(rational.GetNumerator() == 5);
        REQUIRE(rational.GetDenominator() == 14);
    }

    SECTION("Fraction reduction")
    {
        CRational rational1(15, 5);

        REQUIRE(rational1.GetNumerator() == 3);
        REQUIRE(rational1.GetDenominator() == 1);

        CRational rational2(4, 6);

        REQUIRE(rational2.GetNumerator() == 2);
        REQUIRE(rational2.GetDenominator() == 3);
    }

    SECTION("To double fraction")
    {
        CRational rational(4, 10);

        REQUIRE(rational.ToDouble() == 0.4);
    }

    SECTION("Compound fraction")
    {
        CRational rational(16, 11);
        std::pair<int, CRational> result = rational.ToCompoundFraction();

        REQUIRE(result.first == 1);
        REQUIRE(result.second == CRational(5, 11));
    }
}

TEST_CASE("Unary operations checking")
{

    SECTION("Unary plus")
    {
        CRational rational(-11, 16);
        CRational result = +rational;

        REQUIRE(result.GetNumerator() == -11);
        REQUIRE(result.GetDenominator() == 16);
    }

    SECTION("Unary minus")
    {
        CRational rational(-11, 16);
        CRational result = -rational;

        REQUIRE(result.GetNumerator() == 11);
        REQUIRE(result.GetDenominator() == 16);

        CRational rational1(11, -16);
        CRational result1 = -rational1;

        REQUIRE(result1.GetNumerator() == 11);
        REQUIRE(result1.GetDenominator() == 16);
    }
}

TEST_CASE("Binary operations checking")
{
    SECTION("Plus")
    {
        CRational rational1(7, 7);
        CRational rational2(10, 7);
        CRational result1 = rational1 + rational2;

        REQUIRE(result1.GetNumerator() == 17);
        REQUIRE(result1.GetDenominator() == 7);

        result1 = result1 + 1;

        REQUIRE(result1.GetNumerator() == 24);

        CRational rational3(81, 14);
        CRational result2 = rational1 + rational3;
        std::pair<int, CRational> resultPair = result2.ToCompoundFraction();

        REQUIRE(resultPair.first == 6);
        REQUIRE(resultPair.second == CRational(11, 14));
    }

    SECTION("Minus")
    {
        CRational rational1(7, 7);
        CRational rational2(10, 7);
        CRational result1 = rational1 - rational2;

        REQUIRE(result1.GetNumerator() == -3);
        REQUIRE(result1.GetDenominator() == 7);

        CRational result2 = rational2 - rational1;

        REQUIRE(result2.GetNumerator() == 3);
        REQUIRE(result2.GetDenominator() == 7);

        CRational rational3(10, 7);
        CRational result3 = rational2 - rational3;

        REQUIRE(result3.GetNumerator() == 0);
        REQUIRE(result3.GetDenominator() == 1);
    }

    SECTION("Multiplication")
    {
        CRational rational1(2, 7);
        CRational rational2(-3, 7);
        CRational result = rational1 * rational2;

        REQUIRE(result.GetNumerator() == -6);
        REQUIRE(result.GetDenominator() == 49);

        result = result * (-4);

        REQUIRE(result.GetNumerator() == 24);
        REQUIRE(result.GetDenominator() == 49);
    }

    SECTION("Division")
    {
        CRational rational1(6, 2);
        CRational rational2(3);
        CRational result1 = rational1 / rational2;

        REQUIRE(result1.GetNumerator() == 1);
        REQUIRE(result1.GetDenominator() == 1);

        CRational rational3(-3, 8);
        CRational result2 = rational2 / rational3;

        REQUIRE(result2.GetNumerator() == -8);
        REQUIRE(result2.GetDenominator() == 1);
    }
}

TEST_CASE("Change by the value of the second number")
{
    SECTION("Increase") 
    {
        CRational rational1(1, 3);
        CRational rational2(1, 6);
        rational1 += rational2;

        REQUIRE(rational1.GetNumerator() == 1);
        REQUIRE(rational1.GetDenominator() == 2);

        rational1 += 2;

        REQUIRE(rational1.GetNumerator() == 5);
        REQUIRE(rational1.GetDenominator() == 2);
    }

    SECTION("Decrease")
    {
        CRational rational1(3, 5);
        CRational rational2(2, 10);
        rational1 -= rational2;

        REQUIRE(rational1.GetNumerator() == 2);
        REQUIRE(rational1.GetDenominator() == 5);

        rational1 -= 1;

        REQUIRE(rational1.GetNumerator() == -3);
        REQUIRE(rational1.GetDenominator() == 5);
    }

    SECTION("Multiplication")
    {
        CRational rational1(4, 3);
        CRational rational2(5, 7);
        rational1 *= rational2;

        REQUIRE(rational1.GetNumerator() == 20);
        REQUIRE(rational1.GetDenominator() == 21);

        rational1 *= 3;

        REQUIRE(rational1.GetNumerator() == 20);
        REQUIRE(rational1.GetDenominator() == 7);
    }

    SECTION("Division")
    {
        CRational rational1(1, 2);
        CRational rational2(2, 3);
        rational1 /= rational2;

        REQUIRE(rational1.GetNumerator() == 3);
        REQUIRE(rational1.GetDenominator() == 4);

        rational1 /= 5;

        REQUIRE(rational1.GetNumerator() == 3);
        REQUIRE(rational1.GetDenominator() == 20);

        REQUIRE_THROWS(rational1 / 0);
    }
}

TEST_CASE("Checking the comparison")
{
    SECTION("==") 
    {
        CRational rational1(1, 6);
        CRational rational2(2, 6);
        CRational rational3(1, 3);

        REQUIRE_FALSE(rational1 == rational2);
        REQUIRE(rational2 == rational3);
    }

    SECTION("!=")
    {
        CRational rational1(1, 6);
        CRational rational2(2, 6);
        CRational rational3(1, 3);

        REQUIRE_FALSE(rational2 != rational3);
        REQUIRE(rational1 != rational2);
    }

    SECTION("< and <=")
    {
        CRational rational1(1, 6);
        CRational rational2(2, 6);
        CRational rational3(1, 3);

        REQUIRE(rational1 < rational2);
        REQUIRE(rational1 < rational3);
        REQUIRE(rational1 <= rational3);
        REQUIRE(rational2 <= rational3);
    }

    SECTION("> and >=")
    {
        CRational rational1(1, 3);
        CRational rational2(2, 3);
        CRational rational3(4, 6);
        CRational rational4(5, 6);
    
        REQUIRE(rational2 > rational1);
        REQUIRE(rational2 >= rational3);
        REQUIRE(rational3 >= rational1);
        REQUIRE(rational4 > rational3);
        REQUIRE(rational4 >= rational3);
        REQUIRE(rational4 > rational1);
    }
}

TEST_CASE("Checking how the stream works")
{
    CRational rational1(2, 7);
    stringstream stream1;
    stream1 << rational1;

    REQUIRE(stream1.str() == "2/7");

    CRational rational2;
    stream1 >> rational2;

    REQUIRE(rational2.GetNumerator() == 2);
    REQUIRE(rational2.GetDenominator() == 7);

    CRational rational3(2, 4);
    stringstream stream2;
    stream2 << rational3.ToDouble();

    REQUIRE(stream2.str() == "0.5");
}