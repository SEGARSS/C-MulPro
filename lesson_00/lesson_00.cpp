//Многопоточность | Потоки | thread | Многопоточное программирование | Уроки | C++ #1 - Видео №1./

#include<iostream>
#include<thread>
#include<chrono>

using namespace std;

void DoWork()
{
	for (size_t i = 0; i < 10; i++)
	{
		cout << "ID поток = " << this_thread::get_id() << "\tDoWork\t" << i << endl;
		this_thread::sleep_for(chrono::milliseconds(1000));
	}
}

int main()
{
	setlocale(LC_ALL,"ru");

	thread th(DoWork);
	thread th2(DoWork);
	
	for (size_t i = 0; i < 10; i++)
	{
		cout << "ID поток = " << this_thread::get_id() << "\tmain\t" << i << endl;
		this_thread::sleep_for(chrono::milliseconds(500));
	}
	
	th.join();
	th2.join();

	return 0;
}
/*Потоки процессора.....*/