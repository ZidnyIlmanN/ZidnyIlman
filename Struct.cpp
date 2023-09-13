#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Mahasiswa {
    char nama[50];
    int umur;
    char asal[50];
    struct Mahasiswa* next;
};

struct Mahasiswa* top = NULL;

void tambahData() {
    struct Mahasiswa* new_node = (struct Mahasiswa*)malloc(sizeof(struct Mahasiswa));
    printf("Masukkan Nama   : ");
    scanf(" %[^\n]s", new_node->nama);
    printf("Masukkan Umur   : ");
    scanf("%d", &(new_node->umur));
    printf("Masukkan Asal   : ");
    scanf(" %[^\n]s", new_node->asal);

    new_node->next = top;
    top = new_node;
}

void hapusData() {
    if (top == NULL) {
        printf("Tidak ada data\n");
        return;
    }

    int nomor;
    printf("Masukkan nomor data yang ingin dihapus: ");
    scanf("%d", &nomor);

    if (nomor < 1) {
        printf("Nomor data tidak valid\n");
        return;
    }

    struct Mahasiswa* current = top;
    struct Mahasiswa* previous = NULL;

    // Jika data yang ingin dihapus adalah data pertama
    if (nomor == 1) {
        top = top->next;
        printf("Data Mahasiswa Berikut Telah Dihapus:\n");
        printf("Nama : %s\n", current->nama);
        printf("Umur : %d\n", current->umur);
        printf("Asal : %s\n", current->asal);
        free(current);
        return;
    }

    // Mencari data yang ingin dihapus
    for (int i = 1; i < nomor && current != NULL; i++) {
        previous = current;
        current = current->next;
    }

    if (current == NULL) {
        printf("Nomor data tidak valid\n");
        return;
    }

    // Menghapus data
    previous->next = current->next;
    printf("Data Mahasiswa Berikut Telah Dihapus:\n");
    printf("Nama : %s\n", current->nama);
    printf("Umur : %d\n", current->umur);
    printf("Asal : %s\n", current->asal);
    free(current);
}

void tampilkanData() {
    if (top == NULL) {
        printf("Tidak ada data yang tersimpan\n");
        return;
    }
    struct Mahasiswa* current = top;
    int nomor = 1;
    printf("Data Mahasiswa:\n");
    while (current != NULL) {
        printf("Nomor : %d\n", nomor);
        printf("Nama : %s\n", current->nama);
        printf("Umur : %d\n", current->umur);
        printf("Asal : %s\n\n", current->asal);
        current = current->next;
        nomor++;
    }
}

void ubahData() {
    if (top == NULL) {
        printf("Tidak ada data\n");
        return;
    }

    int nomor;
    printf("Masukkan nomor data yang ingin diubah: ");
    scanf("%d", &nomor);

    if (nomor < 1) {
        printf("Nomor data tidak valid\n");
        return;
    }

    struct Mahasiswa* current = top;

    // Mencari data yang ingin diubah
    for (int i = 1; i < nomor && current != NULL; i++) {
        current = current->next;
    }

    if (current == NULL) {
        printf("Nomor data tidak valid\n");
        return;
    }

    printf("Masukkan Nama baru   : ");
    scanf(" %[^\n]s", current->nama);
    printf("Masukkan Umur baru   : ");
    scanf("%d", &(current->umur));
    printf("Masukkan Asal baru   : ");
    scanf(" %[^\n]s", current->asal);

    printf("Data Mahasiswa Berikut Telah Diubah:\n");
    printf("Nama : %s\n", current->nama);
    printf("Umur : %d\n", current->umur);
    printf("Asal : %s\n", current->asal);
}

int main() {
    int choice;

    while (1) {
        printf("\n1. Tambah Data Mahasiswa\n2. Hapus Data Mahasiswa\n3. Tampilkan Data Mahasiswa\n4. Ubah Data Mahasiswa\n5. Exit\n");
        printf("Mau ngapain nih: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                tambahData();
                break;
            case 2:
                hapusData();
                break;
            case 3:
                tampilkanData();
                break;
            case 4:
                ubahData();
                break;
            case 5:
                exit(0);
            default:
                printf("Pilihan tidak valid\n");
        }
    }

    return 0;
}

