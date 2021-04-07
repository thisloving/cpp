#include <iostream>
#include <map>
#include <string>

using namespace std;

typedef void* (*PTRCreateObject)(void);

class ClassFactory {
public:
	static ClassFactory& getInstance() {
		static ClassFactory instance;
		return instance;
	}

public:
	void*  getClassByName(string className);
	void   registClass(string name, PTRCreateObject method);

private:
	ClassFactory() {}
	~ClassFactory() {}
	ClassFactory(const ClassFactory&);
	ClassFactory& operator=(const ClassFactory&);

private:
	map<string, PTRCreateObject> m_classMap;
};

void* ClassFactory::getClassByName(string className) {
	map<string, PTRCreateObject>::const_iterator iter = 
		m_classMap.find(className);
	if (iter == m_classMap.end()) {
		return nullptr;
	} else {
		return iter->second();
	}
}

void ClassFactory::registClass(string name, PTRCreateObject method) {
	m_classMap.insert(std::make_pair(name, method));
}

class RegisterAction {
public:
	RegisterAction(string className, PTRCreateObject ptrCreateFn) {
		ClassFactory::getInstance().registClass(className, ptrCreateFn);
	}
};

// ----------------------------------------------------------------
#define REGISTER(className) \
	className* objectCreator##className() {\
		return new className;\
	}\
	RegisterAction g_creatorRegister##className( \
		#className, (PTRCreateObject)objectCreator##className)

class TestClass {
public:
	TestClass() :i(0){
	}
	
	void add(int num) {
		i += num;
	}

	int  get() const {
		return i;
	}

	void m_print() {
		cout << "hello TestClass" << endl;
	}

	int i;
};

REGISTER(TestClass);

int main(int argc, char* argv[])
{
	TestClass* ptrObj = (TestClass*)ClassFactory::getInstance().getClassByName("TestClass");
	ptrObj->add(2);
	ptrObj->add(1);
	ptrObj->m_print();
	cout << ptrObj->get() << endl;
}
