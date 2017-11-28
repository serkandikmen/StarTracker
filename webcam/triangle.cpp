#include "triangle.h"


//creating database object
Triangle::Triangle()
{

}
Triangle::~Triangle()
{

}

void Triangle::loadData(string filename_cartesian, string filename_triangle, string filename_AreaMoment, string filename_PlanarAngle)
{
	ifstream infile;
	//loading cartesian star coordinates
	infile.open(filename_cartesian.c_str());
	while(infile.good())
	{
		int id;
		double x, y, z, mag;
		infile >> id >> x >> y;
		infile.ignore(256, '\n');
		Star star;
		star.id = id;
		star.x = x;
		star.y = y;
		stars.push_back(star);
	}
	infile.close();

	//loading triangle liebe
	infile.open(filename_triangle.c_str());
	while(infile.good())
	{
		int id1, id2, id3, id4, id5, id6, id7, id8, id9, id10, id11, id12;
		double alpha1;
		double t1_beta, t2_beta, t3_beta, t4_beta, t5_beta, t6_beta, t7_beta, t8_beta, t9_beta, t10_beta;
		double t1_alpha2, t2_alpha2, t3_alpha2, t4_alpha2, t5_alpha2, t6_alpha2, t7_alpha2, t8_alpha2, t9_alpha2, t10_alpha2;
		double heading;
		infile >> id1 >> id2 >> id3 >> id4 >> id5 >> id6 >> id7 >> id8 >> id9 >> id10 >> id11 >> id12 >> alpha1 >> t1_beta >> t1_alpha2 
				>> t2_beta >> t2_alpha2 >> t3_beta >> t3_alpha2 >> t4_beta >> t4_alpha2 >> t5_beta >> t5_alpha2 >> t6_beta >> t6_alpha2 
				>> t7_beta >> t7_alpha2 >> t8_beta >> t8_alpha2 >> t9_beta >> t9_alpha2 >> t10_beta >> t10_alpha2 >> heading;
		infile.ignore(400, '\n');  
		TriangleLiebe t;
		t.id1 = id1;
		t.id2 = id2;
		t.id3 = id3;
		t.id4 = id4;
		t.id5 = id5;
		t.id6 = id6;
		t.id7 = id7;
		t.id8 = id8;
		t.id9 = id9;
		t.id10 = id10;
		t.id11 = id11;
		t.id12 = id12;
		t.alpha1 = alpha1;
		t.t1_beta = t1_beta;
		t.t2_beta = t2_beta;
		t.t3_beta = t3_beta;
		t.t4_beta = t4_beta;
		t.t5_beta = t5_beta;
		t.t6_beta = t6_beta;
		t.t7_beta = t7_beta;
		t.t8_beta = t8_beta;
		t.t9_beta = t9_beta;
		t.t10_beta = t10_beta;
		t.t1_alpha2 = t1_alpha2;
		t.t2_alpha2 = t2_alpha2;
		t.t3_alpha2 = t3_alpha2;
		t.t4_alpha2 = t4_alpha2;
		t.t5_alpha2 = t5_alpha2;
		t.t6_alpha2 = t6_alpha2;
		t.t7_alpha2 = t7_alpha2;
		t.t8_alpha2 = t8_alpha2;
		t.t9_alpha2 = t9_alpha2;
		t.t10_alpha2 = t10_alpha2;
		t.heading = heading;
		trianglesLiebe.push_back(t);
	}
	infile.close();

	//loading triangle area moment
	infile.open(filename_AreaMoment.c_str());
	while(infile.good())
	{
		int id1, id2, id3, id4, id5, id6, id7, id8, id9, id10, id11, id12;
		double t1_area, t2_area, t3_area, t4_area, t5_area, t6_area, t7_area, t8_area, t9_area, t10_area;
		double t1_moment, t2_moment, t3_moment, t4_moment, t5_moment, t6_moment, t7_moment, t8_moment, t9_moment, t10_moment;
		double heading;
		infile >> id1 >> id2 >> id3 >> id4 >> id5 >> id6 >> id7 >> id8 >> id9 >> id10 >> id11 >> id12
				>> t1_area >> t1_moment >>t2_area >> t2_moment >> t3_area >> t3_moment >>t4_area >> t4_moment >> t5_area >> t5_moment
				>> t6_area >> t6_moment >>t7_area >> t7_moment >> t8_area >> t8_moment >>t9_area >> t9_moment >> t10_area >> t10_moment >> heading;
		infile.ignore(400, '\n');
		TriangleAreaMoment t;
		t.id1 = id1;
		t.id2 = id2;
		t.id3 = id3;
		t.id4 = id4;
		t.id5 = id5;
		t.id6 = id6;
		t.id7 = id7;
		t.id8 = id8;
		t.id9 = id9;
		t.id10 = id10;
		t.id11 = id11;
		t.id12 = id12;
		t.t1_area = t1_area;
		t.t1_moment = t1_moment;
		t.t2_area = t2_area;
		t.t2_moment = t2_moment;
		t.t3_area = t3_area;
		t.t3_moment = t3_moment;
		t.t4_area = t4_area;
		t.t4_moment = t4_moment;
		t.t5_area = t5_area;
		t.t5_moment = t5_moment;
		t.t6_area = t6_area;
		t.t6_moment = t6_moment;
		t.t7_area = t7_area;
		t.t7_moment = t7_moment;
		t.t8_area = t8_area;
		t.t8_moment = t8_moment;
		t.t9_area = t9_area;
		t.t9_moment = t9_moment;
		t.t10_area = t10_area;
		t.t10_moment = t10_moment;
		t.heading = heading;
		trianglesAreaMoment.push_back(t);
	}
	infile.close();

	//loading triangle planar angle
	infile.open(filename_PlanarAngle.c_str());
	while(infile.good())
	{
		int id1, id2, id3, id4, id5, id6, id7, id8, id9, id10, id11, id12;
		double t1_alpha, t2_alpha, t3_alpha, t4_alpha, t5_alpha, t6_alpha, t7_alpha, t8_alpha, t9_alpha, t10_alpha;
		double t1_beta, t2_beta, t3_beta, t4_beta, t5_beta, t6_beta, t7_beta, t8_beta, t9_beta, t10_beta;
		double t1_gamma, t2_gamma, t3_gamma, t4_gamma, t5_gamma, t6_gamma, t7_gamma, t8_gamma, t9_gamma, t10_gamma;
		double heading;

		infile >> id1 >> id2 >> id3 >> id4 >> id5 >> id6 >> id7 >> id8 >> id9 >> id10 >> id11 >> id12
				>> t1_alpha >> t1_beta >> t1_gamma >> t2_alpha >> t2_beta >> t2_gamma >> t3_alpha >> t3_beta >> t3_gamma
				>> t4_alpha >> t4_beta >> t4_gamma >> t5_alpha >> t5_beta >> t5_gamma >> t6_alpha >> t6_beta >> t6_gamma
				>> t7_alpha >> t7_beta >> t7_gamma >> t8_alpha >> t8_beta >> t8_gamma >> t9_alpha >> t9_beta >> t9_gamma >> t10_alpha >> t10_beta >> t10_gamma >> heading;
		infile.ignore(400, '\n');
		TrianglePlanarAngle t;
		t.id1 = id1;
		t.id2 = id2;
		t.id3 = id3;
		t.id4 = id4;
		t.id5 = id5;
		t.id6 = id6;
		t.id7 = id7;
		t.id8 = id8;
		t.id9 = id9;
		t.id10 = id10;
		t.id11 = id11;
		t.id12 = id12;
		t.t1_alpha = t1_alpha;
		t.t1_beta = t1_beta;
		t.t1_gamma = t1_gamma;
		t.t2_alpha = t2_alpha;
		t.t2_beta = t2_beta;
		t.t2_gamma = t2_gamma;
		t.t3_alpha = t3_alpha;
		t.t3_beta = t3_beta;
		t.t3_gamma = t3_gamma;
		t.t4_alpha = t4_alpha;
		t.t4_beta = t4_beta;
		t.t4_gamma = t4_gamma;
		t.t5_alpha = t5_alpha;
		t.t5_beta = t5_beta;
		t.t5_gamma = t5_gamma;
		t.t6_alpha = t6_alpha;
		t.t6_beta = t6_beta;
		t.t6_gamma = t6_gamma;
		t.t7_alpha = t7_alpha;
		t.t7_beta = t7_beta;
		t.t7_gamma = t7_gamma;
		t.t8_alpha = t8_alpha;
		t.t8_beta = t8_beta;
		t.t8_gamma = t8_gamma;
		t.t9_alpha = t9_alpha;
		t.t9_beta = t9_beta;
		t.t9_gamma = t9_gamma;
		t.t10_alpha = t10_alpha;
		t.t10_beta = t10_beta;
		t.t10_gamma = t10_gamma;
		t.heading = heading;
		trianglesPlanarAngle.push_back(t);
	}
	infile.close();
}

