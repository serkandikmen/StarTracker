#include "starfinder.h"

Starfinder::Starfinder()
{

}

Starfinder::~Starfinder()
{

}

vector<Star> Starfinder::findStarsByHoughDetection(Mat &frame, int cannyThreshold, int accumulatorThreshold, int min_dist, int max_radius)
{
    //delete previous star list
    clearStars();
    std::vector<Vec3f> circles;
    HoughCircles(frame, circles, CV_HOUGH_GRADIENT, 1, frame.rows/min_dist, cannyThreshold, accumulatorThreshold, 0, max_radius );
    for( size_t i = 0; i < circles.size(); i++ )
    {
        Star detectedStar;
        detectedStar.id = i;
        detectedStar.x = circles[i][0];
        detectedStar.y = circles[i][1];
        //int radius = cvRound(circles[i][2]); don't need the size of stars, because all are equal sized
 		starsOnImage.push_back(detectedStar);
    }
    return starsOnImage;
}

vector<Star> Starfinder::findStarsByHoughDetection(Mat &frame)
{
    findStarsByHoughDetection(frame, CANNYTHRESHOLD, ACCUMULATORTHRESHOLD, MIN_DIST, MAX_RADIUS);
}

vector<Star> Starfinder::findStarsByContourDetection(Mat &frame, int cannyThreshold)
{
    //delete previous star list
    clearStars();
    Mat canny_output;
    vector<vector<Point> > contours;
    vector<Vec4i> hierarchy;

    Canny(frame, canny_output, cannyThreshold, cannyThreshold*2, 3);
    findContours(canny_output, contours, hierarchy, RETR_EXTERNAL, CHAIN_APPROX_SIMPLE, Point(0,0));

    //get moments
    vector<Moments> mu(contours.size());
    for(int i = 0; i < contours.size(); i++)
    {
        mu[i] = moments(contours[i], false);
    }

    //get the mass centers
    vector<Point2f> mc(contours.size());
    vector<Point2f> center(contours.size());
    vector<float> radius(contours.size());
    vector<vector<Point> > contours_poly(contours.size());

    int counter = 0;
    for(int i = 0; i < contours.size(); i++)
    {
        Point2f temp = Point2f(mu[i].m10/mu[i].m00, mu[i].m01/mu[i].m00);
        //delete all NaN values !!!!!!
        if(temp.x == temp.x && temp.y == temp.y) //Nan values hav ethe odd property that comparisons involving them are always false!
        {
            Star detectedStar;
            detectedStar.id = i;
            detectedStar.x = temp.x;
            detectedStar.y = temp.y;
            starsOnImage.push_back(detectedStar);
        } 
    }
    return starsOnImage;
}

vector<Star> Starfinder::findStarsByContourDetection(Mat &frame)
{
    findStarsByContourDetection(frame, CANNYTHRESHOLD);
}

void Starfinder::showStars(Mat &frame, string window_name)
{
	for( size_t i = 0; i < starsOnImage.size(); i++ )
    {
        Point2f pos;
        pos.x = starsOnImage[i].x;
        pos.y = starsOnImage[i].y;
        circle( frame, pos, 4, Scalar(0,0,255), -1, 8, 0 );
        std::stringstream s;
		s << "" << starsOnImage[i].id;
		putText(frame, s.str(), pos, FONT_HERSHEY_SIMPLEX, 0.4, Scalar(0,0,0), 1, 8, false);
    }
    std::stringstream detectedStars;
	detectedStars << "detected stars: " << starsOnImage.size();
	putText(frame, detectedStars.str(), Point(20,20), FONT_HERSHEY_COMPLEX, 0.6, Scalar(0,255,0), 1, 8, false);
    // shows the results
    //imshow( window_name, frame);
}

void Starfinder::clearStars()
{
    starsOnImage.clear();
}
