#include <stdio.h>
#include <stdlib.h>

struct dugum{
	int sayi;
	struct dugum* sonraki;
};

struct dugum* baslangic = NULL;

struct dugum* Olustur(int sayi){
	struct dugum* YeniDugum =(struct dugum*)malloc(sizeof(struct dugum));
	YeniDugum->sayi = sayi;
	YeniDugum->sonraki = NULL;
	
	return YeniDugum;
}


int main(){
	baslangic = Olustur(3);
	struct dugum* ikinci = Olustur(7);
	struct dugum* ucuncu = Olustur(34);
	struct dugum* dorduncu = Olustur(45);
	struct dugum* besinci = Olustur(37);
	
	baslangic->sonraki = ikinci;
	ikinci->sonraki = ucuncu;
	ucuncu->sonraki = dorduncu;
	dorduncu->sonraki = besinci;
	
	struct dugum* temp = baslangic;
	while(temp != NULL){
		printf("%d ",temp->sayi);
		temp = temp -> sonraki;
	}
	
	
}