Point2f Triangle::buildTriangleAndProcess(vector<Star> starsOnImage, Mat &frame, struct DistortionParameter distParam, float alpha, float beta)
{
	/* find the most central stars */
	Star centralStar, centralStar2, centralStar3;
	double dist_min = DBL_MAX; 
	double dist_min2 = DBL_MAX;
	double dist_min3 = DBL_MAX;
	double distToImageCenter;
	double imageWidth = frame.cols;
	double imageHeigth = frame.rows;
	double cx = distParam.cx;
	double cy = distParam.cy;
	for(int i = 0; i < starsOnImage.size(); i++)
	{
		distToImageCenter = sqrt(pow(cx - starsOnImage[i].x, 2) + pow(cy - starsOnImage[i].y, 2));
		
		if(distToImageCenter < dist_min)
		{
			dist_min3 = dist_min2;
			centralStar3 = centralStar2;
			
			dist_min2 = dist_min;
			centralStar2 = centralStar;
			
			dist_min = distToImageCenter;
			centralStar = starsOnImage[i];
		}
		else if(distToImageCenter < dist_min2)
		{
			dist_min3 = dist_min2;
			centralStar3 = centralStar2;
			
			dist_min2 = distToImageCenter;
			centralStar2 = starsOnImage[i];
		}
		else if(distToImageCenter < dist_min3)
		{
			dist_min3 = distToImageCenter;
			centralStar3 = starsOnImage[i];
		}
	}
	/* draw cross for focal point on image */
	line(frame, Point2f(cx-10, cy), Point2f(cx+10, cy), Scalar(0,255,0), 0.5, 4, 0);
	line(frame, Point2f(cx, cy-10), Point2f(cx, cy+10), Scalar(0,255,0), 0.5, 4, 0);
	circle( frame, Point2f(centralStar.x, centralStar.y), 5, Scalar(255,0,0), -1, 8, 0 );

	/* init voting variables for the voting list method */
	vector<TriangleLiebe> matchingList;
	vector<TriangleLiebeVoting> votingList;
	TriangleLiebeVoting triangleVotingResult;

	/* search range for the scale factor of the alpha angles */
	double scaleFactorMin = SCALE_FACTOR_AVERAGE - alpha;
	double scaleFactorMax = SCALE_FACTOR_AVERAGE + alpha;

	/* init voting variables for the 3 most central stars
		--> parameter names with the ending 'correct' signals the result variable */
	TriangleLiebe result1, result2, result3, resultCorrect;
	Point2f starPosition1, starPosition2, starPosition3, starPositionCorrect;
	Star* closeStars;
	Star* closeStars2;
	Star* closeStars3;
	Star closeStarCorrect, starCorrect;
	bool endResultFound = false;

	/* maximum loop if voting for the most 3 central 3 is demanded */
	int maxLoop = 1; 
	if(VOTING_LIEBE == 1) maxLoop = 3;
	for(int n = 0; n < maxLoop; n++)
	{	
		if(!endResultFound)
		{
			votingList.clear();
			
			/* determination of the neighboring stars for every most central stars */
			if(n == 0)
			{
				closeStars = getClosestStars(starsOnImage, centralStar);
				circle( frame, Point2f(closeStars[0].x, closeStars[0].y), 5, Scalar(255,25,0), -1, 8, 0 );
				line(frame, Point2f(closeStars[0].x, closeStars[0].y), Point2f(centralStar.x, centralStar.y), Scalar(255,25,0), 1, 4, 0);
			}
			else if(n == 1)
			{
				closeStars2 = getClosestStars(starsOnImage, centralStar2);
			}
			else if(n == 2)
			{
				closeStars3 = getClosestStars(starsOnImage, centralStar3);
			}
			bool resultfound = false;	
			
			/* for every most central star build max. triangle to get the result */	
			for(int i = 1; i < 11; i++)
			{
				if(!resultfound)
				{	
					Star tempThird;
					double* tempAlphaBeta;

					/* selecting the third star to build the triangle depending on which most central star */
					if(n == 0)
					{
						switch(i)
						{			
							case 1: tempThird = closeStars[1]; break;
							case 2: tempThird = closeStars[2]; break;
							case 3: tempThird = closeStars[3]; break;
							case 4: tempThird = closeStars[4]; break;
							case 5: tempThird = closeStars[5]; break;
							case 6: tempThird = closeStars[6]; break;
							case 7: tempThird = closeStars[7]; break;
							case 8: tempThird = closeStars[8]; break;
							case 9: tempThird = closeStars[9]; break;
							case 10: tempThird = closeStars[10]; break;
						}
						tempAlphaBeta = getAlphaBeta(centralStar, closeStars[0], tempThird, (distParam.fx+distParam.fy)/2);
					}
					if(n == 1)
					{
						switch(i)
						{			
							case 1: tempThird = closeStars2[1]; break;
							case 2: tempThird = closeStars2[2]; break;
							case 3: tempThird = closeStars2[3]; break;
							case 4: tempThird = closeStars2[4]; break;
							case 5: tempThird = closeStars2[5]; break;
							case 6: tempThird = closeStars2[6]; break;
							case 7: tempThird = closeStars2[7]; break;
							case 8: tempThird = closeStars2[8]; break;
							case 9: tempThird = closeStars2[9]; break;
							case 10: tempThird = closeStars2[10]; break;
						}
						tempAlphaBeta = getAlphaBeta(centralStar2, closeStars2[0], tempThird, (distParam.fx+distParam.fy)/2);
					}
					if(n == 2)
					{
						switch(i)
						{			
							case 1: tempThird = closeStars3[1]; break;
							case 2: tempThird = closeStars3[2]; break;
							case 3: tempThird = closeStars3[3]; break;
							case 4: tempThird = closeStars3[4]; break;
							case 5: tempThird = closeStars3[5]; break;
							case 6: tempThird = closeStars3[6]; break;
							case 7: tempThird = closeStars3[7]; break;
							case 8: tempThird = closeStars3[8]; break;
							case 9: tempThird = closeStars3[9]; break;
							case 10: tempThird = closeStars3[10]; break;
						}
						tempAlphaBeta = getAlphaBeta(centralStar3, closeStars3[0], tempThird, (distParam.fx+distParam.fy)/2);
					}

					/* contains all matches in the catalog */
					matchingList = getMatchingListAlphaBeta(i, tempAlphaBeta[0], tempAlphaBeta[1], tempAlphaBeta[2], scaleFactorMin, scaleFactorMax, beta);
					
					/* draw the triangles */
					if(n == 0)
					{
						switch(i)
						{
							case 1: drawTriangle(n, closeStars[1], centralStar, frame); break;
							case 2: drawTriangle(n, closeStars[2], centralStar, frame); break;
							case 3: drawTriangle(n, closeStars[3], centralStar, frame); break;
							case 4: drawTriangle(n, closeStars[4], centralStar, frame); break;
							case 5: drawTriangle(n, closeStars[5], centralStar, frame); break;
							case 6: drawTriangle(n, closeStars[6], centralStar, frame); break;
							case 7: drawTriangle(n, closeStars[7], centralStar, frame); break;
							case 8: drawTriangle(n, closeStars[8], centralStar, frame); break;
							case 9: drawTriangle(n, closeStars[9], centralStar, frame); break;
							case 10: drawTriangle(n, closeStars[10], centralStar, frame); break;
						}
					}
					if(DRAW_ALL_TRIANGLE == 1)
					{
						if(n == 1)
						{
							switch(i)
							{
								case 1: drawTriangle(n, closeStars2[1], centralStar2, frame); break;
								case 2: drawTriangle(n, closeStars2[2], centralStar2, frame); break;
								case 3: drawTriangle(n, closeStars2[3], centralStar2, frame); break;
								case 4: drawTriangle(n, closeStars2[4], centralStar2, frame); break;
								case 5: drawTriangle(n, closeStars2[5], centralStar2, frame); break;
								case 6: drawTriangle(n, closeStars2[6], centralStar2, frame); break;
								case 7: drawTriangle(n, closeStars2[7], centralStar2, frame); break;
								case 8: drawTriangle(n, closeStars2[8], centralStar2, frame); break;
								case 9: drawTriangle(n, closeStars2[9], centralStar2, frame); break;
								case 10: drawTriangle(n, closeStars2[10], centralStar2, frame); break;
							}
						}
						if(n == 2)
						{
							switch(i)
							{
								case 1: drawTriangle(n, closeStars3[1], centralStar3, frame); break;
								case 2: drawTriangle(n, closeStars3[2], centralStar3, frame); break;
								case 3: drawTriangle(n, closeStars3[3], centralStar3, frame); break;
								case 4: drawTriangle(n, closeStars3[4], centralStar3, frame); break;
								case 5: drawTriangle(n, closeStars3[5], centralStar3, frame); break;
								case 6: drawTriangle(n, closeStars3[6], centralStar3, frame); break;
								case 7: drawTriangle(n, closeStars3[7], centralStar3, frame); break;
								case 8: drawTriangle(n, closeStars3[8], centralStar3, frame); break;
								case 9: drawTriangle(n, closeStars3[9], centralStar3, frame); break;
								case 10: drawTriangle(n, closeStars3[10], centralStar3, frame); break;
							}
						}
					}

					/* fill up matching list voting */	
					double alpha1MatchingList, alpha2MatchingList, betaMatchingList;
					for(int k = 0; k < matchingList.size(); k++)
					{
						switch(i)
						{
							case 1: alpha1MatchingList = matchingList[k].alpha1;
									alpha2MatchingList = matchingList[k].t1_alpha2;
									betaMatchingList = matchingList[k].t1_beta;
									break;
							case 2:	alpha1MatchingList = matchingList[k].alpha1;
									alpha2MatchingList =  matchingList[k].t2_alpha2;
									betaMatchingList = matchingList[k].t2_beta;
									break;
							case 3: alpha1MatchingList = matchingList[k].alpha1;
									alpha2MatchingList =  matchingList[k].t3_alpha2;
									betaMatchingList = matchingList[k].t3_beta;
									break;
							case 4: alpha1MatchingList = matchingList[k].alpha1;
									alpha2MatchingList =  matchingList[k].t4_alpha2;
									betaMatchingList = matchingList[k].t4_beta;
									break;
							case 5: alpha1MatchingList = matchingList[k].alpha1;
									alpha2MatchingList =  matchingList[k].t5_alpha2;
									betaMatchingList = matchingList[k].t5_beta;
									break;
							case 6: alpha1MatchingList = matchingList[k].alpha1;
									alpha2MatchingList =  matchingList[k].t6_alpha2;
									betaMatchingList = matchingList[k].t6_beta;
									break;
							case 7: alpha1MatchingList = matchingList[k].alpha1;
									alpha2MatchingList =  matchingList[k].t7_alpha2;
									betaMatchingList = matchingList[k].t7_beta;
									break;
							case 8: alpha1MatchingList = matchingList[k].alpha1;
									alpha2MatchingList =  matchingList[k].t8_alpha2;
									betaMatchingList = matchingList[k].t8_beta;
									break;
							case 9: alpha1MatchingList = matchingList[k].alpha1;
									alpha2MatchingList =  matchingList[k].t9_alpha2;
									betaMatchingList = matchingList[k].t9_beta;
									break;
							case 10:alpha1MatchingList = matchingList[k].alpha1;
									alpha2MatchingList =  matchingList[k].t10_alpha2;
									betaMatchingList = matchingList[k].t10_beta;
									break;
						}
						bool found = false;
						for(vector<TriangleLiebeVoting>::iterator it = votingList.begin(); it != votingList.end(); ++it)
						{
							if((*it).triangleLiebe.id1 == matchingList[k].id1)
							{
								//update
								found = true;
								it->voting += getVoting(tempAlphaBeta[0], tempAlphaBeta[1],tempAlphaBeta[2], alpha1MatchingList, alpha2MatchingList, betaMatchingList);
								it->matching += 1;
							}
						}
						if(!found)
						{
							TriangleLiebeVoting tv;
							tv.triangleLiebe = matchingList[k];
							tv.voting = getVoting(tempAlphaBeta[0], tempAlphaBeta[1],tempAlphaBeta[2], alpha1MatchingList, alpha2MatchingList, betaMatchingList); 
							tv.matching = 1;
							votingList.push_back(tv);
						}
					}	

					/* do matching list voting 
						look for best match (stand alone highest match count)
						there should be only one constellation match
						if not, the triangle constellation is dynamically extended by one more triangle */			
					if(i >= 3)
					{
						vector<TriangleLiebeVoting> tempList;
						for(int matchCount = i; matchCount > 0; matchCount--)
						{
							for(vector<TriangleLiebeVoting>::iterator it = votingList.begin(); it != votingList.end(); ++it)
							{
								if(it->matching == matchCount)
								{
									tempList.push_back(*it);
								}
							}
							if(tempList.size() == 1)
							{
								//best match found;
								triangleVotingResult = tempList[0];
								resultfound = true;
								break;		
							}
							if(i == 10 && tempList.size() != 0)
							{
								//take the triangle with the smallest error
								double smallest = DBL_MAX;
								for(vector<TriangleLiebeVoting>::iterator it = tempList.begin(); it !=tempList.end(); ++it)
								{
									if(it->voting < smallest)
									{
										smallest = it->voting;
									}
								}
								for(vector<TriangleLiebeVoting>::iterator it = tempList.begin(); it != tempList.end(); ++it)
								{
									if(it->voting == smallest)
									{
										triangleVotingResult = *it;
									}
								}
							}	
						}
					}					
				}
			}
			/* assign star positions */
			switch(n)
			{
				case 0: result1 = triangleVotingResult.triangleLiebe; 
						starPosition1.x = stars[result1.id1].x;
						starPosition1.y = stars[result1.id1].y;
						break;
				case 1: result2 = triangleVotingResult.triangleLiebe; 
						starPosition2.x = stars[result2.id1].x;
						starPosition2.y = stars[result2.id1].y;
						break;
				case 2: result3 = triangleVotingResult.triangleLiebe; 
						starPosition3.x = stars[result3.id1].x;
						starPosition3.y = stars[result3.id1].y;
						break;
			}
			/* voting most central stars 
				--> only 2 most central stars (low cost)*/
			if(VOTING_LIEBE == 1)
			{
				if(n == 1)
				{
					printf("s1 %f %f, s2 %f %f\n", starPosition1.x,starPosition1.y,starPosition2.x,starPosition2.y);
					double distOnImage = sqrt(pow(centralStar.x-centralStar2.x,2) + pow(centralStar.y-centralStar2.y,2)) * PIXELTOMM;
					double distCalculated = sqrt(pow(starPosition1.x-starPosition2.x,2) + pow(starPosition1.y-starPosition2.y,2));
					if(distCalculated < distOnImage + 30)
					{
						starPositionCorrect = starPosition1;
						closeStarCorrect = closeStars[0];
						resultCorrect = result1;
						starCorrect = centralStar;
						endResultFound = true;
					}
				}
			}
		}		
	}
	/* voting most central stars 
		--> all 3 most central stars (if not possible with 2)*/
	if(VOTING_LIEBE == 1)
	{
		if(!endResultFound)
		{	
			printf("s1 %f %f, s2 %f %f\n", starPosition1.x,starPosition1.y,starPosition2.x,starPosition2.y);
			printf("s3 %f %f\n", starPosition3.x,starPosition3.y);
			double distOnImage13 = sqrt(pow(centralStar.x-centralStar3.x,2) + pow(centralStar.y-centralStar3.y,2)) * PIXELTOMM;
			double distCalculated13 = sqrt(pow(starPosition1.x-starPosition3.x,2) + pow(starPosition1.y-starPosition3.y,2));
			double distOnImage23 = sqrt(pow(centralStar2.x-centralStar3.x,2) + pow(centralStar2.y-centralStar3.y,2)) * PIXELTOMM;
			double distCalculated23 = sqrt(pow(starPosition2.x-starPosition3.x,2) + pow(starPosition2.y-starPosition3.y,2));
			if(distCalculated13 < distOnImage13 + 30) //3cm deviation
			{
				starPositionCorrect = starPosition1;
				closeStarCorrect = closeStars[0];
				resultCorrect = result1;
				starCorrect = centralStar;
			}
			else if(distCalculated23 < distOnImage23 + 30) //3cm deviation
			{
				starPositionCorrect = starPosition2;
				closeStarCorrect = closeStars2[0];
				resultCorrect = result2;
				starCorrect = centralStar2;
			}
			else
			{
				//assume first central star to be true
				starPositionCorrect = starPosition1;
				closeStarCorrect = closeStars[0];
				resultCorrect = result1;
				starCorrect = centralStar;
			}
		}
	}
	/* if only one most central star */	
	else
	{
		starPositionCorrect = starPosition1;
		closeStarCorrect = closeStars[0];
		resultCorrect = result1;
		starCorrect = centralStar;
	}
	printf("done--->");
	printf("%d\n", resultCorrect.id1);
	printf("xs %f, ys %f \n", stars[resultCorrect.id1].x, stars[resultCorrect.id1].y);
	printf("close  x%f, s %f \n", closeStarCorrect.x, closeStarCorrect.y);
	printf("heading catalog %f\n", resultCorrect.heading);

	/* calculation of camera heading */
	calcHeading(starCorrect, closeStarCorrect, resultCorrect.heading);

	/* calculation position of the vehicle from the star position */
	Point2f currentPosition = setOffset(starCorrect, heading, starPositionCorrect, cx, cy);
	printf("xc %f, yc %f \n", currentPosition.x, currentPosition.y);
	printf("heading %f\n", heading);
	return currentPosition;
}

