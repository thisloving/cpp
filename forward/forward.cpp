#include <iostream>

using namespace std;

template<typename T>
void func(T& param) {
	cout << "left  value: " << endl;
}

template<typename T>
void func(T&& param) {
	cout << "right value: " << endl;
}

template<typename T> 
void warp(T&& param) {
	func(param);
}

template<typename T> 
void warp_forward(T&& param) {
	func(std::forward<T>(param));
}

int main() {
	int num = 2021;
	warp(num);
	warp(2021);

	warp_forward(num);
	warp_forward(std::move(num));
	warp_forward(2021);

	return 0;
}
