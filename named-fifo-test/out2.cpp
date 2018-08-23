#include <iostream>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

using namespace std;

int main(void) {
	const char *fifoname = "fifo_temp";
	int fd,datafd,ret;
	int recv;

	char buffer[1024];
	fd = open(fifoname, O_RDONLY);

	while(1) {
		cout << "readstart" << endl;
		recv = read(fd,buffer,1024);
		cout << buffer << endl;
	}
	close(fd);
	return 0;
}