Point2f Triangle::buildTriangleAreaMomentAndProcess(vector<Star> starsOnImage, Mat &frame, struct DistortionParameter distParam, float area, float moment)
{
	/* find the most central stars */
	Star centralStar, centralStar2, centralStar3;
	double dist_min = DBL_MAX; 
	double dist_min2 = DBL_MAX;
	double dist_min3 = DBL_MAX;
	double distToImageCenter;
	double imageWidth = frame.cols;
	double imageHeigth = frame.rows;
	double cx = distParam.cx;
	double cy = distParam.cy;
	for(int i = 0; i < starsOnImage.size(); i++)
	{
		distToImageCenter = sqrt(pow(cx - starsOnImage[i].x, 2) + pow(cy - starsOnImage[i].y, 2));
		if(distToImageCenter < dist_min)
		{
			dist_min3 = dist_min2;
			centralStar3 = centralStar2;
			
			dist_min2 = dist_min;
			centralStar2 = centralStar;
			
			dist_min = distToImageCenter;
			centralStar = starsOnImage[i];
		}
		else if(distToImageCenter < dist_min2)
		{
			dist_min3 = dist_min2;
			centralStar3 = centralStar2;
			
			dist_min2 = distToImageCenter;
			centralStar2 = starsOnImage[i];
		}
		else if(distToImageCenter < dist_min3)
		{
			dist_min3 = distToImageCenter;
			centralStar3 = starsOnImage[i];
		}
	}
	/* draw cross for focal point on image */
	line(frame, Point2f(cx-10, cy), Point2f(cx+10, cy), Scalar(0,255,0), 0.5, 4, 0);
	line(frame, Point2f(cx, cy-10), Point2f(cx, cy+10), Scalar(0,255,0), 0.5, 4, 0);
	circle( frame, Point2f(centralStar.x, centralStar.y), 5, Scalar(255,0,0), -1, 8, 0 );

	/* init voting variables for the voting list method */
	vector<TriangleAreaMoment> matchingList;
	vector<TriangleAreaMomentVoting> votingList;
	TriangleAreaMomentVoting triangleVotingResult;

	/* init voting variables for the 3 most central stars
		--> parameter names with the ending 'correct' signals the result variable */
	TriangleAreaMoment result1, result2, result3, resultCorrect;
	Point2f starPosition1, starPosition2, starPosition3, starPositionCorrect;
	Star* closeStars;
	Star* closeStars2;
	Star* closeStars3;
	Star closeStarCorrect, starCorrect; 
	bool endResultFound = false;

	/* maximum loop if voting for the most 3 central 3 is demanded */
	int maxLoop = 1; 
	if(VOTING_AREA_MOMENT == 1) maxLoop = 3;
	for(int n = 0; n < maxLoop; n++)
	{
		if(!endResultFound)
		{
			votingList.clear();

			/* determination of the neighboring stars for every most central stars */
			if(n == 0)
			{
				closeStars = getClosestStars(starsOnImage, centralStar);
				circle( frame, Point2f(closeStars[0].x, closeStars[0].y), 5, Scalar(255,25,0), -1, 8, 0 );
				line(frame, Point2f(closeStars[0].x, closeStars[0].y), Point2f(centralStar.x, centralStar.y), Scalar(255,25,0), 1, 4, 0);
			}
			else if(n == 1)
			{
				closeStars2 = getClosestStars(starsOnImage, centralStar2);
			}
			else if(n == 2)
			{
				closeStars3 = getClosestStars(starsOnImage, centralStar3);
			}
			bool resultfound = false;
			
			/* for every most central star build max. triangle to get the result */
			for(int i = 1; i < 11; i++)
			{
				if(!resultfound)
				{	
					Star tempThird;
					double* tempAreaMoment;

					/* selecting the third star to build the triangle depending on which most central star */
					if(n == 0)
					{
						switch(i)
						{			
							case 1: tempThird = closeStars[1]; break;
							case 2: tempThird = closeStars[2]; break;
							case 3: tempThird = closeStars[3]; break;
							case 4: tempThird = closeStars[4]; break;
							case 5: tempThird = closeStars[5]; break;
							case 6: tempThird = closeStars[6]; break;
							case 7: tempThird = closeStars[7]; break;
							case 8: tempThird = closeStars[8]; break;
							case 9: tempThird = closeStars[9]; break;
							case 10: tempThird = closeStars[10]; break;
						}
						tempAreaMoment = getAreaMoment(centralStar, closeStars[0], tempThird);
					}
					if(n == 1)
					{
						switch(i)
						{			
							case 1: tempThird = closeStars2[1]; break;
							case 2: tempThird = closeStars2[2]; break;
							case 3: tempThird = closeStars2[3]; break;
							case 4: tempThird = closeStars2[4]; break;
							case 5: tempThird = closeStars2[5]; break;
							case 6: tempThird = closeStars2[6]; break;
							case 7: tempThird = closeStars2[7]; break;
							case 8: tempThird = closeStars2[8]; break;
							case 9: tempThird = closeStars2[9]; break;
							case 10: tempThird = closeStars2[10]; break;
						}
						tempAreaMoment = getAreaMoment(centralStar2, closeStars2[0], tempThird);
					}
					if(n == 2)
					{
						switch(i)
						{			
							case 1: tempThird = closeStars3[1]; break;
							case 2: tempThird = closeStars3[2]; break;
							case 3: tempThird = closeStars3[3]; break;
							case 4: tempThird = closeStars3[4]; break;
							case 5: tempThird = closeStars3[5]; break;
							case 6: tempThird = closeStars3[6]; break;
							case 7: tempThird = closeStars3[7]; break;
							case 8: tempThird = closeStars3[8]; break;
							case 9: tempThird = closeStars3[9]; break;
							case 10: tempThird = closeStars3[10]; break;
						}
						tempAreaMoment = getAreaMoment(centralStar3, closeStars3[0], tempThird);
					}

					/* contains all matches in the catalog */
					matchingList = getMatchingListAreaMoment(i, tempAreaMoment[0], tempAreaMoment[1], area, moment);

					/* draw the triangles */
					if(n == 0)
					{
						switch(i)
						{
							case 1: drawTriangle(n, closeStars[1], centralStar, frame); break;
							case 2: drawTriangle(n, closeStars[2], centralStar, frame); break;
							case 3: drawTriangle(n, closeStars[3], centralStar, frame); break;
							case 4: drawTriangle(n, closeStars[4], centralStar, frame); break;
							case 5: drawTriangle(n, closeStars[5], centralStar, frame); break;
							case 6: drawTriangle(n, closeStars[6], centralStar, frame); break;
							case 7: drawTriangle(n, closeStars[7], centralStar, frame); break;
							case 8: drawTriangle(n, closeStars[8], centralStar, frame); break;
							case 9: drawTriangle(n, closeStars[9], centralStar, frame); break;
							case 10: drawTriangle(n, closeStars[10], centralStar, frame); break;
						}
					}
					if(DRAW_ALL_TRIANGLE == 1)
					{
						if(n == 1)
						{
							switch(i)
							{
								case 1: drawTriangle(n, closeStars2[1], centralStar2, frame); break;
								case 2: drawTriangle(n, closeStars2[2], centralStar2, frame); break;
								case 3: drawTriangle(n, closeStars2[3], centralStar2, frame); break;
								case 4: drawTriangle(n, closeStars2[4], centralStar2, frame); break;
								case 5: drawTriangle(n, closeStars2[5], centralStar2, frame); break;
								case 6: drawTriangle(n, closeStars2[6], centralStar2, frame); break;
								case 7: drawTriangle(n, closeStars2[7], centralStar2, frame); break;
								case 8: drawTriangle(n, closeStars2[8], centralStar2, frame); break;
								case 9: drawTriangle(n, closeStars2[9], centralStar2, frame); break;
								case 10: drawTriangle(n, closeStars2[10], centralStar2, frame); break;
							}
						}
						if(n == 2)
						{
							switch(i)
							{
								case 1: drawTriangle(n, closeStars3[1], centralStar3, frame); break;
								case 2: drawTriangle(n, closeStars3[2], centralStar3, frame); break;
								case 3: drawTriangle(n, closeStars3[3], centralStar3, frame); break;
								case 4: drawTriangle(n, closeStars3[4], centralStar3, frame); break;
								case 5: drawTriangle(n, closeStars3[5], centralStar3, frame); break;
								case 6: drawTriangle(n, closeStars3[6], centralStar3, frame); break;
								case 7: drawTriangle(n, closeStars3[7], centralStar3, frame); break;
								case 8: drawTriangle(n, closeStars3[8], centralStar3, frame); break;
								case 9: drawTriangle(n, closeStars3[9], centralStar3, frame); break;
								case 10: drawTriangle(n, closeStars3[10], centralStar3, frame); break;
							}
						}
					}

					/* fill up matching list voting */
					double areaMatchingList, momentMatchingList;
					for(int k = 0; k < matchingList.size(); k++)
					{
						bool found = false;
						switch(i)
						{
							case 1: areaMatchingList =  matchingList[k].t1_area;
									momentMatchingList = matchingList[k].t1_moment;
									break;
							case 2: areaMatchingList =  matchingList[k].t2_area;
									momentMatchingList = matchingList[k].t2_moment;
									break;
							case 3: areaMatchingList =  matchingList[k].t3_area;
									momentMatchingList = matchingList[k].t3_moment;
									break;
							case 4: areaMatchingList =  matchingList[k].t4_area;
									momentMatchingList = matchingList[k].t4_moment;
									break;
							case 5: areaMatchingList =  matchingList[k].t5_area;
									momentMatchingList = matchingList[k].t5_moment;
									break;
							case 6: areaMatchingList =  matchingList[k].t6_area;
									momentMatchingList = matchingList[k].t6_moment;
									break;
							case 7: areaMatchingList =  matchingList[k].t7_area;
									momentMatchingList = matchingList[k].t7_moment;
									break;
							case 8: areaMatchingList =  matchingList[k].t8_area;
									momentMatchingList = matchingList[k].t8_moment;
									break;
							case 9: areaMatchingList =  matchingList[k].t9_area;
									momentMatchingList = matchingList[k].t9_moment;
									break;
							case 10: areaMatchingList =  matchingList[k].t10_area;
									momentMatchingList = matchingList[k].t10_moment;
									break; 
						}
						for(vector<TriangleAreaMomentVoting>::iterator it = votingList.begin(); it != votingList.end(); ++it)
						{
							if((*it).tam.id1 == matchingList[k].id1)
							{
								//update
								found = true;
								it->voting += getVoting(tempAreaMoment[0], tempAreaMoment[1], areaMatchingList, momentMatchingList);
								it->matching += 1;
							}
						}
						if(!found)
						{
							TriangleAreaMomentVoting tv;
							tv.tam	= matchingList[k];
							tv.voting = getVoting(tempAreaMoment[0], tempAreaMoment[1], areaMatchingList, momentMatchingList); 
							tv.matching = 1;
							votingList.push_back(tv);
						}
					}	
	
					/* do matching list voting 
						look for best match (stand alone highest match count)
						there should be only one constellation match
						if not, the triangle constellation is dynamically extended by one more triangle */	
					if(i >= 3)
					{
						vector<TriangleAreaMomentVoting> tempList;
						for(int matchCount = i; matchCount > 0; matchCount--)
						{
							for(vector<TriangleAreaMomentVoting>::iterator it = votingList.begin(); it != votingList.end(); ++it)
							{
								if(it->matching == matchCount)
								{
									tempList.push_back(*it);
								}
							}

								if(tempList.size() == 1)
								{
									//best match found;
									triangleVotingResult = tempList[0];
									resultfound = true;
									break;	
								}
								if(i == 10 && tempList.size() != 0)
								{
									double smallest = DBL_MAX;
									for(vector<TriangleAreaMomentVoting>::iterator it = tempList.begin(); it !=tempList.end(); ++it)
									{
										if(it->voting < smallest)
										{
											smallest = it->voting;
										}
									}
									for(vector<TriangleAreaMomentVoting>::iterator it = tempList.begin(); it != tempList.end(); ++it)
									{
										if(it->voting == smallest)
										{
											triangleVotingResult = *it;
										}
									}
								}
							
						}
					}
				}
			}
			switch(n)
			{
				case 0: result1 = triangleVotingResult.tam; 
					starPosition1.x = stars[result1.id1].x;
					starPosition1.y = stars[result1.id1].y;
					break;
				case 1: result2 = triangleVotingResult.tam; 
					starPosition2.x = stars[result2.id1].x;
					starPosition2.y = stars[result2.id1].y;
					break;
				case 2: result3 = triangleVotingResult.tam; 
					starPosition3.x = stars[result3.id1].x;
					starPosition3.y = stars[result3.id1].y;
					break;
			}
			/* voting most central stars 
				--> only 2 most central stars (low cost)*/
			if(VOTING_AREA_MOMENT == 1)
			{
				if(n == 1)
				{
					printf("s1 %f %f, s2 %f %f\n", starPosition1.x,starPosition1.y,starPosition2.x,starPosition2.y);
					double distOnImage = sqrt(pow(centralStar.x-centralStar2.x,2) + pow(centralStar.y-centralStar2.y,2)) * PIXELTOMM;
					double distCalculated = sqrt(pow(starPosition1.x-starPosition2.x,2) + pow(starPosition1.y-starPosition2.y,2));
					if(distCalculated < distOnImage + 30)
					{
						starPositionCorrect = starPosition1;
						closeStarCorrect = closeStars[0];
						resultCorrect = result1;
						starCorrect = centralStar;
						endResultFound = true;
					}
				}
			}
		}
	}

	/* voting most central stars 
		--> all 3 most central stars (if not possible with 2)*/
	if(VOTING_AREA_MOMENT == 1)
	{
		if(!endResultFound)
		{	
			printf("s1 %f %f, s2 %f %f\n", starPosition1.x,starPosition1.y,starPosition2.x,starPosition2.y);
			printf("s3 %f %f\n", starPosition3.x,starPosition3.y);
			double distOnImage13 = sqrt(pow(centralStar.x-centralStar3.x,2) + pow(centralStar.y-centralStar3.y,2)) * PIXELTOMM;
			double distCalculated13 = sqrt(pow(starPosition1.x-starPosition3.x,2) + pow(starPosition1.y-starPosition3.y,2));
			double distOnImage23 = sqrt(pow(centralStar2.x-centralStar3.x,2) + pow(centralStar2.y-centralStar3.y,2)) * PIXELTOMM;
			double distCalculated23 = sqrt(pow(starPosition2.x-starPosition3.x,2) + pow(starPosition2.y-starPosition3.y,2));
			if(distCalculated13 < distOnImage13 + 30) //3cm deviation
			{
				starPositionCorrect = starPosition1;
				closeStarCorrect = closeStars[0];
				resultCorrect = result1;
				starCorrect = centralStar;
			}
			else if(distCalculated23 < distOnImage23 + 30) //3cm deviation
			{
				starPositionCorrect = starPosition2;
				closeStarCorrect = closeStars2[0];
				resultCorrect = result2;
				starCorrect = centralStar2;
			}
			else
			{
				//assume first central star to be true
				starPositionCorrect = starPosition1;
				closeStarCorrect = closeStars[0];
				resultCorrect = result1;
				starCorrect = centralStar;
			}
		}
	}
	/* if only one most central star */	
	else
	{
		starPositionCorrect = starPosition1;
		closeStarCorrect = closeStars[0];
		resultCorrect = result1;
		starCorrect = centralStar;
	}
	printf("done--->");
	printf("%d\n", resultCorrect.id1);
	printf("xs %f, ys %f \n", stars[resultCorrect.id1].x, stars[resultCorrect.id1].y);
	printf("close  x%f, s %f \n", closeStarCorrect.x, closeStarCorrect.y);
	printf("heading catalog %f\n", resultCorrect.heading);

	/* calculation of camera heading */
	calcHeading(starCorrect, closeStarCorrect, resultCorrect.heading);

	/* calculation position of the vehicle from the star position */
	Point2f currentPosition = setOffset(starCorrect, heading, starPositionCorrect, cx, cy);
	printf("xc %f, yc %f \n", currentPosition.x, currentPosition.y);
	printf("heading %f\n", heading);
	return currentPosition;
}

