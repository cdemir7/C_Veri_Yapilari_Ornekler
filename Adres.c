#include <stdio.h>
void change(int *num){
	printf("Ilk deger:%d \n",*num);
	(*num)+= 100;
	printf("Son deger:%d \n",*num);
}

int main(){
	int x = 100;
	printf("X=%d \n",x);
	change(&x);
	printf("X=%d \n",x);
}
