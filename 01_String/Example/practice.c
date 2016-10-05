#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 100000
#define MAX_BUF 10000

int main () {
	// Variable Declaration
	FILE * fp;
	char data[MAX_LENGTH];
	char * tmp_ptr = data;
	char * word[MAX_BUF];
	char input[10];
	int word_num, output, i;

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

	//Convert upper case to lower case
	for (i = 0; i < strlen(data); i++) {
		if (data[i] >= 'A' && data[i] <= 'Z') {
			data[i] -= 'A' - 'a';
		}
	}

	//Tokenize data stream
	word[0] = strtok(data, " ");
	for (i = 1; (word[i] = strtok(NULL, " ")) != NULL; i++);
	word_num = i;

	printf("단어의 시작 문자를 입력해주세요 (a ~ z, else) : ");
	fgets(input, 10, stdin);

	if (strlen(input) == 1 && (input[0] >= 'a' && input[0] <= 'z')) {
		for (output = 0, i = 0; i < word_num; i++) {
			if (word[i][0] == input[0]) {
				output++;
			}
		}
		printf("%c 로 시작하는 단어의 개수는 %d개입니다.\n", input[0], output);
	} else if (strcmp(input, "else")) {
		for (output = 0, i = 0; i < word_num; i++) {
			if (word[i][0] < 'a' || word[i][0] > 'z') {
				output++;
			}
		}
		printf("non-alphanet 으로 시작하는 단어의 개수는 %d개입니다.\n", output);
	} else if (strcmp(input, "end")) {
		printf("프로그램을 종료합니다.\n");
		return 0;
	}

	return 0;
}