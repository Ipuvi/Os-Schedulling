#include<stdio.h>
#include<conio.h>
#include<stdbool.h>
#define MAX 30
int process_f[MAX][4];
int process_s[MAX][4];
int process[2*MAX][4];
int rear = 0;
int front= 0;
int n_f=0,n_s=0,c,np,qt;
int bursttime=0;

int main()
{
int choice;

        printf("1.Insert process to queue \n");
        printf("2.Display all processes of queue \n");
        printf("3.Quit \n");
        printf("Enter your choice : ");
        scanf("%d", &choice);
        switch (choice)
        {
            case 1:
            insert();
            break;
            case 2:
            display();
            break;
    //        case 3:
  //          exit(0);
            default:
            printf("Wrong choice \n");
        } /*End of switch*/
 //   } /*End of while*/
    getch();
    return(0);
} /*End of main()*/

sort()
{
	int i,j,temp;
	for(i=0;i<n_f+n_s;i++)
	for(j=i+1;j<n_f+n_s;j++)
	if((process[i][2]>process[j][2]))
	{
		temp=process[i][0];
	    process[i][0]=process[j][0];
		process[j][0]=temp;
		
		temp=process[i][1];
	    process[i][1]=process[j][1];
		process[j][1]=temp;
		
		temp=process[i][2];
	    process[i][2]=process[j][2];
		process[j][2]=temp;
		
		temp=process[i][3];
		process[i][3]=process[j][3];
		process[j][3]=temp;
	}
	
	for(i=0;i<n_f+n_s;i++)
	for(j=i+1;j<n_f+n_s;j++)
	if(process[i][2]==process[j][2])
	if(process[i][3]>process[j][3])
	{
		
		temp=process[i][0];
	    process[i][0]=process[j][0];
		process[j][0]=temp;
		
		temp=process[i][1];
	    process[i][1]=process[j][1];
		process[j][1]=temp;
		
		temp=process[i][2];
	    process[i][2]=process[j][2];
		process[j][2]=temp;
		
		temp=process[i][3];
		process[i][3]=process[j][3];
		process[j][3]=temp;
	}
}
/*End of Sort() */


FindWait_Time(int np,int wt[np],int quantum)
{
	int i,rem_bt[np];
	for(i=0;i<np;i++)
	{
		rem_bt[i]=process[i][1];
	}
	int t=0;
	while(1)
	{
		int flag = 1 ;
		for(i=0;i<np;i++)
		{
			if(rem_bt[i]>0)
			{
			flag=0;
			if(rem_bt[i]>quantum)
			{
				t+=quantum;
				rem_bt[i]-=quantum;
			}
			else
			{
				t=t+rem_bt[i];
				wt[i]=t-process[i][1];
				rem_bt[i]=0;
			}
			}
		}
		if(flag==1)
		break;
	}
}
/* End of Waiting Time Calculation....*/

FindTurnAround_Time(int np,int wt[np],int quantum,int tat[np])
{
	int i;
	for(i=0;i<np;i++)
	{
		tat[i]=process[i][1]+wt[i];
	}
}
/*End of TurnAround Time Calcution....*/

Findavg_Time(int np,int quantum)
{
	int wt[np],tat[np],total_wt=0,total_tat=0,i;
	FindWait_Time(np,wt,quantum);
	FindTurnAround_Time(np,wt,quantum,tat);
	printf("\nProcess\tBurst Time\tWaiting Time\tTurn Around Time\n");
	for(i=0;i<np;i++)
	{
		total_wt=total_wt+(wt[i]-process[i][2]);
		total_tat=total_tat+tat[i];
		printf(" P%d\t\t%d\t\t%d\t\t%d\n",process[i][0],process[i][1],wt[i]-process[i][2],tat[i]);
	}
	
	printf("Average Waiting time: %f\n",(float)total_wt/(float)np);
	printf("Average Turn Around Time: %f\n",(float)total_tat/(float)np);
	
}
/*End of Calculation of Average time....*/

insert()
{
	int i,p,rearf=0,rears=0,np;
    printf("\nFor Faculty process press 1 and for student press 0: \n");
	scanf("%d",&p);
    int add_p,add_bt,add_at;
    if(p==1)
    {
    if (rearf == MAX && front==0)
    printf("Queue Overflow \n");
    else
    {
        printf("Enter the no. of Faculty processes: \n");
        scanf("%d",&n_f);
        printf("Insert the process in queue, its burst time and arrival time : \n");
        while(rearf<n_f)
        {
        scanf("%d", &process_f[rearf][0]);
		scanf("%d",&process_f[rearf][1]);
		scanf("%d", &process_f[rearf][2]);
        /*process_f[rearf][0] = add_p;
        process_f[rearf][1] = add_bt;
        process_f[rearf][2] = add_at;*/
        process_f[rearf][3] = 0;
        rearf = rearf + 1;
        bursttime=bursttime+process_f[rearf][1];
        }
        for(i=n_s;i<n_f+n_s;i++)
    	{
    		
    		process[i][0]=process_f[i-n_s][0];
    		process[i][1]=process_f[i-n_s][1];
    		process[i][2]=process_f[i-n_s][2];
    		process[i][3]=process_f[i-n_s][3];
    		}
    		//sort();
    	if(bursttime>120)
    	{
    		printf("Time limit exceeded....Cant handle anymore processes today...");
    		goto y;
		}
        
    }
	}
    else
    {
    if (rears == MAX && front == 0)
    printf("Queue Overflow \n");
    else
    {
        //if (front == - 1) /*If queue is initially empty */
        //front = 0;
        printf("Enter the no. of Student processes: ");
        scanf("%d",&n_s);
        printf("Insert the process in queue, its burst time and arrival time : \n");
  
        while(rears<n_s)
        {
        scanf("%d", &process_s[rears][0]);
		scanf("%d",&process_s[rears][1]);
		scanf("%d", &process_s[rears][2]);
      /*  process_s[rears][0] = add_p;
        process_s[rears][1] = add_bt;
        process_s[rears][2] = add_at;*/
        process_s[rears][3] = 1;
        rears = rears + 1;
        bursttime=bursttime+process_s[rears][1];
        }
        for(i=n_f;i<n_f+n_s;i++)
		{
		    process[i][0]=process_s[i-n_f][0];
		    process[i][1]=process_s[i-n_f][1];
		    process[i][2]=process_s[i-n_f][2];
		    process[i][3]=process_s[i-n_f][3];
		    }
		    //sort();
		if(bursttime>120)
    	{
    		printf("Time limit exceeded....Cant handle anymore processes today...");
    		goto y;
		}
    }
	}
	

y:    printf("Press 1 to enter more processes to the queue else press 0 to stop adding and continue: ");
    scanf("%d",&c);
    if(c==1)
    insert();
    else
    {
    	display();
    	np=n_f+n_s;
    	qt=120/np;
    	Findavg_Time(np,qt);
    	
	}
 
	} /*End of insert()*/



display()
{
	sort();
//	qt=bursttime/(n_f+n_s);
    int i;
    if (front == - 1)
        printf("Queue is empty \n");
    else
    {
        printf("Queue is : \n");
        printf("Process\tBurst Time\tArrival Time\tPriority\n");
        for (i = 0; i < n_f+n_s; i++)
            printf("%d\t\t %d\t\t %d\t\t %d\n", process[i][0],process[i][1],process[i][2],process[i][3]);
        printf("\n");
    }
} /*End of display() */


