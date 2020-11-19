#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
//strlen ���ص���һ����size_t��unsigned int ���͵���
int main()
{
	if (strlen("abc") - strlen("abcdef") > 0)
	{
		printf("hehe\n");
	}
	else
	{
		printf("haha\n");
	}
	return 0;
}
//������ص���hehe ����Ϊ3-6 = -3 �������ڴ������Բ������ʽ���д洢�ģ����ص�Ӧ����һ��size_t���͵�ֵ������Ϊ-3�Ĳ������ԭ�룬��������һ���ܴ����
#include<assert.h>
//strlen�Ķ���ʵ�ַ�ʽ
//�ټ�����д��
int my_strlen(const char* str)
{
	int count = 0;
	assert(str != NULL);
	while (*str != '\0')
	{
		count++;
		str++;
	}
	return count;
}
//�������ʹ�����ǵ�my_strlen�������ȥ�������my_strlen("abc") - strlen("abcdef") �õ��Ľ����Ӧ����haha����Ϊ���������Լ����趨�ķ���ֵ��int����

//�ڵݹ�д��(��������ʱ������дһ�����ַ������ȵĴ���)
int my_strlen(const char* str)
{
	if (*str == '\0')
	{
		return 0;
	}
	else
	{
		return 1 + my_strlen(str + 1);
	}
}

//strcpy
//��Դ�ַ���������'\0'����
//�ڻὫԴ�ַ����е�'\0'������Ŀ��ռ�
//��Ŀ��ռ�����㹻����ȷ���ܴ��Դ�ַ���
//��Ŀ��ռ����ɱ�
char* my_strcpy(char* dest, const char* src)
{
	assert(dest != NULL);
	assert(src != NULL);
	char* ret = dest;
	while (*src != '\0')
	{
		*dest = *src;
		dest++;
		src++;
	}
	return ret;
}
//����Ĵ��벻�����������Ĵ��������������
char* my_strcpy(char* dest, const char* src)
{
	assert(dest != NULL);
	assert(src != NULL);
	char* ret = dest;
	//����srcָ����ַ�����destָ��Ŀռ䣬����'\0'
	while (*dest++ = *src++)
	{
		;
	}
	//����Ŀ�ĵؿռ����ʼ��ַ
	return ret;
}
int main()
{
	char arr1[] = "abcdefghi";
	char arr2[] = "bit";
	//char arr2[] = {'b','i','t'}; �����������ʽ���п�������ͻᷢ�����Ҳ�����\0�����ͺ��п��ܻ����Խ�����
	my_strcpy(arr1, arr2);
	printf("%s\n", arr1);
	return 0;
}


//strcat(׷���ַ�������)
char* my_strcat(char* dest, const char* src)
{
	assert(dest != NULL);
	assert(src != NULL);
	char* ret = dest;
	//1.�ҵ�Ŀ���ַ�����'\0'
	while (*dest != '\0')
	{
		dest++;
	}
	//2.׷��
	while (*dest++ = *src++)
	{
		;
	}
	return ret;
}
int main()
{
	char arr1[30] = "hello";
	char arr2[] = "world";
	strcat(arr1, arr2);
	printf("%s\n", arr1);
	return 0;
}


//strcmp
int my_strcmp(const char* str1, const char* str2)
{
	assert(str1 != NULL); 
	assert(str2 != NULL);
	//�Ƚ�
	while (*str1 == *str2)
	{
		if (*str1 == '\0')
		{
			return 0;  //���
		}
		str1++;
		str2++;
	}
	//vs��������ʵ�ֵĽ��
	if (*str1 > *str2)
		return 1; // ����
	else
		return -1; // С��
	//gcc�������·��صĽ��
	//return (*str1 - *str2);
}
int main()
{
	char* p1 = "abcdef";
	char* p2 = "abcqwe";
	int ret = my_strcmp(p1, p2);
	printf("ret = %d\n", ret);
	return 0;
}


//strstr
�ҵ�����͸��ҷ��ز��ҵ����Ǹ��ַ����ĵ�ַ��û���ҵ���͸��ҷ���һ��NULL
int main()
{
	char* p1 = "abcdef";
	char* p2 = "def";
	char* ret = strstr(p1, p2);
	if (ret == NULL)
	{
		printf("�Ӵ�������\n");
	}
	else
	{
		printf("%s\n", ret);
	}
	return 0;
}

char* strstr(const char* p1, const char* p2)
{
	assert(p1 != NULL);
	assert(p2 != NULL);
}






//
//
//strtok
//��strtok�����ҵ�str�е���һ����ǣ���������\0��β������һ��ָ�������ǵ�ָ�루ע��strtok������ı䱻�������ַ�����������ʹ��strtok�����зֵ��ַ���һ�㶼����ʱ���������ݲ��ҿ��޸ġ���
//��strtok�����ĵ�һ��������ΪNULL���������ҵ�str�е�һ����ǣ�strtok���������������ַ����е�λ��
//��strtok�����ĵ�һ������ΪNULL����������ͬһ���ַ����б������λ�ÿ�ʼ��������һ�����
//int main()
//{
//	char arr[] = "wzy@baidu.com";
//	char* p = "@.";
//	char buf[1024] = { 0 };
//	strcpy(buf, arr);
//	//�и�buf�е��ַ���
//	char* ret = strtok(arr,p);
//	printf("%s\n", ret);
//	
//	ret = strtok(NULL, p);
//	printf("%s\n", ret);
//	
//	ret = strtok(NULL, p);
//	printf("%s\n", ret);
//	return 0;
//}


//strerror(�Ѵ����뷭�����������ʶ��)


//void* memcpy(void* dest,const void* src,size_t num)
//size_t num ������ȥ������ռ��С---��λ���ֽ�
//void* ---ͨ������ָ��---������ָ��

//struct S
//{
//	char name[20];
//	int age;
//};
//int main()
//{
//	int arr1[] = { 1,2, 3, 4, 5 };
//	int arr2[5] = { 0 };
//	memcpy(arr2, arr1, sizeof(arr1));
//	struct S arr3[] = { { "����", 20 }, { "����", 30 } };
//	struct S arr4[] = { 0 };
//	memcpy(arr4, arr3, sizeof(arr3));
//	return 0;
//}

//#include<assert.h>
//void* memcpy(void* dest, const void* src, size_t num)
//{
//	void* ret = dest;
//	assert(dest != NULL);
//	assert(src != NULL);
//	//����
//	while (num--)
//	{
//		*(char*)dest = *(char*)src;
//		++(char*)dest;
//		++(char*)src;
//	}
//	return ret;
//}


