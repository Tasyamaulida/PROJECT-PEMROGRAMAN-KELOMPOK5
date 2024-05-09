void tambah_buku(void) {
    struct Book tambahBuku = {0}; // Inisialisasi struct
    FILE *filePointer; // File pointer
    bool isFirstBook = false;
    char pilihan;

    //Membuka file untuk ditulis
    filePointer = fopen("Berekstensi.txt", "a");
    if (filePointer == NULL) {
        printf("Error: Tidak dapat membuka atau membuat file Berekstensi.txt\n");
        return;
    }

    //Mengecek apakah file kosong
if (ftell(filePointer) == 0) {
    isFirstBook = true;
    fprintf(filePointer, "|%-9s|%-42s|%-22s|%-17s|%-16s|%-14s|%-28s|\n",
            "---------", "----------------------------------------", "--------------------",
            "---------------", "----------------", "--------------", "--------------------------");
}

    do {
        system("cls");
        printf("\n\t\t\t=======================================\n");
        printf("\n\t\t\t          PROGRAM PERPUSTAKAAN         \n");
        printf("\n\t\t\t=======================================\n");

        //Meminta masukan data buku dari pengguna
        printf("\n\t\t\tMasukkan detail buku di bawah ini...\n");
        printf("\t\t\tID BUKU        : ");
        scanf("%u", &tambahBuku.id_buku);
        printf("\t\t\tJUDUL BUKU     : ");
        fflush(stdin);
        fgets(tambahBuku.judul_buku, sizeof(tambahBuku.judul_buku), stdin);
        tambahBuku.judul_buku[strcspn(tambahBuku.judul_buku, "\n")] = '\0'; //Hapus karakter newline
        printf("\t\t\tPENULIS        : ");
        fflush(stdin);
        fgets(tambahBuku.penulis, sizeof(tambahBuku.penulis), stdin);
        tambahBuku.penulis[strcspn(tambahBuku.penulis, "\n")] = '\0'; //Hapus karakter newline
        printf("\t\t\tPENERBIT       : ");
        fflush(stdin);
        fgets(tambahBuku.penerbit_buku, sizeof(tambahBuku.penerbit_buku), stdin);
        tambahBuku.penerbit_buku[strcspn(tambahBuku.penerbit_buku, "\n")] = '\0'; //Hapus karakter newline
        printf("\t\t\tJUMLAH HALAMAN : ");
        scanf("%u", &tambahBuku.halaman);
        printf("\t\t\tTAHUN TERBIT   : ");
        scanf("%u", &tambahBuku.tahun_terbit);
        printf("\t\t\tJUMLAH BUKU YANG TERSEDIA : ");
        scanf("%u", &tambahBuku.list_buku_yang_tersedia);

        // Menulis data buku ke dalam file dalam format teks sebagai tabel
        fprintf(filePointer, "| %-7u | %-40s | %-20s | %-15s | %-14u | %-12u | %-26u |\n", tambahBuku.id_buku, tambahBuku.judul_buku,
                tambahBuku.penulis, tambahBuku.penerbit_buku, tambahBuku.halaman, tambahBuku.tahun_terbit,
                tambahBuku.list_buku_yang_tersedia);

        printf("\n\t\t\tData buku berhasil ditambahkan.\n");
        printf("\n\t\t\tApakah Anda ingin menambahkan data buku lagi? (y/n): ");
        fflush(stdin);
        scanf(" %c", &pilihan);
    } while (pilihan == 'y' || pilihan == 'Y');

    //Menutup file setelah selesai menulis
    fclose(filePointer);

    printf("\n\t\t\tTekan tombol enter untuk kembali ke menu utama");
    fflush(stdin);
    getchar();
    system("cls");

}

int main() {
    tambah_buku();
    return 0;
}
