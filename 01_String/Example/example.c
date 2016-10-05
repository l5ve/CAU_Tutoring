#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 100000
#define MAX_BUF 10000

int main () {
	// Variable Declaration
	FILE * fp;
	char data[MAX_LENGTH];
	char * tmp_ptr = data;

	// Read text data & Put into 'data' array
	// If you want to read extended_data, replace "data.txt" to "extended_data.txt"
	if ((fp = fopen("data.txt", "r")) == NULL) {
		printf("File Open Error!\n");
		return -1;
	}
	while (fgets(tmp_ptr, MAX_BUF, fp)) {
		tmp_ptr += strlen(tmp_ptr);
	}
	fclose(fp);

	//Implement Requirements
	printf("%s\n", data);

	return 0;
}