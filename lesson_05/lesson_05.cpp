﻿// Что такое mutex | Cинхронизация потоков | Многопоточное программирование | C++ #6 - Видео №6. 

#include<iostream>
#include<mutex>
#include<thread>
#include"SimpleTimer.h"

using namespace std;


mutex mtx;
//-------------------------------------------------------------------------------
void Print(char ch)
{
	this_thread::sleep_for(chrono::milliseconds(2000));

	mtx.lock();

	for (int i = 0; i < 5; i++)
	{
		for (int i = 0; i < 10; i++)
		{
			cout << ch;
			this_thread::sleep_for(chrono::milliseconds(20));
		}
		cout << endl;
	}
	cout << endl;

	mtx.unlock();

	this_thread::sleep_for(chrono::milliseconds(2000));
}
//-------------------------------------------------------------------------------
int main()
{
	setlocale(LC_ALL,"ru");

	SimpleTimer timer;

	thread t1(Print,'*');
	thread t2(Print,'#');
	thread t3(Print,'@');

	t1.join();
	t2.join();
	t3.join();

	//Print('*');
	//Print('#');

	return 0;
}
//-------------------------------------------------------------------------------