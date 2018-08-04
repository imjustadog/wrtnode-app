#include <iostream>
#include <unistd.h>
#include <semaphore.h>
#include <fcntl.h>

using namespace std;

int main(void) {
	sem_t *sem_test;
	sem_test = sem_open("getphoto",0);

	if(sem_test < 0) {
		cout << "2 create sem fail" << endl;
		return 0;
	}

	while(1) {
		sem_wait(sem_test);
		cout << "test2" << endl;
	}
	sem_close(sem_test);
	sem_unlink("getphoto");
	return 0;
}


