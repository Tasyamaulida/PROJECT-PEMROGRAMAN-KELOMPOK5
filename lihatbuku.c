#include "header.h"

void listBukuTersedia() {
    printf("List Buku Tersedia:\n");

    FILE *file;
    char judul[100];

    
        file = fopen("berekstensi.txt", "r");
        if (file == NULL) {
            printf("Gagal membuka file berekstensi.txt.\n");
            return;
        }

        printf("\n\t\t\t==============================================================================================================");
        printf("\n\t\t\t\t\t\t\t       LIHAT BUKU TERSEDIA       \n");
        printf("\n\t\t\t==============================================================================================================\n");

        printf("Daftar Buku:\n");
        while (fgets(judul, sizeof(judul), file)) {
            printf("%s", judul);
        }

        fclose(file);
    
}
