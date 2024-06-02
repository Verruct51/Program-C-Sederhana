#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define N 3 //banyaknya mahassiswa

#define MID 0.25 //prosentase nilai mid adalah 25 persen
#define UAS 0.30 //prosentase nilai uas adalah 30 persen
#define TGS 0.30 //prosentase nilai tugas adalah 30 persen
#define QSZ 0.15 //prosentase nilai quiz adalah 15 persen

//mendefinisikan tipe bentukan berupa struct bernama MHS
typedef struct MHS{
	char nama[30]; //panjang nama mahasiswa adalah 30 karakter
	char nim[4];  //panjang nim mahasiswa adalah 5 karakter
} MHS; //nama tipe bentukan adalah MHS

typedef struct NILAI{
	double mid;
	double uas;
	double tugas;
	double quiz;
	double nAkhir; //dihitung dengan fungsi hitungAkhir()
	char nHuruf; //diisi melalui pemanggilan fungsi konversiHuruf()
} NILAI;

//kedua tipe MHS dan NILAI digunakan untuk tipe bentukan baru
//suatu stract of struct atau struct di dalam struct, sehingga
//struct yang baru memili seluruh data baik identitas maupun
//nilai2 mahasiswa, sbb:
 typedef struct DATAMHS{
 	MHS mhs;
 	NILAI nilai;
 } DATAMHS;

//deklarasi fungsi yang akan digunakan
void judul();
void menu();
void bacaMhs();
void bacaNilai();
void daftarMhs();
void infoMhs(int i);
void daftarNilai();
void infoNilai(int i);
double hitungAkhir(double m, double u, double t, double q);
char konversiHuruf(double na);
void cariMhs();
int cariData(char nimnya[]);
void lihatJuara();
void urutkan();
void rekapNilai();
void rekapMid();
void rekapUas();
void rekapTugas();
void rekapQuiz();
void rekapAkhir();
void rekapHuruf();

//deklarasi variabel global berupa array of struct dari tipe DATAMHS sbb:
DATAMHS dataMhs[N]; //banyak mahasiswa adalah N orang

main(){
	char jawab = 'Y';

	judul();
	do{
		menu();
		printf("\nKembali ke Menu Pilihan (Y/T)?: ");
		jawab = getche();
	}
	while(toupper(jawab)=='Y');
	printf("\nTerima kasih...");
	getch();
}

void judul(){
	printf("===================================================================\n");
	printf("Program Pengolahan Data Mahasiswa\n");
	printf("Programmer : Alvin Anugerah Pratama\n");
	printf("NIM        : 22343019\n");
	printf("===================================================================\n");
	printf("Tekan tombol enter...");
	getch();
}

void menu(){
	int pilihan;

	printf("\n\nMENU PILIHAN\n");
	printf("===================================\n");
	printf("1. Entri Identitas Mahasiswa\n");
	printf("2. Entri Nilai Mahasiswa\n");
	printf("3. Lihat Daftar Mahasiswa\n");
	printf("4. Lihat Daftar Nilai\n");
	printf("5. Cari Mahasiswa Tertentu\n");
	printf("6. Lihat Para Juara\n");
	printf("7. Lihat Rekapitulasi Nilai\n");
	printf("0. Keluar\n");
	printf("===================================\n");
	printf("Ketikan nomor pilihan: ");
	scanf("%d", &pilihan); fflush(stdin);

	switch(pilihan){
		case 0: printf("Keluar dari Program\n");
				printf("Terima kasih... Tekan Enter");
				getch();
				exit(1);
		case 1: bacaMhs();
				printf("\nTekan enter untuk kembali ke Manu Pilihan... ");
				getch();
				menu();
				break;
		case 2: bacaNilai();
				printf("\nTekan enter untuk kembali ke Manu Pilihan... ");
				getch();
				menu();
				break;
		case 3: daftarMhs();
				printf("\nTekan enter untuk kembali ke Manu Pilihan... ");
				getch();
				menu();
				break;
		case 4: daftarNilai();
				printf("\nTekan enter untuk kembali ke Manu Pilihan... ");
				getch();
				menu();
				break;
		case 5: cariMhs();
				printf("\nTekan enter untuk kembali ke Manu Pilihan... ");
				getch();
				menu();
				break;
		case 6: lihatJuara();
				printf("\nTekan enter untuk kembali ke Manu Pilihan... ");
				getch();
				menu();
				break;
		case 7: rekapNilai();
				printf("\nTekan enter untuk kembali ke Manu Pilihan... ");
				getch();
				menu();
		default: printf("\nNomor pilihan tidak ada... Tekan Enter...");
				getch();
				menu();
	}
}

