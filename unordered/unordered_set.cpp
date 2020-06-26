#include <iostream>
#include <unordered_set>

using namespace std;

int main()
{
	std::unordered_set<int> test = {1, 2, 3, 4, 5};

	//class std::unordered_set<int>’ has no member named ‘rbegin’
	for (auto riter = test.rbegin(); riter != test.rend(); ++riter) {
		cout << *riter << endl;
	}
}
