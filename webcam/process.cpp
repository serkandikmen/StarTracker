#include "process.h"

using namespace cv;
using namespace std;

/* for time calculation */
#define BILLION  1e9;
struct timespec start, stop;
double accum;

/* ID name of star tracker used for sending messages */
const unsigned char ID = 1;

/* counter for saving txt files */
int imageI = 0;
int mode = 1;

/* host and port for TCP communication */
int _port;
char* _host;

/* trackbar names */
const char* trackbar_threshold = "Threshold";
const char* trackbar_smoothing = "None:0, Box:1, Median:2, Gaussian:3";
const char* trackbar_starfinder = "Hough:0, Contour:1";
const char* trackbar_contourCanny = "Contour Canny";
const char* trackbar_houghCanny = "Hough Canny";
const char* trackbar_houghAcc = "Hough Accumulator";
const char* trackbar_houghMin = "Min Distance to centers";
const char* trackbar_houghMax = "Max radius";
const char* trackbar_distortion = "Distorted:0, Undistorted OpenCV:1, Undistorted Matlab:2";
const char* trackbar_typeAlgorithm = "Liebe:0, AreaMoment:1, PlanarAngle:2, All:3";
const char* trackbar_alpha = "Alpha Scale";
const char* trackbar_beta = "Beta Deviation";
const char* trackbar_area = "Area";
const char* trackbar_moment = "Moment";
const char* trackbar_angle = "Angle";
const char* trackbar_voting = "Voting:0 Best, 1: Specific, 2: Last";
const char* trackbar_amount = "Amount for Voting";

/* trackbar values */
int value_threshold = 120;
int value_contourCanny = 10;
int value_houghCanny = 10;
int value_houghAcc = 10;
int value_houghMin = 10;
int value_houghMax = 10;
int value_smoothing = 0;
int value_starfinder = 1;
int value_distortion = 0;
int value_typeAlgorithm = 0;
int value_alpha = 2;
int value_beta = 5;
int value_area = 5;
int value_moment = 7;
int value_angle = 2;
int value_voting = 0;
int value_amount = 5;

/* window names */
string window_name = "Process Star Detection";
string window_name_debug = "Debugging Window";

namespace 
{
    void help(char** av) 
    {
        cout << "STAR TRACKER SOFTWARE" << endl
             << "Usage:\n" << av[0] << " <video file, image sequence or device number>" << endl
             << "esc -- quit" << endl
             << "p save image" << endl 
             << "s start recording" << endl 
             << "r write records to textfile" << endl << endl
             << "\tTo capture from a camera pass the device number. To find the device number, try ls /dev/video*" << endl
             << "\texample: " << av[0] << " 0" << endl;
    }

    void loadParameter(enum ImageType type, struct DistortionParameter* param)
    {
        if(type == ENUM_UNDISTORTED_OPENCV)
        {
            param->fx = PARAM_CV_FX;
            param->fy = PARAM_CV_FY;
            param->cx = PARAM_CV_CX;
            param->cy = PARAM_CV_CY;
            param->k1 = PARAM_CV_K1;
            param->k2 = PARAM_CV_K2;
            param->k3 = PARAM_CV_K3;
            param->p1 = PARAM_CV_P1;
            param->p2 = PARAM_CV_P2;
        }
        else if(type == ENUM_UNDISTORTED_MATLAB)
        {
            param->fx = PARAM_MATLAB_FX;
            param->fy = PARAM_MATLAB_FY;
            param->cx = PARAM_MATLAB_CX;
            param->cy = PARAM_MATLAB_CY;
            param->k1 = PARAM_MATLAB_K1;
            param->k2 = PARAM_MATLAB_K2;
            param->k3 = PARAM_MATLAB_K3;
            param->p1 = PARAM_MATLAB_P1;
            param->p2 = PARAM_MATLAB_P2;
        }
        else if(type == ENUM_DISTORTED)
        {
            param->fx = PARAM_DIST_FX;
            param->fy = PARAM_DIST_FY;
            param->cx = PARAM_DIST_CX;
            param->cy = PARAM_DIST_CY;
            param->k1 = PARAM_DIST_K1;
            param->k2 = PARAM_DIST_K2;
            param->k3 = PARAM_DIST_K3;
            param->p1 = PARAM_DIST_P1;
            param->p2 = PARAM_DIST_P2;
        }
    }

