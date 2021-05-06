#define _CRT_SECURE_NO_WARING
#include <stdio.h>
#include <string.h>
#include <assert.h>

//结构体传参的时候，要传结构体的地址

struct S
{
	int a;
	char c;
	double d;
};

void Init(struct S* ps)
{
	ps -> a = 100;
	ps -> c ='w';
	ps -> d = 3.14;
}
//传值
void Print1(struct S tmp)
{
	printf("%d %c %lf\n", tmp.a, tmp.c, tmp.d);
}
//传址 -> 这种更好
void Print2(struct S* ps)
{
	printf("%d %c %lf\n", ps->a, ps->c, ps->d);
}

int main()
{
	struct S s = { 0 };
	//对s进行传参
	Init(&s);
	Print1(s);
	Print2(&s);

	/*struct S s;
	s.a = 100;
	s.c = 'w';
	s.d = 3.14;
	printf("%d\n", s.a);*/
	return 0;
}


