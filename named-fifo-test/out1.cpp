#include <iostream>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>

using namespace std;

int main(void) {
	const char * fifoname = "fifo_temp";
	int fd;
	int byte;
	int ret;
	int datafd;
	char buffer[] = {"hello world!"};
	pid_t pid;

	if (access(fifoname,F_OK) < 0)
    	{
		ret =mkfifo(fifoname,0777);
		if (ret < 0)
		{	
			cout << "create fail" << endl;
			return 0;
		}
	}

	pid = fork();
	if(pid != 0) {
		fd = open(fifoname,O_WRONLY);
		while(1) {
			cout << "test1" << endl;
			ret = write(fd,buffer,sizeof(buffer));
			sleep(2);
		}
		close(fd);
	}
	else {
		execle("out2",NULL,NULL,NULL);
		//system("./outsh.sh");
	}
	return 0;
}


