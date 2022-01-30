// NIM: 13220031

#include <stdio.h>

// untuk memcmp
#include <string.h>

int main() {
	
	// inisialisasi
	FILE *fileToRead;

	int detectedJPG, detectedPDF;
	unsigned char signPDF[5] = {0x25, 0x50, 0x44, 0x46, 0x2D};
	unsigned char signJPG[3] = {0xFF, 0xD8, 0xFF};
	unsigned char fileHeader[5], fileName[100];

	// input filename
	printf("Masukkan nama file (max 100 karakter) (contoh: sample.pdf):\t");
	scanf("%s", &fileName);

	// buka dan file
	fileToRead = fopen(fileName, "rb");
	fread(fileHeader, sizeof(fileHeader), 1, fileToRead);

	// baca header dengan memcmp
	detectedJPG = memcmp(signJPG, fileHeader, 3);
	detectedPDF = memcmp(signPDF, fileHeader, 5);

	// print output
	printf("\nJenis file yang dideteksi: ");

	// kasus 1 : PDF
	if (detectedPDF == 0) {
		printf("PDF\n");

	// kasus 2: JPG
	} else if (detectedJPG == 0) {
		printf("JPG\n");

	// kasus 3: bukan dua-duanya
	} else {
		printf("Unknown (bukan PDF ataupun JPG)\n");
	}

	// terminate program
	return 0;
}
