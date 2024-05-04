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

}void tambah_buku(void) {
  Buku tambahBuku = {
    0
  }; //Memanggil ke struct ke fungsi
  FILE * filePointer; //filepointer
  filePointer = fopen("berekstensi.txt", "a+");

  system("cls");
  printf("\t\t\t===========================================================================");
  printf("\n\t\t\t------------                                                   ------------ ");
  printf("\n\t\t\t------------       | PROGRAM PERPUSTAKAAN KELOMPOK 5  |        ------------ ");
  printf("\n\t\t\t------------                                                   ------------ ");
  printf("\n\t\t\t=========================================================================== ");
  printf("\n\t\t\t--------------------------------------------------------------------------- ");
  printf("\n\t\t\t                         <<< Menu Tambah Buku >>>                           ");
  printf("\n\t\t\t--------------------------------------------------------------------------- ");

  //Fungsi nambahin buku
  printf("\n\t\t\tMasukan detail buku dibawah...\n");
  printf("\t\tid buku   :");
  fflush(stdin);
  scanf("%u", & tambahBuku.id_buku);
  printf("\t\tJudul Buku   :");
  fflush(stdin);
  fgets(tambahBuku.judul_buku, MAKS_JUDUL_BUKU, stdin);
  printf("\t\t\tNama Penulis:");
  fflush(stdin);
  fgets(tambahBuku.penulis, MAKS_NAMA_PENULIS, stdin);
  printf("\t\t\tPenerbit Buku  :");
  fflush(stdin);
  fgets(tambahBuku.penerbit_buku, MAKS_PENERBIT, stdin);
  printf("\t\t\tHalaman     :");
  scanf("%u", & tambahBuku.jumlah_halaman);
  printf("\t\tTahun Terbit     :");
  scanf("%u", & tambahBuku.tahun_terbit);
  printf("\t\t\tJumlah Yang Tersedia       :");
  scanf("%f", & tambahBuku.list_buku_yang_tersedia);

  //Write ke file
  fwrite( & tambahBuku, sizeof(tambahBuku), 1, filePointer);
  fclose(filePointer);
  printf("\n\t\t\tBuku sudah ditambahkan ke database\n");
  printf("\n\t\t\tTekan tombol enter untuk kembali ke menu utama");
  fflush(stdin);
  getchar();
  system("cls");
}
