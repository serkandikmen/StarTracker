#include "math3d.h"

double dotproduct(vec3d v1, vec3d v2)
{
	return (v1.x*v2.x) + (v1.y*v2.y) + (v1.z*v2.z);
}

double length(vec3d v)
{
	return sqrt((v.x*v.x)+(v.y*v.y)+(v.z*v.z));
}
double dotproduct(vec2d v1, vec2d v2)
{
	return (v1.x*v2.x) + (v1.y*v2.y);
}

double length(vec2d v)
{
	return sqrt((v.x*v.x)+(v.y*v.y));
}
double length(vec3d v1, vec3d v2)
{
	vec3d temp = getVecDiff(v1, v2);
	return sqrt((temp.x*temp.x)+(temp.y*temp.y)+(temp.z*temp.z));
}

double space(Star s1, Star s2)
{
	double result =  sqrt(pow(s1.x - s2.x, 2) + pow(s1.y - s2.y, 2));
	return result;
}

vec3d getVecDiff(vec3d v1, vec3d v2)
{
	vec3d temp;
	temp.x = v1.x - v2.x;
	temp.y = v1.y - v2.y;
	temp.z = v1.z - v2.z;
	return temp;
}

vec3d getVec3d(double x, double y, double z)
{
	vec3d v;
	v.x = x;
	v.y = y;
	v.z = z;
	return v;
}
vec2d getVec2d(double x, double y)
{
	vec2d v;
	v.x = x;
	v.y = y;
	return v;
}

double angle(vec3d v1, vec3d v2)
{
	double angle = acos((dotproduct(v1, v2))/(length(v1) * length(v2)));
	return angle;
}
double angle(vec2d v1, vec2d v2)
{
	return acos((dotproduct(v1, v2))/(length(v1) * length(v2)));
}

void normalize(vec3d& v)
{
	double vectorLength = length(v);
	v.x /= vectorLength;
	v.y /= vectorLength;
	v.z /= vectorLength;
}

vec3d getVec3d(Star s, double cx, double cy)
{
	double uz = pow(1 + pow((s.x - cx) * PIXELSCALE_X * PIXELSIZE_X / FOCAL, 2) + pow((s.y - cy) * PIXELSCALE_Y * PIXELSIZE_Y / FOCAL, 2), -0.5);
	vec3d v;
	v.z = uz;
	v.x = (s.x - cx) * PIXELSCALE_X * PIXELSIZE_X / FOCAL * uz;
	v.y = (s.y - cy) * PIXELSCALE_Y * PIXELSIZE_Y / FOCAL * uz;
	return v;
}

void undistortStar(Star* s)
{
	double x = (s->x - DISTORTIONCENTER_WIDTH);
	double y = (s->y - DISTORTIONCENTER_HEIGTH);
	double r = sqrt(pow(s->x - DISTORTIONCENTER_WIDTH,2) + pow(s->y - DISTORTIONCENTER_HEIGTH,2));

	double x_u = x + x*(K1*pow(r,2) + K2*pow(r,4)) + P2*(pow(r,2)+2*pow(x,2)) + 2*P1*x*y;
	double y_u = y + y*(K1*pow(r,2) + K2*pow(r,4)) + P1*(pow(r,2)+2*pow(y,2)) + 2*P2*x*y;
	printf("---> sx %f  sy %f \n", s->x,s->y);

	printf("dis cent x %f  y %f \n", x_u,y_u);

	x = (s->x - 320);
	y = (s->y - 240);
	r = sqrt(pow((s->x - 320),2) + pow((s->y - 240),2));
	x_u = x + x*(K1*pow(r,2) + K2*pow(r,4)) + P2*(pow(r,2)+2*pow(x,2)) + 2*P1*x*y;
	y_u = y + y*(K1*pow(r,2) + K2*pow(r,4)) + P1*(pow(r,2)+2*pow(y,2)) + 2*P2*x*y;
	printf("orig cent x %f  y %f \n", x_u,y_u);


	s->x = x_u;
	s->y = y_u;

}

vec3d getVec3d(Star s, double focal)
{
	double uz = pow(1 + pow((s.x - 320) / focal, 2) + pow((s.y - 240) / focal, 2), -0.5);
	vec3d v;
	v.z = uz;
	v.x = (s.x - 320) / focal * uz;
	v.y = (s.y - 240) / focal * uz;
	return v;
}

double planarArea(vec3d v1, vec3d v2, vec3d v3)
{
	double a = length(getVecDiff(v1, v2));
	double b = length(getVecDiff(v2, v3));
	double c = length(getVecDiff(v1, v3));
	double s = 0.5*(a+b+c);
	return sqrt(s*(s-a) * (s-b) * (s-c));
}
