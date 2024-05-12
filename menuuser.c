#include "header.h"

void menuUser() {
    int pilihan;
    do {
        printf("Menu User\n");
        printf("1. List Buku Tersedia\n");
        printf("2. Pinjam Buku\n");
        printf("3. Kembalikan Buku\n");
        printf("4. List Buku Dipinjam\n");
        printf("5. Keluar\n");
        printf("Pilihan Anda: ");
        scanf("%d", &pilihan);

        switch (pilihan) {
            case 1:
                listBukuTersedia();
                break;
            case 2:
                pinjamBuku();
                break;
            case 3:
                kembalikanBuku();
                break;
            case 4:
                listBukuDipinjam();
                break;
            case 5:
                printf("Terima kasih. Sampai jumpa!\n");
                break;
            default:
                printf("Pilihan tidak valid. Silakan pilih kembali.\n");
                break;
        }
    } while (pilihan != 5);
}