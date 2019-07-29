/*学生信息管理

学生信息管理应用程序要求能够对学生的信息: 	StudentID, Name, Sex, Age, Time of Enrollment（入学时间）,
Gpa（加权平均）, PhoneNo, MailingAddress, 等进行管理。

功能要求：
（1）Create a student list;
（2）Sort according to the StudentID；
（3）Insert a student；//(to the sorted array or the sorted linked list )
（4）Delete a student;
（5）Update a student Info;.
（6）Search a student ;
（7）Display all students;
*（8）Save to the file;		 	//选作
*（9）Open the file；			//选作
（10）exit

设计要求：
（1）设计一个"Welcome Screen"，显示此应用程序的名称、设计人员的名字、设计时间、软件版本等信息；
（2）设计菜单界面，可以选择上述功能；
（3）每项功能完成后，返回菜单界面；
（4）用户可以退出；
（5）遵循良好的编程习惯（注意格式、注释等），雷同和抄袭一律0分；

完成后，提交源程序，并要求独立演示、讲解并回答问题！！！
int StudentID;
int Age;
int PhoneNo;
float Gpa;
char Name;
char Sex;
char TimeofEnrollment;
char MailingAddress；
void display(Student *head)
{
int i=1;
Student *p =NULL;
a = head->next;

while(a!=NULL)
{
printf("StudentID:%d",a->StudentID);
printf("Age:%d",a->Age);
printf("PhoneNo:%d",a->PhoneNo);
printf("Gpa:%d",a->Gpa);
printf("Name:%s",a->Name);
printf("Sec:%c",a->Sex);
printf("TimeofEnrollment:%s",a->TimeofEnrollment);
printf("MailingAddress:%s",a->MailingAddress);
a = a->next;
}

}
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct STUDENT
{
	int StudentID;
	int Age;
	int PhoneNo;
	int Gpa;
	char Name[20];
	char Sex[10];
	char TimeofEnrollment[20];
	char MailingAddress[20];
	struct STUDENT *next;

};
typedef struct STUDENT Student;
//利用结构体定义学生信息//
//void Luru(Student *head);
void Exit();
void Luru(Student *head);
void Sort(Student *head);
void Insert(Student *head);
void Del(Student *head);
void Search(Student *head);
void Update(Student *head);
void Display(Student *head);
/////////////////////////////////
void main()
{
	int m, i = 0;
	Student *head = NULL;
	head = (Student *)malloc(sizeof(Student));


	printf("********************************************\n\n");
	printf("\t学生信息管理\t\n");
	printf("\t制作人：孙峻礁\t\n");
	printf("\t制作时间：2016.1.3\t\n");
	printf("\t软件信息：VC6.0\t\n\n");
	printf("********************************************\n");
	getchar(); system("cls");
	do
	{
		i++;
		printf("1.Create a student list\n2.Sort according to the StudentID\n3.Insert a student\n4.Delete a student\n5.Update a student Info\n6.Search a student\n7.Display all students\n8.exit\n");
		scanf("%d", &m);

		if (i == 1 && m != 1 && m != 8)
			printf("请先录入\n");
		else if (i == 1 && m == 8)
			printf("啥也不用就退出。。。");//若一开始选择退出

		switch (m)
		{
		case 1:
			Luru(head);
			getchar();
			system("cls");
			break;
		case 2:
			Sort(head);
			system("pause");
			system("cls");
			break;
		case 3:
			Insert(head);
			getchar();
			system("cls");
			break;
		case 4:                                //选择列表
			Del(head);
			getchar();
			system("cls");
			break;
		case 5:
			Update(head);
			getchar();
			system("cls");
			break;
		case 6:
			Search(head);
			system("pause");
			getchar();
			system("cls");
			break;
		case 7:
			Display(head);
			system("pause");
			getchar();
			system("cls");
			break;
		case 8:
			free(head);
			Exit();
			break;//第10项
		}


	} while (1);//无限循环
}
////////////////////////////////////
void Luru(Student *head)

{
	int i, n;
	Student *a = NULL;//声明两个指针变量
	Student *c = NULL;

	printf("please enter how many students:");
	scanf("%d", &n);
    getchar();
	system("cls");
	for (i = 0; i<n; i++)
	{
		
		a = (Student*)malloc(sizeof(Student));//给a分配动态内存
		printf("plesase enter the StudentID:");
		scanf("%d", &a->StudentID);
		printf("plesase enter the Age:");
		scanf("%d", &a->Age);
		printf("plesase enter the PhoneNo:");
		scanf("%d", &a->PhoneNo);
		printf("please enter the Gpa:");
		scanf("%d", &a->Gpa);
		printf("plesase enter the Name:");
		scanf("%s", &a->Name);
		printf("plesase enter the Sex(f or m):");
		scanf(" %s", a->Sex);
		printf("plesase enter the TimeofEnrollment（年.月.日）:");
		scanf("%s", &a->TimeofEnrollment);

		printf("plesase enter the MailingAddress:");
		scanf("%s", &a->MailingAddress);
		
		if (i == 0) 
		{
			head->next = a;
		}//链表开头。空置做引子
		else
		{
			c->next = a;//将学生信息录入
		}
		c = a;
	}
	a->next = NULL;//最后

}
//////////////////////////////////
void Exit()
{
	printf("谢谢使用\n");
	exit(0);//强制退出

}

////////////////////////////////////////////////////

void Sort(Student* head)
{
	int i = 0;//中间变量int 
	char k[20];//中间变量char
	Student *a = NULL;
	Student *c = NULL;



	printf("学生信息");
	for (a = head->next; a != NULL; a = a->next)//循环1
	{
		for (c = a->next; c != NULL; c = c->next)//循环2，两个循环同时进行，且c只需要从a之后开始
		{

			if (a->StudentID>c->StudentID)
			{
				i = a->StudentID;
				a->StudentID = c->StudentID;
				c->StudentID = i;

				i = a->Age;
				a->Age = c->Age;
				c->Age = i;

				i = a->PhoneNo;
				a->PhoneNo = c->PhoneNo;
				c->PhoneNo = i;

				i = a->Gpa;
				a->Gpa = c->Gpa;
				c->Gpa = i;

				strcpy(k, a->Name);
				strcpy(a->Name, c->Name);
				strcpy(c->Name, k);

				strcpy(k, a->Sex);
				strcpy(a->Sex, c->Sex);
				strcpy(c->Sex, k);

				strcpy(k, a->TimeofEnrollment);
				strcpy(a->TimeofEnrollment, c->TimeofEnrollment);
				strcpy(c->TimeofEnrollment, k);

				strcpy(k, a->MailingAddress);
				strcpy(a->MailingAddress, c->MailingAddress);
				strcpy(c->MailingAddress, k);
                                                                  //冒泡排序法
			}


		}


	}
	return;

}


///////////////////////////////////////////////////



void Insert(Student *head)
{
	int i, j = 2;
	Student *a, *c, *k;
	a = (Student*)malloc(sizeof(Student));//给a附初始值，确保地方够用//
	printf("哪里插入");
	scanf("%d", &i);
	printf("plesase enter the StudentID:");

	scanf("%d", &a->StudentID);
	printf("plesase enter the Age:");
	scanf("%d", &a->Age);
	printf("plesase enter the PhoneNo:");
	scanf("%d", &a->PhoneNo);
	printf("please enter the Gpa:");
	scanf("%d", &a->Gpa);
	printf("plesase enter the Name:");
	scanf("%s", &a->Name);
	printf("plesase enter the Sex(f or m):");
	scanf(" %s", &a->Sex);
	printf("plesase enter the TimeofEnrollment:");
	scanf("%s", &a->TimeofEnrollment);

	printf("please enter the MailingAddress:");
	scanf("%s", &a->MailingAddress);


	if (i != 1)//先讨论不差在开头的情况//
	{
		c = head->next;//让c有最开头的位置//	 
		do
		{
			if (j == i) //j=2,当插入第二个位置，就插入，不在第二个，继续循环。// 
			{
				k = c->next;//k赋予第二的位置
				c->next = a;//第二的位置给a
				a->next = k;//把k拥有的第二的位置放到a之后//
				break;
			}
			c = c->next;
			j++;

		} while (a != NULL);
	}
	else//当输入1的时候
	{
		c = head->next;
		head->next = a;
		a->next = c;
	}
	return;
}
//////////////////////////////////////////////////
void Del(Student *head)
{
	int i, j = 2;
	Student *a = NULL;
	Student *c = NULL;
	printf("哪里删除：");
	scanf("%d", &i);
	if (i != 1)
	{
		a = head->next;
		do
		{
			if (i == j)
			{
				c = a->next;
				a->next = c->next;//让链表的上一项与下一项链接
			}
			a = a->next;//相当于一个for循环，每次不符合a就指向下一个
			j++;
		} while (a != NULL);
	}
	else
	{
		a = head->next;
		a->next = head->next;//删除1的情况
	}
}

void Search(Student *head)
{
	Student *a = NULL;
	int n;
	a = head->next;
	a = (Student*)malloc(sizeof(Student));
	printf("请输入查找学生ID:");
	scanf("%d", &n);
	for (a = head->next; a!= NULL; a = a->next)//循环来找出Id相符的一点
	{

		if (a->StudentID = n)
		{
			printf("StudentID:%d", a->StudentID);
			printf("\n");
			printf("Age:%d", a->Age);
			printf("\n");
			printf("PhoneNo:%d", a->PhoneNo);
			printf("\n");
			printf("Gpa:%d", a->Gpa);
			printf("\n");
			printf("Name:%s", a->Name);
			printf("\n");
			printf("Sex:%s", a->Sex);
			printf("\n");
			printf("TimeofEnrollment:%s", a->TimeofEnrollment);
			printf("\n");
			printf("MailingAddress:%s", a->MailingAddress);
			printf("\n");
		}
	}
}

void Update(Student *head)
{
	int n;
	Student *a = NULL;
	printf("请输入更新学生ID:");
	scanf("%d", &n);
	for (a = head->next; a != NULL; a = a->next)//同上
	{

		if (a->StudentID = n)
		{

			printf("plesase enter the StudentID:");

			scanf("%d", &a->StudentID);
			printf("plesase enter the Age:");
			scanf("%d", &a->Age);
			printf("plesase enter the PhoneNo:");
			scanf("%d", &a->PhoneNo);
			printf("please enter the Gpa:");
			scanf("%d", &a->Gpa);
			printf("plesase enter the Name:");
			scanf("%s", &a->Name);
			printf("plesase enter the Sex(f or m):");
			scanf(" %s", &a->Sex);
			printf("plesase enter the TimeofEnrollment:");
			scanf("%s", &a->TimeofEnrollment);

			printf("please enter the MailingAddress:");
			scanf("%s", &a->MailingAddress);
			break;
		}
	}
}



void Display(Student *head)
{
	int i = 1;
	Student *a = NULL;
	a = head->next;
	if (head != NULL)
	{

		do
		{

			printf("No.%d\n", i);

			printf("StudentID:%d", a->StudentID);

			printf("\n");
			printf("Age:%d", a->Age);
			printf("\n");
			printf("PhoneNo:%d", a->PhoneNo);
			printf("\n");
			printf("Gpa:%d", a->Gpa);
			printf("\n");
			printf("Name:%s", a->Name);
			printf("\n");
			printf("Sex:%s", a->Sex);
			printf("\n");
			printf("TimeofEnrollment:%s", a->TimeofEnrollment);
			printf("\n");
			printf("MailingAddress:%s", a->MailingAddress);
			printf("\n");
			i++;
			a = a->next;

		} while (a != NULL);
	}
	else;
	return;


}