Point2f Triangle::buildTrianglePlanarAngleAndProcess(vector<Star> starsOnImage, Mat &frame, struct DistortionParameter distParam, float angle)
{
	/* find the most central stars */
	Star centralStar, centralStar2, centralStar3;
	double dist_min = DBL_MAX;
	double dist_min2 = DBL_MAX;
	double dist_min3 = DBL_MAX; 
	double distToImageCenter;
	double imageWidth = frame.cols;
	double imageHeigth = frame.rows;
	double cx = distParam.cx;
	double cy = distParam.cy;
	for(int i = 0; i < starsOnImage.size(); i++)
	{
		distToImageCenter = sqrt(pow(cx - starsOnImage[i].x, 2) + pow(cy - starsOnImage[i].y, 2));
		if(distToImageCenter < dist_min)
		{
			dist_min3 = dist_min2;
			centralStar3 = centralStar2;
			
			dist_min2 = dist_min;
			centralStar2 = centralStar;
			
			dist_min = distToImageCenter;
			centralStar = starsOnImage[i];
		}
		else if(distToImageCenter < dist_min2)
		{
			dist_min3 = dist_min2;
			centralStar3 = centralStar2;
			
			dist_min2 = distToImageCenter;
			centralStar2 = starsOnImage[i];
		}
		else if(distToImageCenter < dist_min3)
		{
			dist_min3 = distToImageCenter;
			centralStar3 = starsOnImage[i];
		}
	}
	/* draw cross for focal point on image */
	line(frame, Point2f(cx-10, cy), Point2f(cx+10, cy), Scalar(0,255,0), 0.5, 4, 0);
	line(frame, Point2f(cx, cy-10), Point2f(cx, cy+10), Scalar(0,255,0), 0.5, 4, 0);
	circle( frame, Point2f(centralStar.x, centralStar.y), 5, Scalar(255,0,0), -1, 8, 0 );

	/* init voting variables for the voting list method */
	vector<TrianglePlanarAngle> matchingList;
	vector<TrianglePlanarAngleVoting> votingList;
	TrianglePlanarAngleVoting triangleVotingResult;

	/* init voting variables for the 3 most central stars
		--> parameter names with the ending 'correct' signals the result variable */
	TrianglePlanarAngle result1, result2, result3, resultCorrect;
	Point2f starPosition1, starPosition2, starPosition3, starPositionCorrect;
	Star* closeStars;
	Star* closeStars2;
	Star* closeStars3;
	Star closeStarCorrect, starCorrect; 
	bool endResultFound = false;

	/* maximum loop if voting for the most 3 central 3 is demanded */
	int maxLoop = 1; 
	if(VOTING_PLANAR_ANGLE == 1) maxLoop = 3;
	for(int n = 0; n < maxLoop; n++)
	{

		if(!endResultFound)
		{
			votingList.clear();

			/* determination of the neighboring stars for every most central stars */
			if(n == 0)
			{
				closeStars = getClosestStars(starsOnImage, centralStar);
				circle( frame, Point2f(closeStars[0].x, closeStars[0].y), 5, Scalar(255,25,0), -1, 8, 0 );
				line(frame, Point2f(closeStars[0].x, closeStars[0].y), Point2f(centralStar.x, centralStar.y), Scalar(255,25,0), 1, 4, 0);
			}
			else if(n == 1)
			{
				closeStars2 = getClosestStars(starsOnImage, centralStar2);
			}
			else if(n == 2)
			{
				closeStars3 = getClosestStars(starsOnImage, centralStar3);
			}
			bool resultfound = false;
			for(int i = 1; i < 11; i++)
			{
				if(!resultfound)
				{	
					Star tempThird;
					double* tempPlanarAngle;

					/* selecting the third star to build the triangle depending on which most central star */
					if(n == 0)
					{
						switch(i)
						{			
							case 1: tempThird = closeStars[1]; break;
							case 2: tempThird = closeStars[2]; break;
							case 3: tempThird = closeStars[3]; break;
							case 4: tempThird = closeStars[4]; break;
							case 5: tempThird = closeStars[5]; break;
							case 6: tempThird = closeStars[6]; break;
							case 7: tempThird = closeStars[7]; break;
							case 8: tempThird = closeStars[8]; break;
							case 9: tempThird = closeStars[9]; break;
							case 10: tempThird = closeStars[10]; break;
						}
						tempPlanarAngle = getPlanarAngle(centralStar, closeStars[0], tempThird);
					}
					if(n == 1)
					{
						switch(i)
						{			
							case 1: tempThird = closeStars2[1]; break;
							case 2: tempThird = closeStars2[2]; break;
							case 3: tempThird = closeStars2[3]; break;
							case 4: tempThird = closeStars2[4]; break;
							case 5: tempThird = closeStars2[5]; break;
							case 6: tempThird = closeStars2[6]; break;
							case 7: tempThird = closeStars2[7]; break;
							case 8: tempThird = closeStars2[8]; break;
							case 9: tempThird = closeStars2[9]; break;
							case 10: tempThird = closeStars2[10]; break;
						}
						tempPlanarAngle = getPlanarAngle(centralStar2, closeStars2[0], tempThird);
					}
					if(n == 2)
					{
						switch(i)
						{			
							case 1: tempThird = closeStars3[1]; break;
							case 2: tempThird = closeStars3[2]; break;
							case 3: tempThird = closeStars3[3]; break;
							case 4: tempThird = closeStars3[4]; break;
							case 5: tempThird = closeStars3[5]; break;
							case 6: tempThird = closeStars3[6]; break;
							case 7: tempThird = closeStars3[7]; break;
							case 8: tempThird = closeStars3[8]; break;
							case 9: tempThird = closeStars3[9]; break;
							case 10: tempThird = closeStars3[10]; break;
						}
						tempPlanarAngle = getPlanarAngle(centralStar3, closeStars3[0], tempThird);
					}

					/* contains all matches in the catalog */
					matchingList = getMatchingListPlanarAngle(i, tempPlanarAngle[0], tempPlanarAngle[1], tempPlanarAngle[2], angle);

					/* draw the triangles */
					if(n == 0)
					{
						switch(i)
						{
							case 1: drawTriangle(n, closeStars[1], centralStar, frame); break;
							case 2: drawTriangle(n, closeStars[2], centralStar, frame); break;
							case 3: drawTriangle(n, closeStars[3], centralStar, frame); break;
							case 4: drawTriangle(n, closeStars[4], centralStar, frame); break;
							case 5: drawTriangle(n, closeStars[5], centralStar, frame); break;
							case 6: drawTriangle(n, closeStars[6], centralStar, frame); break;
							case 7: drawTriangle(n, closeStars[7], centralStar, frame); break;
							case 8: drawTriangle(n, closeStars[8], centralStar, frame); break;
							case 9: drawTriangle(n, closeStars[9], centralStar, frame); break;
							case 10: drawTriangle(n, closeStars[10], centralStar, frame); break;
						}
					}
					if(DRAW_ALL_TRIANGLE == 1)
					{
						if(n == 1)
						{
							switch(i)
							{
								case 1: drawTriangle(n, closeStars2[1], centralStar2, frame); break;
								case 2: drawTriangle(n, closeStars2[2], centralStar2, frame); break;
								case 3: drawTriangle(n, closeStars2[3], centralStar2, frame); break;
								case 4: drawTriangle(n, closeStars2[4], centralStar2, frame); break;
								case 5: drawTriangle(n, closeStars2[5], centralStar2, frame); break;
								case 6: drawTriangle(n, closeStars2[6], centralStar2, frame); break;
								case 7: drawTriangle(n, closeStars2[7], centralStar2, frame); break;
								case 8: drawTriangle(n, closeStars2[8], centralStar2, frame); break;
								case 9: drawTriangle(n, closeStars2[9], centralStar2, frame); break;
								case 10: drawTriangle(n, closeStars2[10], centralStar2, frame); break;
							}
						}
						if(n == 2)
						{
							switch(i)
							{
								case 1: drawTriangle(n, closeStars3[1], centralStar3, frame); break;
								case 2: drawTriangle(n, closeStars3[2], centralStar3, frame); break;
								case 3: drawTriangle(n, closeStars3[3], centralStar3, frame); break;
								case 4: drawTriangle(n, closeStars3[4], centralStar3, frame); break;
								case 5: drawTriangle(n, closeStars3[5], centralStar3, frame); break;
								case 6: drawTriangle(n, closeStars3[6], centralStar3, frame); break;
								case 7: drawTriangle(n, closeStars3[7], centralStar3, frame); break;
								case 8: drawTriangle(n, closeStars3[8], centralStar3, frame); break;
								case 9: drawTriangle(n, closeStars3[9], centralStar3, frame); break;
								case 10: drawTriangle(n, closeStars3[10], centralStar3, frame); break;
							}
						}
					}

					/* fill up matching list voting */
					double alphaMatchingList, betaMatchingList, gammaMatchingList;
					for(int k = 0; k < matchingList.size(); k++)
					{
						bool found = false;
						switch(i)
						{
							case 1: alphaMatchingList =  matchingList[k].t1_alpha;
									betaMatchingList = matchingList[k].t1_beta;
									gammaMatchingList = matchingList[k].t1_gamma;
									break;
							case 2: alphaMatchingList =  matchingList[k].t2_alpha;
									betaMatchingList = matchingList[k].t2_beta;
									gammaMatchingList = matchingList[k].t2_gamma;
									break;
							case 3: alphaMatchingList =  matchingList[k].t3_alpha;
									betaMatchingList = matchingList[k].t3_beta;
									gammaMatchingList = matchingList[k].t3_gamma;
									break;
							case 4: alphaMatchingList =  matchingList[k].t4_alpha;
									betaMatchingList = matchingList[k].t4_beta;
									gammaMatchingList = matchingList[k].t4_gamma;
									break;
							case 5: alphaMatchingList =  matchingList[k].t5_alpha;
									betaMatchingList = matchingList[k].t5_beta;
									gammaMatchingList = matchingList[k].t5_gamma;
									break;
							case 6: alphaMatchingList =  matchingList[k].t6_alpha;
									betaMatchingList = matchingList[k].t6_beta;
									gammaMatchingList = matchingList[k].t6_gamma;
									break;
							case 7: alphaMatchingList =  matchingList[k].t7_alpha;
									betaMatchingList = matchingList[k].t7_beta;
									gammaMatchingList = matchingList[k].t7_gamma;
									break;
							case 8: alphaMatchingList =  matchingList[k].t8_alpha;
									betaMatchingList = matchingList[k].t8_beta;
									gammaMatchingList = matchingList[k].t8_gamma;
									break;
							case 9: alphaMatchingList =  matchingList[k].t9_alpha;
									betaMatchingList = matchingList[k].t9_beta;
									gammaMatchingList = matchingList[k].t9_gamma;
									break;
							case 10: alphaMatchingList =  matchingList[k].t10_alpha;
									betaMatchingList = matchingList[k].t10_beta;
									gammaMatchingList = matchingList[k].t10_gamma;;
									break; 
						}
						for(vector<TrianglePlanarAngleVoting>::iterator it = votingList.begin(); it != votingList.end(); ++it)
						{
							if((*it).trianglePlanarAngle.id1 == matchingList[k].id1)
							{
								//update
								found = true;
								it->voting += getVoting(tempPlanarAngle[0], tempPlanarAngle[1], tempPlanarAngle[2], alphaMatchingList, betaMatchingList, gammaMatchingList);
								it->matching += 1;
							}
						}
						if(!found)
						{
							TrianglePlanarAngleVoting tv;
							tv.trianglePlanarAngle	= matchingList[k];
							tv.voting = getVoting(tempPlanarAngle[0], tempPlanarAngle[1], tempPlanarAngle[2], alphaMatchingList, betaMatchingList, gammaMatchingList); 
							tv.matching = 1;
							votingList.push_back(tv);
						}
					}	
					
					/* do matching list voting 
						look for best match (stand alone highest match count)
						there should be only one constellation match
						if not, the triangle constellation is dynamically extended by one more triangle */						
					if(i >= 3)//minimum 3 triangleLiebe
					{
						vector<TrianglePlanarAngleVoting> tempList;
						for(int matchCount = i; matchCount > 0; matchCount--)
						{
							for(vector<TrianglePlanarAngleVoting>::iterator it = votingList.begin(); it != votingList.end(); ++it)
							{
								if(it->matching == matchCount)
								{
									tempList.push_back(*it);
								}
							}


								if(tempList.size() == 1)
								{
									//best match found;
									triangleVotingResult = tempList[0];
									resultfound = true;
									break;	
	
								}
								if(i == 10 && tempList.size() != 0)
								{
									double smallest = DBL_MAX;
									for(vector<TrianglePlanarAngleVoting>::iterator it = tempList.begin(); it !=tempList.end(); ++it)
									{
										if(it->voting < smallest)
										{
											smallest = it->voting;
										}
									}
									for(vector<TrianglePlanarAngleVoting>::iterator it = tempList.begin(); it != tempList.end(); ++it)
									{
										if(it->voting == smallest)
										{
											triangleVotingResult = *it;
										}
									}
								}
							
						}
					}			
				}
			}
			switch(n)
			{
				case 0: result1 = triangleVotingResult.trianglePlanarAngle; 
					starPosition1.x = stars[result1.id1].x;
					starPosition1.y = stars[result1.id1].y;
					break;
				case 1: result2 = triangleVotingResult.trianglePlanarAngle; 
					starPosition2.x = stars[result2.id1].x;
					starPosition2.y = stars[result2.id1].y;
					break;
				case 2: result3 = triangleVotingResult.trianglePlanarAngle; 
					starPosition3.x = stars[result3.id1].x;
					starPosition3.y = stars[result3.id1].y;
					break;
			}
			/* voting most central stars 
				--> only 2 most central stars (low cost)*/
			if(VOTING_PLANAR_ANGLE == 1)
			{
				if(n == 1)
				{
					printf("s1 %f %f, s2 %f %f\n", starPosition1.x,starPosition1.y,starPosition2.x,starPosition2.y);
					double distOnImage = sqrt(pow(centralStar.x-centralStar2.x,2) + pow(centralStar.y-centralStar2.y,2)) * PIXELTOMM;
					double distCalculated = sqrt(pow(starPosition1.x-starPosition2.x,2) + pow(starPosition1.y-starPosition2.y,2));
					if(distCalculated < distOnImage + 30)
					{
						starPositionCorrect = starPosition1;
						closeStarCorrect = closeStars[0];
						resultCorrect = result1;
						starCorrect = centralStar;
						endResultFound = true;	
					}
				}
			}
		}
	}	
	/* voting most central stars 
		--> all 3 most central stars (if not possible with 2)*/
	if(VOTING_PLANAR_ANGLE == 1)
	{
		if(!endResultFound)
		{	
			printf("s1 %f %f, s2 %f %f\n", starPosition1.x,starPosition1.y,starPosition2.x,starPosition2.y);
			printf("s3 %f %f\n", starPosition3.x,starPosition3.y);
			double distOnImage13 = sqrt(pow(centralStar.x-centralStar3.x,2) + pow(centralStar.y-centralStar3.y,2)) * PIXELTOMM;
			double distCalculated13 = sqrt(pow(starPosition1.x-starPosition3.x,2) + pow(starPosition1.y-starPosition3.y,2));
			double distOnImage23 = sqrt(pow(centralStar2.x-centralStar3.x,2) + pow(centralStar2.y-centralStar3.y,2)) * PIXELTOMM;
			double distCalculated23 = sqrt(pow(starPosition2.x-starPosition3.x,2) + pow(starPosition2.y-starPosition3.y,2));
			if(distCalculated13 < distOnImage13 + 30) //3cm deviation
			{
				starPositionCorrect = starPosition1;
				closeStarCorrect = closeStars[0];
				resultCorrect = result1;
				starCorrect = centralStar;
			}
			else if(distCalculated23 < distOnImage23 + 30) //3cm deviation
			{
				starPositionCorrect = starPosition2;
				closeStarCorrect = closeStars2[0];
				resultCorrect = result2;
				starCorrect = centralStar2;
			}
			else
			{
				//assume first central star to be true
				starPositionCorrect = starPosition1;
				closeStarCorrect = closeStars[0];
				resultCorrect = result1;
				starCorrect = centralStar;
			}
		}
	}
	/* if only one most central star */	
	else
	{
		starPositionCorrect = starPosition1;
		closeStarCorrect = closeStars[0];
		resultCorrect = result1;
		starCorrect = centralStar;
	}	
	printf("done--->");
	printf("%d\n", resultCorrect.id1);
	printf("xs %f, ys %f \n", stars[resultCorrect.id1].x, stars[resultCorrect.id1].y);
	printf("close  x%f, s %f \n", closeStarCorrect.x, closeStarCorrect.y);
	printf("heading catalog %f\n", resultCorrect.heading);

	/* calculation of camera heading */
	calcHeading(starCorrect, closeStarCorrect, resultCorrect.heading);

	/* calculation position of the vehicle from the star position */
	Point2f currentPosition = setOffset(starCorrect, heading, starPositionCorrect, cx, cy);
	printf("xc %f, yc %f \n", currentPosition.x, currentPosition.y);
	printf("heading %f\n", heading);
	return currentPosition;
}

