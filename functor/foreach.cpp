#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

template<int value>
void add(int& elem) {
	elem += value;
}

template<typename T>
void print_ele(T t) {
	for (auto i : t) {
		cout << i << " ";
	}
	cout << endl;
}

class PrintInt {
public:
	void operator() (int elem) const {
		cout << elem << ' ';
	}
};

class AddValue {
public:
	AddValue(int v) : value(v) {
	}

	void operator()(int& elem) const {
		elem += value;
	}

private:
	int value;
};

int main()
{
	vector<int>  coll={1, 2, 3, 4, 5 ,6 ,7 ,8, 9};
	
	for_each(coll.cbegin(), coll.cend(), PrintInt());
	cout << endl;
	for_each(coll.begin(), coll.end(), add<10>);
	print_ele(coll);

	for_each(coll.begin(), coll.end(), AddValue(10));
	print_ele(coll);
	for_each(coll.begin(), coll.end(), AddValue(*coll.begin()));
	print_ele(coll);

	cout << endl;
}
