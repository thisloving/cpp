#include <iostream>
#include <set>
#include <deque>
#include <algorithm>
#include <iterator>
#include <functional>

using namespace std;
using namespace std::placeholders;

template<typename T>
void print_ele(T t) {
	for (auto i : t) {
		cout << i << " ";
	}
	cout << endl;
}

int main() {
	set<int, less<int>> coll1 = {1, 2, 3, 4, 5, 6, 7, 8, 9};
	print_ele(coll1);

	deque<int> coll2;

	transform(coll1.cbegin(), coll1.cend(),
				back_inserter(coll2),
				bind(multiplies<int>(), _1, 10));
	print_ele(coll2);

	replace_if(coll2.begin(), coll2.end(),
				bind(equal_to<int>(), _1, 70),
				42);
	print_ele(coll2);

	coll2.erase(remove_if(coll2.begin(), coll2.end(),
				bind(logical_and<bool>(),
					bind(greater_equal<int>(), _1, 50),
					bind(less_equal<int>(), _1, 80))),
				coll2.end());
	print_ele(coll2);
}
