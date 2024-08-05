#include <stdio.h>
void main()
{
    int page[20]={7,0,1,2,0,3,0,4,2,3,0,3,2,1,2,0,1,7,0,1};
    int temp[3]={-1,-1,-1};
    int count=0;
    int i=0;
    int n=sizeof(page)/sizeof(page[0]);
    while(i<n)
    {
        int found=0;
        for(int j=0;j<3;j++)
        {
           if(temp[j]==page[i])
           {
               found=1;
               break;
           }
        }
        if(!found)
        {
            int replace=-1;
            int farthest=i+1;
           for(int j=0;j<3;j++)
           {
               int k;
               for(k=i+1;k<n;k++)
               {
                   if(temp[j]==page[k])
                   {
                       if(k>farthest)
                       {
                        farthest=k;
                        replace=j;
                       }
                       break;
                   }
                   
               }
               if(k==n)
               {
                   replace=j;
                   break;
               }
           }
           if(replace==-1)
           {
               replace=0;
               
           }
           temp[replace]=page[i];
           count++;
        }
        i++;
    }
    printf("%d",count);
    return 0;
}