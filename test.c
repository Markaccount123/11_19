#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
//strlen 返回的是一个（size_t）unsigned int 类型的数
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
//结果返回的是hehe ，因为3-6 = -3 但是在内存中是以补码的形式进行存储的，返回的应该是一个size_t类型的值电脑认为-3的补码就是原码，所以这是一个很大的数
#include<assert.h>
//strlen的二种实现方式
//①计数器写法
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
//如果这里使用我们的my_strlen这个函数去求上面的my_strlen("abc") - strlen("abcdef") 得到的结果就应该是haha，因为这里我们自己所设定的返回值是int类型

//②递归写法(不创建临时变量，写一个求字符串长度的代码)
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
//①源字符串必须以'\0'结束
//②会将源字符串中的'\0'拷贝到目标空间
//③目标空间必须足够大，以确保能存放源字符串
//④目标空间必须可变
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
//上面的代码不够精简，这样的代码才是最完美的
char* my_strcpy(char* dest, const char* src)
{
	assert(dest != NULL);
	assert(src != NULL);
	char* ret = dest;
	//拷贝src指向的字符串到dest指向的空间，包含'\0'
	while (*dest++ = *src++)
	{
		;
	}
	//返回目的地空间的起始地址
	return ret;
}
int main()
{
	char arr1[] = "abcdefghi";
	char arr2[] = "bit";
	//char arr2[] = {'b','i','t'}; 如果是这种形式进行拷贝，你就会发现他找不到‘\0’，就很有可能会造成越界访问
	my_strcpy(arr1, arr2);
	printf("%s\n", arr1);
	return 0;
}


//strcat(追加字符串函数)
char* my_strcat(char* dest, const char* src)
{
	assert(dest != NULL);
	assert(src != NULL);
	char* ret = dest;
	//1.找到目的字符串的'\0'
	while (*dest != '\0')
	{
		dest++;
	}
	//2.追加
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
	//比较
	while (*str1 == *str2)
	{
		if (*str1 == '\0')
		{
			return 0;  //相等
		}
		str1++;
		str2++;
	}
	//vs编译器下实现的结果
	if (*str1 > *str2)
		return 1; // 大于
	else
		return -1; // 小于
	//gcc编译器下返回的结果
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
找到了你就给我返回查找到的那个字符串的地址，没有找到你就给我返回一个NULL
int main()
{
	char* p1 = "abcdef";
	char* p2 = "def";
	char* ret = strstr(p1, p2);
	if (ret == NULL)
	{
		printf("子串不存在\n");
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
//①strtok函数找到str中的下一个标记，并将其用\0结尾，返回一个指向这个标记的指针（注：strtok函数会改变被操作的字符串，所以在使用strtok函数切分的字符串一般都是临时拷贝的内容并且可修改。）
//②strtok函数的第一个参数不为NULL，函数将找到str中第一个标记，strtok函数将保存它在字符串中的位置
//③strtok函数的第一个参数为NULL，函数将在同一个字符串中被保存的位置开始，查找下一个标记
//int main()
//{
//	char arr[] = "wzy@baidu.com";
//	char* p = "@.";
//	char buf[1024] = { 0 };
//	strcpy(buf, arr);
//	//切割buf中的字符串
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


//strerror(把错误码翻译成我们所认识的)


//void* memcpy(void* dest,const void* src,size_t num)
//size_t num 拷贝过去内容所占大小---单位是字节
//void* ---通用类型指针---无类型指针

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
//	struct S arr3[] = { { "张三", 20 }, { "李四", 30 } };
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
//	//拷贝
//	while (num--)
//	{
//		*(char*)dest = *(char*)src;
//		++(char*)dest;
//		++(char*)src;
//	}
//	return ret;
//}


