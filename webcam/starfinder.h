#ifndef STARFINDER_H_
#define STARFINDER_H_

#include "opencv2/imgproc/imgproc.hpp"
#include <opencv2/video/video.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/opencv.hpp>
#include <opencv2/features2d/features2d.hpp>

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include "starEntity.h"

using namespace std;
using namespace cv;

#define CANNYTHRESHOLD -1
#define ACCUMULATORTHRESHOLD -1
#define MIN_DIST -1
#define MAX_RADIUS -1


class Starfinder
{
public:
	Starfinder();
	virtual ~Starfinder();
	vector<Star> findStarsByHoughDetection(Mat &frame, int cannyThreshold, int accumulatorThreshold, int min_dist, int max_radius);
	vector<Star> findStarsByHoughDetection(Mat &frame);
	vector<Star> findStarsByContourDetection(Mat &frame, int cannyThreshold);
	vector<Star> findStarsByContourDetection(Mat &frame);
	void showStars(Mat &frame, string window_name);
private:
	vector<Star> starsOnImage;
	void clearStars();
};


#endif
