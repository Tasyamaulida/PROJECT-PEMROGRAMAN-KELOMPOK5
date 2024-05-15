#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header.h"

void kembalikanBuku() {
    // Meminta input ID buku yang akan dikembalikan
    unsigned int id;
    printf("Masukkan ID buku yang akan dikembalikan: ");
    scanf("%u", &id);

    // Membuka file database
    FILE *file = fopen("bukudipinjam.txt", "r+");
    if (file == NULL) {
        printf("Gagal membuka file.\n");
        return;
    }

    // Membaca dan mencari buku dengan ID yang sesuai
    Buku buku;
    int bukuDitemukan = 0;
    long int posisiBuku = -1;
    FILE *tempFile = fopen("temp.txt", "w");
    while (fscanf(file, "%u,%[^,],%[^,],%[^,],%u,%u,%u\n", &buku.id, buku.judul, buku.penulis, buku.penerbit, &buku.halaman, &buku.tahun, &buku.jumlah_tersedia) == 7) {
        if (buku.id == id && buku.jumlah_tersedia > 0) {
            bukuDitemukan = 1;
            posisiBuku = ftell(file) - strlen(buku.judul) - strlen(buku.penulis) - strlen(buku.penerbit) - 22; // Menghitung posisi buku dalam file

            // Mengurangi jumlah tersedia dan menulis kembali data buku
            fseek(file, posisiBuku, SEEK_SET);
            buku.jumlah_tersedia++;
            fprintf(file, "%u,%s,%s,%s,%u,%u,%u\n", buku.id, buku.judul, buku.penulis, buku.penerbit, buku.halaman, buku.tahun, buku.jumlah_tersedia);
            printf("Buku dengan ID %u berhasil dikembalikan.\n", buku.id);
            break;
        }
    }

    // Jika buku tidak ditemukan atau tidak tersedia
    if (!bukuDitemukan) {
        printf("Buku tidak ditemukan atau tidak sedang dipinjam.\n");
    }
    fclose(file);
    fclose(tempFile);

    // Menghapus file asli dan mengganti dengan file sementara
    remove("bukudipinjam.txt");
    rename("temp.txt", "bukudipinjam.txt");
}
