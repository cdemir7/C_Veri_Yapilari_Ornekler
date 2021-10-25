#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define BOYUT 10

int Dizi[BOYUT];

void ElemanEkle(int eklenecek,int indis){
	if(indis > BOYUT - 1){
		printf("Boyutu Astiniz....");
		return;
	}
	Dizi[indis] = eklenecek;
}

void Yazdir(){
	int i;
	for( i = 0; i < BOYUT; i++){
		printf("\n %d",Dizi[i]);
	}

}

void RastgeleElemanEkle(int kacTane){
	int i;
	for( i = 0;i < kacTane; i++){
		int eklenecek = rand() % 50;
		int konum = rand() % BOYUT;
		Dizi[konum] = eklenecek;
	}
}


int main(){
	srand(time(NULL));
	int sayi;
	printf("Kac tane sayi ekleyeceksiniz:");
	scanf("%d",&sayi);
	RastgeleElemanEkle(sayi);
	Yazdir();
	
}
