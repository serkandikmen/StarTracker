#ifndef TRIANGLE_H_
#define TRIANGLE_H_

#include <iostream>
#include <stdio.h>
#include <fstream>
#include <vector>
#include "math3d.h"
#include <string>
#include <cfloat>
#include "opencv2/imgproc/imgproc.hpp"
#include <opencv2/video/video.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/opencv.hpp>
#include <opencv2/features2d/features2d.hpp>
#include "starEntity.h"
#include "param.h"

using namespace std;
using namespace cv;

//TODO
#define PI 3.14159265
#define DEGtoRAD PI/180
#define RADtoDEG 180/PI
#define FOCAL 3.67E-3
#define FOCALINPIXEL 612.46145
#define PIXELSIZE_X 2.083333333E-6
#define PIXELSIZE_Y 2.34375E-6
#define PIXELSCALE_X 3.6
#define PIXELSCALE_Y 3.2

//radial distortion coefficients
#define K1 1.892065-1//0.1299
#define K2 -2.7085//-0.3771

//tangential distortion coeffcients
#define P1 -9.270515E-4//-7.3859E-5
#define P2 -1.89057E-3//-0.0081

//distortion center //principal point
#define DISTORTIONCENTER_WIDTH 219.5//312.7737
#define DISTORTIONCENTER_HEIGTH 239.5//242.5541 

//alpha scaling
#define SCALE_FACTOR_MAX 18
#define SCALE_FACTOR_MIN 13
#define SCALE_FACTOR_AVERAGE 15.5

//beta deviation
#define BETA_DEVIATION 5

#define PIXELTOMM 0.34 // 217.6 mm on screen video capture

class Triangle
{
public:
	Triangle();
	virtual ~Triangle();
	void loadData(string filename_cartesian, string filename_triangle, string filename_AreaMoment, string filename_PlanarAngle);
	Point2f buildTriangleAndProcess(vector<Star> starsOnImage, Mat &frame, struct DistortionParameter distParam, float alpha, float beta);
	Point2f buildTriangleAreaMomentAndProcess(vector<Star> starsOnImage, Mat &frame, struct DistortionParameter distParam, float area, float moment);
	Point2f buildTrianglePlanarAngleAndProcess(vector<Star> starsOnImage, Mat &frame, struct DistortionParameter distParam, float angle);
	void drawTriangle(int n, Star centralStar, Star closeStar, Mat &frame);
	void calcHeading(Star center, Star fix, double angleCatalog);
	Point2f setOffset(Star centralCorrect, float headingCam, Point2f starPos, double cx, double cy);
	double getHeading();
	double getAngleFromVector(double v1x, double v1y, double v2x, double v2y);

	double getVoting(double t1_a, double t1_b, double t2_a, double t2_b);
	double getVoting(double t1_a, double t1_b, double t1_c, double t2_a, double t2_b, double t2_c);

	Star* getClosestStars(vector<Star> starsOnImage, Star centralStar);
	double* getAlphaBeta(Star center, Star fix, Star third, double f);
	double* getAreaMoment(Star center, Star fix, Star third);
	double* getPlanarAngle(Star center, Star fix, Star third);
	vector<TriangleLiebe> getMatchingListAlphaBeta(int num, double calculatedAlpha1, double calculatedAlpha2, double calculatedBeta, double scaleMin, double scaleMax, double betaPercentage);
	vector<TriangleAreaMoment> getMatchingListAreaMoment(int num, double calculatedArea, double calculatedMoment, double areaPercentage, double momentPercentage);
	vector<TrianglePlanarAngle> getMatchingListPlanarAngle(int num, double calculatedAlpha, double calculatedBeta, double calculatedGamma, double percentage);
private: 
	vector<Star> stars;
	vector<TriangleLiebe> trianglesLiebe;
	vector<TriangleAreaMoment> trianglesAreaMoment;
	vector<TrianglePlanarAngle> trianglesPlanarAngle;
	double heading;
	
	Point2f lastPositionLiebe;
	Point2f lastPositionAreaMoment;
	Point2f lastPositionPlanarAngle;
	bool lastPositionLiebeFound = false;; 
	bool lastPositionAreaMomentFound = false;
	bool lastPositionPlanarAngleFound = false;;
};



#endif
