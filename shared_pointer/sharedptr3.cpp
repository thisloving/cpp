#include <iostream>
#include <memory>
#include <sys/mman.h>
#include <fcntl.h>
#include <unistd.h>
#include <cstring>
#include <cerrno>
#include <string>

using namespace std;

class SharedMemoryDetacher {
public:
	void operator() (int* p) {
		cout << "unlink /tmp1234" << endl;
		if (shm_unlink("/tmp1234") != 0) {
			cerr << "OOPS: shm_unlink() failed" << endl;
		}
	}
};

std::shared_ptr<int> getSharedIntMemory(int num) {
	void* mem;
	int shmfd = shm_open("/tmp1234", O_CREAT|O_RDWR, S_IRWXU|S_IRWXG);
	if (shmfd < 0) {
		throw std::string(strerror(errno));
	}
	if (ftruncate(shmfd, num*sizeof(int)) == -1) {
		throw std::string(strerror(errno));
	}
	mem = mmap(nullptr, num*sizeof(int), PROT_READ|PROT_WRITE, MAP_SHARED, shmfd, 0);
	if (mem == MAP_FAILED) {
		throw std::string(strerror(errno));
	}

	return std::shared_ptr<int>(static_cast<int*>(mem), SharedMemoryDetacher());
}

int main()
{
	std::shared_ptr<int> smp(getSharedIntMemory(100));

	for (int i = 0; i < 100; ++i) {
		smp.get()[i] = i*42;
	}

	cout << "<return>" << endl;
	cin.get();

	smp.reset();

	return 0;
}
//g++ -std=c++11 -lrt -g sharedptr3.cpp -o sharedptr3
