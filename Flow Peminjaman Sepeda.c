#include <stdio.h>
#include <string.h>

#define JUMLAH_SEPEDA 5
#define PANJANG_NAMA 50

char sepeda[JUMLAH_SEPEDA][20] = {"Sepeda Gunung", "Sepeda Lipat", "Sepeda Balap", "Sepeda Kota", "Sepeda Listrik"};
char status[JUMLAH_SEPEDA][PANJANG_NAMA] = {"Tersedia", "Tersedia", "Tersedia", "Tersedia", "Tersedia"};

void tampilkan_sepeda() {
    printf("\nDaftar Sepeda:\n");
    for (int i = 0; i < JUMLAH_SEPEDA; i++) {
        printf("%d. %s - %s\n", i + 1, sepeda[i], status[i]);
    }
}

void pinjam_sepeda() {
    tampilkan_sepeda();
    int pilihan;
    char nama[PANJANG_NAMA];
    printf("Masukkan nomor sepeda yang ingin dipinjam: ");
    scanf("%d", &pilihan);
    getchar(); 

    if (pilihan < 1 || pilihan > JUMLAH_SEPEDA) {
        printf("Pilihan tidak valid.\n");
        return;
    }

    if (strcmp(status[pilihan - 1], "Tersedia") == 0) {
        printf("Masukkan nama peminjam: ");
        fgets(nama, sizeof(nama), stdin);
        nama[strcspn(nama, "\n")] = 0; 
        sprintf(status[pilihan - 1], "Dipinjam oleh %s", nama);
        printf("%s berhasil dipinjam.\n", sepeda[pilihan - 1]);
    } else {
        printf("Sepeda tidak tersedia.\n");
    }
}

void kembalikan_sepeda() {
    tampilkan_sepeda();
    int pilihan;
    printf("Masukkan nomor sepeda yang ingin dikembalikan: ");
    scanf("%d", &pilihan);

    if (pilihan < 1 || pilihan > JUMLAH_SEPEDA) {
        printf("Pilihan tidak valid.\n");
        return;
    }

    if (strncmp(status[pilihan - 1], "Dipinjam", 8) == 0) {
        strcpy(status[pilihan - 1], "Tersedia");
        printf("%s berhasil dikembalikan.\n", sepeda[pilihan - 1]);
    } else {
        printf("Sepeda memang sedang tersedia.\n");
    }
}

int main() {
    int pilihan;

    do {
        printf("\n--- Sistem Peminjaman Sepeda ---\n");
        printf("1. Lihat daftar sepeda\n");
        printf("2. Pinjam sepeda\n");
        printf("3. Kembalikan sepeda\n");
        printf("4. Keluar\n");
        printf("Pilih menu: ");
        scanf("%d", &pilihan);

        switch(pilihan) {
            case 1:
                tampilkan_sepeda();
                break;
            case 2:
                pinjam_sepeda();
                break;
            case 3:
                kembalikan_sepeda();
                break;
            case 4:
                printf("Terima kasih telah menggunakan layanan peminjaman sepeda kami.\n");
                break;
            default:
                printf("Pilihan tidak valid.\n");
        }
    } while(pilihan != 4);

    return 0;
}
