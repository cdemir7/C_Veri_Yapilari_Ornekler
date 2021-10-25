#include <stdio.h>
#include <stdlib.h>

int main(){
	int dizi[10]={2,3,6,3,14,1,9,8,2,6};
	int i,enBuyuk;
	int max = 0;
	for(int i = 0;i<10;i++){
		if(dizi[i] > enBuyuk){
			enBuyuk = dizi[i];
		}
	}
	printf("En buyuk sayi: %d",enBuyuk);
	return 0;
}



