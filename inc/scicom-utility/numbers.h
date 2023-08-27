#ifndef SCICOM_UTILITY_NUMBERS_H
#define SCICOM_UTILITY_NUMBERS_H

#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include <cmath>
#include <limits>
#include <boost/cast.hpp>
#include <boost/lexical_cast.hpp>

namespace Numbers {

	// Convert hexadecimal string to a long
	long hextol(const std::string& hexStr);

	// Convert numbers to hexadecimal string
	template<typename T>
	std::string ntohex(const T& num) {
		std::stringstream ss;
		ss << std::showbase << std::hex << num;
		return(ss.str());
	};

	// Convert strings to numbers
	template<typename T>
	T strtonum(const std::string& numStr) {
		T res = 0;
		try {
			T res = boost::lexical_cast<T>(numStr);
		}
		catch (boost::bad_lexical_cast& e) {
			std::cerr << "Bad cast: " << e.what() << std::endl;
		}
		return(res);
	};

	// Convert numbers to strings
	template<typename T>
	std::string numtostr(const T& num) {
		std::stringstream ss;
		ss << num;
		return(ss.str());
	};

	// Testing whether a string contains a valid number
	template<typename T>
	bool isValid(const std::string& str) {
		bool res = true;
		try {
			T temp = boost::lexical_cast<T>(str);
		}
		catch (boost::bad_lexical_cast& e) {
			res = false;
		}
		return(res);
	};

	// Comparing floating point numbers with bounded accuracy
	bool doubleEquals(double left, double right, double epsilon);
	bool doubleLess(double left, double right, double epsilon, bool orequal = false);
	bool doubleGreater(double left, double right, double epsilon, bool orequal = false);

	// Parsing a string containing a number in scientific notation
	template<typename T>
	T strToNum(const std::string& str) {
		std::stringstream ss(str);
		T temp;
		ss >> temp;

		if (ss.fail()) {
			std::string s = "Unable to format ";
			s += str;
			s += " as a number.";
			throw(s);
		}
		return temp;
	};

	// Converting safely between numeric types
	template<typename Source, typename Target>
	Target typeConvert(const Source num) {
		Target res;
		try {
			Target res = boost::numeric_cast<Target>(num);
		}
		catch (boost::bad_numeric_cast& e) {
			std::cerr << e.what() << std::endl;
		}
		return(res);
	};

	// Getting the minimum and maximum values for a numeric type
	template<typename T>
	void showMinMax() {
		std::cout << "min: " << std::numeric_limits<T>::min() << std::endl;
		std::cout << "max: " << std::numeric_limits<T>::max() << std::endl;
		std::endl;
	};

} // namespace Numbers

#endif // SCICOM_UTILITY_NUMBERS_H