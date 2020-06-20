#pragma once
#include "CBody.h"
#include "CCone.h"
#include "CCylinder.h"
#include "CParallelepiped.h"
#include "CSphere.h"
#include "stdafx.h"

const std::string LIGHTEST_BODY_IN_WATER = "Lightest body in water: ";
const std::string BIGGEST_WEIGHT = "Body with biggest weight: ";
const std::string ENTER_BODY_TYPE = "Enter body type: \n\t1 - Cone\n\t2 - Cylinder\n\t3 - Parallelepiped\n\t4 - Sphere\n\t0 - End and calculate results\n";
const std::string UNKNOWN_TYPE = "Unknown type\n";
const std::string ENTER_DENSITY = "Enter density: ";
const std::string ENTER_CONE_BASERADIUS = "Enter Cone baseradius: "; 
const std::string ENTER_CONE_HEIGHT = "Enter Cone height: ";
const std::string ENTER_CYLINDER_BASERADIUS = "Enter Cylinder baseradius: ";
const std::string ENTER_CYLINDER_HEIGHT = "Enter Cylinder height: ";
const std::string ENTER_PARALLELEPIPED_WIDTH = "Enter Parallelepiped width: ";
const std::string ENTER_PARALLELEPIPED_HEIGHT = "Enter Parallelepiped height: ";
const std::string ENTER_PARALLELEPIPED_DEPTH = "Enter Parallelepiped depth: ";
const std::string ENTER_SPHERE_RADIUS = "Enter Sphere radius: ";

std::shared_ptr<CBody> FindMaxWeight(const std::vector<std::shared_ptr<CBody>>& bodies);
std::shared_ptr<CBody> FindMinWeightInWater(const std::vector<std::shared_ptr<CBody>>& bodies);
bool IsCorrectType(int& type);
void FillBodiesVector(std::vector<std::shared_ptr<CBody>>& bodies, std::istream& input, std::ostream& output);
void Controller(std::vector<std::shared_ptr<CBody>> bodies, std::istream& input, std::ostream& output);
void Print(const std::shared_ptr<CBody>& bodies, std::ostream& output);