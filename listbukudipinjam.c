#include <stdio.h>
#include "header.h"

void listBukuDipinjam() {
    // Membuka file database
    FILE *file = fopen("bukudipinjam.txt", "r");
    if (file == NULL) {
        printf("Gagal membuka file.\n");
        return;
    }
    printf("\n\t\t\t=======================================================================================");
    printf("\n\t\t\t\t\t\t       DAFTAR BUKU DIPINJAM       \n");
    printf("\n\t\t\t=======================================================================================\n");
    printf("Daftar Buku yang andapinjam:\n");

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
            printf("\n");
        }
    }

    fclose(file);
}
