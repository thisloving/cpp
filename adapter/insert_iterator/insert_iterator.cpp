#include <iostream>
#include <algorithm>
#include <iterator>
#include <list>
#include <vector>
#include <deque>
#include <set>
#include <iostream>

using namespace std;

template<typename T>
void print_insert(T t) {
	for (auto i : t) {
		cout << i << " ";
	}
	cout << endl;
}

int main()
{
	list<int> coll1 = {1, 2, 3, 4, 5, 6, 7, 8, 9};

	vector<int> coll2;
	copy(coll1.cbegin(), coll1.cend(), back_inserter(coll2));
	print_insert(coll2);

	deque<int> coll3;
	copy(coll1.cbegin(), coll1.cend(), front_inserter(coll3));
	print_insert(coll3);

	set<int> coll4;
	copy(coll1.cbegin(), coll1.cend(), inserter(coll4, coll4.begin()));
	print_insert(coll4);
}
