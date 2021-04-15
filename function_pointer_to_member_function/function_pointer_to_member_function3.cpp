#include <iostream>

using namespace std;

class A {
public:
	void (A::*p1)(void);
	void (*p2)(void);

	A() {
		p1 = &A::funa;
		p2 = &A::funb;
	}

	void funa(void) {
		puts("A");
	}

	static void funb(void) {
		puts("B");
	}
};

int main() 
{
	A a;
	void (A::*p)(void);
	
	(a.*a.p1)();

	p = a.p1;
	(a.*p)();

	A* b = &a;
	(b->*p)();

	void (*pp)(void);
	pp = &A::funb;
	pp();

	return 0;
}
