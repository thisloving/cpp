#include <iostream>
#include <atomic>
#include <thread>
#include <vector>

using namespace std;

int num = 0;

void Add() {
	for (int i = 0; i < 10000000; i++) {
		num++;
	}
}

int main() 
{
	clock_t startClock = clock();

	thread t1(Add);
	thread t2(Add);
	thread t3(Add);

	t1.join();
	t2.join();
	t3.join();

	clock_t endClock = clock();
	cout << "raw    time consuming:" << endClock-startClock <<  ", result=" << num << endl;

	return 0;
}
