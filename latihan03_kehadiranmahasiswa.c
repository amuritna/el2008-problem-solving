// NIM: 13220031

#include <stdio.h>

// deklarasi struktur mahasiswa
struct mahasiswa {
    char nama[10];
    int nim;
    float kehadiran;
};

int main() {
    // input tidak divalidasi lagi;
    // DIASUMSIKAN SEMUA INPUT VALID

    // inisialisasi
    int jumlahMhs = 5;

    struct mahasiswa kelas[5] = {
        {"Michael", 13220314, 0},
        {"James", 13220100, 0},
        {"Andre", 13220302, 0},
        {"Charles", 13220174, 0},
        {"Simeon", 13220999, 0}
    };

    // print isi kelas
    printf("\nDAFTAR MAHASISWA K09\n\n");
    for (int i = 0; i < 5; i++) {
        printf("[%d] %s\t(%d)\n", i+1, kelas[i].nama, kelas[i].nim);
    }

    printf("\n- - - - \n");

    // input presensi
    printf("\nPresensi berbentuk angka desimal,\ne.g. 1.0 untuk presensi 100 persen dan 0.75 untuk presensi 75 persen.\n");

    for (int i = 0; i < 5; i++) {
        printf("\nMasukkan presensi untuk %s:  ", kelas[i].nama);
        scanf("%f", &kelas[i].kehadiran);
    }

    printf("\n- - - - \n");

    // output
    printf("\nMahasiswa yang kehadirannya kurang dari 80%:\n\nNama\t\tNIM\t\tKehadiran\n\n");

    for (int i = 0; i < 5; i++) {
        if (kelas[i].kehadiran < 0.8) {
            printf("%s\t\t%d\t%.2f persen\n", kelas[i].nama, kelas[i].nim, kelas[i].kehadiran * 100);
        }
    }
}
