
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#define YD 3
typedef struct PSRT{
	char nama[30];
} PSRT;
typedef struct NILAI{
	int anakpanah1;
	int anakpanah2;
	int anakpanah3;
	int nAkhir;
} NILAI;
 typedef struct DATAPESERTA{
 	PSRT psrt;
 	NILAI nilai;
 } DATAPESERTA;
void menu();
void peserta();
void nilai();
void daftarpeserta();
void infopeserta(int i);
void daftarnilai();
void infonilai(int i);
void caripeserta();
int cariData(char namanya[]);
void lihatJuara();
void urutkan();
DATAPESERTA datapsrt[YD];
void main(){
	printf("============================================\n");
	printf("===== Selamat Datang Di Program Memanah ====\n");
	printf("============================================\n");
	printf("\nTekan enter untuk Masuk ke Manu Pilihan... ");
	getch();
	system("cls");
	menu();
}
void menu(){
	int pilihan;

	printf("MENU PILIHAN\n");
	printf("===================================\n");
	printf("1. Entri Identitas Peserta\n");
	printf("2. Entri Nilai Peserta\n");
	printf("3. Lihat Daftar Peserta\n");
	printf("4. Lihat Daftar Nilai Pertandingan Peserta\n");
	printf("5. Cari Peserta Tertentu\n");
	printf("6. Lihat Para Juara\n");
	printf("0. Keluar\n");
	printf("===================================\n");
	printf("Ketikan nomor pilihan: ");
	scanf("%d", &pilihan); fflush(stdin);
	switch(pilihan){
		case 0: printf("Keluar dari Program\n");
				printf("Terima kasih... Tekan Enter");
				getch();
				exit(1);
		case 1: peserta();
				printf("\nTekan enter untuk kembali ke Manu Pilihan... ");
				getch();
				system("cls");
				menu();
				break;
		case 2: nilai();
				printf("\nTekan enter untuk kembali ke Manu Pilihan... ");
getch();
				system("cls");
				menu();
				break;
		case 3: daftarpeserta();
				printf("\nTekan enter untuk kembali ke Manu Pilihan... ");
				getch();
				system("cls");
				menu();
				break;
		case 4: daftarnilai();
				printf("\nTekan enter untuk kembali ke Manu Pilihan... ");
				getch();
				system("cls");
				menu();
				break;
		case 5: caripeserta();
				printf("\nTekan enter untuk kembali ke Manu Pilihan... ");
				getch();
				system("cls");
				menu();
				break;
		case 6: lihatJuara();
				printf("\nTekan enter untuk kembali ke Manu Pilihan... ");
				getch();
				system("cls");
				menu();
				break;
		default: printf("\nNomor pilihan tidak ada... Tekan Enter...");
				getch();
				system("cls");
				menu();
	}
}
void peserta(){
	int i;
	char namanya[30];
	printf("\nEntri identitas Peserta Pemanah\n");
	printf("========================================\n");
	printf("Jumlah Peserta Panahan: %d Orang\n",YD);
	for(i=0;i<YD;i++){
		printf("Ketikkan Nama Peserta ke-%d: ",i+1);
		gets(namanya); fflush(stdin);
		strcpy(datapsrt[i].psrt.nama, namanya);
	}
	printf("\nEntri Data selesai... Tekan enter...");
}

