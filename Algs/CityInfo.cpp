#include "CityInfo.h"
/*
 * Output operator.  The output operator merely puts the data out in string form.  
 */
ostream& operator << (ostream& ostr, CityInfo city) {
	ostr << city.getName()
		<< " ( " << city.getLatitude() << ", " << city.getLongitude() 
		<< ")  Population = " << city.getPopulation();
	return ostr;
}
/*
 * Constructor -- default and complete.  It tries to build the object given the 
 * parameters for name, longitude, latitude, and population.  It may throw an
 * exception if longitude, latitude, or population is out of range.
 */
CityInfo::CityInfo(string name, double lat, double lon, int pop) {
	cityname = name;
	try {
		this->setLatitude(lat);
	} catch (InvalidLatitudeException & e) {
		latitude = 0.0;
	}
	try {
		this->setLongitude(lon);
	} catch (InvalidLongitudeException & e) {
		longitude = 0.0;
	}
	try {
		this->setPopulation(pop);
	} catch (InvalidPopulationException & e) {
		population = 0;
	}
}

/*
 * Destructor -- merely sets the properties to default values.
 */
CityInfo::~CityInfo() {
	cityname = "Noname";
	latitude = 0.0;
	longitude = 0.0;
	population = 0;
}

/* 
 * Set longitude will check that longitude is in range.  If it is not in 
 * range it will throw an InvalidLongitudeException.  
 */
void CityInfo::setLongitude(double lon) throw(InvalidLongitudeException) {
	if (lon > 180.0 || lon < -180.0) {
		throw InvalidLongitudeException();
	} else {
		longitude = lon;
	}
}

/*
 * Set latitude will check that the latitude is in range.  If it is not 
 * in range it will throw an InvalidLatitudeException.
 */
void CityInfo::setLatitude(double lat) throw (InvalidLatitudeException) {
	if (lat > 90.0 || lat < -90.0) {
		throw InvalidLatitudeException();
	} else {
		latitude = lat;
	}
}

/*
 * Set population will set the population to the given value if it is in
 * range.  If it is negative it will throw and InvalidPopulationException and
 * leave the instance variable unchanged.
 */
void CityInfo::setPopulation(int pop) throw (InvalidPopulationException) {
	if (pop < 0) {
		// Throw an exception and don't change the population
		throw InvalidPopulationException();
	} else {
		population = pop;
	}
}

/*
 * Comparison operators -- The comparison operators are overloaded and
 * check ONLY the string.  If two objects have the same name but different
 * locations they will return a true for equality.
 */
bool CityInfo::operator == (CityInfo &rhs) {
	return cityname == rhs.cityname;
}

bool CityInfo::operator != (CityInfo &rhs){
	return cityname != rhs.cityname;
}

bool CityInfo::operator < (CityInfo &rhs){
	return cityname < rhs.cityname;
}

bool CityInfo::operator > (CityInfo &rhs){
	return cityname > rhs.cityname;
}

bool CityInfo::operator >= (CityInfo &rhs){
	return cityname >= rhs.cityname;
}

bool CityInfo::operator <= (CityInfo &rhs){
	return cityname <= rhs.cityname;
}


/*
 * This needs to be added to calculate the distance from the current city to
 * the city passed in.  
 */
double CityInfo::calculateDistance(CityInfo &to) {

	double absLongitude, sinAbsLongitude, cosAbsLongitude;
	double sinLat1, sinLat2, cosLat1, cosLat2, sinLong1, sinLong2, cosLong1, cosLong2;
	double angle;
#ifndef M_PI
	double M_PI = 4.0*atan(1.0);
#endif

	absLongitude = abs(longitude - to.longitude);
	sinAbsLongitude = sin(absLongitude * M_PI / 180.0);
	cosAbsLongitude = cos(absLongitude * M_PI / 180.0);
	sinLat1 = sin(latitude * M_PI/180.0);
	cosLat1 = cos(latitude * M_PI/180.0);
	sinLat2 = sin(to.latitude * M_PI/180.0);
	cosLat2 = cos(to.latitude * M_PI/180.0);
	sinLong1 = sin(longitude * M_PI/180.0);
	cosLong1 = cos(longitude * M_PI/180.0);
	sinLong2 = sin(to.longitude * M_PI/180.0);
	cosLong2 = cos(to.longitude * M_PI/180.0);

		angle = atan2(sqrt(pow(cosLat2 * sinAbsLongitude, 2) + pow(cosLat1*sinLat2 - sinLat1*cosLat2*cosAbsLongitude *cosAbsLongitude, 2)),
			(sinLat1*sinLat2+cosLat1*cosLat2*cosAbsLongitude));

	return 6371.0 * angle;
}
