//priority scheduling
#include<stdio.h>
void main()
{
	int n,i,j,k,temp=0,t=0,s=0,sum=0;
	float tat,awt;
	printf("Enter the number of processes:");
	scanf("%d",&n);
	int a[n],b[n],p[n],ct[n],wt[n];
	printf("Enter the arrival times:");
	for(i=0;i<n;i++)
	{
	   scanf("%d",&a[i]);	
	}
	printf("Enter burst times:");
	for(j=0;j<n;j++)
	{
		scanf("%d",&b[j]);
	}
	printf("Enter priorities:");
	for(k=0;k<n;k++)
	{
		scanf("%d",&p[k]);
	}
    for(i=0;i<n-1;i++)
	{
		for(j=0;j<n-1-i;j++)
		{
			//if(p[j]<p[j+1])if low number high priority then
			if(p[j]>p[j+1])
			{
			    temp=p[j];
			    p[j]=p[j+1];
			    p[j+1]=temp;
			    temp=b[j];
			    b[j]=b[j+1];
			    b[j+1]=temp;
			}
		}
	}
	for(i=0;i<n;i++)
	{
		ct[i]=t+b[i];
		t=ct[i];
		s+=ct[i];
		wt[i]=ct[i]-b[i];
		sum+=wt[i];
	}
	tat=(float)s/n;
	awt=(float)sum/n;
	printf("Average turn around time %0.2f\n",tat);
	printf("Average waiting time %0.2f",awt);
}