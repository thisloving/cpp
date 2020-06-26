#include <iostream>
#include <unordered_map>

using namespace std;

int main()
{
	std::unordered_map<int, int> test = {{1, 2}, {3, 4}, {5, 6}};

	//‘class std::unordered_map<int, int>’ has no member named ‘rbegin’
	for (auto riter = test.rbegin(); riter != test.rend(); ++riter) {
		cout << riter->first<< " " << riter->second << endl;
	}
}
