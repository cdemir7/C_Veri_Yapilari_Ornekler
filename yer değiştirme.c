#include <stdio.h>

void swap(int , int);

int main(){
	int a =10;
	int b =20;
	printf("Degerleri degistirmeden once:  a = %d , b = %d\n",a,b);
	swap(a,b);
	printf("Degerleri degistirdikten sonra:  a = %d , b = %d\n",a,b);
}

void swap(int a, int b){
	int gecici;
	gecici = a;
	a = b;
	b = gecici;
	printf("Fonksiyondaki degerleri degistirdikten sonra: a = %d , b = %d\n",a ,b);
}
