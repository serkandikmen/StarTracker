#ifndef PARAM_H_
#define PARAM_H_


#include <iostream>
#include <stdio.h>
#include <fstream>
#include <vector>
#include "math3d.h"
#include <string>
#include <cfloat>
#include <opencv2/imgproc.hpp>
#include <opencv2/video/video.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/opencv.hpp>
#include <opencv2/features2d/features2d.hpp>
#include "starEntity.h"

using namespace cv;

#define OFFSET_VEHICLE_CAM 265 //mm

#define PARAM_CV_FX 6.1251645028048017e+02
#define PARAM_CV_FY 6.1251645028048017e+02
#define PARAM_CV_CX 3.1950000000000000e+02
#define PARAM_CV_CY 2.3950000000000000e+02
#define PARAM_CV_K1 1.8930650815204930e-01
#define PARAM_CV_K2 -2.7085059296171616e+00
#define PARAM_CV_K3 1.8192133864845225e+01
#define PARAM_CV_P1 -9.2705154357984685e-04
#define PARAM_CV_P2 -1.8905700196152531e-03

#define PARAM_MATLAB_FX 613.1740
#define PARAM_MATLAB_FY 611.7489
#define PARAM_MATLAB_CX 312.7737
#define PARAM_MATLAB_CY 242.5541
#define PARAM_MATLAB_K1 0.1299
#define PARAM_MATLAB_K2 -0.3771
#define PARAM_MATLAB_K3 0
#define PARAM_MATLAB_P1 -7.3859e-05
#define PARAM_MATLAB_P2 -0.0081

#define PARAM_DIST_FX 612
#define PARAM_DIST_FY 612
#define PARAM_DIST_CX 640/2
#define PARAM_DIST_CY 480/2
#define PARAM_DIST_K1 0
#define PARAM_DIST_K2 0
#define PARAM_DIST_K3 0
#define PARAM_DIST_P1 0
#define PARAM_DIST_P2 0

//voting parameters for selecting the most central 3 stars
#define VOTING_LIEBE 1
#define VOTING_AREA_MOMENT 1
#define VOTING_PLANAR_ANGLE 1

//running all algorithms together and select best one
#define VOTING_ALL_ALGORITHMS 0
#define VOTING_AREA_MOMENT_PLANAR_ANGLE 1
#define DRAW_ALL_TRIANGLE 0

enum ImageType
{
	ENUM_DISTORTED, ENUM_UNDISTORTED_OPENCV, ENUM_UNDISTORTED_MATLAB
};

struct DistortionParameter
{
	double fx, fy, cx, cy;
	double k1, k2, k3, p1, p2;
};


#endif
