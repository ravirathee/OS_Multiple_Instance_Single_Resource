//Ravi Rathee
//16csu292
//Multiple Instance Single Resource Code

#include <stdio.h>

int main() {
    int i,j,n,A; //A is currently available resources
    int max_need[100]={0};
    int curr_need[100]={0};
    int need_left[100]={0};
    int total_curr_need = 0;

    printf("Enter number of instances of Resource ");
    scanf("%d",&A);

    printf("Enter the number of processes");
    scanf("%d",&n);

    printf("Enter the max needs");
    for(i=0;i<n;i++){
        scanf("%d",&max_need[i]);
    }

    printf("Enter the current needs");
    for(i=0;i<n;i++){
        scanf("%d",&curr_need[i]);
        total_curr_need += curr_need[i];
    }

    for(i=0;i<n;i++) {
        need_left[i] = max_need[i]-curr_need[i];
    }

    A = A - total_curr_need;
    if(A<0){
        printf("Cant execute");
    }

    int processes_left = n;
    int flag = 0;
    int counter = 0;

    while(processes_left){
        for(i=0;i<n;i++){
            if( A >= need_left[i] && need_left[i]!=0){
                A+=need_left[i];
                need_left[i]=0;
                processes_left-=1;
                printf("P%d ",i);
            }else{
                counter+=1;
            }
        }

        if(counter==n){
            printf("No safe sequence available");
            break;
        }
        counter = 0;
    }
}
/*
OUTPUT

Enter number of instances of Resource 12
Enter the number of processes3
        Enter the max needs10
4
9
Enter the current needs5
2
2
P1 P0 P2

*/


