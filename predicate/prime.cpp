#include <iostream>
#include <list>
#include <algorithm>
#include <cstdlib>

using namespace std;

bool isPrime(int number) {
	number = abs(number);

	if (number == 0 || number == 1) {
		return false;
	}

	int divisor;
	for (divisor = number/2; number%divisor != 0; --divisor) {
	}

	return divisor == 1;
}

int main() {
	list<int> coll{24, 25, 26, 27, 28, 29, 30};

	auto pos = find_if(coll.cbegin(), coll.cend(), isPrime);

	if (pos != coll.end()) {
		cout << *pos << " is first prime number found" << endl;
	} else {
		cout << "o prime number found" << endl;
	}

	return 0;
}
