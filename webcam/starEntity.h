#ifndef STARENTITY_H_
#define STARENTITY_H_

struct Star
{
	int id;
	double x;
	double y; 
};

struct TriangleLiebe
{
	int id1, id2, id3, id4, id5, id6, id7, id8, id9, id10, id11, id12;
	double alpha1;
	double t1_beta, t2_beta, t3_beta, t4_beta, t5_beta, t6_beta, t7_beta, t8_beta, t9_beta, t10_beta;
	double t1_alpha2, t2_alpha2, t3_alpha2, t4_alpha2, t5_alpha2, t6_alpha2, t7_alpha2, t8_alpha2, t9_alpha2, t10_alpha2;
	double heading;
};

struct TriangleLiebeVoting
{
	TriangleLiebe triangleLiebe; 
	double voting; //sum of percent devation --> best fit in case of many matching
	int matching; //amount of matched center star --> max 3
};

struct TriangleAreaMoment
{
	int id1, id2, id3, id4, id5, id6, id7, id8, id9, id10, id11, id12;
	double t1_area, t2_area, t3_area, t4_area, t5_area, t6_area, t7_area, t8_area, t9_area, t10_area;
	double t1_moment, t2_moment, t3_moment, t4_moment, t5_moment, t6_moment, t7_moment, t8_moment, t9_moment, t10_moment;
	double heading;
};

struct TriangleAreaMomentVoting
{
	TriangleAreaMoment tam;
	double voting;
	int matching;
};

struct TrianglePlanarAngle
{
	int id1, id2, id3, id4, id5, id6, id7, id8, id9, id10, id11, id12; //id1 = central star, id2= fix star, rest the 3rd point of a triangle
	double t1_alpha, t2_alpha, t3_alpha, t4_alpha, t5_alpha, t6_alpha, t7_alpha, t8_alpha, t9_alpha, t10_alpha;
	double t1_beta, t2_beta, t3_beta, t4_beta, t5_beta, t6_beta, t7_beta, t8_beta, t9_beta, t10_beta;
	double t1_gamma, t2_gamma, t3_gamma, t4_gamma, t5_gamma, t6_gamma, t7_gamma, t8_gamma, t9_gamma, t10_gamma;
	double heading;
};

struct TrianglePlanarAngleVoting
{
	TrianglePlanarAngle trianglePlanarAngle;
	double voting;
	int matching;
};
#endif