#include <stdio.h>
#include <stdlib.h>

struct node{
	int sayi;
	struct node* sonraki;
};

struct node* baslangic = NULL;

struct node* Olustur(int sayi){
	struct node* YeniDugum = (struct node*)malloc(sizeof(struct node));
	YeniDugum->sayi=sayi;
	YeniDugum->sonraki= NULL;
	return YeniDugum;
}

void Ekle(int sayi){
	struct node* Eklenecek = Olustur(sayi);
	
	if(baslangic== NULL){
		baslangic = Eklenecek;
	}
	else{
		struct node* gecici = baslangic;
		while(gecici->sonraki != NULL){
			gecici = gecici->sonraki;
		}
		gecici->sonraki = Eklenecek;
	}
}

void Yazdir(){
	struct node* gecici = baslangic;
	while(gecici->sonraki!=NULL){
		printf("%d =>",gecici->sayi);
		gecici = gecici->sonraki;
	}
	
}


int main(){
	int dizi[10]={2,3,6,3,4,1,9,8,2,6};
	int i;
	int j;
	int temp;
	for(i=2;i<10;i++){
		for(j=0;j<10;j++){
			if(dizi[j]>dizi[j+1]){
				temp= dizi[j];
				dizi[j]=dizi[j+1];
				dizi[j+1]=temp;
			}
		}
	}
	int c;
	for(c=0;c<10;c++){
		printf("%d,",dizi[c]);
	}
	printf("\n");
	int k;
	for(k=0;k<11;k++){
		Ekle(dizi[k]);
	}
	Yazdir();
}
