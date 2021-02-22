#include <iostream>
#include <vector>
#include <string.h>

using namespace std;

class String {
public:
	String(const char* c_str=nullptr);
	String(const String& str);
	String& operator=(const String& str);
	String(String&& str);
	String& operator=(String&& str);
	~String();

private:
	char* m_data;
};

inline String::String(const char *c_str) {
	if (c_str != nullptr) {
		int len = strlen(c_str);
		m_data = new char[len+1];
		memcpy(m_data, c_str, len);
		m_data[len] = '\0';
		
		cout << "construtor is called! src:" << c_str << " dst:" << m_data << endl;
	} else {
		m_data = new char[1];
		m_data[0] = '\0';
	}	
}

inline String::String(const String& str) {
	int len = strlen(str.m_data);
	m_data = new char[len+1];
	memcpy(m_data, str.m_data, len);
	m_data[len] = '\0';

	cout << "copy construtor is called! src:" << str.m_data << " dst:" << m_data << endl;
}

inline String& String::operator=(const String& str) {
	if (this == &str) {
		return *this;
	}

	delete []m_data;
	int len = strlen(str.m_data);
	m_data = new char[len+1];
	memcpy(m_data, str.m_data, len);
	m_data[len] = '\0';

	cout << "copy assignment is called! src:" << str.m_data << " dst:" << m_data << endl;

	return *this;
}

inline String::String(String&& str) {
	m_data = str.m_data;
	str.m_data = nullptr;

	cout << "move construtor is called! src:" << (str.m_data ? str.m_data :"") << " dst:"<< m_data << endl;
}

inline String& String::operator=(String&& str) {
	if (this != &str) {
		return *this;
	}

	m_data = str.m_data;
	str.m_data = nullptr;

	cout << "move assignment is called! src:" << (str.m_data ? str.m_data:"") << " dst:" << m_data << endl;

	return *this;
}

String::~String() {
	cout << "destructor is called!" << (m_data ? m_data : "") << endl;
	delete []m_data;
}

int main() 
{
	String str;
	str = String("Hello");

	String str2 = String("World");

	std::vector<String> vec;
	vec.push_back(String("!"));

	return 0;
}

//g++ -std=c++20 -g string.cpp -o string
