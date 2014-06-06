#include "stdio.h"
#include "MRI.h"

struct Student
{
	int age;
	char name[10];
	int sex;
};

struct Teacher
{
	int age;
	char name[10];
	int sex;
};

class Calculate
{
public:
	int sum(int a, int b)
	{
		return (int)(a+b);
	}
};

int main()
{
	return 0;
}
