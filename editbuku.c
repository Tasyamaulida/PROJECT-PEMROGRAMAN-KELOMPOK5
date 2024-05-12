#include <string.h>
#include "header.h"

void editBuku() {
    unsigned int id;
    printf("Edit Buku\n");
    printf("Id Buku yang akan diedit: ");
    scanf("%u", &id);

    // Membuka file sementara untuk menulis data buku yang akan diedit
    FILE *tempFile = fopen("temp.txt", "w");
    if (tempFile == NULL) {
        printf("Gagal membuka file.\n");
        return;
    }

    // Membuka file database
    FILE *file = fopen("berekstensi.txt", "r");
    if (file == NULL) {
        printf("Gagal membuka file.\n");
        fclose(tempFile);
        return;
    }

    // Membaca data buku dari file
    Buku buku;
    int found = 0;
    while (fscanf(file, "%u,%[^,],%[^,],%[^,],%u,%u,%u\n", &buku.id, buku.judul, buku.penulis, buku.penerbit, &buku.halaman, &buku.tahun, &buku.jumlah_tersedia) != EOF) {
        // Menyalin data buku ke file sementara jika buku dengan id yang diedit tidak ditemukan
        if (buku.id != id) {
            fprintf(tempFile, "%u,%s,%s,%s,%u,%u,%u\n", buku.id, buku.judul, buku.penulis, buku.penerbit, buku.halaman, buku.tahun, buku.jumlah_tersedia);
        } else {
            found = 1;

            // Membaca data buku yang baru dari pengguna
            printf("Data Buku yang Baru\n");
            printf("Judul: ");
            getchar(); // Membersihkan newline character dari buffer
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

            // Menulis data buku yang baru ke file sementara
            fprintf(tempFile, "%u,%s,%s,%s,%u,%u,%u\n", buku.id, buku.judul, buku.penulis, buku.penerbit, buku.halaman, buku.tahun, buku.jumlah_tersedia);
        }
    }

    fclose(file);
    fclose(tempFile);

    // Mengganti file database dengan file sementara
    remove("berekstensi.txt");
    rename("temp.txt", "berekstensi.txt");

    if (found) {
        printf("Buku dengan ID %u berhasil diedit.\n", id);
    } else {
        printf("Buku dengan ID %u tidak ditemukan.\n", id);
    }
}