#include <iostream>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <mqueue.h>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

int main(void) {
	char *recvbuf = NULL;
        struct mq_attr attr;
	mqd_t mqd;
	int recvlen;
	unsigned int prio;
	char prbuf[10];


	mqd = mq_open("/mq1", O_RDONLY);

    	if (mq_getattr(mqd, &attr) < 0) { 
        	cout << "get addr fail" << endl;
        	return -1;
    	}
	recvbuf = (char *)malloc(attr.mq_msgsize * sizeof(char));

	while(1) {
		recvlen = mq_receive(mqd, recvbuf, attr.mq_msgsize, &prio); //不用管优先级时prio可以为NULL
		sprintf(prbuf,"%d", prio); 
		cout << "recv: " << recvbuf << "  prio: " << prbuf << endl;
	}
	mq_close(mqd);
	mq_unlink("/mq1");
	return 0;
}