Point2f Triangle::setOffset(Star centralCorrect, float headingCam, Point2f starPos, double cx, double cy)
{

	/* calculation position of the vehicle form the star position */
	double offsetLength_cam = (( centralCorrect.y - cy) * (-1)) * PIXELTOMM; //y-coordinate in opencv stars from top, platform from below, therefore -1 to swip axis
	double offsetWide_cam = (centralCorrect.x - cx) * PIXELTOMM;
	double offsetX_vehicle = OFFSET_VEHICLE_CAM + offsetLength_cam;
	double offsetY_vehicle = offsetWide_cam;
	double offsetXY_vehicle = sqrt(offsetX_vehicle*offsetX_vehicle + offsetY_vehicle*offsetY_vehicle);
	double alphaOff = asin(abs(offsetY_vehicle) / offsetXY_vehicle) * RADtoDEG;
	Point2f pos;
	if(headingCam >=0 && headingCam < 90)
	{
		double newAngle;
		if(offsetY_vehicle < 0) newAngle = (90-headingCam) + alphaOff;
		else newAngle = (90-headingCam) - alphaOff;
		double dy = abs(sin((newAngle)*DEGtoRAD) * offsetXY_vehicle);
		double dx = abs(cos((newAngle)*DEGtoRAD) * offsetXY_vehicle);
		pos.x = starPos.x - dx;
		pos.y = starPos.y - dy; 
	}
	if(headingCam >=90 && headingCam < 180)
	{
		double newAngle;
		if(offsetY_vehicle < 0) newAngle = (180-headingCam) + alphaOff;
		else newAngle = (180-headingCam) - alphaOff;
		double dx = abs(sin((newAngle)*DEGtoRAD) * offsetXY_vehicle);
		double dy = abs(cos((newAngle)*DEGtoRAD) * offsetXY_vehicle);
		pos.x = starPos.x - dx;
		pos.y = starPos.y + dy; 
	}
	if(headingCam >=180 && headingCam < 270)
	{
		double newAngle;
		if(offsetY_vehicle < 0) newAngle = (270-headingCam) + alphaOff;
		else newAngle = (270-headingCam) - alphaOff;
		double dy = abs(sin((newAngle)*DEGtoRAD) * offsetXY_vehicle);
		double dx = abs(cos((newAngle)*DEGtoRAD) * offsetXY_vehicle);
		pos.x = starPos.x + dx;
		pos.y = starPos.y + dy; 
	}
	if(headingCam >=270 && headingCam < 360)
	{
		double newAngle;
		if(offsetY_vehicle < 0) newAngle = (360-headingCam) + alphaOff;
		else newAngle = (360-headingCam) - alphaOff;
		double dx = abs(sin((newAngle)*DEGtoRAD) * offsetXY_vehicle);
		double dy = abs(cos((newAngle)*DEGtoRAD) * offsetXY_vehicle);
		pos.x = starPos.x + dx;
		pos.y = starPos.y - dy; 
	}
	return pos;
}

