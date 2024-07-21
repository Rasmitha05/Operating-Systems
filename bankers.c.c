#include<stdio.h>
int main()
{
    int n,m;
    int sum=0,temp;
    printf("Enter the size of resources and processes:\n");
    scanf("%d",&m);
    scanf("%d",&n);
    int max[n][m],allocated[n][m],need[n][m];
    int available[m],total[m],finished[n];
    int safe[n];
    printf("Enter the available resources:\n");
    for(int i=0;i<m;i++)
    {
        scanf("%d",&available[i]);
    }
    printf("Enter the maximum resources processor needed:\n");
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            scanf("%d",&max[i][j]);
        }
    }
    printf("Enter the resources processor allocated\n");
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            scanf("%d",&allocated[i][j]);
        }
    }
    for(int i=0;i<m;i++)
    {
        sum=0;//Total matrix
        for(int j=0;j<n;j++)
        {
            
            sum=sum+allocated[j][i];
            
        }
        total[i]=sum+available[i];
            
    }
    for(int i=0;i<n;i++)
    {
        finished[i]=0;
    }
    printf("total resources are:\n");
    for(int i=0;i<m;i++ )
    {
        printf("%d ",total[i]);
    }
    printf("\n");
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            need[i][j]=max[i][j]-allocated[i][j];
        }
    }
    printf("total need matrix\n");
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            printf("%d ",need[i][j]);
        }
        printf("\n");
    }
    int t=0;//no of processes that have been safely completed
    int s=0;//index for inserting nxt process in safe
    int f=0;//flag to indicta any process was able to proceed
    while(t<n)
    {
        
        f=0;
        for(int i=0;i<n;i++)
        {
            if(finished[i]!=1)
            {
                int j;
                for(j=0;j<m;j++)
                {
                    if(need[i][j]>available[j])
                    {
                        break;
                    
                    }
                }
                if(j==m)
                {
                    for(int k=0;k<m;k++)
                    {
                        available[k]=available[k]+allocated[i][k];
                    }
                    finished[i]=1;
                    t++;
                    safe[s]=i;
                    s++;
                    f=1;
                }
            }    
               
            
        }
    }
    if(f==1)
    {
        printf("safe state is:\n");
        for(int i=0;i<n;i++)
        {
            printf("%d ",safe[i]);
        }
    }
    else
    {
        printf("it is unsafe state");
    }
    return 0;
}