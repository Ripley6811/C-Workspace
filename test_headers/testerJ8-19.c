#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "extern1.h"
#include "murky.h"


void readEntireFile();
void readAndVerify();


int main(int argc, char *argv[]) {
	// argc = number of items typed at command prompt
	// argv = array of strings of items typed. Alternatively use **argv or *argv[]
	printf("PROGRAM NAME: '%s'\n", argv[0]);
	printf("OTHER: '%s'\n", argv[1]);
	printf("OTHER: '%i'\n", MAX_FOOS);
	printf("OTHER: '%i'\n", BUST);
	printf("OTHER: '%i'\n", fuzz(3));
	srand(time(NULL));
	printf("OTHER: '%i'\n", rand() % 50);
	double num;
	printf("Goodbye world\n");

	int size = 15;
	int *pointerInt;
	char *letter;
	double *price;

	pointerInt = &size;

	printf("Address %p contains %d.\n", (void *) pointerInt, *pointerInt);


	int data[] = {15, 20, 30, 45, 60, 80};
	int *ptr = data;
	printf("data[] starts at address");

	int numElements = sizeof(data) / sizeof(int);
	printf("elements: %i\n", numElements);

	for(int i=0; i<numElements; i++) {
		printf("Address %p \n", (void *) ptr);
		ptr++;
	}

	readEntireFile();

	readAndVerify();


	return(0);
}


void readEntireFile() {
	int ch;
	FILE *fp;
	fp = fopen("message", "r");
	ch = getc(fp);
	while (ch != EOF) {
		putchar(ch);
		ch = getc(fp);
	}
	fclose(fp);
}

void readAndVerify() {
	int ch;

	FILE *fp;
	char messageToWrite[] = "This message will be written to file";
	char textBuffer[30];

	fp = fopen("message2", "w+");
	fwrite(messageToWrite, strlen(messageToWrite)+1, 1, fp);

	//fputs is another option

	fseek(fp, SEEK_SET, 0);

	fread(textBuffer, strlen(messageToWrite)+1, 1, fp);

	fclose(fp);
}