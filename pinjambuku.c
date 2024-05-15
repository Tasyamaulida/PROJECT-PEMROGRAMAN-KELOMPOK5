#include <stdlib.h>
#include <string.h>
#include "header.h"

void pinjamBuku() {
    // Meminta input ID buku yang akan dipinjam
    unsigned int id;
    printf("Masukkan ID buku yang akan dipinjam: ");
    scanf("%u", &id);

    // Membuka file database
    FILE *file = fopen("berekstensi.txt", "r+");
    if (file == NULL) {
        printf("Gagal membuka file.\n");
        return;
    }

    // Membaca dan mencari buku dengan ID yang sesuai
    Buku buku;
    int bukuDitemukan = 0;
    long int posisiBuku = -1;
    while (fscanf(file, "%u,%[^,],%[^,],%[^,],%u,%u,%u\n", &buku.id, buku.judul, buku.penulis, buku.penerbit, &buku.halaman, &buku.tahun, &buku.jumlah_tersedia) == 7) {
        if (buku.id == id && buku.jumlah_tersedia > 0) {
            bukuDitemukan = 1;
            posisiBuku = ftell(file) - strlen(buku.judul) - strlen(buku.penulis) - strlen(buku.penerbit) - 22; // Menghitung posisi buku dalam file

            // Mengurangi jumlah tersedia dan menulis kembali data buku
            fseek(file, posisiBuku, SEEK_SET);
            buku.jumlah_tersedia--;
            fprintf(file, "%u,%s,%s,%s,%u,%u,%u\n", buku.id, buku.judul, buku.penulis, buku.penerbit, buku.halaman, buku.tahun, buku.jumlah_tersedia);
            printf("Buku dengan ID %u berhasil dipinjam.\n", buku.id);

            // Menambahkan buku ke daftar buku yang dipinjam
            FILE *pinjamFile = fopen("bukudipinjam.txt", "a");
            if (pinjamFile == NULL) {
                printf("Gagal membuka file.\n");
                return;
            }
            fprintf(pinjamFile, "%u,%s,%s,%s,%u,%u,%u\n", buku.id, buku.judul, buku.penulis, buku.penerbit, buku.halaman, buku.tahun, buku.jumlah_tersedia);
            fclose(pinjamFile);
            break;
        }
    }

    // Jika buku tidak ditemukan atau tidak tersedia
    if (!bukuDitemukan) {
        printf("Buku tidak ditemukan atau tidak tersedia.\n");
    }

    fclose(file);
}
