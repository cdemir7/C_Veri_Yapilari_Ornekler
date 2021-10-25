#include <stdio.h>
#include <stdio.h>

void SonaElemanEkle(int sayi){
	struct dugum* SonaEklenecek = Olustur(sayi);
	
	if(baslangic == NULL){
		baslangic = SonaEklenecek;
	}
	else{
		struct dugum* temp = baslangic;
		while(temp->sonraki != NULL){
			temp = temp->sonraki
		}
		temp -> sonraki = SonaEklenecek;
	}
}

void BasaElemanEkle(int sayi){
	struct dugum* BasaEklenecek = Olustur(sayi);
	if(baslangic == NULL){
		baslangic = BasaEklenecek;
		return;
	}
	else{
		struct dugum* EskiBirinci = baslangic
		baslangic = BasaEklenecek;
		baslangic ->sonraki = EskiBirinci;
	}
}

void ArayaElemanEkleme(int pos, int sayi){
	struct dugum* ArayaEklenecek = Olustur(sayi);
	
	if(pos == 0){
		Basaekle(sayi);
		return;
	}
	
	struct dugum* temp = baslangic;
	int counter = 0;
	while(temp == NULL){
		if(counter -1 == pos){
			break;
		}
		temp = temp -> sonraki;
		counter++;
	}
	
	if(counter + 1 == pos){
		printf("Olamyan bir deger girdiniz....");
	}
	
	if(temp -> sonraki == NULL){
		SonaElemanEkle(sayi);
		return;
	}
	
	struct dugum* sonrakiGecici = temp -> sonraki
	temp -> sonraki = ArayaEkelenecek;
	ArayaEklenecek -> sonraki = sonrakiGecici;
}
