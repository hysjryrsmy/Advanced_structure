#define _CRT_SECURE_NO_WARING
#include <stdio.h>
#include <string.h>
#include <assert.h>


//自定义类型： 结构体、枚举、联合

// 结构体：结构是一些值的集合，这些值成为成员变量。结构的每个成员可以是不同类型的变量



//声明一个结构体类型
//声明一个学生类型，是想过学生类型来创建学生变量（对象）
//描述学生： 属性 - 名字 +电话 + 性别+ 年龄

//struct Stu
//{
//	char name[20];//名字
//	char tele[12];//电话
//	char sex[10]; //性别
//	int age;
//}s4, s5, s6; //全局变量
//
//struct Stu s3; //全局变量
//
//int main()
//{
//	//创建的结构体变量 
//	struct Stu s1;
//	struct Stu s2;
//	return 0;
//}


//结构体的自引用
//struct Node
//{
//	int data;
//	struct Node* next;
//};
//
//int main()
//{
//	sizeof(struct Node);
//	return 0;
//}



//struct T
//{
//	double weight;
//	short age;
//};
//struct S
//{
//	char c;
//	struct T st;
//	int a;
//	double d;
//	char arr[20];
//};
//int main()
//{
//	//struct S s = { 'c', 100, 3.14,"hello bit" };
//	struct S s = { 'c',{55.6, 30}, 100, 3.14,"hello bit" };
//	printf("%c %d %lf %s\n", s.c, s.a, s.d, s.arr);
//	printf("%lf\n", s.st.weight);
//	return 0;
//}



//结构体内存对齐 （结构体的内存对齐是拿空间来换取时间的做法）
//设计结构体的时候，让占用空间小的成员尽量集中在一起


// 结构体的对齐规则
// 1.第一个成员与结构体变量偏移量为0的地址处
// 2.其他成员变量要对齐到某个数字（对齐数）的整数倍的地址处
// 对齐数 = 编译器默认的一个对齐数与该成员大小的较小值
// vs中默认的值为8
// 3.结构体总大小为最大对齐数（每个成员变量都有一个对齐数）的整数倍
// 4.如果嵌套了结构体的情况，嵌套的结构体对齐到自己的最大对齐数的整数倍处，结构体的整体大小就是所有最大对齐数（含嵌套结构体的对齐数）的整数倍
// 
// 
//

//struct S1 
//{
//	char c1;
//	int a;
//	char c2;
//};
//
//struct S2
//{
//	char c1;
//	char c2;
//	int a;
//};
//
//struct s3
//{
//	double d;
//	char c;
//	int i;
//};
//
//struct s4
//{
//	char c1;
//	struct s3 s3;
//	double d;
//};
//
//int main()
//{
//	struct S1 s1 = { 0 };
//	printf("%d\n", sizeof(s1));
//	struct S2 s2 = { 0 };
//	printf("%d\n", sizeof(s2));
//	
//	return 0;
//}


//修改默认对齐数 ：#pragma -> 可以改变默认的对齐数

//设置默认对齐数为4
//#pragma pack(4)
//struct S
//{
//	char c1;  //1
//	// 浪费7  -> 3
//	double d; //8 4 4
//}; 
//#pragma pack()
//取消设置的默认对齐数


//设置默认对齐数为4
//#pragma pack(1)
//struct S
//{
//	char c1;  //1
//	// 
//	double d; 
//};
//#pragma pack()
////取消设置的默认对齐数
//
//int main()
//{
//	struct S s;
//	printf("%d\n", sizeof(s));
//	return 0;
//}



//百度笔试题：写一个宏，计算结构体中某变量相当于首地址的偏移，并给出说明
#include <stddef.h>
struct S
{
	char c;
	int i;
	double d;
};

int main()
{
	//offsetof(); //offsetof：偏移量。计算结构体成员相对于结构体起始位置偏移量是多少
	            //size_t offsetof(structName, memberName);
	printf("%d\n", offsetof(struct S, c));   
	printf("%d\n", offsetof(struct S, i));
	printf("%d\n", offsetof(struct S, d));
	return 0;
}