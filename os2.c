#include<stdio.h> 
int main() 
{ 
  int count,j=0,n,time,remain,tq1,tq2; 
  int wt[10],tat[10],at[10],burst[10],rt[10],t[10];
  int totalturnaroundtime=0,totalwaitingtime=0;
  float avgtat=0,avgwt=0; 
  int i,m,k=0;
  int max,l;
  printf("Enter Total Process:\t \n"); 
  scanf("%d",&n); 
  remain=n; 
  for(i=0;i<n;i++) 
  { 
    printf("Enter Arrival Time(ascending order) and Burst Time for Process P[%d]:\n",i+1); 
    scanf("%d",&at[i]); 
    scanf("%d",&burst[i]); 
    rt[i]=burst[i]; 
  } 
  time=at[0]; 
  printf("given 3 iterations enter one by one\n");
  printf("Enter Time Quantum: for 1st iteration\t\n");//for 1st iteration time quantum is 6
  scanf("%d",&tq1); 
 	for(i=0;i<n;i++){
		if(at[i]<=time && rt[i]!=0)
		{
			printf("the process P[%d] is running at present\n",i+1);
			rt[i] -=tq1;
			time+=tq1;
			if(rt[i]<=0)
			{
				printf("the process P[%d] is completed at 1st iteration \n",i+1);
				t[i]=time;
				rt[i]=0;
				tat[i]=time-burst[i];
				wt[i]=tat[i]-at[i];
				printf("%d\t%d\t",tat[i],wt[i]);
			}
		}
	}
	printf("Enter Time Quantum: for 2nd iteration\t\n");//for 2nd iteration time quantum is 10
  scanf("%d",&tq2);
  for(i=0;i<n;i++)
  {
		if(at[i]<=time && rt[i]!=0)
		{
			printf("the process P[%d] is running at present\n",i+1);
			rt[i]-=tq2;
			time+=tq2;
			if(rt[i]<=0)
			{
				printf("the process P[%d] is completed at 2nd iteration\n",i+1);
				t[i]=time;
				rt[i]=0;
					tat[i]=time-burst[i];
				wt[i]=tat[i]-at[i];	
			}
		}	
	} 
	printf("iteration for max burst time\n");
	for(i=0;i<n;i++)
	{
		if(rt[i]>0)
		{
			max=rt[i];
		}
	}
	printf("burst time max is %d\n",max);
	if(max!=0){
		for(j=0;j<n;j++)
		{
			m=0;
			l=0;
			for(i=0;i<n;i++)
			{
				if(rt[i]>=max && rt[i]>0)
				{
					max = rt[i];
					l=i;
				}
				
			}
			 
			if(max!=0)
			{	
			m=l;		
			printf("the process P[%d]   having max burst time %d is running at present\n",m+1,rt[l]);
			time+=rt[l];
			rt[l]=0;
			printf("the process P[%d] is completed at 3rd iteration\n",m+1);
			t[l]=time;
				tat[l]=time-burst[l];
				wt[l]=tat[l]-at[l];
	    	for(k=0;k<n;k++)
     	     {
	     	    if(rt[k]>0)
	    	   {
			      max=rt[k];
	    	   }
	    	   else
	    	   {
	    	   	max=0;
			   }
    	     }	
			 printf("next max is %d",max);
	}
		}
	}
	else{
		printf("all the process are completed at previous itearation\n");
}
	 printf("\n\nProcess\t|Turnaround Time|Waiting Time|Time completed\n\n"); 
	for(i=0;i<n;i++)
	{
		printf("P[%d]%d\t%d\t%d\t\n",i+1,tat[i],wt[i],t[i]);
	}
	for(i=0;i<n;i++)
	{
		totalturnaroundtime +=tat[i];
		totalwaitingtime +=wt[i];
	}
	avgtat=totalturnaroundtime/n;
	avgwt=totalwaitingtime/n;
	printf("total waiting time is %d\n",totalwaitingtime);
	printf("total turnaround time is %d",totalturnaroundtime);
 printf("Average turn around time is%f\n",avgtat);
 printf("Average wating time is %f\n",avgwt);
}