void bacaMhs(){
	int i; //variable konter perulangan
	char namanya[30]; //penyimpan sementara nama mahasiswa
	char nimnya[4]; //penyimpan sementara nim mahasiswa

	printf("\nMembaca identitas sejumlah Mahasiswa\n");
	printf("========================================\n");
	printf("Jumlah Mahasiswa: %d Orang\n",N);
	for(i=0;i<N;i++){
		printf("Ketikkan nama Mahasiswa ke-%d: ",i+1);
		gets(namanya); fflush(stdin); //baca nama mahasiswa
		printf("Ketikkan NIM  Mahasiswa     : ");
		gets(nimnya); fflush(stdin); //baca nim mahasiswa
		//masukan nama dan nim mahasiswa ke array of struct
		strcpy(dataMhs[i].mhs.nama, namanya); //perhatikan cara mengakses field
		strcpy(dataMhs[i].mhs.nim, nimnya);
	}
	printf("\nEntri Data selesai... Tekan enter...");
}

void bacaNilai(){
	double midnya, uasnya, tugasnya, quiznya, nAkhirnya;
	char nHurufnya;
	char namanya[30], nimnya[4];
	int i;

	printf("\nMembaca Nilai-nilai Mahasiswa\n");
	printf("========================================\n");
	//cek dulu apakah mahasiswanya sudah ada?
	if(!strcmp(dataMhs[0].mhs.nim, "")){
		printf("\nData Masih Kosong... Tekan enter...");
		getch();
	}
	else{
		for(i=0;i<N;i++){
			strcpy(namanya, dataMhs[i].mhs.nama);
			strcpy(nimnya, dataMhs[i].mhs.nim);
			printf("Nama Mahasiswa: %s\n",namanya);
			printf("NIM			  : %s\n",nimnya);
			printf("Ketik nilai MID  : ");
			scanf("%lf",&midnya); fflush(stdin);
			printf("Ketik nilai UAS  : ");
			scanf("%lf",&uasnya); fflush(stdin);
			printf("Ketik nilai TUGAS: ");
			scanf("%lf",&tugasnya); fflush(stdin);
			printf("Ketik nilai QUIZ : ");
			scanf("%lf",&quiznya); fflush(stdin);
			//lalu masukkan ke array dataMhs, sbb
			dataMhs[i].nilai.mid = midnya;
			dataMhs[i].nilai.uas = uasnya;
			dataMhs[i].nilai.tugas = tugasnya;
			dataMhs[i].nilai.quiz = quiznya;
			//lalu panggil fungsi untuk menghitung nilai akhir dan
			//tampung nilai baliknya pada variabel nAkhirnya
			nAkhirnya  = hitungAkhir(midnya, uasnya, tugasnya, quiznya);
			//lalu panggil fungsi untuk mengkonveri nilai akhir ke nilai huruf
			//dg passing parameter berupa nilai akhir atau nAkhirnya
			//tampung hasil atau nilai baliknya pada variabel nHurufnya
			nHurufnya = konversiHuruf(nAkhirnya);
			//simpan nilai akhir dan nilai huruf ke dataMhs
			dataMhs[i].nilai.nAkhir = nAkhirnya;
			dataMhs[i].nilai.nHuruf = nHurufnya;
			printf("\n");
		}
	}
}

void daftarMhs(){
	int i;

	printf("\nDaftar Mahasiswa Peserta Kuliah\n");
	printf("=========================================\n");

	//cek dulu apakah datanya kosong?
	if(!strcmp(dataMhs[0].mhs.nim,"")){
		printf("\nData masih Kosong... Tekan enter...");
		getch();
	}
	else{
		for(i=0;i<N;i++){
			printf("%d. ", i+1);
			infoMhs(i);
		}
	}
}


//fungsi ini harus dimodifikasi melibatkan data nilai2
void infoMhs(int i){
	char namanya[30]; //penyimpan sementara nama mahasiswa
	char nimnya[4]; //penyimpan sementara nim mahasiswa

	//salin dulu data mahasiswa ke variabel sementara
	strcpy(namanya, dataMhs[i].mhs.nama);
	strcpy(nimnya, dataMhs[i].mhs.nim);

	//tampilkan informasi mahasiswa yang diminta
	printf("Nama Mahasiswa: %s\n", namanya);
	printf("\tNIM	   : %s\n", nimnya);
	printf("========================================\n");
}

