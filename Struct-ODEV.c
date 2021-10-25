#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

struct GidaDisi{
	char isim[20];
	int maliyet;
	char tur[1];
	int reyonNo;
	char reyonTarafi[1];
}G;

struct Sut{
	char isim[20];
	int maliyet;
	char skt[10];
}S;

struct KONSERVE{
	char isim[20];
	int maliyet;
	char skt[10];
	int reyonNo;
	char reyonTarafi[1];
}K;

struct ET{
	char isim[20];
	int maliyet;
	char tur[1];
	char paketlenmeTarihi[10];
	char skt[10];
}E;

struct TARIM{
	char isim[20];
	int maliyet;
	char tur[1];
	char alinmaTarihi[10];
}T;

char urun_kaydet(char secim){
	char y[1];
	
	printf("\n Urun Kategorisini Seciniz(E,T,S,K,G) -> ");
    scanf("%c", &secim);
    switch(secim){
        case 'E':
            printf("\n Urun Adini Giriniz: ");
            scanf("%c", E.isim);
            printf("\n Urunun TL Cinsinden Birim Maliyetini Giriniz: ");
            scanf("%d", &E.maliyet);
            printf("Et'in Turunu Giriniz(R,B,P):");
            scanf("%c", E.tur);
            printf("Paketlenme Tarihini Giriniz(#-#-#):");
            scanf("%s", E.paketlenmeTarihi);
            printf("SKT Giriniz(#-#-#):");
            scanf("%s", E.skt);
			break;
        case 'T':
            printf("\n Urun Adini Giriniz: ");
            scanf("%c", T.isim);
            printf("\n Urunun TL Cinsinden Birim Maliyetini Giriniz: ");
            scanf("%d", &T.maliyet);
            printf("Tarim Turunu Giriniz(M,S):");
            scanf("%c", T.tur);
            printf("Alinma Tarihini Giriniz(#-#-#):");
            scanf("%s", T.alinmaTarihi);
            break;
        case 'S':
            printf("\n Urun Adini Giriniz: ");
            scanf("%c", S.isim);
            printf("\n Urunun TL Cinsinden Birim Maliyetini Giriniz: ");
            scanf("%d", &S.maliyet);
            printf("SKT Giriniz(#-#-#):");
            scanf("%s", S.skt);
            break;
        case 'K':
            printf("\n Urun Adini Giriniz: ");
            scanf("%c", K.isim);
            printf("\n Urunun TL Cinsinden Birim Maliyetini Giriniz: ");
            scanf("%d", &K.maliyet);
            printf("SKT Giriniz(Sadece Ay ve Yil):");
            scanf("%s", K.skt);
            printf("\n Reyon Numarasini Giriniz: ");
            scanf("%d", &K.reyonNo);
            printf("\n Reyon Tarafini Giriniz: ");
            scanf("%c", K.reyonTarafi);
            break;
		case 'G':
			printf("\n Urun Adini Giriniz: ");
            scanf("%c", G.isim);
            printf("\n Urunun TL Cinsinden Birim Maliyetini Giriniz: ");
            scanf("%d", &G.maliyet);
            printf("Tarim Turunu Giriniz(M,S):");
            scanf("%c", G.tur);
            printf("\n Reyon Numarasini Giriniz: ");
            scanf("%d", &G.reyonNo);
            printf("\n Reyon Tarafini Giriniz: ");
            scanf("%c", G.reyonTarafi);
		}
	
}

void urun_goster(){
	printf("***************Kayýtlý Ürünler***************\n");
	printf("%s  %dTL  %s %s\n",T.isim,T.maliyet,T.tur,T.alinmaTarihi);
	printf("%s  %d  %s  %s  %s\n",E.isim,E.maliyet,E.tur,E.paketlenmeTarihi,E.skt);

	printf("%s  %dTL  %s\n",S.isim,S.maliyet,S.skt);
	printf("%s  %dTL  %s  %d  %s\n",K.isim,K.maliyet,K.skt,K.reyonNo,K.reyonTarafi);
	printf("%s  %dTL  %s  %d  %s\n",G.isim,G.maliyet,G.tur,G.reyonNo,G.reyonTarafi);
}

int main(){
	char kategori[1];
	while (1){
		printf("Ürün Kategorisini Seçiniz (E,T,S,K,G) -> ");
		scanf("%c",&kategori);
		switch(kategori){
			case 'E':
				urun_kaydet('E');
				printf("Cýkmak icin c'ye basin.Devam etmek istiyorsaniz herhangi bir tusa basin.' ");
			scanf("%s",kategori);
			if(kategori[0] == 'c'){
				break;
			}
			else{
				continue;
			}
			break;
		
		   	case 'T':
		   		urun_kaydet('T');
				printf("Cýkmak icin c'ye basin.Devam etmek istiyorsaniz herhangi bir tusa basin.' ");
			scanf("%s",kategori);
			if(kategori[0] == 'c'){
				break;
			}
			else{
				continue;
			}
			break;
			
			case 'S':
				urun_kaydet('S');
				printf("Cýkmak icin c'ye basin.Devam etmek istiyorsaniz herhangi bir tusa basin.' ");
			scanf("%s",kategori);
			if(kategori[0] == 'c'){
				break;
			}
			else{
				continue;
			}
			break;
			
			case 'K':
				urun_kaydet('K');
				printf("Cýkmak icin c'ye basin.Devam etmek istiyorsaniz herhangi bir tusa basin.' ");
			scanf("%s",kategori);
			if(kategori[0] == 'c'){
				break;
			}
			else{
				continue;
			}
			break;
			
			case 'G':
				urun_kaydet('G');
				printf("Cýkmak icin c'ye basin.Devam etmek istiyorsaniz herhangi bir tusa basin.' ");
			scanf("%s",kategori);
			if(kategori[0] == 'c'){
				break;
			}
			else{
				continue;
			}
			break;
			
			default:
				printf("Aradiginiz kategori bulunamadi!!!\n");
			    
		}
	urun_goster();
		return 0;
	}
}
