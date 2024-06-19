// С++ потоки и методы класса | С++ метод класса в потоке | Многопоточное программирование | C++ #5 - Видео №5.

#include<iostream>
#include<thread>
using namespace std;

//---------------------------------------------------------------------------------------------------------
class MyClass
{
public:
	void DoWork()
	{
		this_thread::sleep_for(chrono::milliseconds(2000));
		cout << "ID потока = " << this_thread::get_id() << " =============\t " << "DoWork STARTED\t=============" << endl;

		this_thread::sleep_for(chrono::milliseconds(5000));
		cout << "ID потока = " << this_thread::get_id() << " =============\t " << "DoWork STOPPED\t=============" << endl;
	}

	void DoWork2(int a)
	{
		this_thread::sleep_for(chrono::milliseconds(2000));
		cout << "ID потока = " << this_thread::get_id() << " =============\t " << "DoWork2 STARTED\t=============" << endl;

		this_thread::sleep_for(chrono::milliseconds(5000));
		cout << "DoWork2 значение параметра\t" << a << endl;
		cout << "ID потока = " << this_thread::get_id() << " =============\t " << "DoWork2 STOPPED\t=============" << endl;
	}

	int Sum(int a, int b)
	{
		this_thread::sleep_for(chrono::milliseconds(2000));
		cout << "ID потока = " << this_thread::get_id() << " =============\t " << "Sum STARTED\t=============" << endl;

		this_thread::sleep_for(chrono::milliseconds(5000));
		cout << "ID потока = " << this_thread::get_id() << " =============\t " << "Sum STOPPED\t=============" << endl;

		return a + b;
	}
};
//---------------------------------------------------------------------------------------------------------
int main()
{
	setlocale(LC_ALL,"ru");

	//------------------------------------------------------------------------------------------------

	int result;

	MyClass m;

	thread t([&]()
	{
		result = m.Sum(2, 5);
	});

	for (size_t i = 1; i <= 10; i++)
	{
		cout << "ID потока = " << this_thread::get_id() << "\tmain works\t" << i << endl;
		this_thread::sleep_for(chrono::milliseconds(500));
	}

	t.join();
	cout << "RESELT\t" << result << endl;

	//------------------------------------------------------------------------------------------------

	cout << "Пример тотже самый, но синтаксис написания другой." << endl;

	MyClass n;
	thread y(&MyClass::DoWork, n);

	for (size_t i = 1; i <= 10; i++)
	{
		cout << "ID потока = " << this_thread::get_id() << "\tmain works\t" << i << endl;
		this_thread::sleep_for(chrono::milliseconds(500));
	}

	y.join();

	//------------------------------------------------------------------------------------------------

	cout << "Пример тотже самый, но синтаксис написания другой(добавили напрямую данные)." << endl;

	MyClass h;
	thread k(&MyClass::DoWork2, h, 6);

	for (size_t i = 1; i <= 10; i++)
	{
		cout << "ID потока = " << this_thread::get_id() << "\tmain works\t" << i << endl;
		this_thread::sleep_for(chrono::milliseconds(500));
	}

	k.join();

	//------------------------------------------------------------------------------------------------

	return 0;
}
//---------------------------------------------------------------------------------------------------------