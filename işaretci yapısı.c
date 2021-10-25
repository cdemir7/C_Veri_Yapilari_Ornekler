#include <stdio.h>

struct kisi{
	int yas;
	float kilo;
};

int main(){
	struct kisi *kisiKs, kisi1;
	kisiKs = &kisi1;
	printf("Yasinizi giriniz:");
	scanf("%d",&kisiKs->yas);
	printf("Kilonuzu giriniz:");
	scanf("%f",&kisiKs->kilo);
	printf("Kisi\n");
	printf("Yasiniz:%d",kisiKs->yas);
	printf("\nKilonuz:%f",kisiKs->kilo);
}
