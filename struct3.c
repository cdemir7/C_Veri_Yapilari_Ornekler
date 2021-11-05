#include <stdio.h>
#include <stdlib.h>

struct contact{
	int c_id;
	struct contact *next;
};
struct contact* start = NULL; //başlangıç düğümü
struct contact* temporary = NULL; //geçici düğüm
struct contact* delete = NULL; //silme düğümü

void List_Insert(struct contact *data);
void List_Print();
int List_Search(int id);
int List_Delete(int id);
int main(){
	//eklenecek düğümler
	struct contact* c_one = (struct contact*)malloc(sizeof(struct contact));
	struct contact* c_two = (struct contact*)malloc(sizeof(struct contact));
	struct contact* c_three = (struct contact*)malloc(sizeof(struct contact));
	struct contact* c_four = (struct contact*)malloc(sizeof(struct contact));
	struct contact* c_five = (struct contact*)malloc(sizeof(struct contact));
	struct contact* c_six = (struct contact*)malloc(sizeof(struct contact));
	//Listeye ekleme ve yazdırma
	c_one->c_id = 20;
	c_one->next = NULL;
	List_Insert(c_one);
	List_Print();
 	
	c_two->c_id = 14;
	c_two->next = NULL;
	List_Insert(c_two);
	List_Print();
	
	c_three->c_id = 26;
	c_three->next = NULL;
	List_Insert(c_three);
	List_Print();
	
	c_four->c_id = 56;
	c_four->next = NULL;
	List_Insert(c_four);
	List_Print();
	
	c_five->c_id = 787;
	c_five->next = NULL;
	List_Insert(c_five);
	List_Print();
	
	c_six->c_id = 45;
	c_six->next = NULL;
	List_Insert(c_six);
	List_Print();
	
	int j = 20; //aranacak değer
	int k = List_Search(j); //dönüş değeri
	if (k) //aranan elemen listede var ise
		printf("Aranan eleman %d. sirada ve %d degerinde\n", k, j);
	else
		printf("%d Not found\n",j);
	List_Delete(26); //silinecek düğümün id değeri
	List_Print(); //son liste görünümü
	free(c_one);
	free(c_five);
	free(c_four);
	free(c_six);
	free(c_three);
	free(c_two);
	getchar();
	return 0;
}

void List_Insert(struct contact *data){
	if (start == NULL) //liste boş ise
	{
		start = data; //liste başına ekleme
	}
	else
	{
		temporary = start; //başlangıç elemanı geçici düğümüne aktarma
		while (temporary->next != NULL) //liste sonuna gelinmediyse
		{
			temporary = temporary->next; //bir sonraki düğümü geçici düğüme ata
		}
		temporary->next = data; //son eleman bulunduğunda eklenecek düğümü sona ekleme
	}
}

void List_Print(){
	temporary = start; //başlangıç elemanı geçici düğümüne aktarma
	if (temporary != NULL) //listede eleman varsa
	{
		while (temporary->next != NULL) //son elemana gelene kadar devam et
		{
			printf("%d->", temporary->c_id); //ekrana bas
			temporary = temporary->next; //sonraki düğümü geçici düğüme aktar
		}
		printf("%d\n", temporary->c_id); //son düğümü ekrana bas
	}
	else
	{
		printf("Liste bos"); //liste boş ise
	}


}

int List_Search(int id){
	int i = 1; //sıra tutma değişkeni
	if (start == NULL) //liste boş ise
		printf("Liste boş\n");
	else
	{
		temporary = start; //başlangış düğümünü tut
		while (1) //sonsuz dön
		{
			if (temporary != NULL && temporary->c_id == id)
			{
				return i; //düğüm sırasını döndür
			}
			else if (temporary == NULL)
			{
				return 0; //düğüm bulunamadığında
			}
			i++;
			temporary = temporary->next; //sonraki düğümü geçici düğüme aktar
		}
	}
}

int List_Delete(int id){
	if (List_Search(id) != 0) //düğüm listede var mı?
	{
		if (start->next == NULL && start->c_id == id) //listede bir düğüm varsa
		{
			start = NULL; // düğümü sil
			return 0;
		}
		temporary = start; //sonraki düğümü geçici düğüme aktar
		delete = temporary; //silinen düğümden önceki düğümü tut
		while (1){

			if (temporary->next != NULL && temporary->c_id == id){
				if (List_Search(id) == 1) //ilk düğüm ise
				{
					start = temporary->next; //geçici düğümü ilk düğüm yap
					return 1;
				}
				else //düğüm ortada ise
				{
					delete->next = temporary->next; //önceki düğüm sonrakini göstersin
					return 0;
				}

			}
			else if (temporary->next == NULL && temporary->c_id == id) //düğüm sonda ise
			{
				delete->next = NULL; //önceki düğüm boşu göstersin
				return 1;
			}
			delete = temporary; //önceki düğümü tut
			temporary = temporary->next; //sonraki düğüme geç
		}

	}
	else //düğüm yok ise
	{
		printf("Silinecek %d degeri bulunamadı...\n", id);
	}
}
