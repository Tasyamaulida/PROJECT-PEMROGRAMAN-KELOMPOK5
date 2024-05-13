#include <stdio.h>
#include "header.h"

void kembalikanBuku(Buku buku[], Buku buku_dipinjam[], int* jumlah_buku_dipinjam) {
    int bookId;
    printf("Masukkan ID buku yang akan dikembalikan: ");
    scanf("%d", &bookId);

    // Mencari buku berdasarkan ID buku
    int i;
    int index = -1;
    for (i = 0; i < *jumlah_buku_dipinjam; i++) {
        if (buku_dipinjam[i].id == bookId) {
            index = i;
            break;
        }
    }

    if (index != -1) {
        // Tambahkan buku ke daftar buku yang tersedia
        buku[buku_dipinjam[index].id].jumlah_tersedia++;

        // Geser buku dalam array buku_dipinjam
        for (i = index; i < *jumlah_buku_dipinjam - 1; i++) {
            buku_dipinjam[i] = buku_dipinjam[i+1];
        }

        // Kurangi jumlah buku yang dipinjam
        (*jumlah_buku_dipinjam)--;

        printf("Buku berhasil dikembalikan.\n");

        // Simpan perubahan ke file
        FILE *file = fopen("berekstensi.txt", "w");
        if (file != NULL) {
            for (i = 0; i < JUMLAH_BUKU; i++) {
                fprintf(file, "%d,%s,%d\n", buku[i].id, buku[i].judul, buku[i].jumlah_tersedia);
            }
            fclose(file);
        } else {
            printf("Gagal menyimpan perubahan ke file.\n");
        }
    } else {
        printf("Buku dengan ID tersebut tidak ditemukan.\n");
    }
}