void Triangle::drawTriangle(int n, Star centralStar, Star closeStar, Mat &frame)
{
	Scalar color;
	switch(n)
	{
		case 0: color = Scalar(255,0,0); break;
		case 1: color = Scalar(0,255,255); break;
		case 2: color = Scalar(0,0,255); break;
	}
	circle(frame, Point2f(closeStar.x, closeStar.y), 5, color, -1, 8, 0);
	line(frame, Point2f(closeStar.x, closeStar.y), Point2f(centralStar.x, centralStar.y), color, 1, 4, 0);
}

double Triangle::getVoting(double t1_a, double t1_b, double t2_a, double t2_b)
{
	return sqrt(pow(t1_a - t2_a, 2) + pow(t1_b - t2_b, 2));
}

double Triangle::getVoting(double t1_a, double t1_b, double t1_c, double t2_a, double t2_b, double t2_c)
{
	return sqrt(pow(t1_a - t2_a, 2) + pow(t1_b - t2_b, 2) + pow(t1_c - t2_c, 2));
}



Star* Triangle::getClosestStars(vector<Star> starsOnImage, Star centralStar)
{
	Star* closestStars = new Star[11];
	Star star1, star2, star3, star4, star5, star6, star7, star8, star9, star10, star11;
	double dist;
	double smallestDist1 = DBL_MAX;
	double smallestDist2 = DBL_MAX;
	double smallestDist3 = DBL_MAX;
	double smallestDist4 = DBL_MAX;
	double smallestDist5 = DBL_MAX;
	double smallestDist6 = DBL_MAX;
	double smallestDist7 = DBL_MAX;
	double smallestDist8 = DBL_MAX;
	double smallestDist9 = DBL_MAX;
	double smallestDist10 = DBL_MAX;
	double smallestDist11 = DBL_MAX;
	
	for(int k = 0; k < starsOnImage.size(); k++)
	{
		if(centralStar.id != starsOnImage[k].id)
		{
			dist = space(centralStar, starsOnImage[k]);
			if(dist < smallestDist1)
			{
				smallestDist11 = smallestDist10;
				star11 = star10;

				smallestDist10 = smallestDist9;
				star10 = star9;

				smallestDist9 = smallestDist8;
				star9 = star8;

				smallestDist8 = smallestDist7;
				star8 = star7;

				smallestDist7 = smallestDist6;
				star7 = star6;

				smallestDist6 = smallestDist5;
				star6 = star5;

				smallestDist5 = smallestDist4;
				star5 = star4;

				smallestDist4 = smallestDist3;
				star4 = star3;

				smallestDist3 = smallestDist2;
				star3 = star2;

				smallestDist2 = smallestDist1;
				star2 = star1;

				smallestDist1 = dist;					
				star1 = starsOnImage[k];
			}
			else if(dist < smallestDist2)
			{
				smallestDist11 = smallestDist10;
				star11 = star10;

				smallestDist10 = smallestDist9;
				star10 = star9;

				smallestDist9 = smallestDist8;
				star9 = star8;

				smallestDist8 = smallestDist7;
				star8 = star7;

				smallestDist7 = smallestDist6;
				star7 = star6;

				smallestDist6 = smallestDist5;
				star6 = star5;

				smallestDist5 = smallestDist4;
				star5 = star4;

				smallestDist4 = smallestDist3;
				star4 = star3;

				smallestDist3 = smallestDist2;
				star3 = star2;

				smallestDist2 = dist;
				star2 = starsOnImage[k];
			}
			else if(dist < smallestDist3)
			{
				smallestDist11 = smallestDist10;
				star11 = star10;

				smallestDist10 = smallestDist9;
				star10 = star9;

				smallestDist9 = smallestDist8;
				star9 = star8;

				smallestDist8 = smallestDist7;
				star8 = star7;

				smallestDist7 = smallestDist6;
				star7 = star6;

				smallestDist6 = smallestDist5;
				star6 = star5;

				smallestDist5 = smallestDist4;
				star5 = star4;
					
				smallestDist4 = smallestDist3;
				star4 = star3;

				smallestDist3 = dist;
				star3 = starsOnImage[k];
			}
			else if(dist < smallestDist4)
			{
				smallestDist11 = smallestDist10;
				star11 = star10;

				smallestDist10 = smallestDist9;
				star10 = star9;

				smallestDist9 = smallestDist8;
				star9 = star8;

				smallestDist8 = smallestDist7;
				star8 = star7;

				smallestDist7 = smallestDist6;
				star7 = star6;

				smallestDist6 = smallestDist5;
				star6 = star5;

				smallestDist5 = smallestDist4;
				star5 = star4;

				smallestDist4 = dist;
				star4 = starsOnImage[k];
			}
			else if(dist < smallestDist5)
			{
				smallestDist11 = smallestDist10;
				star11 = star10;

				smallestDist10 = smallestDist9;
				star10 = star9;

				smallestDist9 = smallestDist8;
				star9 = star8;

				smallestDist8 = smallestDist7;
				star8 = star7;

				smallestDist7 = smallestDist6;
				star7 = star6;

				smallestDist6 = smallestDist5;
				star6 = star5;

				smallestDist5 = dist;
				star5 = starsOnImage[k];
			}
			else if(dist < smallestDist6)
			{
				smallestDist11 = smallestDist10;
				star11 = star10;

				smallestDist10 = smallestDist9;
				star10 = star9;

				smallestDist9 = smallestDist8;
				star9 = star8;

				smallestDist8 = smallestDist7;
				star8 = star7;

				smallestDist7 = smallestDist6;
				star7 = star6;

				smallestDist6 = dist;
				star6 = starsOnImage[k];
			}
			else if(dist < smallestDist7)
			{
				smallestDist11 = smallestDist10;
				star11 = star10;

				smallestDist10 = smallestDist9;
				star10 = star9;

				smallestDist9 = smallestDist8;
				star9 = star8;

				smallestDist8 = smallestDist7;
				star8 = star7;

				smallestDist7 = dist;
				star7 = starsOnImage[k];
			}
			else if(dist < smallestDist8)
			{
				smallestDist11 = smallestDist10;
				star11 = star10;

				smallestDist10 = smallestDist9;
				star10 = star9;

				smallestDist9 = smallestDist8;
				star9 = star8;

				smallestDist8 = dist;
				star8 = starsOnImage[k];
			}
			else if(dist < smallestDist9)
			{
				smallestDist11 = smallestDist10;
				star11 = star10;

				smallestDist10 = smallestDist9;
				star10 = star9;

				smallestDist9 = dist;
				star9 = starsOnImage[k];
			}
			else if(dist < smallestDist10)
			{
				smallestDist11 = smallestDist10;
				star11 = star10;

				smallestDist10 = dist;
				star10 = starsOnImage[k];
			}
			else if(dist < smallestDist11)
			{
				smallestDist11 = dist;
				star11 = starsOnImage[k];
			}
		}
	}
	closestStars[0] = star1;
	closestStars[1] = star2;
	closestStars[2] = star3;
	closestStars[3] = star4;
	closestStars[4] = star5;
	closestStars[5] = star6;
	closestStars[6] = star7;
	closestStars[7] = star8;
	closestStars[8] = star9;
	closestStars[9] = star10;
	closestStars[10] = star11;
	return closestStars;
}

double* Triangle::getAlphaBeta(Star center, Star fix, Star third, double f)
{
	double* temp = new double[3];
	vec3d vecCenter = getVec3d(center, f);
	vec3d vecStar1 = getVec3d(fix, f);
	vec3d vecStar2 = getVec3d(third, f);
	double alpha1 = angle(vecCenter, vecStar1) * RADtoDEG;
	double alpha2 = angle(vecCenter, vecStar2) * RADtoDEG;
	vec3d vecS1C = getVecDiff(vecStar1, vecCenter);
	vec3d vecS2C = getVecDiff(vecStar2, vecCenter);
	double beta = angle(vecS1C, vecS2C) * RADtoDEG;
	temp[0] = alpha1;
	temp[1] = alpha2;
	temp[2] = beta;
	return temp;
}

