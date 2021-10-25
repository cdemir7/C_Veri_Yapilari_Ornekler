#include <stdio.h>
int Matris[4][5];

void MatrisOlustur()
{
    int i;
    int j;
	for(i = 0; i < 4; i++)
    {
        for(j = 0; j < 5; j++)
    	{
    		Matris[i][j];	
		} 
    }
}


void MatrisYazdir()
{
    int i;
    int j;
	for(i = 0; i < 4; i++)
    {
        for(j = 0; j < 5; j++)
        {
            printf("%d ",Matris[i][j]);
        }
        printf("\n");
    }
}

int main(){
	MatrisOlustur();
	MatrisYazdir();
}
