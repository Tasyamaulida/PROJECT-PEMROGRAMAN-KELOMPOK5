#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h>

#define MAKS_JUDUL_BUKU 50
#define MAKS_NAMA_PENULIS 50
#define MAKS_PENERBIT 50
#define MAKS_PEMINJAMAN 50
#define MAKS_NAMA_PEMINJAM 50
#define MAKS_USER 20
#define MAKS_PASS 20

//Struct?
typedef struct Buku {
  int id_buku;
  char judul_buku[MAKS_JUDUL_BUKU];
  char penerbit_buku[MAKS_PENERBIT];
  char penulis[MAKS_NAMA_PENULIS];
  int jumlah_halaman;
  int tahun_terbit;
  int list_buku_yang_tersedia;
}
Buku;

typedef struct Bukup{
  int id_bukup;
  char judulp_buku[MAKS_JUDUL_BUKU];
  char batas[MAKS_PEMINJAMAN];
  char nama_peminjam[MAKS_NAMA_PEMINJAM];
  int nim;
}
Bukup;

typedef enum {
  ADMIN,
  USER
} Role;

typedef struct {
  char username[50];
  char password[50];
  Role role;
} User;

int main() {
  // Data pengguna
  User users[] = {
    {"admin", "admin123", ADMIN},
    {"user", "user123", USER}
  };

  // Menampilkan menu login
  int pilihan;
  do {
    printf("\nMenu Login:\n");
    printf("1. Login Admin\n");
    printf("2. Login User\n");
    printf("3. Keluar\n");
    printf("Masukkan pilihan: ");
    scanf("%d", &pilihan);

    switch (pilihan) {
      case 1:
        loginAdmin(users);
        break;
      case 2:
        loginUser(users);
        break;
      case 3:
        printf("Keluar dari program...\n");
        break;
      default:
        printf("Pilihan tidak valid!\n");
    }
  } while (pilihan != 3);

  return 0;
}

void loginAdmin(User users[]) {
  char username[50], password[50];
  printf("\nLogin Admin:\n");
  printf("Username: ");
  scanf("%s", username);
  printf("Password: ");
  scanf("%s", password);

  int found = 0;
  for (int i = 0; i < sizeof(users) / sizeof(User); i++) {
    if (strcmp(username, users[i].username) == 0 && strcmp(password, users[i].password) == 0 && users[i].role == ADMIN) {
      printf("Login berhasil!\n");
      // Tampilkan halaman admin
      tampilHalamanAdmin();
      found = 1;
      break;
    }
  }

  if (!found) {
    printf("Username atau password salah!\n");
  }
}

void loginUser(User users[]) {
  char username[50], password[50];
  printf("\nLogin User:\n");
  printf("Username: ");
  scanf("%s", username);
  printf("Password: ");
  scanf("%s", password);

  int found = 0;
  for (int i = 0; i < sizeof(users) / sizeof(User); i++) {
    if (strcmp(username, users[i].username) == 0 && strcmp(password, users[i].password) == 0 && users[i].role == USER) {
      printf("Login berhasil!\n");
      // Tampilkan halaman user
      tampilHalamanUser();
      found = 1;
      break;
    }
  }

  if (!found) {
    printf("Username atau password salah!\n");
  }
}

