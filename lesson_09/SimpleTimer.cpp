#include"SimpleTimer.h"

SimpleTimer::~SimpleTimer()
{
	end = chrono::high_resolution_clock::now();
	duration = end - start;
	float result = duration.count();
	cout << "������ �����: " << result << " ������." << endl;
}

SimpleTimer::SimpleTimer()
: duration(0)
{
	start = std::chrono::high_resolution_clock::now();
}