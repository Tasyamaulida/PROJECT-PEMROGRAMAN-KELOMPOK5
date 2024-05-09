
void lihatDaftarBuku() {
    FILE *file;
    char judul[100];
    char pilihan;

    do {
        file = fopen("Berekstensi.txt", "r");
        if (file == NULL) {
            printf("Gagal membuka file berekstensi.txt.\n");
            return;
        }

        system("cls");
        printf("\n\t\t\t=======================================\n");
        printf("\n\t\t\t       PROGRAM LIHAT BUKU       \n");
        printf("\n\t\t\t=======================================\n");

        printf("Daftar Buku:\n");
        while (fgets(judul, sizeof(judul), file)) {
            printf("%s", judul);
        }

        fclose(file);

        printf("\n\t\t\tApakah Anda ingin melihat daftar buku lagi? (Y/N) : ");
        fflush(stdin);
        scanf(" %c", &pilihan);
    } while (pilihan == 'Y' || pilihan == 'y');
}
