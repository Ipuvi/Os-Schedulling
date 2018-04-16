#include<stdio.h>
#include<conio.h>
#include<unistd.h>
#include<windows.h>
#define MAX 30

int process_f[MAX][4];
int process_s[MAX][4];
int process[2*MAX][4];
int rear = 0;
int front= 0;
int n_f=0,n_s=0,c,np,qt,a=4;
int bursttime=0;

int main()
{
	int a,i;
	char user[20]="qqq",username[20],c;
	char pass[50]={'q','q','q'},pswrd[50];
	printf("\n*******************************Welcome to Query Management System******************************\n");
	printf("\t\t\tPress \n\t\t\t1. Login\n\t\t\t2.Exit...");
	scanf("%d",&a);
	
	if(a!=1)
	{
		printf("\n\n\t\t\t\t\tThank U for Visiting !");
		sleep(1);
		printf("\n\t\t\t\t\t  Have a Nice Day !\n\n");
		exit(0);
	}
	printf("\n\n\tEnter Username : ");
	scanf("%s",username);
	printf("\n\tEnter Password : ");
	i=0;
	while(1)
	{
		c=getch();
		if(c==13)
		break;
		if(c==8)
		{
			if(i>0)
			printf("\b \b");
			i--;
			continue;
		}
		if(i<0)
		i=0;
		printf("*");
		pswrd[i]=c;
		i++;
	}
	if(i>=0)
	pswrd[i]=NULL;
	else
	pswrd[0]=NULL;
	if((user==username)&&(strcmp(pass,pswrd)==0))
	{
		system("cls");
		printf("\nRedirecting...");
		sleep(1);
		system("cls");
}
}
