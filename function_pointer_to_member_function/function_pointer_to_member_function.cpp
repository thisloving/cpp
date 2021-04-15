#include <stdio.h>
#include <iostream>

using namespace std;

class A {
public:
	A(int aa = 0) : a(aa) {}

	~A() {}

	void setA(int aa = 1) {
		a = aa;
	}

	virtual void print() {
		cout << "A: " << a << endl;
	}

	virtual void printa() {
		cout << "A1: " << a << endl;
	}

private:
	int a;
};

class B : public A {
public:
	B() : A(), b(0){}
	B(int aa, int bb):A(aa), b(bb){}
	~B(){}

	virtual void print() {
		A::print();
		cout << "B: " << b << endl;
	}

	virtual void printa() {
		A::printa();
		cout << "B: " << b << endl;
	}
private:
	int b;
};

int main(void) 
{
	A a;
	B b;
	void (A::*ptr)(int) = &A::setA;
	A* pa = &a;

	printf("A::set():%p\n", &A::setA);
	printf("B::print():%p\n", &A::print);
	printf("B::print():%p\n", &A::printa);

	a.print();

	a.setA(10);
	a.print();
	a.setA(100);
	a.print();

	(pa->*ptr)(1000);
	a.print();

	(a.*ptr)(10000);

	a.print();
	return 0;
}
