#include <iostream>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <mqueue.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>


using namespace std;

int main(void) {

	pid_t pid;	
	mqd_t mqd;
	struct mq_attr setattr;
	unsigned int prio;
	int recvlen;
	const char *sendbuf = "123456";

	setattr.mq_maxmsg = 10;
	setattr.mq_msgsize = 10; 

	mqd = mq_open("/mq1",O_RDWR|O_CREAT|O_EXCL, 0644, NULL);
    	if (mqd < 0) {
	        cout << strerror(errno) << endl;
		return -1;
	}


	pid = fork();
	if(pid != 0) {
		while(1) {
			cout << "test1" << endl;
			mq_send(mqd, sendbuf, 6, 0); //数值越大，优先级越大，0为最小优先级
			sleep(2);
		}
		mq_close(mqd);
		mq_unlink("/mq1");
	}
	else {
		execle("out2",NULL,NULL,NULL);
	}
	return 0;
}


