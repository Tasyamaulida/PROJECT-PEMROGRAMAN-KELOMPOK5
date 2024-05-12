#include <string.h>
#include "header.h"

void tambahBuku() {
    // Membaca data buku yang akan ditambahkan dari pengguna
    Buku buku;
    printf("Tambah Buku\n");
    printf("Id Buku: ");
    scanf("%u", &buku.id);
    getchar(); // Membersihkan newline character dari buffer
    printf("Judul: ");
    fgets(buku.judul, sizeof(buku.judul), stdin);
    buku.judul[strcspn(buku.judul, "\n")] = '\0'; // Menghapus newline character jika ada
    printf("Penulis: ");
    fgets(buku.penulis, sizeof(buku.penulis), stdin);
    buku.penulis[strcspn(buku.penulis, "\n")] = '\0';
    printf("Penerbit: ");
    fgets(buku.penerbit, sizeof(buku.penerbit), stdin);
    buku.penerbit[strcspn(buku.penerbit, "\n")] = '\0';
    printf("Jumlah Halaman: ");
    scanf("%u", &buku.halaman);
    printf("Tahun Terbit: ");
    scanf("%u", &buku.tahun);
    printf("Jumlah Buku yang Tersedia: ");
    scanf("%u", &buku.jumlah_tersedia);

    // Menyimpan data buku ke dalam file
    FILE *file = fopen("berekstensi.txt", "a");
    if (file == NULL) {
        printf("Gagal membuka file.\n");
        return;
    }
    fprintf(file, "| %-7u | %-40s | %-20s | %-15s | %-14u | %-12u | %-26u |\n", buku.id, buku.judul, buku.penulis, buku.penerbit, buku.halaman, buku.tahun, buku.jumlah_tersedia);
    fclose(file);

    printf("Buku berhasil ditambahkan.\n");
}
