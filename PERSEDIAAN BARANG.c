#include <stdio.h>
#include <stdbool.h>

#define MAX_BARANG 100

struct Barang {
    int kode;
    char nama[50];
    int stok;
};

struct Barang dataBarang[MAX_BARANG];
int jumlahBarang = 0;

// Fungsi untuk menambahkan data barang
void tambahBarang(int kode, char nama[], int stok) {
    struct Barang barang;
    barang.kode = kode;
    strcpy(barang.nama, nama);
    barang.stok = stok;

    dataBarang[jumlahBarang++] = barang;
}

// Fungsi untuk mencetak daftar barang
void cetakBarang() {
    printf("\nDaftar Barang:\n");
    printf("Kode\tNama\tStok\n");
    printf("==========================\n");

    for (int i = 0; i < jumlahBarang; i++) {
        printf("%d\t%s\t%d\n", dataBarang[i].kode, dataBarang[i].nama, dataBarang[i].stok);
    }
}

// Fungsi untuk melakukan sorting barang berdasarkan kode menggunakan Bubble Sort
void sortBarang() {
    for (int i = 0; i < jumlahBarang - 1; i++) {
        for (int j = 0; j < jumlahBarang - i - 1; j++) {
            if (dataBarang[j].kode > dataBarang[j + 1].kode) {
                // Tukar posisi
                struct Barang temp = dataBarang[j];
                dataBarang[j] = dataBarang[j + 1];
                dataBarang[j + 1] = temp;
            }
        }
    }

    printf("Barang berhasil diurutkan berdasarkan kode.\n");
}

// Fungsi untuk melakukan pencarian barang berdasarkan nama
void cariBarang(char nama[]) {
    bool ditemukan = false;

    for (int i = 0; i < jumlahBarang; i++) {
        if (strcmp(dataBarang[i].nama, nama) == 0) {
            printf("Barang ditemukan:\n");
            printf("Kode: %d\n", dataBarang[i].kode);
            printf("Nama: %s\n", dataBarang[i].nama);
            printf("Stok: %d\n", dataBarang[i].stok);
            ditemukan = true;
            break;
        }
    }

    if (!ditemukan) {
        printf("Barang tidak ditemukan.\n");
    }
}

int main() {
    int pilihan;
    bool selesai = false;

    do {
        printf("\nMenu:\n");
        printf("1. Tambah Barang\n");
        printf("2. Cetak Barang\n");
        printf("3. Urutkan Barang\n");
        printf("4. Cari Barang\n");
        printf("5. Keluar\n");
        printf("Pilihan Anda: ");
        scanf("%d", &pilihan);

        switch (pilihan) {
            case 1: {
                int kode, stok;
                char nama[50];

                printf("Masukkan kode barang: ");
                scanf("%d", &kode);
                printf("Masukkan nama barang: ");
                scanf(" %[^\n]", nama);
                printf("Masukkan stok barang: ");
                scanf("%d", &stok);
		tambahBarang(kode, nama, stok);
	printf("Barang berhasil ditambahkan.\n");
	break;
}
	case 2:
		cetakBarang();
		break;
	case 3:
	sortBarang();
		break;
	case 4: {
	char nama[50];
		printf("Masukkan nama barang yang ingin dicari: ");
		scanf(" %[^\n]", nama);
		cariBarang(nama);
		break;
}
	case 5:
		selesai = true;
		break;
	default:
		printf("Pilihan tidak valid.\n");
}
} while (!selesai);

printf("Program selesai. Terima kasih!\n");

return 0;
}