void tampilHalamanAdmin() {
  int pilihan;
  do {
    system("cls");
    system("color B0");
    printf("\t\t\t===========================================================================");
    printf("\n\t\t\t------------                                                   ------------ ");
    printf("\n\t\t\t------------   | PROGRAM PERPUSTAKAAN KELOMPOK 5  |   ---------------------- ");
    printf("\n\t\t\t------------                                                   ------------ ");
    printf("\n\t\t\t=========================================================================== ");
    printf("\n\t\t\t--------------------------------------------------------------------------- ");
    printf("\n\t\t\t                     <<< Selamat Berkunjung :D >>>                          ");
    printf("\n\t\t\t--------------------------------------------------------------------------- ");
    scanf("%*[^\n]");
    fflush(stdin);

    int b;
    char j_menu[50] = "|>>> MENU PROGRAM <<<|";
    char j_pilihan[25] = "Masukan Pilihan : ";
    printf("\n\n\t");
    for (b = 0; b < 22; b++) {
      Sleep(50);
      printf("%c", j_menu[b]);

    }
    printf("\n\n");
    printf("\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n");
    printf("\t\xB2 1. Menambahkan buku    \xB2\n");
    printf("\t\xB2 2. Menghapus buku      \xB2\n");
    printf("\t\xB2 3. Laporan Peminjaman  \xB2\n");
    printf("\t\xB2 4. edit                 \xB2\n");
    printf("\t\xB2 5. Kembali             \xB2\n");
    printf("\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    printf("\n\n\t");
    for (b = 0; b < 18; b++) {
      Sleep(50);
      printf("%c", j_pilihan[b]);

    }
    scanf("%i", & pilihan);
    fflush(stdin);

    switch (pilihan) {
    case 1:
      tambah_buku();
      break;
    case 2:
      delete_buku();
      break;
    case 3:
      laporan_peminjam();
      break;
    case 4:
      edit_buku();
      break;
    case 5:
      exit(0);
      break;
    default:
      printf("Masukan input yang benar!");
    }
  } while (pilihan != 5);

}

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
    fprintf(filePointer, "| %-7s | %-40s | %-20s | %-15s | %-14s | %-12s | %-26s |\n",
            "ID BUKU", "JUDUL BUKU", "PENULIS", "PENERBIT", "JUMLAH HALAMAN", "TAHUN TERBIT", "JUMLAH BUKU YANG TERSEDIA");
    fprintf(filePointer, "|%-9s|%-42s|%-22s|%-17s|%-16s|%-14s|%-28s|\n",
            "---------", "----------------------------------------", "--------------------",
            "---------------", "----------------", "--------------", "--------------------------");
}

    do {
        system("cls");
        printf("\n\t\t\t============================================\n");
        printf("\n\t\t\t          PROGRAM PERPUSTAKAAN KELOMPOK 5       \n");
        printf("\n\t\t\t==============================================\n");

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
  //Fungsi delete buku
  int ketemu = 0, buku = 0;
  FILE * filePointer;
  FILE * tempfP;
  Buku tambahBuku = {
    0
  }; //Memanggil ke struct ke fungsi
  filePointer = fopen("berekstensi.txt", "r");
  tempfP = fopen("temp.txt", "w");

  printf("\n\t\t\tMasukan Kode Buku untuk didelete:");
  fflush(stdin);
  scanf(" %d", & buku);

  while (fread( & tambahBuku, sizeof(tambahBuku), 1, filePointer)) {
    if (tambahBuku.id_buku != buku) {
      fwrite( & tambahBuku, sizeof(tambahBuku), 1, tempfP);
    } else {
      ketemu = 1;
    }
  }
  if (ketemu == 0) {
    printf("\n\t\t\tBuku berhasil di-delete");
    getchar();
  } else {
    printf("\n\t\t\tBuku tidak ditemukan");
    getchar();
  }
  fclose(filePointer);
  fclose(tempfP);
  remove("berekstensi.txt");
  rename("temp.txt", "berekstensi.txt");
  printf("\n\t\t\tTekan tombol enter untuk kembali ke menu utama");
  fflush(stdin);
  getchar();
  system("cls");
}

