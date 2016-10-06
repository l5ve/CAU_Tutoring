#include <stdio.h>
#include <string.h>
#include "stdlib.h"

#define MAX_LENGTH 100000
#define MAX_BUF 10000
	FILE * fp;
	char data[MAX_LENGTH];
	char * tmp_ptr = data;
	char *danu[MAX_BUF], search[MAX_BUF], *jungbok[MAX_BUF];
	int k = 0;
	int check[MAX_BUF], jungboknum[MAX_BUF];

	void change ();
int main() {
	// Variable Declaration

	// Read text data & Put into 'data' array
	// If you want to read extended_data, replace "data.txt" to "extended_data.txt"
	if ((fp = fopen("extended_data.txt", "r")) == NULL) {
		printf("File Open Error!\n");
		system("pause");
		return -1;
	}
	while (fgets(tmp_ptr, MAX_BUF, fp)) {
		tmp_ptr += strlen(tmp_ptr);
	}
	fclose(fp);

	//Implement Requirements
	printf("%s\n\n-----------------------------------------------------------\n", data);

	tmp_ptr = strtok(data, " " "	" "\n");
	//최초 단어 정리
	change();
	k++;
	while ((tmp_ptr = strtok(NULL, " " "	" "\n")))
	{
		//단어 정리
		change();
		k++;
	}
	printf("\n\n\n%");
	while (1)
	{
		int c = 0, jk=0;
		printf("단어의 시작 문자를 입력해주세요(a~z, else): ");
		scanf("%s", search);
		if ('A' <= search[0] && search[0] <= 'Z')
		{
			search[0] += 'a' - 'A';
		}
		if (strcmp(search, "end")==0)
		{
			break;
		}
		else if ('a' > search[0] || search[0] > 'z' || strlen(search) > 1)
		{
			printf("error!\n");
		}
		else
		{
			for (int a = 0; a < k; a++)
			{
				if (strncmp(danu[a], search, 1) == 0)
				{
					jungbok[c] = danu[a];
					c++;
				}
			}
			for (int cor = 0; cor < c; cor++)
			{
				check[cor] = 0;
				jungboknum[cor] = 1;
			}
			for (int cor = 0; cor < c; cor++)
			{
				for (int row = 0; row < c; row++)
				{
					if (strcmp(jungbok[cor], jungbok[row]) == 0&&cor<row)
					{
						check[row] = -1;
						jungboknum[cor]++;
					}
				}
			}
			for (int cor = 0; cor < c; cor++)
			{
				for (int row = 0; row < c; row++)
				{
					for (int letter = 1; letter <= strlen(jungbok[cor]) ; letter++)
					{
						if (jungbok[row][letter] > jungbok[cor][letter] && (check[cor] != -1))
						{
							check[cor]++;
							break;
						}
						else if (jungbok[row][letter] < jungbok[cor][letter] && (check[cor] != -1))
							break;
					}
				}
			}
			for (int cor = k; cor >= 0; cor--)
			{
				for (int row = 0; row < c; row++)
				{
					if (check[row]==cor)
					printf("%s [%d]회 \n", jungbok[row], jungboknum[row]);
				}
			}
		}
		if (jk = 0)
			printf("검색 결과가 없습니다!");
	}
	system("pause");
	return 0;
}
void change ()
{
	for (int letter = 0; letter < strlen(tmp_ptr); letter++)
	if (('a' <= tmp_ptr[letter] && tmp_ptr[letter] <= 'z') || ('0' <= tmp_ptr[letter] && tmp_ptr[letter] <= '9'))
	{
	}
	else if ('A' <= tmp_ptr[letter] && tmp_ptr[letter] <= 'Z')
	{
		tmp_ptr[letter] = tmp_ptr[letter] + 'a' - 'A';
	}
	else
	{
		for (int nlength = letter; nlength <= strlen(tmp_ptr); nlength++)
		{
			if(nlength != strlen(tmp_ptr)-1)
			tmp_ptr[nlength] = tmp_ptr[nlength + 1];
			if (nlength == strlen(tmp_ptr)-1)
			{
				tmp_ptr[nlength] = '\0';
			}
		}
		for (int nlength = letter; nlength <= strlen(tmp_ptr); nlength++)
		{
			if (nlength != strlen(tmp_ptr) - 1)
				tmp_ptr[nlength] = tmp_ptr[nlength + 1];
			if (nlength == strlen(tmp_ptr) - 1)
			{
				tmp_ptr[nlength] = '\0';
			}
		}
	}
	danu[k] = tmp_ptr;
	printf("%s\n", tmp_ptr);
}