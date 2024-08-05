#include<stdio.h>
void main()
{
	int n,i,j,page[25],fr[3];
    int flag,flag2,pf=0,count=0;
    printf("Enter no of pages\n");
    scanf("%d",&n);
    printf("Enter page reference string\n");
    for(i=0;i<n;i++)
    {
 	   scanf("%d",&page[i]);
    }
    for(i=0;i<3;i++)
    {
       fr[i]=-1;
    }
    for(j=0;j<n;j++)
    {
    	flag=0;
    	flag2=0;
    	for(i=0;i<3;i++)
    	{
    		if(fr[i]==page[j])
    		{
    			flag=1;
    			flag2=1;
    			break;
			}
		}
		if(flag==0)
		{
			for(i=0;i<3;i++)
			{
				if(fr[i]==-1)
				{
					fr[i]=page[j];
					pf++;
					flag2=1;
					break;
				}
			}
		}
		if(flag2==0)
		{
			fr[count]=page[j];
			count=(count+1)%3;
			pf++;
		}
	}
	printf("Total page faults = %d",pf);
}