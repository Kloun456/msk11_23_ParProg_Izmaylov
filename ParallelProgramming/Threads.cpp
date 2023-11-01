/*#include <iostream>
#include <thread>

using namespace std;



int main()
{
	setlocale(0, "");
	int n = 10;
	float f = 2.394945;
	double* d = new double[n];
	double v1[2] = { 1, 2 };
	double v2[2] = { 1, 2 };

	for (int i = 0; i < n; i++)
		d[i] = i;


	auto code1 = [](int n) -> void { printf("\nInside thread = % d\tNumber - %d", this_thread::get_id(), n); };
	auto code2 = [](float f) -> void { printf("\nInside thread = % d\tFloat - %f", this_thread::get_id(), f); };
	auto code3 = [](double *d, int n) -> void 
	{ 
		printf("\nInside thread = % d", this_thread::get_id()); 
		printf("\nArray:\n");
		for (int i = 0; i < n; i++)
		{
			printf("%f\t",d[i]);
		}
	};
	auto code4 = [](double v1[2], double v2[2]) -> double
	{
		printf("\n—кал€рное произведение векторов - %f", v1[0] * v2[0] + v1[1] * v2[1]);
		return v1[0] * v2[0] + v1[1] * v2[1];
	};


	thread t1(code1,n);
	thread t2(code2, f);
	thread t3(code3,d, n);
	thread t4(code4, v1, v2);

	t1.join();
	t2.join();
	t3.join();
	t4.join();
}*/