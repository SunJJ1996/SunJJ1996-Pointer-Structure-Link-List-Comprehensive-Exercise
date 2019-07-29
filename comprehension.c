/*ѧ����Ϣ����

ѧ����Ϣ����Ӧ�ó���Ҫ���ܹ���ѧ������Ϣ: 	StudentID, Name, Sex, Age, Time of Enrollment����ѧʱ�䣩,
Gpa����Ȩƽ����, PhoneNo, MailingAddress, �Ƚ��й���

����Ҫ��
��1��Create a student list;
��2��Sort according to the StudentID��
��3��Insert a student��//(to the sorted array or the sorted linked list )
��4��Delete a student;
��5��Update a student Info;.
��6��Search a student ;
��7��Display all students;
*��8��Save to the file;		 	//ѡ��
*��9��Open the file��			//ѡ��
��10��exit

���Ҫ��
��1�����һ��"Welcome Screen"����ʾ��Ӧ�ó�������ơ������Ա�����֡����ʱ�䡢����汾����Ϣ��
��2����Ʋ˵����棬����ѡ���������ܣ�
��3��ÿ�����ɺ󣬷��ز˵����棻
��4���û������˳���
��5����ѭ���õı��ϰ�ߣ�ע���ʽ��ע�͵ȣ�����ͬ�ͳ�Ϯһ��0�֣�

��ɺ��ύԴ���򣬲�Ҫ�������ʾ�����Ⲣ�ش����⣡����
int StudentID;
int Age;
int PhoneNo;
float Gpa;
char Name;
char Sex;
char TimeofEnrollment;
char MailingAddress��
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
//���ýṹ�嶨��ѧ����Ϣ//
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
	printf("\tѧ����Ϣ����\t\n");
	printf("\t�����ˣ������\t\n");
	printf("\t����ʱ�䣺2016.1.3\t\n");
	printf("\t�����Ϣ��VC6.0\t\n\n");
	printf("********************************************\n");
	getchar(); system("cls");
	do
	{
		i++;
		printf("1.Create a student list\n2.Sort according to the StudentID\n3.Insert a student\n4.Delete a student\n5.Update a student Info\n6.Search a student\n7.Display all students\n8.exit\n");
		scanf("%d", &m);

		if (i == 1 && m != 1 && m != 8)
			printf("����¼��\n");
		else if (i == 1 && m == 8)
			printf("ɶҲ���þ��˳�������");//��һ��ʼѡ���˳�

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
		case 4:                                //ѡ���б�
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
			break;//��10��
		}


	} while (1);//����ѭ��
}
////////////////////////////////////
void Luru(Student *head)

{
	int i, n;
	Student *a = NULL;//��������ָ�����
	Student *c = NULL;

	printf("please enter how many students:");
	scanf("%d", &n);
    getchar();
	system("cls");
	for (i = 0; i<n; i++)
	{
		
		a = (Student*)malloc(sizeof(Student));//��a���䶯̬�ڴ�
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
		printf("plesase enter the TimeofEnrollment����.��.�գ�:");
		scanf("%s", &a->TimeofEnrollment);

		printf("plesase enter the MailingAddress:");
		scanf("%s", &a->MailingAddress);
		
		if (i == 0) 
		{
			head->next = a;
		}//����ͷ������������
		else
		{
			c->next = a;//��ѧ����Ϣ¼��
		}
		c = a;
	}
	a->next = NULL;//���

}
//////////////////////////////////
void Exit()
{
	printf("ллʹ��\n");
	exit(0);//ǿ���˳�

}

////////////////////////////////////////////////////

void Sort(Student* head)
{
	int i = 0;//�м����int 
	char k[20];//�м����char
	Student *a = NULL;
	Student *c = NULL;



	printf("ѧ����Ϣ");
	for (a = head->next; a != NULL; a = a->next)//ѭ��1
	{
		for (c = a->next; c != NULL; c = c->next)//ѭ��2������ѭ��ͬʱ���У���cֻ��Ҫ��a֮��ʼ
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
                                                                  //ð������
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
	a = (Student*)malloc(sizeof(Student));//��a����ʼֵ��ȷ���ط�����//
	printf("�������");
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


	if (i != 1)//�����۲����ڿ�ͷ�����//
	{
		c = head->next;//��c���ͷ��λ��//	 
		do
		{
			if (j == i) //j=2,������ڶ���λ�ã��Ͳ��룬���ڵڶ���������ѭ����// 
			{
				k = c->next;//k����ڶ���λ��
				c->next = a;//�ڶ���λ�ø�a
				a->next = k;//��kӵ�еĵڶ���λ�÷ŵ�a֮��//
				break;
			}
			c = c->next;
			j++;

		} while (a != NULL);
	}
	else//������1��ʱ��
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
	printf("����ɾ����");
	scanf("%d", &i);
	if (i != 1)
	{
		a = head->next;
		do
		{
			if (i == j)
			{
				c = a->next;
				a->next = c->next;//���������һ������һ������
			}
			a = a->next;//�൱��һ��forѭ����ÿ�β�����a��ָ����һ��
			j++;
		} while (a != NULL);
	}
	else
	{
		a = head->next;
		a->next = head->next;//ɾ��1�����
	}
}

void Search(Student *head)
{
	Student *a = NULL;
	int n;
	a = head->next;
	a = (Student*)malloc(sizeof(Student));
	printf("���������ѧ��ID:");
	scanf("%d", &n);
	for (a = head->next; a!= NULL; a = a->next)//ѭ�����ҳ�Id�����һ��
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
	printf("���������ѧ��ID:");
	scanf("%d", &n);
	for (a = head->next; a != NULL; a = a->next)//ͬ��
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

