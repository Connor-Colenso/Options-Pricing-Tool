#include <iostream>
#include <numeric>
#include <thread>
#include <vector>
#include <chrono>
#include <random>

int main() {
	float a = 40.3f;
	int expon;
	float mant = frexpf(a, &expon);

	std::cout << mant << " " << expon << std::endl;
}
