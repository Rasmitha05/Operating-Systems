#include<stdio.h>
void main()
{
	int i,j,n,k,tq,flag=0,temp=0;
	float atat,awt;
	printf("Enter number of processes:");
	scanf("%d",&n);
	int a[n],b[n],pid[n],ct[n],tat[n],wt[n],bt[n];
	printf("Enter arrival times:");
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
		pid[i]=i+1;
	}
	printf("Enter burst times:");
	for(j=0;j<n;j++)
	{
		scanf("%d",&b[j]);
	}
	for(i=0;i<n;i++)
	{
		bt[i]=b[i];
	}
	printf("Enter time quantum:");
	scanf("%d",&tq);
	int t=0;
	while(1)
	{
		flag=1;
		for(i=0;i<n;i++)
		{
			if(b[i]>0)
			{
				flag=0;
				if(b[i]>tq)
				{
					t+=tq;
					b[i]-=tq;
				}
				else
				{
					t+=b[i];
					b[i]=0;
					ct[i]=t;
				}
			}
		}
		if(flag==1)
		break;
	}	
	for(i=0;i<n;i++)
	{
		tat[i]=ct[i]-a[i];
		atat+=tat[i];
		wt[i]=tat[i]-bt[i];
		awt+=wt[i];
	}
	//atat=(float)s/n;
	//awt=(float)sum/n;
	printf("Average tat = %0.2f \n",atat/n);
	printf("Avearge wt = %0.2f",awt/n);
}
