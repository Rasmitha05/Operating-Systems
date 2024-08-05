#include <stdio.h>

void main()
{
    int page[20]={7,0,1,2,0,3,0,4,2,3,0,3,2,1,2,0,1,7,0,1};
    int temp[3]={-1,-1,-1};
    int recent[3]={0,0,0};
    int count=0;
    int time=0;
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
                recent[j]=time;
                break;
            }
        }
        if(!found) 
        {
            int lru=0;
            for (int j=1;j<3;j++)
            {
                if(recent[j]<recent[lru])
                {
                    lru=j;
                }
            }
            temp[lru]=page[i];
            recent[lru]=time; 
            count++;
        }
        time++;
        i++;
    }
    printf("%d", count);
}