vector<TriangleLiebe> Triangle::getMatchingListAlphaBeta(int num, double calculatedAlpha1, double calculatedAlpha2, double calculatedBeta, double scaleMin, double scaleMax, double betaPercentage)
{
	vector<TriangleLiebe> matchingList;
	switch(num)
	{
		case 1:
				for(int i = 0; i < trianglesLiebe.size(); i++)
				{
					if(trianglesLiebe[i].alpha1 < (calculatedAlpha1/scaleMin) && trianglesLiebe[i].alpha1 > (calculatedAlpha1/scaleMax))
					{
						if(trianglesLiebe[i].t1_alpha2 < (calculatedAlpha2/scaleMin) && trianglesLiebe[i].t1_alpha2 > (calculatedAlpha2/scaleMax))
						{
							if(trianglesLiebe[i].t1_beta < (calculatedBeta + betaPercentage) && trianglesLiebe[i].t1_beta > (calculatedBeta - betaPercentage))
							{
								matchingList.push_back(trianglesLiebe[i]);
							}
						}
					}
				}
				break;
		case 2:
				for(int i = 0; i < trianglesLiebe.size(); i++)
				{
					if(trianglesLiebe[i].alpha1 < (calculatedAlpha1/scaleMin) && trianglesLiebe[i].alpha1 > (calculatedAlpha1/scaleMax))
					{
						if(trianglesLiebe[i].t2_alpha2 < (calculatedAlpha2/scaleMin) && trianglesLiebe[i].t2_alpha2 > (calculatedAlpha2/scaleMax))
						{
							if(trianglesLiebe[i].t2_beta < (calculatedBeta + betaPercentage) && trianglesLiebe[i].t2_beta > (calculatedBeta - (calculatedBeta * betaPercentage / 100)))
							{
								matchingList.push_back(trianglesLiebe[i]);
							}
						}
					}
				}
				break;
		case 3:
				for(int i = 0; i < trianglesLiebe.size(); i++)
				{
					if(trianglesLiebe[i].alpha1 < (calculatedAlpha1/scaleMin) && trianglesLiebe[i].alpha1 > (calculatedAlpha1/scaleMax))
					{
						if(trianglesLiebe[i].t3_alpha2 < (calculatedAlpha2/scaleMin) && trianglesLiebe[i].t3_alpha2 > (calculatedAlpha2/scaleMax))
						{
							if(trianglesLiebe[i].t3_beta < (calculatedBeta + betaPercentage) && trianglesLiebe[i].t3_beta > (calculatedBeta - betaPercentage))
							{
								matchingList.push_back(trianglesLiebe[i]);
							}
						}
					}
				}
				break;
		case 4:
				for(int i = 0; i < trianglesLiebe.size(); i++)
				{
					if(trianglesLiebe[i].alpha1 < (calculatedAlpha1/scaleMin) && trianglesLiebe[i].alpha1 > (calculatedAlpha1/scaleMax))
					{
						if(trianglesLiebe[i].t4_alpha2 < (calculatedAlpha2/scaleMin) && trianglesLiebe[i].t4_alpha2 > (calculatedAlpha2/scaleMax))
						{
							if(trianglesLiebe[i].t4_beta < (calculatedBeta + betaPercentage) && trianglesLiebe[i].t4_beta > (calculatedBeta - betaPercentage))
							{
								matchingList.push_back(trianglesLiebe[i]);
							}
						}
					}
				}
				break;
		case 5:
				for(int i = 0; i < trianglesLiebe.size(); i++)
				{
					if(trianglesLiebe[i].alpha1 < (calculatedAlpha1/scaleMin) && trianglesLiebe[i].alpha1 > (calculatedAlpha1/scaleMax))
					{
						if(trianglesLiebe[i].t5_alpha2 < (calculatedAlpha2/scaleMin) && trianglesLiebe[i].t5_alpha2 > (calculatedAlpha2/scaleMax))
						{
							if(trianglesLiebe[i].t5_beta < (calculatedBeta + betaPercentage) && trianglesLiebe[i].t5_beta > (calculatedBeta - betaPercentage))
							{
								matchingList.push_back(trianglesLiebe[i]);
							}
						}
					}
				}
				break;
		case 6:
				for(int i = 0; i < trianglesLiebe.size(); i++)
				{
					if(trianglesLiebe[i].alpha1 < (calculatedAlpha1/scaleMin) && trianglesLiebe[i].alpha1 > (calculatedAlpha1/scaleMax))
					{
						if(trianglesLiebe[i].t6_alpha2 < (calculatedAlpha2/scaleMin) && trianglesLiebe[i].t6_alpha2 > (calculatedAlpha2/scaleMax))
						{
							if(trianglesLiebe[i].t6_beta < (calculatedBeta + betaPercentage) && trianglesLiebe[i].t6_beta > (calculatedBeta - betaPercentage))
							{
								matchingList.push_back(trianglesLiebe[i]);
							}
						}
					}
				}
				break;
		case 7:
				for(int i = 0; i < trianglesLiebe.size(); i++)
				{
					if(trianglesLiebe[i].alpha1 < (calculatedAlpha1/scaleMin) && trianglesLiebe[i].alpha1 > (calculatedAlpha1/scaleMax))
					{
						if(trianglesLiebe[i].t7_alpha2 < (calculatedAlpha2/scaleMin) && trianglesLiebe[i].t7_alpha2 > (calculatedAlpha2/scaleMax))
						{
							if(trianglesLiebe[i].t7_beta < (calculatedBeta + betaPercentage) && trianglesLiebe[i].t7_beta > (calculatedBeta - betaPercentage))
							{
								matchingList.push_back(trianglesLiebe[i]);
							}
						}
					}
				}
				break;
		case 8:
				for(int i = 0; i < trianglesLiebe.size(); i++)
				{
					if(trianglesLiebe[i].alpha1 < (calculatedAlpha1/scaleMin) && trianglesLiebe[i].alpha1 > (calculatedAlpha1/scaleMax))
					{
						if(trianglesLiebe[i].t8_alpha2 < (calculatedAlpha2/scaleMin) && trianglesLiebe[i].t8_alpha2 > (calculatedAlpha2/scaleMax))
						{
							if(trianglesLiebe[i].t8_beta < (calculatedBeta + betaPercentage) && trianglesLiebe[i].t8_beta > (calculatedBeta - betaPercentage))
							{
								matchingList.push_back(trianglesLiebe[i]);
							}
						}
					}
				}
				break;
		case 9:
				for(int i = 0; i < trianglesLiebe.size(); i++)
				{
					if(trianglesLiebe[i].alpha1 < (calculatedAlpha1/scaleMin) && trianglesLiebe[i].alpha1 > (calculatedAlpha1/scaleMax))
					{
						if(trianglesLiebe[i].t9_alpha2 < (calculatedAlpha2/scaleMin) && trianglesLiebe[i].t9_alpha2 > (calculatedAlpha2/scaleMax))
						{
							if(trianglesLiebe[i].t9_beta < (calculatedBeta + betaPercentage) && trianglesLiebe[i].t9_beta > (calculatedBeta - betaPercentage))
							{
								matchingList.push_back(trianglesLiebe[i]);
							}
						}
					}
				}
				break;
		case 10:
				for(int i = 0; i < trianglesLiebe.size(); i++)
				{
					if(trianglesLiebe[i].alpha1 < (calculatedAlpha1/scaleMin) && trianglesLiebe[i].alpha1 > (calculatedAlpha1/scaleMax))
					{
						if(trianglesLiebe[i].t10_alpha2 < (calculatedAlpha2/scaleMin) && trianglesLiebe[i].t10_alpha2 > (calculatedAlpha2/scaleMax))
						{
							if(trianglesLiebe[i].t10_beta < (calculatedBeta + betaPercentage) && trianglesLiebe[i].t10_beta > (calculatedBeta - betaPercentage))
							{
								matchingList.push_back(trianglesLiebe[i]);
							}
						}
					}
				}
				break;
		default: break;
	}
	return matchingList;
}


vector<TriangleAreaMoment> Triangle::getMatchingListAreaMoment(int num, double calculatedArea, double calculatedMoment, double areaPercentage, double momentPercentage)
{	
	vector<TriangleAreaMoment> matchingList;
	switch(num)
	{
		case 1: 
				for(int i = 0; i < trianglesAreaMoment.size(); i++)
				{
					if(trianglesAreaMoment[i].t1_area < (calculatedArea + (calculatedArea * areaPercentage / 100)) && trianglesAreaMoment[i].t1_area > (calculatedArea - (calculatedArea * areaPercentage / 100)))
					{
						if(trianglesAreaMoment[i].t1_moment < (calculatedMoment + (calculatedMoment * momentPercentage / 100)) && trianglesAreaMoment[i].t1_moment > (calculatedMoment - (calculatedMoment * momentPercentage / 100)))
						{
							matchingList.push_back(trianglesAreaMoment[i]);
						}
					}
				};
				break;
		case 2:
				for(int i = 0; i < trianglesAreaMoment.size(); i++)
				{
					if(trianglesAreaMoment[i].t2_area < (calculatedArea + (calculatedArea * areaPercentage / 100)) && trianglesAreaMoment[i].t2_area > (calculatedArea - (calculatedArea * areaPercentage / 100)))
					{
						if(trianglesAreaMoment[i].t2_moment < (calculatedMoment + (calculatedMoment * momentPercentage / 100)) && trianglesAreaMoment[i].t2_moment > (calculatedMoment - (calculatedMoment * momentPercentage / 100)))
						{
							matchingList.push_back(trianglesAreaMoment[i]);
						}
					}
				};
				break;
		case 3: 
				for(int i = 0; i < trianglesAreaMoment.size(); i++)
				{
					if(trianglesAreaMoment[i].t3_area < (calculatedArea + (calculatedArea * areaPercentage / 100)) && trianglesAreaMoment[i].t3_area > (calculatedArea - (calculatedArea * areaPercentage / 100)))
					{
						if(trianglesAreaMoment[i].t3_moment < (calculatedMoment + (calculatedMoment * momentPercentage / 100)) && trianglesAreaMoment[i].t3_moment > (calculatedMoment - (calculatedMoment * momentPercentage / 100)))
						{
							matchingList.push_back(trianglesAreaMoment[i]);
						}
					}
				};
				break;
		case 4:
				for(int i = 0; i < trianglesAreaMoment.size(); i++)
				{
					if(trianglesAreaMoment[i].t4_area < (calculatedArea + (calculatedArea * areaPercentage / 100)) && trianglesAreaMoment[i].t4_area > (calculatedArea - (calculatedArea * areaPercentage / 100)))
					{
						if(trianglesAreaMoment[i].t4_moment < (calculatedMoment + (calculatedMoment * momentPercentage / 100)) && trianglesAreaMoment[i].t4_moment > (calculatedMoment - (calculatedMoment * momentPercentage / 100)))
						{
							matchingList.push_back(trianglesAreaMoment[i]);
						}
					}
				};
				break;
		case 5: 
				for(int i = 0; i < trianglesAreaMoment.size(); i++)
				{
					if(trianglesAreaMoment[i].t5_area < (calculatedArea + (calculatedArea * areaPercentage / 100)) && trianglesAreaMoment[i].t5_area > (calculatedArea - (calculatedArea * areaPercentage / 100)))
					{
						if(trianglesAreaMoment[i].t5_moment < (calculatedMoment + (calculatedMoment * momentPercentage / 100)) && trianglesAreaMoment[i].t5_moment > (calculatedMoment - (calculatedMoment * momentPercentage / 100)))
						{
							matchingList.push_back(trianglesAreaMoment[i]);
						}
					}
				};
				break;
		case 6: 
				for(int i = 0; i < trianglesAreaMoment.size(); i++)
				{
					if(trianglesAreaMoment[i].t6_area < (calculatedArea + (calculatedArea * areaPercentage / 100)) && trianglesAreaMoment[i].t6_area > (calculatedArea - (calculatedArea * areaPercentage / 100)))
					{
						if(trianglesAreaMoment[i].t6_moment < (calculatedMoment + (calculatedMoment * momentPercentage / 100)) && trianglesAreaMoment[i].t6_moment > (calculatedMoment - (calculatedMoment * momentPercentage / 100)))
						{
							matchingList.push_back(trianglesAreaMoment[i]);
						}
					}
				};
				break;
		case 7:
				for(int i = 0; i < trianglesAreaMoment.size(); i++)
				{
					if(trianglesAreaMoment[i].t7_area < (calculatedArea + (calculatedArea * areaPercentage / 100)) && trianglesAreaMoment[i].t7_area > (calculatedArea - (calculatedArea * areaPercentage / 100)))
					{
						if(trianglesAreaMoment[i].t7_moment < (calculatedMoment + (calculatedMoment * momentPercentage / 100)) && trianglesAreaMoment[i].t7_moment > (calculatedMoment - (calculatedMoment * momentPercentage / 100)))
						{
							matchingList.push_back(trianglesAreaMoment[i]);
						}
					}
				};
				break;
		case 8: 
				for(int i = 0; i < trianglesAreaMoment.size(); i++)
				{
					if(trianglesAreaMoment[i].t8_area < (calculatedArea + (calculatedArea * areaPercentage / 100)) && trianglesAreaMoment[i].t8_area > (calculatedArea - (calculatedArea * areaPercentage / 100)))
					{
						if(trianglesAreaMoment[i].t8_moment < (calculatedMoment + (calculatedMoment * momentPercentage / 100)) && trianglesAreaMoment[i].t8_moment > (calculatedMoment - (calculatedMoment * momentPercentage / 100)))
						{
							matchingList.push_back(trianglesAreaMoment[i]);
						}
					}
				};
				break;
		case 9:
				for(int i = 0; i < trianglesAreaMoment.size(); i++)
				{
					if(trianglesAreaMoment[i].t9_area < (calculatedArea + (calculatedArea * areaPercentage / 100)) && trianglesAreaMoment[i].t9_area > (calculatedArea - (calculatedArea * areaPercentage / 100)))
					{
						if(trianglesAreaMoment[i].t9_moment < (calculatedMoment + (calculatedMoment * momentPercentage / 100)) && trianglesAreaMoment[i].t9_moment > (calculatedMoment - (calculatedMoment * momentPercentage / 100)))
						{
							matchingList.push_back(trianglesAreaMoment[i]);
						}
					}
				};
				break;
		case 10: 
				for(int i = 0; i < trianglesAreaMoment.size(); i++)
				{
					if(trianglesAreaMoment[i].t10_area < (calculatedArea + (calculatedArea * areaPercentage / 100)) && trianglesAreaMoment[i].t10_area > (calculatedArea - (calculatedArea * areaPercentage / 100)))
					{
						if(trianglesAreaMoment[i].t10_moment < (calculatedMoment + (calculatedMoment * momentPercentage / 100)) && trianglesAreaMoment[i].t10_moment > (calculatedMoment - (calculatedMoment * momentPercentage / 100)))
						{
							matchingList.push_back(trianglesAreaMoment[i]);
						}
					}
				};
				break;
		default: break;
	}
	return matchingList;
}

