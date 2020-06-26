#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;

template<typename T>
void print_ele(T t) {
	for (auto i : t) {
		cout << i << " ";
	}
	cout << endl;
}

int square(int value) {
	return value * value;
}

int main()
{
	std::set<int> coll1{1, 2, 3, 4, 5, 6, 7, 8, 9};
	std::vector<int> coll2;

	std::transform(coll1.cbegin(), coll1.cend(), std::back_inserter(coll2), square);
	print_ele(coll2);

	return 0;
}
