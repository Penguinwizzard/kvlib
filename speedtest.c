#include <stdio.h>
#include <stdlib.h>
#include "kvlib.h"

unsigned long load_file(unsigned char** buf, const char* fname, const char* opts, const char* errmsg) {
	FILE* file;
	file = fopen(fname,opts);
	if(file == NULL) {
		printf("%s",errmsg);
		exit(1);
	}
	fseek(file, 0, SEEK_END);
	unsigned long fsize = (unsigned long)ftell(file);
	fseek(file, 0, SEEK_SET);

	(*buf) = (unsigned char*)malloc((size_t)fsize);
	fread(*buf, fsize, 1, file);
	fclose(file);
	return fsize;
}

int main(int argc, char* argv[]) {
	printf("KV Parsing Speed Test\n");
	unsigned char *buf = NULL;
	unsigned long fsize = load_file(&buf, argv[1], "rb", "Could not find kv file\n");
	readKV(buf,(unsigned int)fsize);
}
