#include <iostream>
#include <deque>
#include <algorithm>
#include <functional>

using namespace std;

template<typename T>
void print_ele(T t) {
	for (auto i : t) {
		cout << i << " ";
	}
	cout << endl;
}

int main()
{
	deque<int> coll = {1, 2, 3, 5, 7, 11, 13, 17, 19};
	print_ele(coll);

	transform(coll.cbegin(), coll.cend(), 
				coll.begin(), 
				negate<int>());
	print_ele(coll);

	transform(coll.cbegin(), coll.cend(),
				coll.cbegin(),
				coll.begin(),
				multiplies<int>());
	print_ele(coll);
}
