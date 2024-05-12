#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header.h"

int login(char* username, char* password) {
    if (strcmp(username, "akunuser") == 0 && strcmp(password, "kelompok5") == 0) {
        return 0;  // User
    } else if (strcmp(username, "akunadmin") == 0 && strcmp(password, "kelompok5") == 0) {
        return 1;  // Admin
    } else {
        return -1;  // Gagal login
    }
}

void menuAdmin();
void menuUser();

int main() {
    char username[20];
    char password[20];

    printf("Username: ");
    scanf("%s", username);

    printf("Password: ");
    scanf("%s", password);

    // Melakukan login
    int isAdmin = login(username, password);

    if (isAdmin == -1) {
        printf("Username atau password salah.\n");
        return 0;
    } else if (isAdmin) {
        // Menjalankan program admin
        printf("Selamat datang, Admin!\n");
        menuAdmin();
    } else {
        // Menjalankan program user
        printf("Selamat datang, User!\n");
        menuUser();
    }

    return 0;
}