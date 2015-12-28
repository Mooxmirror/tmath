#include "tmath_test.hpp"
#include <iostream>
#include <cstdlib>

bool TMathTest::equal(TMath::DOUBLE x, TMath::DOUBLE y, TMath::DOUBLE tolerance) {
	if (x - tolerance <= y && x + tolerance >= y) return true;
	else return false;
}

void TMathTest::assert(TMath::DOUBLE value, TMath::DOUBLE correct, std::string expression) {
    assert(value, correct, expression, TMathTest::DEFAULT_TOLERANCE);
}

void TMathTest::assert(TMath::DOUBLE value, TMath::DOUBLE correct, std::string expression, TMath::DOUBLE tolerance) {
    if (!equal(value, correct, tolerance)) {
        std::cout << "Assert: " << expression << " failed" << std::endl;
		std::cout << value << " is not nearly equal " << correct << std::endl;
        exit(1);
    } else {
		double deviation = value - correct;
		deviation = deviation < 0 ? -deviation : deviation;
		std::cout << "Test (" << expression << ") passed with deviation of " << deviation << std::endl;
	}
}
