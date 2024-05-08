#include <stdio.h>

// Deklarasi Menu
void showMenu(int isAdmin, int isUser);

int main() {
    int choice;
    int isUser = 1; // 
    int isAdmin = 1; // 

    do {
        // Display menu untuk user
        showMenu(isAdmin, isUser);

       
        printf("Enter your choice: ");
        scanf("%d", &choice); 

      
        switch (choice) {
            case 1:
                // Action for choice 1
                break;
            case 2:
                // Action for choice 2
                break;
            // Add more cases as needed
            default:
                printf("Pilihan salah. Masukkan pilihan yang benar.\n");
        }
    } while (choice != 0); // 

    return 0;
}

// Fungsi display menu
void showMenu(int isAdmin, int isUser) {
    printf("Menu:\n");
    printf("1. Lihat Semua Buku\n");
    printf("2. Pinjam Buku\n");
    printf("3. Kembalikan Buku\n");
    if(isAdmin) {
        printf("4. Tambah Buku\n");
        printf("5. Hapus Buku\n");
    }
    printf("0. Exit\n");
}

