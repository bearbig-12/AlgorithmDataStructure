#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main(int argc, char** argv) {
    char* fileName;      // ������ ��ϵǾ��ִ� ������ ���ϸ�, (path ����)

    fileName = argv[1];

    char* pattern = argv[2];

    char Text[512];   // ���Ͽ��� ���� ������ ������ �迭

    FILE* fp;

    fp = fopen(fileName, "r");   // ������ �б���� ����

    if (fp == NULL) {
        printf("�����б⿡ �����Ͽ����ϴ�.\n");
        return 0;
    }

    if (argc < 3) {
        printf("Usage: �������ϸ� �������ϸ� ���Ϲ��ڿ�");
        return 0;
    }

    int patternLength = strlen(pattern);   // ���� ���ڿ��� ����
    int line = 1;
    int Find = 0;
    while (fgets(Text, 512, fp) != NULL) {
        // �о���� ����ȿ� ã�� ���� ���ڿ��� �ִ��� Ȯ���ϰ�
        // ������ �ش� ���ι�ȣ�� �÷���ȣ�� ����ϸ�˴ϴ�.

        int length = strlen(Text);   // ���� ���ڿ��� ���̸� ���Ѵ�.

        for (int i = 0; i < length- patternLength; ++i)
        {
            if (Text[i] == pattern[0])
            {
                Find = 1;
                for (int j = 1; j < patternLength; ++j)
                {
                    if (Text[i + j] == pattern[j])
                    {
                        ++Find;
                    }
                    else
                    {
                        Find = 0;
                        break;
                    }
                }
            }

            if (Find == patternLength)  // ���� ���̿� ��
            {
                printf("line %d: %s", line, Text);
                Find = 0;
                break;
            }
        }
     

        line++;
    }

    fclose(fp);

    return 0;
}