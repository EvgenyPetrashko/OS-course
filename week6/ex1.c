#include <stdio.h>
#include <stdlib.h>

void Bubble_sort(int **processes, int numberOfProcesses) {
    for (int i = 0; i < numberOfProcesses; ++i) {
        for (int j = i+1; j < numberOfProcesses; ++j) {
            if (processes[i][0] > processes[j][0]) {
                int *temp = processes[i];
                processes[i] = processes[j];
                processes[j] = temp;
            }
        }
    }
}

int main() {
    int numberOfProcesses;
    printf("Write the number of processes\n");
    scanf("%d", &numberOfProcesses);
    int **processes = malloc(sizeof(int*) * numberOfProcesses);
    printf("Write arrival time and burst time for each process\n");
    for (int i = 0; i < numberOfProcesses; ++i) {
        processes[i] = malloc(sizeof(int) * 5);
        int aT;
        int bT;
        scanf("%d %d", &aT, &bT);

        processes[i][0] = aT;
        processes[i][1] = bT;
        processes[i][2] = 0;
        processes[i][3] = 0;
        processes[i][4] = 0;
    }
    Bubble_sort(processes, numberOfProcesses);
    double sumOfTAT = 0;
    double sumOfWT = 0;

    int time = 0;
    for (int i = 0; i < numberOfProcesses; ++i) {
        int CT;
        int TAT;
        int WT;
        if (time < processes[i][0]) time = processes[i][0];
        CT = time + processes[i][1];
        TAT = CT - processes[i][0];
        WT = TAT - processes[i][1];
        processes[i][2] = CT;
        processes[i][3] = TAT;
        processes[i][4] = WT;
        sumOfTAT = sumOfTAT + TAT;
        sumOfWT = sumOfWT + WT;
        time = time + processes[i][1];
    }
    for (int i = 0; i < numberOfProcesses; ++i) {
        printf("P%d(%d, %d): \tCT = %d \v\tTAT = %d \v\tWT = %d\n", i, processes[i][0], processes[i][1], processes[i][2], processes[i][3], processes[i][4]);
    }
    printf("Average Turn around Time = %f\n", sumOfTAT/numberOfProcesses);
    printf("Average Waiting Time = %f\n", sumOfWT/numberOfProcesses);


    return 0;
}
