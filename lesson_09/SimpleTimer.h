#pragma once

#include<chrono>
#include<iostream>

using namespace std;

class SimpleTimer
{
public:
	~SimpleTimer();
	SimpleTimer();

private:

	chrono::time_point<chrono::steady_clock> start, end;
	chrono::duration<float> duration;
};
#pragma once
#pragma once