void laporan_peminjam(void){
  system("cls");
  printf("\t\t\t===========================================================================");
  printf("\n\t\t\t------------                                                   ------------ ");
  printf("\n\t\t\t------------      | PROGRAM PERPUSTAKAAN KELOMPOK 5    |       ------------ ");
  printf("\n\t\t\t------------                                                   ------------ ");
  printf("\n\t\t\t=========================================================================== ");
  printf("\n\t\t\t--------------------------------------------------------------------------- ");
  printf("\n\t\t\t                      <<< Menu Lihat Buku Dipinjam >>>                      ");
  printf("\n\t\t\t--------------------------------------------------------------------------- ");

  //Fungsi lihat buku yang dipinjam
  int ketemu = 0;
  char judulp_buku[MAKS_JUDUL_BUKU] = {
    0
  };
  Bukup peminjaman = {
    0
  }; //Memanggil ke struct ke fungsi
  FILE * filePointer;
  filePointer = fopen("berekstensi.txt", "r");
  while (fread( & peminjaman, sizeof(peminjaman), 1, filePointer)) {
    printf("\n\t\t\tid Buku        = %u", peminjaman.id_bukup);
    printf("\n\t\t\tNama Buku        = %s", peminjaman.judulp_buku);
    printf("\t\t\tBatas Peminjaman = %s", peminjaman.batas);
    printf("\n\t\t\t");
    ketemu = 1;
  }

  fclose(filePointer);
  if (!ketemu) {
    printf("\n\t\t\tNo Record");
  }
  printf("\n\t\t\tTekan tombol enter untuk kembali ke menu utama");
  fflush(stdin);
  getchar();
  system("cls");
}

void edit_buku(void){
    Buku editbuku = {
        0
    };
 FILE *fp = fopen("berekstensi.txt", "r+");
  printf("id buku: %d\n", editbuku.id_buku);
  printf("judul buku: %s\n", editbuku.judul_buku);
  printf("penulis: %s\n", editbuku.penulis);
  printf("penerbit: %s\n", editbuku.penerbit_buku);
  printf("jumlah halaman: %.d\n\n", editbuku.jumlah_halaman);
  printf("tahun terbit: %.d\n\n", editbuku.tahun_terbit);
  printf("list buku yang tersedia: %.d\n\n", editbuku.list_buku_yang_tersedia);
}

// Function to edit a book's information
void editbuku(Buku *buku) {
    int pilihan;

    do {
        printf("\nEdit Menu Edit Buku:\n");
        printf("1. Edit Id Buku\n");
        printf("2. Edit Judul Buku\n");
        printf("3. Edit Penulis Buku\n");
        printf("4. Edit Penerbit Buku\n");
        printf("5. Edit Jumlah Halaman Buku\n");
        printf("6. Edit Tahun Terbit\n");
        printf("7. Edit List Buku Yang Tersedia\n");
        printf("6. Simpan and Kembali\n");
        printf("Masukkan Pilihan: ");
        scanf("%d", &pilihan);

        switch (pilihan) {
            case 1:
                printf("masukkan id buku: ");
                scanf("%s[^\n]", buku->id_buku);
                break;
            case 2:
                printf("masukkan judul buku: ");
                scanf("%s[^\n]", buku->judul_buku);
                break;
            case 3:
                printf("masukkan penulis buku: ");
                scanf("%d", &buku->penulis);
                break;
            case 4:
                printf("masukkan penerbit buku: ");
                scanf("%f", &buku->penerbit_buku);
                break;
            case 5:
                printf("masukkan jumlah halaman buku: ");
                scanf("%f", &buku->jumlah_halaman);
                break;
            case 6:
                printf("masukkan tahun terbit: ");
                scanf("%f", &buku->tahun_terbit);
                break;
            case 7:
                printf("masukkan list buku yang tersedia: ");
                scanf("%f", &buku->list_buku_yang_tersedia);
                break;
            case 8:
                printf("simpan dan kembali:");
                break;
            default:
                printf("pilihan tidak valid. ulangi lagi.\n");
        }
    } while (pilihan != 8);
}

