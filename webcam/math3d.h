#ifndef MATH3D_H_
#define MATH3D_H_

#include <math.h>
#include "triangle.h"
#include "starEntity.h"

struct vec3d
{
	double x;
	double y; 
	double z;
};

struct vec2d
{
	double x;
	double y;
};

double dotproduct(vec3d v1, vec3d v2);
double length(vec3d v);
double dotproduct(vec2d v1, vec2d v2);
double length(vec2d v);
double length(vec3d v1, vec3d v2);
double space(Star s1, Star s2);
vec3d getVecDiff(vec3d v1, vec3d v2);
vec3d getVec3d(double x, double y, double z);
vec2d getVec2d(double x, double y);
double angle(vec3d v1, vec3d v2);
double angle(vec2d v1, vec2d v2);
void normalize(vec3d &v);
vec3d getVec3d(Star s, double cx, double cy);
void undistortStar(Star* s);
vec3d getVec3d(Star s, double focal);
double planarArea(vec3d v1, vec3d v2, vec3d v3);
//double planarMoment(vec3d v1, vec3d v2, vec3d v3, double area);
#endif 