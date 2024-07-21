#include<stdio.h>
void fcfs(){
    int n;
    printf("Enter number of processors: \n");
    scanf("%d",&n);
    int i,j,temp1,temp2;
    int at[i],bt[i],ct[i],wt[i],tat[i];
    float atat,awt;
    printf("enter the arrival time: \n");
    for(i=0;i<n;i++)
        scanf("%d",&at[i]);
    printf("enter the burst times: \n");
        for(i=0;i<n;i++){
            ct[i]=0;
            scanf("%d",&bt[i]);
        }
    for(i=0;i<n-1;i++)
        for(j=i+1;j<n;j++)
            if(at[i]>at[j])
            {
                temp1=at[i];
                temp2=bt[i];
                at[i]=at[j];
                bt[i]=bt[j];
                at[j]=temp1;
                bt[j]=temp2;
            }
    printf("\n");
    ct[0]=at[0]+bt[0];
    for(i=0;i<n;i++){
        if(i>0)
        
            ct[i]=ct[i-1]+bt[i];
            tat[i]=ct[i]-at[i];
            atat += tat[i];
            wt[i]=tat[i]-bt[i];
            awt += wt[i];
    }
    printf("AVG TAT:%.2f\n",atat/n);
    printf("AVG AWT:%.2f\n",awt/n);
    
}*/