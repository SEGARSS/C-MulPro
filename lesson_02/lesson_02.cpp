//Возврат результата из потока по ссылке | Многопоточное программирование | Уроки | C++ #3 - Видео №3. 

#include<iostream>
#include<string>
#include<thread>
using namespace std;

//---------------------------------------------------------------------------------------------------------
void DoWork(int &a)
{
	this_thread::sleep_for(chrono::milliseconds(3000));
	cout << "ID потока = " << this_thread::get_id() << " =============\t " << "DoWork STARTED\t=============" << endl;

	this_thread::sleep_for(chrono::milliseconds(5000));
	a *= 2;

	cout << "ID потока = " << this_thread::get_id() << " =============\t " << "DoWork STOPPED\t=============" << endl;
}
//---------------------------------------------------------------------------------------------------------
int main()
{
	setlocale(LC_ALL,"ru");

	int q = 5;

	thread t(DoWork, ref(q) );
		
	
	for (size_t i = 0; i < 10; i++)
	{
		cout << "ID потоков = " << this_thread::get_id() << "\tmain works\t" << i << endl;
		this_thread::sleep_for(chrono::milliseconds(500) );
	}
	

	t.join();
	cout << q << endl;

	return 0;
}
//---------------------------------------------------------------------------------------------------------