void daftarNilai(){
	int i;

	printf("\nDaftar Nilai Mahasiswa Peserta Kuliah\n");
	printf("=========================================\n");

	//cek dulu datanya
	if(dataMhs[i].nilai.nAkhir == 0.0){
		printf("Data masih Kosong... Tekan enter...");
		getch();
	}
	else{
		for(i=0;i<N;i++){
			printf("%d. ", i+1);
			infoNilai(i);
		}
	}
}

void infoNilai(int i){
	char namanya[30]; //penyimpan sementara nama mahasiswa
	char nimnya[4]; //penyimpan sementara nim mahasiswa
	double midnya, uasnya, tugasnya, quiznya, nAkhirnya;
	char nHurufnya;

	//salin dulu data nilai ke variabel sementara
	strcpy(namanya, dataMhs[i].mhs.nama);
	strcpy(nimnya, dataMhs[i].mhs.nim);

	//tampung dulu nilai-nilainya
	midnya = dataMhs[i].nilai.mid;
	uasnya = dataMhs[i].nilai.uas;
	tugasnya = dataMhs[i].nilai.tugas;
	quiznya = dataMhs[i].nilai.quiz;
	nAkhirnya = dataMhs[i].nilai.nAkhir;
	nHurufnya = dataMhs[i].nilai.nHuruf;
	//tampilkan informasi mahasiswa yang diminta
	printf("Nama Mahasiswa: %s\n", namanya);
	printf("\tNIM			   : %s\n", nimnya);
	printf("\tNilai MID        : %0.1lf\n", midnya);
	printf("\tNilai UAS        : %0.1lf\n", uasnya);
	printf("\tNilai Tugas      : %0.1lf\n", tugasnya);
	printf("\tNilai Quiz       : %0.1lf\n", quiznya);
	printf("\tNilai Akhir      : %0.1lf\n", nAkhirnya);
	printf("\tNilai Huruf      : %c\n", nHurufnya);
	printf("========================================\n");
}

double hitungAkhir(double m, double u, double t, double q){
	double nAkhirnya;

	nAkhirnya = m * MID + u * UAS + t * TGS + q * QSZ;
	return nAkhirnya;
}

char konversiHuruf(double na){
	char nHurufnya;
	//tentukan nilai hurufnya
	if((na >= 81.0) && (na<= 100.0))
		nHurufnya = 'A';
	else if(na >= 76.0)
		nHurufnya = 'B';
	else if(na >= 56.0)
		nHurufnya = 'C';
	else if(na >= 45.0)
		nHurufnya = 'D';
	else nHurufnya = 'E';

	return nHurufnya; //kirim hasilnya sebagai nilai balik
}

void cariMhs(){
	char nimnya[4];
	int posisi;

	//cek dulu datanya
	if(!strcmp(dataMhs[0].mhs.nim, "")){
		printf("\nData masih Kosong... Tekan enter... ");
	}
	else{
		printf("Ketik NIM yang dicari: ");
		gets(nimnya); fflush(stdin);
		posisi = cariData(nimnya);
		if(posisi == -999){
			printf("\nData tidak ditemukan... Tekan enter...");
			getch();
		}
		else{
			printf("\nData ditemukan\n");
			//tampilkan
			infoNilai(posisi);
		}
	}
}

int cariData(char nimnya[]){
	int i, posisi;

	//cari nim tersebut di array nim
	for(i=0;i<N;i++){
		if(!strcmp(nimnya, dataMhs[i].mhs.nim)){
			posisi = i;
			break;
		}
		else {
			posisi = -999; //nilai ini menunjukkan data tdk ditemukan
		}
	}
	return posisi; //posisi data dikirim sebagai nilai balik
}

void lihatJuara(){
	int i;

	printf("\nPara Juara dengan Nilai Tertinggi\n");
	printf("========================================\n");
	//cek dulu keberadaan datanya
	if(dataMhs[0].nilai.nAkhir == 0.0){
		printf("\nData masih kosong... tekan enter...");
		getch();
	}
	else{
		//urutkan dulu datanya
		urutkan();
		for(i=0;i<3;i++){
			printf("Juara ke-%d\n", i+1);
			infoNilai(i);
		}
	}
}

