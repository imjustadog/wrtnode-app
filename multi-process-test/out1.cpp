#include <iostream>
#include <unistd.h>
#include <semaphore.h>
#include <fcntl.h>


using namespace std;

int main(void) {

	pid_t pid;
	sem_t *sem_test;
	sem_test = sem_open("getphoto", O_CREAT, 0644, 0);

	if(sem_test < 0) {
		cout << "1 create sem fail" << endl;
		return 0;
	}


	pid = fork();
	if(pid != 0) {
		while(1) {
			cout << "test1" << endl;
			sem_post(sem_test);
			sleep(2);
		}
		sem_close(sem_test);
		sem_unlink("getphoto");
	}
	else {
		execle("out2",NULL,NULL,NULL);
	}
	return 0;
}


