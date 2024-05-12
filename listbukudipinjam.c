#include <stdio.h>
#include "header.h"

void listBukuDipinjam() {
    // Membuka file database
    FILE *file = fopen("berekstensi.txt", "r");
    if (file == NULL) {
        printf("Gagal membuka file.\n");
        return;
    }

    // Membaca data buku dari file
    Buku buku;
    int counter = 0;
    printf("Daftar Buku yang Dipinjam:\n");
    printf("ID\tJudul\t\t\tPengarang\t\tTahun Terbit\n");

    while (fscanf(file, "%u,%[^,],%[^,],%[^,],%u,%u,%u\n", &buku.id, buku.judul, buku.penulis, buku.penerbit, &buku.halaman, &buku.tahun, &buku.jumlah_tersedia) != EOF) {
        if (buku.jumlah_tersedia == 0) {
            printf("%u\t%-40s\t%-40s\t%u\n", buku.id, buku.judul, buku.penulis, buku.tahun);
            counter++;
        }
    }

    fclose(file);

    if (counter == 0) {
        printf("Tidak ada buku yang dipinjam.\n");
    }
}