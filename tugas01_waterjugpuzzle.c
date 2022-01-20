// NIM: 13220031

// Edit (tanggal 20/01/2022, saat jam kelas): Fix infinite loop apabila mendapatkan input char

// Sumber kode yang digunakan untuk fix:
// https://stackoverflow.com/questions/53056369/c-infinite-loop-when-char-input-instead-of-int

#include <stdio.h>

// Function untuk mengosongkan stdin
// Sumber: David C. Rankin di StackOverflow (lihat link pada line 6)
void empty_stdin (void) /* simple helper-function to empty stdin */
{
    int c = getchar();

    while (c != '\n' && c != EOF)
        c = getchar();
}

int main(void) {

    printf("\nSelamat datang! \nProgram ini akan berhenti apabila ember 5 liter sudah memiliki isi 4 liter.\n\n");

    // inisialisasi
    int jugA = 0; // 3 liter
    int jugB = 0; // 5 liter
    int pilihan = 0; // input user
    int rtn = 0; // variabel untuk save scanf return

    // interaksi dengan user
    while (jugB != 4) {

        // status isi ember
        printf("Isi ember 3 liter: %d liter\nIsi ember 5 liter: %d liter\n\n", jugA, jugB);

        // print menu + ambil input
        // Sumber: David C. Rankin di StackOverflow, dengan modifikasi (lihat link pada line 6)

        for (;;) { // loop sampai dapat valid input atau EOF

            printf("Pilihan instruksi:\n 1. Penuhi ember 3 liter\n 2. Penuhi ember 5 liter\n 3. Kosongkan ember 3 liter\n 4. Kosongkan ember 5 liter\n 5. Tuang isi ember 3 liter ke ember 5 liter\n 6. Tuang isi ember 5 liter ke ember 3 liter\n\nMasukkan nomor instruksi yang dipilih >>> ");
            rtn = scanf("%d", &pilihan);

            if (rtn == EOF) {   /* user generates manual EOF */
                fputs ("\n\n(User membatalkan input (EOF).)\n", stderr);
                return 1;
            }
            else if (rtn == 0) {    /* matching failure */
                fputs ("\n\nError: Input integer tidak valid.\n", stderr);
                empty_stdin();
            }
            else if (pilihan < 1 || 6 < pilihan) {  /* validate range */
                fputs ("\n\nError: Input integer di luar range [1-6]\n", stderr);
                empty_stdin();
            }
            else {  /* good input */
                empty_stdin();
                break;
            }
        }

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