    void setNewPicture(struct DistortionParameter param, Mat& frame)
    {
        double dataCameraMatrix[3][3] = {param.fx, 0, param.cx, 0, param.fy, param.cy, 0, 0, 1};
        double dataDistCoeffs[8][1] = {param.k1, param.k2, param.p1, param.p2, param.k3};
        Mat cameraMatrix = Mat(3, 3, CV_64F, &dataCameraMatrix);
        Mat distCoeffs = Mat(8, 1, CV_64F, &dataDistCoeffs);
        Mat rview, map1, map2;
        initUndistortRectifyMap(cameraMatrix, distCoeffs, Mat(), getOptimalNewCameraMatrix(cameraMatrix, distCoeffs, Size(640,480), 1, Size(640,480), 0), Size(640,480), CV_16SC2, map1, map2);
        remap(frame, rview, map1, map2, INTER_LINEAR);
        frame = rview.clone();
    }

    int process(VideoCapture& capture) 
    {
        int n = 0;
        char filename[200];
        cout << "press esc to quit" << endl;
        #ifdef DEBUG
        
        //creating main windows
        namedWindow(window_name, WINDOW_AUTOSIZE);
        namedWindow(window_name_debug, WINDOW_AUTOSIZE);
        	
        createTrackbar(trackbar_threshold, window_name, &value_threshold, 255); 
		createTrackbar(trackbar_starfinder, window_name, &value_starfinder, 1); 
        createTrackbar(trackbar_contourCanny, window_name, &value_contourCanny, 255);
		createTrackbar(trackbar_houghCanny, window_name, &value_houghCanny, 255); 
		createTrackbar(trackbar_houghAcc, window_name, &value_houghAcc, 100); 
		createTrackbar(trackbar_houghMin, window_name, &value_houghMin, 64); 
		createTrackbar(trackbar_houghMax, window_name, &value_houghMax, 30); 
		createTrackbar(trackbar_smoothing, window_name, &value_smoothing, 3); 

    	createTrackbar(trackbar_distortion, window_name_debug, &value_distortion, 2);
    	createTrackbar(trackbar_typeAlgorithm, window_name_debug, &value_typeAlgorithm, 3);
    	createTrackbar(trackbar_alpha, window_name_debug, &value_alpha, 7);
    	createTrackbar(trackbar_beta, window_name_debug, &value_beta, 30);
    	createTrackbar(trackbar_area, window_name_debug, &value_area, 30);
   		createTrackbar(trackbar_moment, window_name_debug, &value_moment, 30);
    	createTrackbar(trackbar_angle, window_name_debug, &value_angle, 30);
    	createTrackbar(trackbar_voting, window_name_debug, &value_voting, 2);
    	createTrackbar(trackbar_amount,  window_name_debug, &value_amount, 10);
       	#endif
       	
       	/* Paramaters */
        Mat frame_gray, frame_thres;
        Mat frame;
        ImageType _imageType;
        DistortionParameter _distortionParameter;

        /* Object Starfinder to detect stars on image */
        Starfinder starfinder;

        /* Object Triangle for the algorithms */
        Triangle triangle;
        triangle.loadData("cartesian.txt", "tLiebe.txt", "tAreaMoments.txt", "tPlanarAngles.txt"); //load catalogs

        /* every algorithms position and heading saved extra 
        --> lists for recording*/
        double headingLiebe;
        double headingAreaMoment;
        double headingPlanarAngle;
        double headingCorrect;
        vector<double> headingListLiebe;
        vector<double> headingListAreaMoment;
        vector<double> headingListPlanarAngle;
        vector<double> headingListCorrect;
        Point2f currentPositionLiebe;
        Point2f currentPositionAreaMoment;
        Point2f currentPositionPlanarAngle;
        Point2f currentPositionCorrect;
        bool lastPositionFound = false;
        Point2f lastPosition;
        lastPosition.x = 0;
        lastPosition.y = 0;
        vector<Point2f> lastPositionList;
        vector<Point2f> positionListLiebe;
        vector<Point2f> positionListAreaMoment;
        vector<Point2f> positionListPlanarAngle;
        vector<Point2f> positionListCorrect;
        vector<double> timeList;
        double lastProcessedTime = 0;
        bool autoDetect = false;
	  
        /* Object for TCP communication */
        Client client(_host, _port);
	    /* init */
        _imageType = ENUM_DISTORTED;
        loadParameter(_imageType, &_distortionParameter);
	
    	/*state machine for received message
    	-->states: 0 = idle mode waiting for DELIMITER
    	-->1 = id, 2 = length, 3 = type, 4 data(if any) */
    	int state = 0;
    	unsigned char idGroundStation;
    	unsigned char lengthData;
    	unsigned char type;
    	unsigned char data;

        /* loop */
        for (;;) 
        {
            capture >> frame;
            if (frame.empty()) break;  
	    	
            /* look for commands from ground station */
	    	while(writeIndex != readIndex)
            {
				unsigned char temp = ringbuffer[readIndex++];
				if(readIndex == RINGBUFFERSIZE) readIndex = 0;
				switch(state)
				{
				    case 0: if(temp == 255)
		                  {
							state = 1;
						  } 
						break;
					case 1: idGroundStation = temp;
						state = 2;
						break;
					case 2: lengthData = temp;
						state = 3;
						break;
					case 3: type = temp;
						if(type == type_reserved)
						{
							//message from the groundstation that everything is fine
							state = 0;
						}
						else
						{
							state = 4;
						}
						break;
					case 4:	state = 0;
						switch(type)
						{
							case type_noDistortion: value_distortion = 0; 
										_imageType = ENUM_DISTORTED;
										loadParameter(_imageType, &_distortionParameter);
										break;
							case type_opencv: value_distortion = 1;
										_imageType = ENUM_UNDISTORTED_OPENCV;
										loadParameter(_imageType, &_distortionParameter);
										break;
							case type_matlab: value_distortion = 2;
										_imageType = ENUM_UNDISTORTED_MATLAB;
										loadParameter(_imageType, &_distortionParameter);
										break;	
							case type_noSmoothing: value_smoothing = 0;
										break;
							case type_Box:value_smoothing = 1; break;
							case type_Median: value_smoothing = 2; break;
							case type_Gaussian: value_smoothing = 3; break;
							case type_detectionThreshold: value_threshold = temp; break;
							case type_Hough: value_starfinder = 0; break;
							case type_Contour: value_starfinder = 1; break;
							case type_HoughCanny: value_houghCanny = temp; break;
							case type_HoughAccumulator: value_houghAcc = temp; break;
							case type_HoughMin: value_houghMin = temp; break;
							case type_HoughMax: value_houghMax = temp; break;
							case type_ContourCanny: value_contourCanny = temp; break;
							case type_Liebe: value_typeAlgorithm = 0; break;
							case type_AreaMoment: value_typeAlgorithm = 1; break;
							case type_PlanarAngle: value_typeAlgorithm = 2; break;
							case type_LiebeAlpha: value_alpha = temp; break;
							case type_LiebeBeta: value_beta = temp; break;
							case type_Area: value_area = temp; break;
							case type_Moment: value_moment = temp; break;
							case type_Angle: value_angle = temp; break;							
						}				
				}
		    }
            Mat simulationFrame = Mat::zeros(440, 540, CV_8UC3);
            clock_gettime( CLOCK_REALTIME, &start);

            /* distortion correction */
			#ifdef DEBUG
				if(value_distortion == 0)
				{
					_imageType = ENUM_DISTORTED;
					loadParameter(_imageType, &_distortionParameter);
				}
				else if(value_distortion == 1)
				{
					_imageType = ENUM_UNDISTORTED_OPENCV;
					loadParameter(_imageType, &_distortionParameter);
				}
				else if(value_distortion == 2)
				{
					_imageType = ENUM_UNDISTORTED_MATLAB;
					loadParameter(_imageType, &_distortionParameter);
				}
			#endif
			setNewPicture(_distortionParameter, frame);
		
            /* Image processing */
            /* gray conversion */
            cvtColor(frame, frame_gray, COLOR_RGB2GRAY);
            /* applying threshold */
            threshold(frame_gray, frame_thres, value_threshold, 255, 0);
            /*smoothing*/
            if(value_smoothing == 1) blur(frame_thres, frame_thres, Size(9,9), Point(-1, -1));
            else if(value_smoothing == 2) medianBlur(frame_thres, frame_thres, 9);
            else if(value_smoothing == 3) GaussianBlur(frame_thres, frame_thres, Size(9, 9), 2, 2);

            /* parameters which cannot be zero are set to 1 */ 
            value_threshold = std::max(value_threshold, 1);
            value_houghCanny = std::max(value_houghCanny, 1);
            value_houghMin = std::max(value_houghMin, 1);
            value_houghMax = std::max(value_houghMax, 1);
            value_contourCanny = std::max(value_contourCanny, 1);
            /* Find stars in the image with either Hough or Contour */      
            vector<Star> currentStars;
    		if(value_starfinder == 0)
    		{
    			currentStars = starfinder.findStarsByHoughDetection(frame_thres, value_houghCanny, value_houghAcc, value_houghMin, value_houghMax);
    		}
    		else if(value_starfinder == 1)
    		{
    			currentStars = starfinder.findStarsByContourDetection(frame_thres, value_contourCanny);
    		}
    		starfinder.showStars(frame, window_name);

            /* auto brightness */
            printf("thres %d", value_threshold);
    		if(autoDetect)
    		{
    			if(currentStars.size() > 35)
    			{
    				value_threshold += 10;
    				continue;
    			}
    			if(currentStars.size() < 20)
    			{
    				value_threshold -= 10;
    				continue;
    			}	
    		}
        
            /* Star Tracker Algorithms*/
            /* Determine Star constellations and calculate position and heading */
            if(value_typeAlgorithm == 0)
            {
                currentPositionLiebe = triangle.buildTriangleAndProcess(currentStars, frame, _distortionParameter, value_alpha, value_beta);
                headingLiebe = triangle.getHeading();
                headingLiebe += 90; //from camera reference to vehicle reference
                if(headingLiebe>360) headingLiebe -= 360;
                positionListLiebe.push_back(currentPositionLiebe);
                headingListLiebe.push_back(headingLiebe);
            }
            else if(value_typeAlgorithm == 1)
            {
                currentPositionAreaMoment = triangle.buildTriangleAreaMomentAndProcess(currentStars, frame, _distortionParameter, value_area, value_moment);
                headingAreaMoment = triangle.getHeading();
                headingAreaMoment += 90; //from camera reference to vehicle reference
                if(headingAreaMoment>360) headingAreaMoment -= 360;
                positionListAreaMoment.push_back(currentPositionAreaMoment);
                headingListAreaMoment.push_back(headingAreaMoment);
            }
            else if(value_typeAlgorithm == 2)
            {
                currentPositionPlanarAngle = triangle.buildTrianglePlanarAngleAndProcess(currentStars, frame, _distortionParameter, value_angle);
                headingPlanarAngle = triangle.getHeading();
                headingPlanarAngle += 90; //from camera reference to vehicle reference
                if(headingPlanarAngle>360) headingPlanarAngle -= 360;
                positionListPlanarAngle.push_back(currentPositionPlanarAngle);
                headingListPlanarAngle.push_back(headingPlanarAngle);
            }
            else if(value_typeAlgorithm == 3)
            {
                /*currentPositionLiebe = triangle.buildTriangleAndProcess(currentStars, frame, _distortionParameter, value_alpha, value_beta);
                headingLiebe = triangle.getHeading();
                headingLiebe += 90; //from camera reference to vehicle reference
                if(headingLiebe>360) headingLiebe -= 360;*/
                currentPositionAreaMoment = triangle.buildTriangleAreaMomentAndProcess(currentStars, frame, _distortionParameter, value_area, value_moment);
                headingAreaMoment = triangle.getHeading();
                headingAreaMoment += 90; //from camera reference to vehicle reference
                if(headingAreaMoment>360) headingAreaMoment -= 360;
                currentPositionPlanarAngle = triangle.buildTrianglePlanarAngleAndProcess(currentStars, frame, _distortionParameter, value_angle);
                headingPlanarAngle = triangle.getHeading();
                headingPlanarAngle += 90; //from camera reference to vehicle reference
                if(headingPlanarAngle>360) headingPlanarAngle -= 360;
                //positionListLiebe.push_back(currentPositionLiebe);
                positionListAreaMoment.push_back(currentPositionAreaMoment);
                positionListPlanarAngle.push_back(currentPositionPlanarAngle);
                //headingListLiebe.push_back(headingLiebe);
                headingListAreaMoment.push_back(headingAreaMoment);
                headingListPlanarAngle.push_back(headingPlanarAngle);
                
            }

            /* Voting all algorithms*/
            /*if(VOTING_ALL_ALGORITHMS == 1 && value_typeAlgorithm == 3)
            {
            	    if((currentPositionAreaMoment.x - currentPositionPlanarAngle.x == 0) && (currentPositionAreaMoment.y - currentPositionPlanarAngle.y == 0))
                    {
                        positionListCorrect.push_back(currentPositionPlanarAngle);
                    	headingListCorrect.push_back(headingPlanarAngle); 
                    }
            	    else if((currentPositionLiebe.x - currentPositionPlanarAngle.x == 0) && (currentPositionLiebe.y - currentPositionPlanarAngle.y == 0))
                    {
                        positionListCorrect.push_back(currentPositionPlanarAngle);
                    	headingListCorrect.push_back(headingPlanarAngle); 
                    }
                    else if((currentPositionAreaMoment.x - currentPositionLiebe.x == 0) && (currentPositionAreaMoment.y - currentPositionLiebe.y == 0))
                    {
                        positionListCorrect.push_back(currentPositionAreaMoment);
                    	headingListCorrect.push_back(headingAreaMoment); 
                    }                 
                    else
                    {
                        currentPositionCorrect.x = 0.0;
                        currentPositionCorrect.y = 0.0;
                        headingCorrect = 0.0;
                        positionListCorrect.push_back(currentPositionCorrect);
                    	headingListCorrect.push_back(headingCorrect);
                    }
            }  */ 

            /* Voting only area moment and palanar angle algorithms*/
            if(VOTING_AREA_MOMENT_PLANAR_ANGLE == 1 && value_typeAlgorithm == 3)
            {

                    if((currentPositionAreaMoment.x - currentPositionPlanarAngle.x == 0) && (currentPositionAreaMoment.y - currentPositionPlanarAngle.y == 0))
                    {
                    	currentPositionCorrect = currentPositionPlanarAngle;
                    	headingCorrect = headingPlanarAngle;
                    	positionListCorrect.push_back(currentPositionCorrect);
                    	headingListCorrect.push_back(headingCorrect);             
                    	lastPositionList.push_back(currentPositionPlanarAngle);
			if(!lastPositionFound && lastPositionList.size() == 10)
			{
				lastPositionFound = true;
			} 
                    	else if(lastPositionFound)
                    	{	printf("size before %d", lastPositionList.size());
                    		for(int i = 0; i < lastPositionList.size()-1; i++)
                    		{
                    				lastPositionList[i] = lastPositionList[i+1];
                    		}
                    		lastPositionList.pop_back();
                    		lastPosition.x = 0;
                    		lastPosition.y = 0;
                    		for(int i = 0; i < lastPositionList.size(); i++)
                    		{
                    			 lastPosition.x += lastPositionList[i].x;
                    			 lastPosition.y += lastPositionList[i].y;
                    		}
                    		printf("size %d", lastPositionList.size());
                    		lastPosition.x /= 10;
                    		lastPosition.y /= 10;
                    		printf("Last positon x %f, y %f", lastPosition.x,lastPosition.y);
                    	} 
     		   }                
      		   else
                   {		
                   		currentPositionCorrect.x = 0.0;
                        	currentPositionCorrect.y = 0.0;
                        	headingCorrect = 0.0;
                    		if(lastPositionFound)
                    		{
                    			double temp = sqrt(pow(currentPositionPlanarAngle.x-lastPosition.x,2) + pow(currentPositionPlanarAngle.y-lastPosition.y,2));
                    			if(temp<200) //100 mm
                    			{
                    				currentPositionCorrect = currentPositionPlanarAngle;
                    				headingCorrect = headingPlanarAngle;
                    			}
                    		}
                        	positionListCorrect.push_back(currentPositionCorrect);
                    		headingListCorrect.push_back(headingCorrect);
               	} 
            }

            /* stop clock */
            clock_gettime( CLOCK_REALTIME, &stop);
            accum = ( stop.tv_sec - start.tv_sec ) + ( stop.tv_nsec - start.tv_nsec ) / BILLION;

            /* accumulate time if no position was detected */
            if(value_typeAlgorithm == 3 && currentPositionCorrect.x == 0.0)
            {
            	lastProcessedTime += accum*1000;
            	timeList.push_back(0);
            }
            else
            {
            	if(lastProcessedTime != 0)
            	{
            		timeList.push_back(accum*1000 + lastProcessedTime);
            		lastProcessedTime = 0;
            	}
            	else timeList.push_back(accum*1000);
            }

            /* Simulation Window*/
        	std::stringstream putFPS;
        	putFPS << "time in ms: " << accum * 1000;
        	putText(frame, putFPS.str(), Point(20,460), FONT_HERSHEY_COMPLEX, 0.6, Scalar(0,255,0), 1, 8, false);
        	#ifdef DEBUG
        		imshow( window_name, frame);
        	#endif
        	circle( simulationFrame, Point2f(currentPositionLiebe.x/10, (simulationFrame.rows - (currentPositionLiebe.y/10))), 5, Scalar(0,255,0), -1, 8, 0 );
 	 	line(simulationFrame, Point2f(simulationFrame.cols/2, 0), Point2f(simulationFrame.cols/2, simulationFrame.rows), Scalar(255,0,0), 0.5, 4, 0);
        	line(simulationFrame, Point2f(0, simulationFrame.rows/2), Point2f(simulationFrame.cols, simulationFrame.rows/2), Scalar(255,0,0), 0.5, 4, 0);       	
        	circle( simulationFrame, Point2f(currentPositionAreaMoment.x/10, (simulationFrame.rows - (currentPositionAreaMoment.y/10))), 5, Scalar(255,0,0), -1, 8, 0 );
        	circle( simulationFrame, Point2f(currentPositionPlanarAngle.x/10, (simulationFrame.rows - (currentPositionPlanarAngle.y/10))), 5, Scalar(0,0,255), -1, 8, 0 );	
        	std::stringstream putHeading;
        	putHeading << "Heading: " << headingLiebe << " " << headingAreaMoment << " " << headingPlanarAngle;
        	putText(simulationFrame, putHeading.str(), Point(20,20), FONT_HERSHEY_COMPLEX, 0.6, Scalar(0,255,0), 1, 8, false);
        	#ifdef DEBUG
        	   imshow(window_name_debug, simulationFrame);
	        #endif	

		
        	/* TCP connection */
        	/*client.connectToServer();
        	Mat clientImage = frame.clone();
        	clientImage = (clientImage.reshape(0,1));
        	long imgSize = clientImage.total()*clientImage.elemSize();
        	long n = 0;
        	n = client.sendPosition((int)currentPosition.x,(int)currentPosition.y, ID);
        	printf("%ld pos\n", n);
        	n = client.sendAttitude((int) heading, ID);
        	printf("%ld att\n", n);
        	n = client.sendImage(clientImage.data, imgSize, ID);
        	printf("%ld image\n", n);
        	//read
        	char* buf = new char[1024];
        	n = client.receive(buf);
        	for(int i = 0; i < n; i++)
        	{
        		ringbuffer[writeIndex++] = buf[i];
        		if(writeIndex == RINGBUFFERSIZE) writeIndex = 0;
        	}
        	printf("%ld received\n", n);
             client.unconnectToServer();*/


		    char key = (char)waitKey(30); //delay N millis, usually long enough to display and capture input
            printf("%c", key);
            switch (key) 
            {
            	case 112: char s[50];
            		sprintf(s, "/home/ubuntu/code/webcam/images/image%d.png", imageI++);
            		imwrite(s, frame); break;
            	case 115: //start recording with r
            		positionListLiebe.clear();
            		positionListAreaMoment.clear();
            		positionListPlanarAngle.clear();
            		positionListCorrect.clear();
            		headingListLiebe.clear();
            		headingListAreaMoment.clear();
            		headingListPlanarAngle.clear();
            		headingListCorrect.clear();
            		timeList.clear();
            		break;
            	case 114: //record with s
            		{	
            		char fileName[50];
            		//sprintf(fileName, "/home/ubuntu/code/webcam/records/outLiebe%d.txt", imageI++);
            		//sprintf(fileName, "/home/ubuntu/code/webcam/records/outAreaM%d.txt", imageI++);
            		//sprintf(fileName, "/home/ubuntu/code/webcam/records/outAngle%d.txt", imageI++);
            		sprintf(fileName, "/home/ubuntu/code/webcam/records/outAreaAngle%d.txt", imageI++);
            		//sprintf(fileName, "/home/ubuntu/code/webcam/records/outALL%d.txt", imageI++);
            		ofstream out;
			        out.open(fileName);
			        /*//14 enries
        			for(int k = 0 ; k < positionListLiebe.size(); k++)
        			{
        				out << k << " " << positionListLiebe[k].x << " "<< positionListLiebe[k].y << " " << headingListLiebe[k] <<
        				" " << positionListAreaMoment[k].x << " "<< positionListAreaMoment[k].y << " " << headingListAreaMoment[k]<<
        				" " << positionListPlanarAngle[k].x << " "<< positionListPlanarAngle[k].y << " " << headingListPlanarAngle[k] << 
        				" " << positionListCorrect[k].x << " "<< positionListCorrect[k].y << " " << headingListCorrect[k] << " "<< timeList[k] << endl;
        			}*/
        			//11 enries area + planar
        			for(int k = 0 ; k < positionListAreaMoment.size(); k++)
        			{
        				out << k << " " << positionListAreaMoment[k].x << " "<< positionListAreaMoment[k].y << " " << headingListAreaMoment[k]<<
        				" " << positionListPlanarAngle[k].x << " "<< positionListPlanarAngle[k].y << " " << headingListPlanarAngle[k] << 
        				" " << positionListCorrect[k].x << " "<< positionListCorrect[k].y << " " << headingListCorrect[k] << " "<< timeList[k] << endl;
        			}
        			//liebe
        			/*for(int k = 0 ; k < positionListLiebe.size(); k++)
        			{
        				out << k << " " << positionListLiebe[k].x << " "<< positionListLiebe[k].y << " " << headingListLiebe[k]  << " "<< timeList[k] << endl;
        			}*/
        			 //area moment
        			/*for(int k = 0 ; k < positionListAreaMoment.size(); k++)
        			{
        				out << k << " " << positionListAreaMoment[k].x << " "<< positionListAreaMoment[k].y << " " << headingListAreaMoment[k]  << " "<< timeList[k] << endl;
        			}*/
        			 //planarAngle
        			/*for(int k = 0 ; k < positionListPlanarAngle.size(); k++)
        			{
        				out << k << " " << positionListPlanarAngle[k].x << " "<< positionListPlanarAngle[k].y << " " << headingListPlanarAngle[k]  << " "<< timeList[k] << endl;
        			}*/
        			out.close();
        			break;}
                case 27: return 0;
                case 49: lastPositionFound = false; break;
                default: break;
            }

        }
        return 0;
    }
}



int main(int ac, char** av) 
{

    /* start webcam */
    if (ac != 2) 
    {
        help(av);
        return 1;
    }
    std::string arg = av[1];
    VideoCapture capture(arg); //try to open string, this will attempt to open it as a video file or image sequence
       system("/home/ubuntu/code/webcam/disableAutofocus.sh");
    if (!capture.isOpened()) //if this fails, try to open as a video camera, through the use of an integer param
        capture.open(atoi(arg.c_str()));
    if (!capture.isOpened()) 
    {
        cerr << "Failed to open the video device, video file or image sequence!\n" << endl;
        help(av);
        return 1;
    }

    /* communication parameters */
	_host = "192.168.0.100";
	_port = 1234;

    /* loop */
    return process(capture);
}
