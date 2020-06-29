#include <iostream>

using namespace std;

template<typename T>
void forward_value(T& val) {
	cout << "forward_value(T& val) " << val << endl;
}

template<typename T>
void forward_value(const T& val) {
	cout << "forward_value(const T& val) " << val << endl;
}

#if 0
template<typename T> 
void forward_value(T&& val) {
	cout << "forward_value(T&& val) " << val << endl;
}
#endif

int main()
{
	int a = 1;
	forward_value(a);

	const int b = 2;
	forward_value(2);

	forward_value(3);
}
