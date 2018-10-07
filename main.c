//Ravi Rathee
//16csu292
//Multiple Instance Single Resource Code

#include <stdio.h>

int main() {
    int i, n, A;   //A is currently available resources
    printf("Enter the number of instances of A : ");
    scanf("%d", &A);

    printf("Enter the number of processes :");
    scanf("%d", &n);


    int max_need[100] = {0};
    int curr_need[100] = {0};
    int need_left[100] = {0};
    int total_curr_need = 0;
    int remain = n;


    printf("Enter the max needs : ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &max_need[i]);
    }

    printf("Enter the curr needs : ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &curr_need[i]);
        total_curr_need += curr_need[i];
    }

    for (int i = 0; i < n; ++i) {
        need_left[i] = max_need[i] - curr_need[i];
    }

    A = A - total_curr_need;
    if (A < 0) {
        printf("Cant execute");
    }

    int flag = 0;

    while (remain != 0) {
        for (int i = 0; i < n; ++i) {
            if (need_left[i] <= A && need_left[i] != 0) {
                remain--;
                A += curr_need[i];
                need_left[i] = 0;
                printf("P%d ", i);
            } else {
                flag += 1;
            }
        }

        if (flag == n) {
            printf("No safe sequence");
            break;
        }
        flag = 0;
    }
}
/*
OUTPUT

Enter the number of instances of A : 12
Enter the number of processes :3
Enter the max needs : 10
4
9
Enter the curr needs : 5
2
2
P1 P0 P2

*/


