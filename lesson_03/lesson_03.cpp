//Лямбда выражения и возврат результата выполнения потока | Многопоточное программирование | C++ #4 - Видео №4.

#include<iostream>
#include<thread>
using namespace std;

//---------------------------------------------------------------------------------------------------------
int Sum(int a, int b)
{
	this_thread::sleep_for(chrono::milliseconds(2000));
	cout << "ID потока = " << this_thread::get_id() << " =============\t " << "Sum STARTED\t=============" << endl;

	this_thread::sleep_for(chrono::milliseconds(5000));
	cout << "ID потока = " << this_thread::get_id() << " =============\t " << "Sum STOPPED\t=============" << endl;

	return a + b;
}
//---------------------------------------------------------------------------------------------------------
int main()
{
	setlocale(LC_ALL,"ru");

	int result;

	thread t([&result]() 
	{
		result = Sum(2, 5);
	});

	// ( [&result]() {result = Sum(2, 5)} ); - Анонимная функция (Лямда выражений).

	for (size_t i = 1; i <= 10; i++)
	{
		cout << "ID потоков = " << this_thread::get_id() << "\tmain works\t" << i << endl;
		this_thread::sleep_for(chrono::milliseconds(500) );
	}

	t.join();
	cout << "Sum result = " << result << endl;

	return 0;
}
//---------------------------------------------------------------------------------------------------------