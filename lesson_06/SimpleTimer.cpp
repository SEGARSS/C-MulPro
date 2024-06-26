#include"SimpleTimer.h"

SimpleTimer::~SimpleTimer()
{
	end = chrono::high_resolution_clock::now();
	duration = end - start;
	float result = duration.count();
	cout << "Прошло время: " << result << " секунд." << endl;
}

SimpleTimer::SimpleTimer()
: duration(0)
{
	start = std::chrono::high_resolution_clock::now();
}