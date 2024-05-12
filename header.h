#ifndef HEADER_H
#define HEADER_H

#include <stdio.h>

// Maksimum jumlah buku yang dapat dipinjam
#define MAX_BUKU_DIPINJAM 100
#define JUMLAH_BUKU 100

// Struktur data buku
typedef struct {
    unsigned int id;
    char judul[100];
    char penulis[100];
    char penerbit[100];
    unsigned int halaman;
    unsigned int tahun;
    unsigned int jumlah_tersedia;
} Buku;

// Fungsi-fungsi admin
void tambahBuku();
void hapusBuku();
void editBuku();

// Fungsi-fungsi user
void listBukuTersedia();
void pinjamBuku();
void kembalikanBuku();
void listBukuDipinjam();

// Fungsi utilitas
int login(char* username, char* password);

#endif