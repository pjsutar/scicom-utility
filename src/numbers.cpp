#include <scicom-utility/numbers.h>

// Convert Hexadecimal string to a long
long Numbers::hextol(const std::string& hexStr) {
	char* offset;
	if (hexStr.length() > 2) {
		if (hexStr[0] == '0' && hexStr[1] == 'x') {
			return std::strtol(hexStr.c_str(), &offset, 0);
		}
	}
	return std::strtol(hexStr.c_str(), &offset, 16);
}

// Comparing floating point numbers with bounded accuracy
bool Numbers::doubleEquals(double left, double right, double epsilon) {
	return(std::fabs(left - right) < epsilon);
}

bool Numbers::doubleLess(double left, double right, double epsilon, bool orequal) {
	if (std::fabs(left - right) < epsilon) {
		// Within epsilon, so consider equal
		return orequal;
	}
	return (left < right);
}

bool Numbers::doubleGreater(double left, double right, double epsilon, bool orequal) {
	if (std::fabs(left - right) < epsilon) {
		// Within epsilon, so consider equal
		return orequal;
	}
	return (left > right);
}

