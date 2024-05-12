#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header.h"

void pinjamBuku() {
    FILE *file = fopen("berekstensi.txt", "r");
    FILE *tempFile = fopen("temp.txt", "w");

    if (file == NULL || tempFile == NULL) {
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
            } else {
                printf("Buku dengan ID %u tidak tersedia.\n", id);
                fclose(file);
                fclose(tempFile);
                remove("temp.txt");
                return;
            }
        }
        fprintf(tempFile, "%u,%s,%s,%s,%u,%u,%u\n", buku.id, buku.judul, buku.penulis, buku.penerbit, buku.halaman, buku.tahun, buku.jumlah_tersedia);
    }

    if (!found) {
        printf("Buku dengan ID %u tidak ditemukan.\n", id);
        fclose(file);
        fclose(tempFile);
        remove("temp.txt");
        return;
    }

    fclose(file);
    fclose(tempFile);

    remove("berekstensi.txt");
    rename("temp.txt", "berekstensi.txt");

    printf("Buku dengan ID %u berhasil dipinjam.\n", id);
}