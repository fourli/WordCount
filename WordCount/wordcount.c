#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdio.h>

int main(int argc, char *argv[])
{
	char parameter[3];		//存放参数
	FILE *fp;				//文件指针
	char textbuffer[500];	//文本缓冲区
	char n;					//字符缓冲区
	int textlength;			//文本长度
	int charendFlag = 0;	//判断单词是否结束
	int charCount = 0;		//字符计数
	int wordCount = 0;		//单词计数
	int i = 0;

	//打开文件并且判断是否成功
	if ((fp = fopen(argv[2], "rb")) == NULL) {
		printf("Error Filename!\n");
		return -1;
	}

	//缓冲区读取一行文本,并且进行单字符循环遍历计数
	while (fgets(textbuffer, 500, fp) != NULL) {
		textlength = strlen(textbuffer);
		i = 0;
		while (i < textlength) {
			n = textbuffer[i];
			if (n == ' ' || n == ',') {
				if (charendFlag == 0) wordCount++;
				charCount++;
				charendFlag = 1;
			}
			else if(n != '\r'){
				charCount++;
				charendFlag = 0;
			}
			else if (n == '\r') {
				charCount++;
				i++;
				break;
			}
			i++;
		}
		if (charendFlag == 0) wordCount++;
		charendFlag = 1;
	}
	fclose(fp);

	//读取命令函参数控制输出结果
	strncpy(parameter, argv[1], 2);
	if (parameter[1] == 'c') {
		printf("字符数：%d\n", charCount);
	}
	else if (parameter[1] == 'w') {
		printf("单词数：%d\n", wordCount);
	}
	else {
		printf("Error Parameter!");
		return -1;
	}
	
	return 0;
}