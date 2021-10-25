#include <stdio.h>
#define BOYUT 10
int Dizi[BOYUT];

void ElemanEkle(int eklenecek,int indis){
	if(indis > BOYUT - 1){
		printf("Boyutu Astiniz ...");
		return;
	}
	Dizi[indis] = eklenecek;
}

void Yazdir(int vurgula){
	    int i;
	for(i = 0; i < BOYUT; i++){
		if(i == vurgula){
			printf("\n %d <======",Dizi[i]);
		}
		else{
			printf("\n %d",Dizi[i]);
		}
		
	}
}

int main(){
	int secim;
	int sayi, index;
	
	while(1){
		printf("\n");
		printf("\n ****** MENU ******");
		printf("\n 1-) Eleman ekle ...");
		printf("\n Yapmak istediginiz  islemi giriniz: ");
		scanf("%d",&secim);
		
		switch(secim){
			case 1:
				printf("Eklemek istediginiz sayiyi giriniz:");
				scanf("%d",&sayi);
				printf("indisi giriniz:");
				scanf("%d",&index);
				ElemanEkle(sayi,index);
				Yazdir(index);
				break;
		}
		
	}
}
