#ifndef PROCESS_H_
#define PROCESS_H_

#include <opencv2/imgproc.hpp>
#include <opencv2/video/video.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/opencv.hpp>
#include <opencv2/features2d/features2d.hpp>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <cmath>
#include <vector>
#include "triangle.h"
#include "math3d.h"
#include "starfinder.h"
#include "starEntity.h"
#include "param.h"
#include <time.h>
#include "client.h"

#define DEBUG


//ringbuffer for reading
#define RINGBUFFERSIZE 1024
unsigned char ringbuffer[RINGBUFFERSIZE];
int readIndex;
int writeIndex;

const unsigned char type_reserved = 0;
const unsigned char type_noDistortion = 1;
const unsigned char type_opencv = 2;
const unsigned char type_matlab = 3;
const unsigned char type_noSmoothing = 4;
const unsigned char type_Box = 5;
const unsigned char type_Median = 6;
const unsigned char type_Gaussian = 7;
const unsigned char type_detectionThreshold = 8;
const unsigned char type_Hough = 9;
const unsigned char type_Contour = 10;
const unsigned char type_HoughCanny = 11;
const unsigned char type_HoughAccumulator = 12;
const unsigned char type_HoughMin = 13;
const unsigned char type_HoughMax = 14;
const unsigned char type_ContourCanny = 15;
const unsigned char type_Liebe = 16;
const unsigned char type_LiebeAlpha = 17;
const unsigned char type_LiebeBeta = 18;
const unsigned char type_AreaMoment = 19;
const unsigned char type_Area = 20;
const unsigned char type_Moment = 21;
const unsigned char type_PlanarAngle = 22;
const unsigned char type_Angle = 23;
const unsigned char type_Best = 24;
const unsigned char type_Specific = 25;
const unsigned char type_Amount = 26;
const unsigned char type_Last = 27;
const unsigned char type_BestLast = 28;


#endif