void tampilHalamanUser() {
 int pilihan;
  do {
    system("cls");
    system("color B0");
    printf("\t\t\t===========================================================================");
    printf("\n\t\t\t------------                                                   ------------ ");
    printf("\n\t\t\t------------   | PROGRAM PERPUSTAKAAN KELOMPOK 5  |   ---------------------- ");
    printf("\n\t\t\t------------                                                   ------------ ");
    printf("\n\t\t\t=========================================================================== ");
    printf("\n\t\t\t--------------------------------------------------------------------------- ");
    printf("\n\t\t\t                     <<< Selamat Berkunjung :D >>>                          ");
    printf("\n\t\t\t--------------------------------------------------------------------------- ");
    scanf("%*[^\n]");
    fflush(stdin);

    int b;
    char j_menu[50] = "|>>> MENU PROGRAM <<<|";
    char j_pilihan[25] = "Masukan Pilihan : ";
    printf("\n\n\t");
    for (b = 0; b < 22; b++) {
      Sleep(50);
      printf("%c", j_menu[b]);

    }
    printf("\n\n");
    printf("\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n");
    printf("\t\xB2 1. Melihat Buku                  \xB2\n");
    printf("\t\xB2 2. Peminjaman Buku               \xB2\n");
    printf("\t\xB2 3. Melihat Buku Yang Di Pinjam   \xB2\n");
    printf("\t\xB2 4. Pengembalian Buku             \xB2\n");
    printf("\t\xB2 5. Kembali                       \xB2\n");
    printf("\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    printf("\n\n\t");
    for (b = 0; b < 18; b++) {
      Sleep(50);
      printf("%c", j_pilihan[b]);

    }
    scanf("%i", & pilihan);
    fflush(stdin);

    switch (pilihan) {
    case 1:
      lihat_buku();
      break;
    case 2:
      pinjam_buku();
      break;
    case 3:
      melihat_buku_yang_dipinjam();
      break;
    case 4:
      pengembalian_buku();
      break;
    case 5:
      exit(0);
      break;
    default:
      printf("Masukan input yang benar!");
    }
  } while (pilihan != 5);
}

void lihat_buku(void) {
  system("cls");
  printf("\t\t\t===========================================================================");
  printf("\n\t\t\t------------                                                   ------------ ");
  printf("\n\t\t\t------------   | PROGRAM PERPUSTAKAAN UNIVERSITAS UDAYANA  |   ------------ ");
  printf("\n\t\t\t------------                                                   ------------ ");
  printf("\n\t\t\t=========================================================================== ");
  printf("\n\t\t\t--------------------------------------------------------------------------- ");
  printf("\n\t\t\t                        <<< Menu Lihat Buku >>>                           ");
  printf("\n\t\t\t--------------------------------------------------------------------------- ");

  //Fungsi lihat buku
  int ketemu = 0;
  char judulBuku[MAKS_JUDUL_BUKU] = {
    0
  };
  Buku tambahBuku = {
    0
  }; //Memanggil ke struct ke fungsi
  FILE * filePointer;
  filePointer = fopen("Buku.bin", "rb");
  while (fread( & tambahBuku, sizeof(tambahBuku), 1, filePointer)) {
    printf("\n\t\t\tKode Buku = %d", tambahBuku.id_buku);
    printf("\n\t\t\tNama Buku = %s", tambahBuku.judul_buku);
    printf("\t\t\tPenulis = %s", tambahBuku.penulis);
    printf("\t\t\tJenis Buku = %s", tambahBuku.penerbit_buku);
    printf("\t\t\tHalaman = %d", tambahBuku.jumlah_halaman);
    printf("\n\t\t\tHarga =%d", tambahBuku.tahun_terbit);
     printf("\n\t\t\tHarga =%d", tambahBuku.list_buku_yang_tersedia);
    printf("\n\t\t\t");
    ketemu = 1;
  }
  fclose(filePointer);
  if (!ketemu) {
    printf("\n\t\t\tNo Record");
  }
  printf("\n\t\t\tTekan tombol enter untuk kembali ke menu utama");
  fflush(stdin);
  getchar();
  system("cls");
}