void urutkan() { //metode selection sort
   int indexMaks,i,j;
   DATAMHS temp; //variabel sementara berupa struct DATAMHS

   //loop untuk seluruh data
   for(i = 0; i < N-1; i++) {

      // elemen sekarang yang dianggap nilai maksimum
      indexMaks = i;

      //periksa nilai akhir terbesar
      for(j = i+1;j < N;j++) {
         if(dataMhs[j].nilai.nAkhir > dataMhs[indexMaks].nilai.nAkhir) {
            indexMaks = j;
         }
      }

      if(indexMaks != i) {//kalau posisinya bukan posisi awal
         // pertukarkan posisi data
         temp = dataMhs[indexMaks];
         dataMhs[indexMaks] = dataMhs[i];
         dataMhs[i] = temp;
      }
   }
}

void rekapNilai(){
	printf("\nRekapitulasi Nilai Mahasiswa\n");
	printf("====================================\n");

	//cek dulu apakah datanya ada?
	if(dataMhs[0].nilai.nAkhir == 0.0){
		printf("\nData masih kosong... Tekan enter...");
		getch();
	}
	else{
		rekapMid();
		rekapUas();
		rekapTugas();
		rekapQuiz();
		rekapAkhir();
		rekapHuruf();
	}
}

void rekapMid(){
	double rerata = 0.0;
	double jumlah = 0.0;
	int i;

	for(i=0;i<N;i++){
		jumlah += dataMhs[i].nilai.mid;
	}
	rerata = jumlah/N;
	printf("\nRata-rata nilai MID  : %0.1lf\n", rerata);
}

void rekapUas(){
	double rerata = 0.0;
	double jumlah = 0.0;
	int i;

	for(i=0;i<N;i++){
		jumlah += dataMhs[i].nilai.uas;
	}
	rerata = jumlah/N;
	printf("\nRata-rata nilai UAS  : %0.1lf\n", rerata);
}

void rekapTugas(){
	double rerata = 0.0;
	double jumlah = 0.0;
	int i;

	for(i=0;i<N;i++){
		jumlah += dataMhs[i].nilai.tugas;
	}
	rerata = jumlah/N;
	printf("\nRata-rata nilai Tugas: %0.1lf\n", rerata);
}

void rekapQuiz(){
	double rerata = 0.0;
	double jumlah = 0.0;
	int i;

	for(i=0;i<N;i++){
		jumlah += dataMhs[i].nilai.quiz;
	}
	rerata = jumlah/N;
	printf("\nRata-rata nilai Quis : %0.1lf\n", rerata);
}

void rekapAkhir(){
	double rerata = 0.0;
	double jumlah = 0.0;
	int i;

	for(i=0;i<N;i++){
		jumlah += dataMhs[i].nilai.nAkhir;
	}
	rerata = jumlah/N;
	printf("\nRata-rata nilai Akhir: %0.1lf\n", rerata);
}

void rekapHuruf(){
	int hurufA=0, hurufB=0, hurufC=0, hurufD=0, hurufE=0;
	int i;

	//hitung yang memperoleh nilai A
	for(i=0;i<N;i++){
		if(dataMhs[i].nilai.nHuruf == 'A'){
			hurufA += 1;
		}
	}
	printf("\nMemperoleh nilai A: %d Orang\n", hurufA);

	//hitung yang memperoleh nilai B
	for(i=0;i<N;i++){
		if(dataMhs[i].nilai.nHuruf == 'B'){
			hurufB += 1;
		}
	}
	printf("\nMemperoleh nilai B: %d Orang\n", hurufB);
	//hitung yang memperoleh nilai C
	for(i=0;i<N;i++){
		if(dataMhs[i].nilai.nHuruf == 'C'){
			hurufC += 1;
		}
	}
	printf("\nMemperoleh nilai C: %d Orang\n", hurufC);
	//hitung yang memperoleh nilai D
	for(i=0;i<N;i++){
		if(dataMhs[i].nilai.nHuruf == 'D'){
			hurufD += 1;
		}
	}
	printf("\nMemperoleh nilai D: %d Orang\n", hurufD);
	//hitung yang memperoleh nilai E
	for(i=0;i<N;i++){
		if(dataMhs[i].nilai.nHuruf == 'E'){
			hurufE += 1;
		}
	}
	printf("\nMemperoleh nilai E: %d Orang\n", hurufE);
}

