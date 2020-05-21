#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdio.h>

int main(int argc, char *argv[])
{
	char parameter[3];		//��Ų���
	FILE *fp;				//�ļ�ָ��
	char textbuffer[500];	//�ı�������
	char n;					//�ַ�������
	int textlength;			//�ı�����
	int charendFlag = 0;	//�жϵ����Ƿ����
	int charCount = 0;		//�ַ�����
	int wordCount = 0;		//���ʼ���
	int i = 0;

	//���ļ������ж��Ƿ�ɹ�
	if ((fp = fopen(argv[2], "rb")) == NULL) {
		printf("Error Filename!\n");
		return -1;
	}

	//��������ȡһ���ı�,���ҽ��е��ַ�ѭ����������
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

	//��ȡ�����������������
	strncpy(parameter, argv[1], 2);
	if (parameter[1] == 'c') {
		printf("�ַ�����%d\n", charCount);
	}
	else if (parameter[1] == 'w') {
		printf("��������%d\n", wordCount);
	}
	else {
		printf("Error Parameter!");
		return -1;
	}
	
	return 0;
}