#include "header.h"

void hapusBuku() {
    unsigned int id;
    printf("Hapus Buku\n");
    printf("Id Buku yang akan dihapus: ");
    scanf("%u", &id);

    // Membuka file sementara untuk menulis data buku yang tidak akan dihapus
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

    // Membaca data buku dari file berekstensi.txt
    Buku buku;
    int found = 0;
    while (fscanf(file, "%u,%[^,],%[^,],%[^,],%u,%u,%u\n", &buku.id, buku.judul, buku.penulis, buku.penerbit, &buku.halaman, &buku.tahun, &buku.jumlah_tersedia) != EOF) {
        // Menyalin data buku ke file sementara jika buku dengan id yang dihapus tidak ditemukan
        if (buku.id != id) {
            fprintf(tempFile, "%u,%s,%s,%s,%u,%u,%u\n", buku.id, buku.judul, buku.penulis, buku.penerbit, buku.halaman, buku.tahun, buku.jumlah_tersedia);
        } else {
            found = 1;
        }
    }

    fclose(file);
    fclose(tempFile);

    // Mengganti file database dengan file sementara
    remove("berekstensi.txt");
    rename("temp.txt", "berekstensi.txt");

    if (found) {
        printf("Buku dengan ID %u berhasil dihapus.\n", id);
    } else {
        printf("Buku dengan ID %u tidak ditemukan.\n", id);
    }
}
