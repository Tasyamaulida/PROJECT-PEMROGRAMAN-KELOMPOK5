
void lihatDaftarBukuDipinjam() {
    FILE *file;
    char judul[100];
    char pilihan;

    file = fopen("datauser.txt", "r");
    if (file == NULL) {
        printf("Anda belum meminjam buku apapun\n");
        return;
    }

    printf("\n\t\t\t==============================================\n");
    printf("\n\t\t\t       PROGRAM LIHAT BUKU YANG DIPINJAM       \n");
    printf("\n\t\t\t==============================================\n");

    printf("Daftar Buku Yang Anda Dipinjam:\n");
    while (fgets(judul, sizeof(judul), file)) {
        printf("%s", judul); 
    }

    fclose(file);

    do {
        printf("\n\t\t\tApakah Anda ingin kembali ke menu utama buku lagi? (Y/N) : ");
        fflush(stdin);
        scanf(" %c", &pilihan);
    } while (pilihan == 'Y' || pilihan == 'y');
}



