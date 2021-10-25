#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <limits.h>


struct Yigin{
int boyut;
int tepe;
int *array;
};

int disk = 3;

struct Yigin* Olustur(int boyut);
int Dolu(struct Yigin* yigin);
int Bos(struct Yigin* yigin);
void yap(struct Yigin *yigin, int item);
int pop(struct Yigin* yigin);
void diski_Tasi(char cubuktan, char cubuga, int disk);
void diskleri_Iki_Cubuk_Arasinda_Tasi(struct Yigin *src,
            struct Yigin *dest, char s, char d);
void yinelemeli(int disk, struct Yigin*src, struct Yigin *aux,struct Yigin *dest);



int main(){
    struct Yigin *src, *dest, *aux;

    src = Olustur(disk);
    aux = Olustur(disk);
    dest = Olustur(disk);

    yinelemeli(disk, src, aux, dest);
    return 0;
}

struct Yigin* Olustur(int boyut){
    struct Yigin* yigin =
        (struct Yigin*) malloc(sizeof(struct Yigin));
    yigin -> boyut = boyut;
    yigin -> tepe = -1;
    yigin -> array =
        (int*) malloc(yigin -> boyut * sizeof(int));
    return yigin;
}

int Dolu(struct Yigin* yigin){
return (yigin->tepe == yigin->boyut - 1);
}

int Bos(struct Yigin* yigin){
return (yigin->tepe == -1);
}


void yap(struct Yigin *yigin, int item){
    if (Dolu(yigin))
        return;
    yigin -> array[++yigin -> tepe] = item;
}

int pop(struct Yigin* yigin){
    if (Bos(yigin))
        return INT_MIN;
    return yigin -> array[yigin -> tepe--];
}


void diski_Tasi(char cubuktan, char cubuga, int disk){
    printf("Disk %d  \'%c\' den  \'%c\' ye  tasiyin...\n",
        disk, cubuktan, cubuga);
}


void diskleri_Iki_Cubuk_Arasinda_Tasi(struct Yigin *src,
            struct Yigin *dest, char s, char d){
    int cubuk1UstDisk = pop(src);
    int pole2TopDisk = pop(dest);


    if (cubuk1UstDisk == INT_MIN){
        yap(src, pole2TopDisk);
        diski_Tasi(d, s, pole2TopDisk);
    }


    else if (pole2TopDisk == INT_MIN){
        yap(dest, cubuk1UstDisk);
        diski_Tasi(s, d, cubuk1UstDisk);
    }


    else if (cubuk1UstDisk > pole2TopDisk){
        yap(src,cubuk1UstDisk);
        yap(src, pole2TopDisk);
       diski_Tasi(d, s, pole2TopDisk);
    }


    else{
        yap(dest, pole2TopDisk);
        yap(dest, cubuk1UstDisk);
        diski_Tasi(s, d, cubuk1UstDisk);
    }
}


void yinelemeli(int disk, struct Yigin
            *src, struct Yigin *aux,
            struct Yigin *dest)
			{
    int i, toplam_hamle_sayisi;
    char s = 'S', d = 'D', a = 'A';


    if (disk % 2 == 0){
        char temp = d;
        d = a;
        a = temp;
    }
    toplam_hamle_sayisi = pow(2, disk) - 1;

    for (i = disk; i >= 1; i--)
        yap(src, i);

    for (i = 1; i <= toplam_hamle_sayisi; i++){
        if (i % 3 == 1)
        diskleri_Iki_Cubuk_Arasinda_Tasi(src, dest, s, d);

        else if (i % 3 == 2)
        diskleri_Iki_Cubuk_Arasinda_Tasi(src, aux, s, a);

        else if (i % 3 == 0)
        diskleri_Iki_Cubuk_Arasinda_Tasi(aux, dest, a, d);
    }
}
