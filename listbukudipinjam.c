#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header.h"

void listBukuDipinjam() {
    FILE *file = fopen("bukudipinjam.txt", "r");
    if (file == NULL) {
        printf("Gagal membuka file.\n");
        return;
    }

    printf("\n\t\t\t=======================================================================================");
    printf("\n\t\t\t\t\t\t       DAFTAR BUKU DIPINJAM       \n");
    printf("\n\t\t\t=======================================================================================\n");
    printf("Daftar Buku yang anda pinjam:\n");


    Buku buku;
    while (fscanf(file, "%u,%[^,],%[^,],%[^,],%u,%u,%u\n", &buku.id, buku.judul, buku.penulis, buku.penerbit, &buku.halaman, &buku.tahun, &buku.jumlah_tersedia) == 7) {
        printf("ID: %u\n", buku.id);
        printf("Judul: %s\n", buku.judul);
        printf("Penulis: %s\n", buku.penulis);
        printf("Penerbit: %s\n", buku.penerbit);
        printf("Halaman: %u\n", buku.halaman);
        printf("Tahun: %u\n", buku.tahun);
        printf("Jumlah Tersedia: %u\n", buku.jumlah_tersedia);
        printf("\n");
    }

    fclose(file);
}
