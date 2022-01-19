// NIM: 13220031

#include <stdio.h>

int main(void) {

    printf("\nSelamat datang! \nProgram ini akan berhenti apabila ember 5 liter sudah memiliki isi 4 liter.\n\n");

    // inisialisasi
    int jugA = 0; // 3 liter
    int jugB = 0; // 5 liter
    int pilihan = 0; // input user

    // interaksi dengan user
    while (jugB != 4) {

        // status isi ember
        printf("Isi ember 3 liter: %d liter\nIsi ember 5 liter: %d liter\n\n", jugA, jugB);

        // menu
        printf("Pilihan instruksi:\n 1. Penuhi ember 3 liter\n 2. Penuhi ember 5 liter\n 3. Kosongkan ember 3 liter\n 4. Kosongkan ember 5 liter\n 5. Tuang isi ember 3 liter ke ember 5 liter\n 6. Tuang isi ember 5 liter ke ember 3 liter\n\nMasukkan nomor instruksi yang dipilih >>> ");
        scanf("%d", &pilihan);

        // Penuhi ember 3 liter
        if (pilihan == 1) {
            jugA = 3;
            printf("\nEmber 3 liter telah dipenuhi ...\n\n");

        // Penuhi ember 5 liter
        } else if (pilihan == 2) {
            jugB = 5;
            printf("\nEmber 5 liter telah dipenuhi ...\n\n");

        // Kosongkan ember 3 liter
        } else if (pilihan == 3) {
            jugA = 0;
            printf("\nEmber 3 liter telah dikosongkan ...\n\n");

        // Penuhi ember 5 liter
        } else if (pilihan == 4) {
            jugB = 0;
            printf("\nEmber 5 liter telah dikosongkan ...\n\n");

        // Tuangkan isi ember 3 liter ke ember 5 liter
        } else if (pilihan == 5) {
            if (jugA + jugB > 5) {
                jugA = (jugA + jugB) - 5;
                jugB = 5;
            } else {
                jugB += jugA;
                jugA = 0;
            }
            printf("\nIsi ember 3 liter telah dituangkan ke ember 5 liter ...\n\n");

        // Tuangkan isi ember 5 liter ke ember 3 liter
        } else if (pilihan == 6) {
            if (jugA + jugB > 3) {
                jugB = (jugA + jugB) - 3;
                jugA = 3;
            } else {
                jugA += jugB;
                jugB = 0;
            }
            printf("\nIsi ember 5 liter telah dituangkan ke ember 3 liter ...\n\n");

        // Invalid input
        } else {
            printf("\nPilihan instruksi tidak valid.\n\n");
        }

        printf("- - - - - - -\n\n");

    }

    printf("Objektif telah tercapai!\n");
}
