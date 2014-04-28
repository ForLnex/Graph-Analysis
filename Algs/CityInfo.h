#ifndef __CITYINFO_H__
#define __CITYINFO_H__

/*
 * CityInfo class for project 3 in EECS 2510: Nonlinear data structures
 *
 * This class implements a basic class for the city info required by this project.  
 *
 * It throws exceptions for invalid longitude, latitude, or population values.
 *
 * Author:  Jerry Heuring
 * Date:    March 18, 2014
 *
 * Revisions:
 *    Added comparison operators to the basic class.  Comparisons are by 
 *    city name only -- if you have two cities that vary by other than 
 *    the name they will come back as equal.
 *
 * Bugs:
 *
 */
#include <string>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <exception>
#include <cmath>
using namespace std;
class InvalidPopulationException : public exception {
};

class InvalidLongitudeException : public exception {
};

class InvalidLatitudeException : public exception {
};

class CityInfo {
protected:
	string cityname;
	double longitude, latitude;
	int population;
public:
	CityInfo(string name="Noname", double latitude=0.0, double longitude=0.0, int population = 0);
	~CityInfo();
	string getName() { return cityname; }
	double getLongitude() { return longitude; }
	double getLatitude() { return latitude; }
	int getPopulation() { return population; }

	bool operator == (CityInfo &rhs);
	bool operator != (CityInfo &rhs);
	bool operator < (CityInfo &rhs);
	bool operator > (CityInfo &rhs);
	bool operator >= (CityInfo &rhs);
	bool operator <= (CityInfo &rhs);

	void setLatitude(double lat) throw (InvalidLatitudeException);
	void setLongitude(double lon) throw (InvalidLongitudeException);
	void setPopulation(int pop) throw (InvalidPopulationException);

	double calculateDistance(CityInfo &to);
};

ostream& operator << (ostream& ostr, CityInfo city);


#endif

