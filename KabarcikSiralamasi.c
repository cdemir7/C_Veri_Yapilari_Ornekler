#include <stdio.h>


int main(){
	int dizi[10]={45,12,37,34,55,375,96,85,74,123};
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
	for(c=0;c<11;c++){
		printf("%d,",dizi[c]);
	}
}
