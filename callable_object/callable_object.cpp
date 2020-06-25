#include <iostream>
#include <memory>
#include <future>

using namespace std;

void func (int x, int y) {
	cout << "call func: x=" << x << " y=" << y << endl;
}

auto l = [](int x, int y) {
	cout << "call lambda: x=" << x << " y=" << y << endl;
};

class C {
public:
	void operator()(int x, int y) const {
		cout << "call functor: x=" << x << " y=" << y << endl;
	}

	void memfunc(int x, int y) const {
		cout << "call memfunc: x=" << x << " y=" << y << endl;
	}
};

int main()
{	
	C c;
	std::shared_ptr<C> sp(new C);

	// bind() uses callable objects to bind arguments
	cout << "bind:" << endl;
	std::bind(func, 77, 33)();
	std::bind(l, 77, 33)();
	std::bind(C(), 77, 33)();
	std::bind(c, 77, 33)();
	std::bind(&C::memfunc, c, 77, 33)();
	std::bind(&C::memfunc, sp, 77, 33)();

	cout << "async:" << endl;
	std::async(func, 42, 77);
	std::async(l, 42, 77);
	std::async(c, 42, 77);
	std::async(&C::memfunc, &c, 42, 77);
	std::async(&C::memfunc, sp, 42, 77);
}
