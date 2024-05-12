#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header.h"

void pinjamBuku() {
    FILE *file = fopen("berekstensi.txt", "r");
    FILE *pinjamFile = fopen("bukudipinjam.txt", "a");

    if (file == NULL || pinjamFile == NULL) {
        printf("Gagal membuka file.\n");
        return;
    }

    unsigned int id;
    printf("Masukkan ID buku yang ingin dipinjam: ");
    scanf("%u", &id);

    Buku buku;
    int found = 0;

    while (fscanf(file, "%u,%[^,],%[^,],%[^,],%u,%u,%u\n", &buku.id, buku.judul, buku.penulis, buku.penerbit, &buku.halaman, &buku.tahun, &buku.jumlah_tersedia) != EOF) {
        if (buku.id == id) {
            found = 1;
            if (buku.jumlah_tersedia > 0) {
                buku.jumlah_tersedia--;
                fprintf(pinjamFile, "%u,%s,%s,%s,%u,%u,%u\n", buku.id, buku.judul, buku.penulis, buku.penerbit, buku.halaman, buku.tahun, buku.jumlah_tersedia);
            } else {
                printf("Buku dengan ID %u tidak tersedia.\n", id);
                fclose(file);
                fclose(pinjamFile);
                return;
            }
        }
        fprintf(pinjamFile, "%u,%s,%s,%s,%u,%u,%u\n", buku.id, buku.judul, buku.penulis, buku.penerbit, buku.halaman, buku.tahun, buku.jumlah_tersedia);
    }

    if (!found) {
        printf("Buku dengan ID %u tidak ditemukan.\n", id);
        fclose(file);
        fclose(pinjamFile);
        return;
    }

    fclose(file);
    fclose(pinjamFile);

    printf("Buku dengan ID %u berhasil dipinjam.\n", id);
}
