#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <sys/wait.h>  // wait(NULL)
#include <sys/time.h>

/********************

Copy and rename this folder for a new project.

cp -r template_project new_project_name

This template is an example using fork(), execvp(), and wait()

*********************/

int main(int argc, char *argv[])
{
	printf("hello world (pid:%d)\n", (int) getpid());
	int x = 42;
	//int f = open("./fork.output", O_CREAT|O_WRONLY|O_TRUNC, S_IRWXU);


	int rc = fork();



	struct timeval tv;
	gettimeofday(&tv, NULL);

	printf("%ld\n", tv.tv_sec / 60/ 60/24/365);

	

	if (rc < 0) {
		fprintf(stderr, "fork failed bro\n");
		exit(1);
	} else if (rc ==0) {
		raise(SIGSTOP);
		//x = 666;
		printf("hello, I am child (pid:%d)\n", (int) getpid());
		printf("x is %d\n", x);
		//write(f, "hello from child\n", 62);
	} else {
		//int wc = wait(NULL);
		printf("hello, I am parent of %d (pid:%d)\n", rc, (int) getpid());
		printf("x is %d\n", x);
		//write(f, "hello from parent\n", 62);
		waitpid(rc, NULL, WUNTRACED);
		kill(rc, SIGCONT);
	}


	return 0;
}