vector<TrianglePlanarAngle> Triangle::getMatchingListPlanarAngle(int num, double calculatedAlpha, double calculatedBeta, double calculatedGamma, double percentage)
{
	vector<TrianglePlanarAngle> matchingList;
	switch(num)
	{
		case 1:
				for(int i = 0; i < trianglesPlanarAngle.size(); i++)
				{
					if(trianglesPlanarAngle[i].t1_alpha < (calculatedAlpha + percentage) && trianglesPlanarAngle[i].t1_alpha > (calculatedAlpha - percentage))
					{
						if(trianglesPlanarAngle[i].t1_beta < (calculatedBeta + percentage) && trianglesPlanarAngle[i].t1_beta > (calculatedBeta - percentage))
						{
							if(trianglesPlanarAngle[i].t1_gamma < (calculatedGamma + percentage) && trianglesPlanarAngle[i].t1_gamma> (calculatedGamma - percentage))
							{
								matchingList.push_back(trianglesPlanarAngle[i]);
							}
						}
					}
				}
				break;
		case 2:
				for(int i = 0; i < trianglesPlanarAngle.size(); i++)
				{
					if(trianglesPlanarAngle[i].t2_alpha < (calculatedAlpha + percentage) && trianglesPlanarAngle[i].t2_alpha > (calculatedAlpha - percentage))
					{
						if(trianglesPlanarAngle[i].t2_beta < (calculatedBeta + percentage) && trianglesPlanarAngle[i].t2_beta > (calculatedBeta - percentage))
						{
							if(trianglesPlanarAngle[i].t2_gamma < (calculatedGamma + percentage) && trianglesPlanarAngle[i].t2_gamma> (calculatedGamma - percentage))
							{
								matchingList.push_back(trianglesPlanarAngle[i]);
							}
						}
					}
				}
				break;
		case 3:
				for(int i = 0; i < trianglesPlanarAngle.size(); i++)
				{
					if(trianglesPlanarAngle[i].t3_alpha < (calculatedAlpha + percentage) && trianglesPlanarAngle[i].t3_alpha > (calculatedAlpha - percentage))
					{
						if(trianglesPlanarAngle[i].t3_beta < (calculatedBeta + percentage) && trianglesPlanarAngle[i].t3_beta > (calculatedBeta - percentage))
						{
							if(trianglesPlanarAngle[i].t3_gamma < (calculatedGamma + percentage) && trianglesPlanarAngle[i].t3_gamma> (calculatedGamma - percentage))
							{
								matchingList.push_back(trianglesPlanarAngle[i]);
							}
						}
					}
				}
				break;
		case 4:
				for(int i = 0; i < trianglesPlanarAngle.size(); i++)
				{
					if(trianglesPlanarAngle[i].t4_alpha < (calculatedAlpha + percentage) && trianglesPlanarAngle[i].t4_alpha > (calculatedAlpha - percentage))
					{
						if(trianglesPlanarAngle[i].t4_beta < (calculatedBeta + percentage) && trianglesPlanarAngle[i].t4_beta > (calculatedBeta - percentage))
						{
							if(trianglesPlanarAngle[i].t4_gamma < (calculatedGamma + percentage) && trianglesPlanarAngle[i].t4_gamma> (calculatedGamma - percentage))
							{
								matchingList.push_back(trianglesPlanarAngle[i]);
							}
						}
					}
				}
				break;
		case 5:
				for(int i = 0; i < trianglesPlanarAngle.size(); i++)
				{
					if(trianglesPlanarAngle[i].t5_alpha < (calculatedAlpha + percentage) && trianglesPlanarAngle[i].t5_alpha > (calculatedAlpha - percentage))
					{
						if(trianglesPlanarAngle[i].t5_beta < (calculatedBeta + percentage) && trianglesPlanarAngle[i].t5_beta > (calculatedBeta - percentage))
						{
							if(trianglesPlanarAngle[i].t5_gamma < (calculatedGamma + percentage) && trianglesPlanarAngle[i].t5_gamma> (calculatedGamma - percentage))
							{
								matchingList.push_back(trianglesPlanarAngle[i]);
							}
						}
					}
				}
				break;
		case 6:
				for(int i = 0; i < trianglesPlanarAngle.size(); i++)
				{
					if(trianglesPlanarAngle[i].t6_alpha < (calculatedAlpha + percentage) && trianglesPlanarAngle[i].t6_alpha > (calculatedAlpha - percentage))
					{
						if(trianglesPlanarAngle[i].t6_beta < (calculatedBeta + percentage) && trianglesPlanarAngle[i].t6_beta > (calculatedBeta - percentage))
						{
							if(trianglesPlanarAngle[i].t6_gamma < (calculatedGamma + percentage) && trianglesPlanarAngle[i].t6_gamma> (calculatedGamma - percentage))
							{
								matchingList.push_back(trianglesPlanarAngle[i]);
							}
						}
					}
				}
				break;
		case 7:
				for(int i = 0; i < trianglesPlanarAngle.size(); i++)
				{
					if(trianglesPlanarAngle[i].t7_alpha < (calculatedAlpha + percentage) && trianglesPlanarAngle[i].t7_alpha > (calculatedAlpha - percentage))
					{
						if(trianglesPlanarAngle[i].t7_beta < (calculatedBeta + percentage) && trianglesPlanarAngle[i].t7_beta > (calculatedBeta - percentage))
						{
							if(trianglesPlanarAngle[i].t7_gamma < (calculatedGamma + percentage) && trianglesPlanarAngle[i].t7_gamma> (calculatedGamma - percentage))
							{
								matchingList.push_back(trianglesPlanarAngle[i]);
							}
						}
					}
				}
				break;
		case 8:
				for(int i = 0; i < trianglesPlanarAngle.size(); i++)
				{
					if(trianglesPlanarAngle[i].t8_alpha < (calculatedAlpha + percentage) && trianglesPlanarAngle[i].t8_alpha > (calculatedAlpha - percentage))
					{
						if(trianglesPlanarAngle[i].t8_beta < (calculatedBeta + percentage) && trianglesPlanarAngle[i].t8_beta > (calculatedBeta - percentage))
						{
							if(trianglesPlanarAngle[i].t8_gamma < (calculatedGamma + percentage) && trianglesPlanarAngle[i].t8_gamma> (calculatedGamma - percentage))
							{
								matchingList.push_back(trianglesPlanarAngle[i]);
							}
						}
					}
				}
				break;
		case 9:
				for(int i = 0; i < trianglesPlanarAngle.size(); i++)
				{
					if(trianglesPlanarAngle[i].t9_alpha < (calculatedAlpha + percentage) && trianglesPlanarAngle[i].t9_alpha > (calculatedAlpha - percentage))
					{
						if(trianglesPlanarAngle[i].t9_beta < (calculatedBeta + percentage) && trianglesPlanarAngle[i].t9_beta > (calculatedBeta - percentage))
						{
							if(trianglesPlanarAngle[i].t9_gamma < (calculatedGamma + percentage) && trianglesPlanarAngle[i].t9_gamma> (calculatedGamma - percentage))
							{
								matchingList.push_back(trianglesPlanarAngle[i]);
							}
						}
					}
				}
				break;
		case 10:
				for(int i = 0; i < trianglesPlanarAngle.size(); i++)
				{
					if(trianglesPlanarAngle[i].t10_alpha < (calculatedAlpha + percentage) && trianglesPlanarAngle[i].t10_alpha > (calculatedAlpha - percentage))
					{
						if(trianglesPlanarAngle[i].t10_beta < (calculatedBeta + percentage) && trianglesPlanarAngle[i].t10_beta > (calculatedBeta - percentage))
						{
							if(trianglesPlanarAngle[i].t10_gamma < (calculatedGamma + percentage) && trianglesPlanarAngle[i].t10_gamma> (calculatedGamma - percentage))
							{
								matchingList.push_back(trianglesPlanarAngle[i]);
							}
						}
					}
				}
				break;
	}
	return matchingList;
}

double* Triangle::getAreaMoment(Star center, Star fix, Star third)
{
	double* temp = new double[2];
	double a = sqrt(pow(fix.x - center.x, 2) + pow(fix.y - center.y, 2)) * PIXELTOMM;
	double b = sqrt(pow(center.x - third.x, 2) + pow(center.y - third.y, 2)) * PIXELTOMM;
	double c = sqrt(pow(fix.x - third.x, 2) + pow(fix.y - third.y, 2)) * PIXELTOMM;
	double s = 0.5*(a+b+c);
	double area = sqrt(s*(s-a) * (s-b) * (s-c));
	double moment = area * (a*a + b*b + c*c) / 36 ;
	temp[0] = area;
	temp[1] = moment;
	return temp;
}

double* Triangle::getPlanarAngle(Star center, Star fix, Star third)
{
	double* temp = new double[3];
	double a = sqrt(pow(fix.x - center.x, 2) + pow(fix.y - center.y, 2)) * PIXELTOMM;
	double b = sqrt(pow(center.x - third.x, 2) + pow(center.y - third.y, 2)) * PIXELTOMM;
	double c = sqrt(pow(fix.x - third.x, 2) + pow(fix.y - third.y, 2)) * PIXELTOMM;

	double alpha = acos((a*a - c*c - b*b) / (-2*c*b)) * RADtoDEG;
	double beta = acos((b*b - a*a - c*c) / (-2*a*c))* RADtoDEG;
	double gamma = acos((c*c - a*a - b*b) / (-2*a*b))* RADtoDEG;
	temp[0] = alpha;
	temp[1] = beta;
	temp[2] = gamma;
	return temp;
}

void Triangle::calcHeading(Star center, Star fix, double angleCatalog)
{
	//heading calculation
	Star centerCorrected, fixCorrected;
	centerCorrected.x = center.x;
	centerCorrected.y = 480-center.y;
	fixCorrected.x = fix.x;
	fixCorrected.y = 480-fix.y;
	vec2d v1 = getVec2d(fixCorrected.x - centerCorrected.x, fixCorrected.y - centerCorrected.y);
	vec2d v2 = getVec2d(0, 10);
	heading = angle(v1, v2) * RADtoDEG;
	if(fix.x < center.x) heading *= -1;
	heading = angleCatalog - heading;
	if(heading<0) heading +=360;
}

double Triangle::getHeading()
{
	return heading;
}

double Triangle::getAngleFromVector(double v1x, double v1y, double v2x, double v2y)
{
	return angle(getVec2d(v1x, v1y), getVec2d(v2x, v2y)) * RADtoDEG;
}
