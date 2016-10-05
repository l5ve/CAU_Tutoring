#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>
#include<stdlib.h>




#define MAX_LENGTH 100000
#define MAX_BUF 10000

char input[100];
char *charlist[100000];
char *searchlist[100000]; // 검색용 searchlist --> 담으려는것
int	searchnum[100000];

int check[100000] = { 0, };
char *ans[100000];
int ans_num[100000] = { 0, };



int main() {
	// Variable Declaration
	FILE * fp;
	char data[MAX_LENGTH];
	char * tmp_ptr = data;
	char *ptr;//strtok
	char input[100];//질문

	int k = 0;

	// Read text data & Put into 'data' array
	// If you want to read extended_data, replace "data.txt" to "extended_data.txt"
	if ((fp = fopen("extended_data.txt", "r")) == NULL) {
		printf("File Open Error!\n");
		return -1;
	}
	while (fgets(tmp_ptr, MAX_BUF, fp)) {
		tmp_ptr += strlen(tmp_ptr);
	}
	fclose(fp);

	ptr = strtok(data, "	 (),.?-;:\"\n");

	while (ptr != NULL) {
		charlist[k] = ptr;
		ptr = strtok(NULL, "	 (),.?-;:\"\n");
		k++;
	}

	for (int i = 0; i < k; i++) {
		if (charlist[i][0] >= 'A' && charlist[i][0] <= 'Z') {
			charlist[i][0] -= 'A' - 'a';
		}
	}

	while (1) {
		
		int a = 0;
		int p = 0;
		for (int i = 0; i < MAX_LENGTH; i++) {
			check[i] = 0;
			ans[i] = 0;
			ans_num[i] = 0;
		}// initialize


		printf("단어의 시작 문자를 입력해주세요.(a~z), else, end : ");
		scanf("%s", input);
		if ((strlen(input) == 1 && (input[0] >= 'a' && input[0] <= 'z'))) {
			printf("%s 로 시작하는 단어 리스트입니다\n", input);
			
			for (int i = 0; i < k; i++) {
				if (input[0] == charlist[i][0]) {
					searchlist[a] = charlist[i];
					a++;
				}
			}


			for (int i = 0; i < a - 1; i++) {

				for (int j = i; j < a; j++) {
					if (check[j] == 0 && !strcmp(searchlist[i], searchlist[j])) {
						ans[p] = searchlist[i];
						ans_num[p]++;
						check[j] = -1;
					}
				}
				p++;
			}
			if (p== 0) {
				printf("해당 문자로 시작하는 단어가 없습니다\n");
			}


			for (int i = 0; i < p - 1; i++) {
				for (int j = 0; j < p - 1; j++) {
					int temp = ans_num[0];

					if (ans_num[j] < ans_num[j + 1])
					{
						temp = ans_num[j];
						ans_num[j] = ans_num[j + 1];
						ans_num[j + 1] = temp;

					}
				}
			}
			int count = 0;
			for (int i = 0; i < p; i++) {
				
				if (ans[i] != NULL) {
					if (ans_num[i] == 0) {
						ans_num[i] = 1;
					}
					count++;
					printf("[%2d] %s %d회\n",count, ans[i], ans_num[i]);
					
				}
		
			}

		}
		else if (!strcmp(input, "else")) {
			printf("Non-Alphabet 으로 시작하는 단어 리스트 입니다 \n");
			for (int i = 0; i < k; i++) {
				if (charlist[i][0] >= '0' && charlist[i][0] <= '9') {
					printf("%s\n", charlist[i]);
				}
			}

		}
		else if (!strcmp(input, "end")) {
			printf("종료\n");
			break;
		}
		else {
			;
		}
	}

	return 0;

	}
