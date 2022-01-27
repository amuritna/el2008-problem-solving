// NIM: 13220031

/* SAMPLE INPUT (bisa langsung copas)
6
0
250
50
170
130
75
190
100
210
130
350
50
100
*/

#include <stdio.h>

// create times data structure
struct times {
    int processID, arrivalTime, executionTime, remainingTime;
};

int main() {

    // inisialisasi
    int i, j, jumlahProses, time, remain, flag=0, quantum;
    struct times a[100];

    // interface
    printf("Masukkan jumlah proses, arrival time, dan execution time.\n\n");
    printf("Ketentuan:\n1. Arrival time proses pertama mesti 0.\n2. Harus selalu ada proses yang sedang dijalankan (tidak pernah idle).\n3. Arrival time mesti sudah berurutan (arrival time P0 < arrivalTime P1, dst.)\n\n");

    // input
    printf("Jumlah proses :\t\t");
    scanf("%d",&jumlahProses);
    remain = jumlahProses;

    // DIASUMSIKAN INPUT PASTI VALID

    for (i = 0; i < jumlahProses; i++) {

        printf("\nArrival time P%d:\t", i);
        scanf("%d", &a[i].arrivalTime);

        printf("Execution time P%d:\t", i);
        scanf("%d", &a[i].executionTime);

        a[i].processID = i;
        a[i].remainingTime = a[i].executionTime;
    }

    printf("\nQuantum time :\t\t");
    scanf("%d",&quantum);

    printf("\n- - - - - -\n\nTime\tProses yang berakhir\t\tKeterangan\n\n");

    for (time = 0, i = 0; remain != 0;) {

        if(a[i].remainingTime == 0 && flag == 1) {
             remain--;
             flag = 0;
        }

        // completed
        if(a[i].remainingTime <= quantum && a[i].remainingTime > 0) {
             time = time + a[i].remainingTime;
             printf("%d\tP%d\t\t\t\tProses %d selesai.\n", time, a[i].processID, a[i].processID);
             a[i].remainingTime = 0;
             flag = 1;
        }

        // kicked
        else if (a[i].remainingTime > 0) {
             a[i].remainingTime = a[i].remainingTime - quantum;
             time = time + quantum;
             printf("%d\tP%d\t\t\t\tProses %d mesti kembali mengantri.\n", time, a[i].processID, a[i].processID);
        }

        if (i == jumlahProses - 1) {
             i = 0;

        } else if(a[i+1].arrivalTime <= time) {
             i++;

        } else {
             i = 0;
        }

    }

    return 0;
}
