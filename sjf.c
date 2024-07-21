#include<stdio.h>
 void sjf(){
    int n;
    printf("Enter n:");
    scanf("%d", &n);
    int at[n], bt[n], ct[n], tat[n], wt[n];
    float atat, awt;
    printf("Enter arrival times:\n");
    for (int i=0; i<n; i++)
        scanf("%d", &at[i]);
    printf("Enter burst times:\n");
    for (int i=0; i<n; i++)
        scanf("%d", &bt[i]);
    for (int i=0; i<n; i++){
        for ( int j=0; j<n; j++){
            if (bt[i] < bt[j]){
                int temp1 = at[i];
                int temp2 = bt[i];
                at[i] = at[j];
                bt[i] = bt[j];
                at[j] = temp1;
                bt[j] = temp2;
            }
        }
    }
    //printf("\nats\n");
    //for (int i=0; i<n; i++)
      //  printf("%d ", at[i]);
    //printf("\n");
    //printf("\nbts:\n");
    //for (int i=0; i<n; i++)
      //  printf("%d ", bt[i]);
    printf("\n");
    ct[0] = at[0] + bt[0];
    for (int i = 0; i < n; i++) {
        if (i > 0)
            ct[i] = ct[i-1] + bt[i];
        tat[i] = ct[i] - at[i];
        atat += tat[i];
        wt[i] = tat[i] - bt[i];
        awt += wt[i];
    }
    //for (int i=0; i<n; i++)
        //printf("%d ", ct[i]);
    printf("avg tat: %.2f\n", atat/n);
    printf("avg wt: %.2f", awt/n);
 }
