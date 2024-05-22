//Потоки с параметрами | Многопоточное программирование | Уроки | C++ #2 - Видео №2.

#include<iostream>
#include<string>
#include<thread>

using namespace std;

//------------------------------------------------------------------------------------------
void DoWork(int a, int b, string ms)
{
	cout << ms << endl;

	this_thread::sleep_for(chrono::milliseconds(3000));
	cout << "========\t " << "DoWork STARTED\t=============" << endl;

	this_thread::sleep_for(chrono::milliseconds(5000));
	cout << "a+b = " << a + b << endl;

	this_thread::sleep_for(chrono::milliseconds(3000));
	cout << "========\t " << "DoWork STARTED\t=============" << endl;
}
//------------------------------------------------------------------------------------------
int main()
{
	setlocale(LC_ALL,"ru");

	thread th(DoWork,2,3, "or mssing");

	for (size_t i = 0; true; i++)
	{
		cout << "ID потоков = " << this_thread::get_id() << "\tmain works\t" << i << endl;
		this_thread::sleep_for(chrono::milliseconds(500) );
	}

	th.join();

	return 0;
}
//------------------------------------------------------------------------------------------
/*Разделение потоков данных если программа работает медленно и с большими задачами.*/