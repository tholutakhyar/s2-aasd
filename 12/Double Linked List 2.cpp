#include <stdio.h>
#include <stdlib.h>

struct SNode {
	int data;
	struct SNode *next;
	struct SNode *before;
};

struct SNode *n_awal,
*n_tampil,
*n_bantu;

int iterasi;

void inisialisasi() {
	n_awal = NULL;
}

void tampil_list() {
	n_tampil = n_awal;
	
	while(n_tampil != NULL) {
		printf("%d", n_tampil->data);
		n_tampil = n_tampil->before;
	}
	
	printf("\n");
}

//method untuk insert node baru
void insert_node(int data) {
	//node baru yang akan di insert
	struct SNode *n_insert;
	n_insert = (struct SNode *)malloc(sizeof(struct SNode));
	n_insert->data = iterasi;
	n_insert->next = NULL;
	n_insert->before = NULL;
	
	//kondisi linked list masih kosong
	if (n_awal == NULL) {
		n_awal = n_insert;
	} else {
		n_bantu = n_awal;
		
		//cari node terakhir
		while(n_bantu->next != NULL) {
			n_bantu = n_bantu->next;
		}
		
		//hubungkan node terakhir dengan node baru
		if (n_bantu->next==NULL) {
			n_bantu->next = n_insert;
			n_insert->before = n_bantu;
		}
	}
}

int main(int argc, char *argv[]) {
	inisialisasi();
	
	for(iterasi = 10; iterasi <= 15; iterasi++) {
		insert_node(iterasi);
	}
	
	tampil_list();
	
	system("PAUSE");
	return 0;
}