void nilai(){
	int panah1, panah2, panah3, nAkhirnya;
	char namanya[30];
	int i;
	printf("\nMembaca Nilai Memanah\n");
	printf("========================================\n");
	if(!strcmp(datapsrt[0].psrt.nama, "")){
		printf("\nData Masih Kosong... Tekan enter...");
		getch();
	}
	else{
		for(i=0;i<YD;i++){
			strcpy(namanya, datapsrt[i].psrt.nama);
			printf("Nama Peserta: %s\n",namanya);
			printf("Ketik nilai tembakan pertama	: ");
			scanf("%d",&panah1); fflush(stdin);
			printf("Ketik nilai tembakan kedua	: ");
			scanf("%d",&panah2); fflush(stdin);
			printf("Ketik nilai tembakan Ketiga	: ");
			scanf("%d",&panah3); fflush(stdin);
			datapsrt[i].nilai.anakpanah1 = panah1;
			datapsrt[i].nilai.anakpanah2 = panah2;
			datapsrt[i].nilai.anakpanah3 = panah3;

			nAkhirnya  = panah1 + panah2 + panah3;
			datapsrt[i].nilai.nAkhir = nAkhirnya;
			printf("\n");
		}
	}
}
void daftarpeserta(){
	int i;
	printf("\nDaftar Peserta Pemanah\n");
	printf("=========================================\n");
	if(!strcmp(datapsrt[0].psrt.nama,"")){
		printf("\nData masih Kosong... Tekan enter...");
		getch();
	}
	else{
		for(i=0;i<YD;i++){
			printf("%d. ", i+1);
			infopeserta(i);
		}
	}
}
void infopeserta(int i){
	char namanya[30];

	strcpy(namanya, datapsrt[i].psrt.nama);
	printf("Nama Peserta Pemanah: %s\n", namanya);
	printf("========================================\n");
}

void daftarnilai(){
	int i;
	printf("\nDaftar Nilai Peserta Pemanah\n");
	printf("=========================================\n");
	if(datapsrt[i].nilai.nAkhir == 0.0){
		printf("Data masih Kosong... Tekan enter...");
		getch();
	}
	else{
		for(i=0;i<YD;i++){
			printf("%d. ", i+1);
			infonilai(i);
		}
	}
}
void infonilai(int i){
	char namanya[30];
	int panah1, panah2, panah3, nAkhirnya;

	strcpy(namanya, datapsrt[i].psrt.nama);
	panah1 = datapsrt[i].nilai.anakpanah1;
	panah2 = datapsrt[i].nilai.anakpanah2;
	panah3 = datapsrt[i].nilai.anakpanah3;
	nAkhirnya = datapsrt[i].nilai.nAkhir;
	printf("Nama Peserta: %s\n", namanya);
	printf("\tNilai Tembakan Pertama        	: %d\n", panah1);
	printf("\tNilai Tembakan Kedua        	: %d\n", panah2);
	printf("\tNilai Tembakan Ketiga      	: %d\n", panah3);
	printf("\tNilai Akhir     		: %d\n", nAkhirnya);
	printf("========================================\n");
}
void caripeserta(){
	char namanya[4];
	int posisi;
	if(!strcmp(datapsrt[0].psrt.nama, "")){
		printf("\nData masih Kosong... Tekan enter... ");
	}
	else{
		printf("Ketik nama peserta yang dicari: ");
		gets(namanya); fflush(stdin);
		posisi = caridata(namanya);
		if(posisi == -999){
			printf("\nData tidak ditemukan... Tekan enter...");
			getch();
		}
		else{
			printf("\nData ditemukan\n");
			infonilai(posisi);
		}
	}
}

int caridata(char namanya[]){
	int i, posisi;
	for(i=0;i<YD;i++){
		if(!strcmp(namanya, datapsrt[i].psrt.nama)){
			posisi = i;
			break;
		}
		else {
			posisi = -999;
		}
	}
	return posisi;
}

void lihatJuara(){
	int i;
	printf("\nPara Juara dengan Nilai Tertinggi\n");
	printf("========================================\n");
	if(datapsrt[0].nilai.nAkhir == 0.0){
		printf("\nData masih kosong... tekan enter...");
		getch();
	}
	else{
		urutkan();
		for(i=0;i<3;i++){
			printf("Juara ke-%d\n", i+1);
			infonilai(i);
		}
	}
}
void urutkan() {
   int indexMaks,i,j;
   DATAPESERTA temp;
   //loop untuk seluruh data
   for(i = 0; i < YD-1; i++) {
      indexMaks = i;
      for(j = i+1;j < YD;j++) {
         if(datapsrt[j].nilai.nAkhir > datapsrt[indexMaks].nilai.nAkhir) {
            indexMaks = j;
         }
      }
      if(indexMaks != i) {
         temp = datapsrt[indexMaks];
         datapsrt[indexMaks] = datapsrt[i];
         datapsrt[i] = temp;
      }
   }
}
