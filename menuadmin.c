#include "header.h"

void menuAdmin() {
    int choice;
    do {
        printf("Menu Admin:\n");
        printf("1. Tambah Buku\n");
        printf("2. Hapus Buku\n");
        printf("3. Edit Buku\n");
        printf("4. Logout\n");
        printf("Pilihan Anda: ");
        scanf("%d", &choice);
        getchar(); // Membersihkan newline character dari buffer

        switch (choice) {
            case 1:
                tambahBuku();
                break;
            case 2:
                hapusBuku();
                break;
            case 3:
                editBuku();
                break;
            case 4:
                printf("Logout berhasil.\n");
                break;
            default:
                printf("Pilihan tidak valid.\n");
                break;
        }
    } while (choice != 4);
}