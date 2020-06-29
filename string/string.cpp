#include <iostream>
#include <vector>
#include <string.h>

using namespace std;

class MyString {
public:	
	MyString() {
		data = nullptr;
		len  = 0;
	}

	MyString(const char *p) {
		len = strlen(p);
		init_data(p);
		cout << "construtor is called! source:" << p << endl;
	}

	MyString(const MyString& str) {
		len = str.len;
		init_data(str.data);
		cout << "copy construtor is called! source:" << str.data << endl;
	}

	MyString& operator=(const MyString& str) {
		if(this != &str) {
			len = str.len;
			init_data(str.data);
		}

		cout << "copy assignment is called! source:" << str.data << endl;
		return *this;
	}

#if 1
	MyString(MyString&& str) {
		cout << "move construtor is called! source:" << str.data << endl;
		len  = str.len;
		data = str.data;
		str.len  = 0;
		str.data = nullptr;
	}

	MyString& operator=(MyString&& str) {
		cout << "move assignment is called! source:" << str.data << endl;
		if (this != &str) {
			len = str.len;
			data = str.data;
			str.len = 0;
			str.data = nullptr;
		}

		return *this;
	}
#endif

	virtual ~MyString() {
		if (data) {
			free(data);
		}
	}

private:
	void init_data(const char* s) {
		data = new char[len+1];
		memcpy(data, s, len);
		data[len] = '\0';
	}

private:
	char*  data;
	size_t len;
};

int main()
{
	MyString str;
	str = MyString("Hello");
	
	//MyString str2 = MyString("Hello2");

	std::vector<MyString> vec;
	vec.push_back(MyString("World"));
}
