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
	struct node* eklenecek = Olustur(sayi);
	if(baslangic==NULL){
		baslangic = eklenecek;
	}
	else{
		struct node* gecici = baslangic;
		while(gecici->sonraki != NULL){
			gecici = gecici->sonraki;
		}
		gecici->sonraki = eklenecek;
	}
}

void Yazdir(){
	struct node* temp = baslangic;
	while(temp->sonraki != NULL){
		printf("%d =>",temp->sayi);
		temp = temp->sonraki;
	}
}

int main(){
	int sayi;
	while(1){
		printf("Eklemek istediðiniz sayiyi giriniz:");
		scanf("%d",&sayi);
		Ekle(sayi);
		if(sayi==0){
			Yazdir();
			break;
		}
	}
}
