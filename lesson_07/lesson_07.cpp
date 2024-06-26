// Deadlock �������� ���������� | ������������� ���������������� | C++ #8 - ����� �8.

#include<iostream>
#include<mutex>
#include<thread>
#include"SimpleTimer.h"

using namespace std;


mutex mtx1;
mutex mtx2;
//-------------------------------------------------------------------------------
void Print1(char ch)
{
	mtx1.lock();

	this_thread::sleep_for(chrono::milliseconds(1000));

	mtx2.lock();
	
	for (int i = 0; i < 5; i++)
	{
		for (int i = 0; i < 10; i++)
		{
			cout << '*';
			this_thread::sleep_for(chrono::milliseconds(10));
		}
		cout << endl;
	}
	cout << endl;

	mtx1.unlock();

	mtx2.unlock();
}
//-------------------------------------------------------------------------------
void Print2(char ch)
{
	mtx1.lock();

	this_thread::sleep_for(chrono::milliseconds(1000));

	mtx2.lock();
	
	for (int i = 0; i < 5; i++)
	{
		for (int i = 0; i < 10; i++)
		{
			cout << '#';
			this_thread::sleep_for(chrono::milliseconds(10));
		}
		cout << endl;
	}
	cout << endl;

	mtx1.unlock();

	mtx2.unlock();
}
//-------------------------------------------------------------------------------
int main()
{
	setlocale(LC_ALL,"ru");

	SimpleTimer timer;

	thread t1(Print1, '*');
	thread t2(Print2, '#');

	t1.join();
	t2.join();

	return 0;
}
//-------------------------------------------------------------------------------
/*���������� ��������� ������� mutex, ����� �������� �������� ����������.*/
