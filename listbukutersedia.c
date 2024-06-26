#include "header.h"
#include <stdio.h>

void listBukuTersedia() {

    // Membuka file database
    FILE *file = fopen("berekstensi.txt", "r");
    if (file == NULL) {
        printf("Gagal membuka file.\n");
        return;
    }
    printf("\n\t\t\t=======================================================================================");
    printf("\n\t\t\t\t\t\t       LIHAT BUKU TERSEDIA       \n");
    printf("\n\t\t\t=======================================================================================\n");
    printf("Daftar Buku yang tersedia:\n");

    // Membaca dan menampilkan data buku dari file
    Buku buku;
    while (fscanf(file, "%u,%[^,],%[^,],%[^,],%u,%u,%u\n", &buku.id, buku.judul, buku.penulis, buku.penerbit, &buku.halaman, &buku.tahun, &buku.jumlah_tersedia) == 7) {
        if (buku.jumlah_tersedia > 0) {
            printf("ID: %u\n", buku.id);
            printf("Judul: %s\n", buku.judul);
            printf("Penulis: %s\n", buku.penulis);
            printf("Penerbit: %s\n", buku.penerbit);
            printf("Jumlah Halaman: %u\n", buku.halaman);
            printf("Tahun Terbit: %u\n", buku.tahun);
            printf("Jumlah Tersedia: %u\n", buku.jumlah_tersedia);
            printf("\n");
        }
    }

    fclose(file);
}
