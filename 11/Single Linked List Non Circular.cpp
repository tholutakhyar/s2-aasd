#include <iostream>
#include <conio.h>
using namespace std;
struct TNode {
	int data;
	TNode *next;
};

TNode *head, *tail;

void init() {
	head = NULL;
	tail = NULL;
}

int isEmpty(){
	if(tail == NULL) return 1;
	else return 0;
}

void insertDepan(int databaru){ 
	TNode *baru;
	baru = new TNode;
	baru->data = databaru;
	baru->next = NULL;
	
	if(isEmpty()==1){
		head=tail=baru;
		tail->next=NULL;
	} else {
		baru->next = head;
		head = baru;
	}
	
	cout<<"Data masuk\n";
}

void insertBelakang(int databaru) {
	TNode *baru,*bantu;
	baru = new TNode;
	baru->data = databaru;
	baru->next = NULL;
	if(isEmpty()==1) {
		head=baru;
		tail=baru;
		tail->next = NULL;
	} else {
		tail->next = baru;
		tail=baru;
	}
	
	cout<<"Data masuk\n";
}

void tampil(){
	TNode *bantu;
	bantu = head;
	
	cout<<"Data: ";
	
	if(isEmpty()==0){
		while(bantu!=NULL) {
			cout<<bantu->data<<" ";
			bantu=bantu->next;
		}
	} else cout<<"Data Masih kosong\n";
}

void hapusDepan(){
	TNode *hapus;
	int d;
	if (isEmpty()==0) {
		if(head!=tail) {
			hapus = head;
			d = hapus->data;
			head = head->next;
			delete hapus;
		} else {
			d = tail->data;
			head=tail=NULL;
		}
		cout<<d<<"terhapus";
	} else cout<<"Masih kosong\n";
}

void hapusBelakang() {
	TNode *bantu,*hapus;
	int d;
	if (isEmpty()==0) {
		bantu = head;
		if(head!=tail) {
			while(bantu->next!=tail){
				bantu = bantu->next;
			}
			hapus = tail;
			tail=bantu;
			d = hapus->data;
			delete hapus;
			tail->next = NULL;
		} else {
			d = tail->data;
			head=tail=NULL;
		}
		cout<<d<<" terhapus\n";
	} else cout<<"Masih kosong\n";
}

main() {
	int pil,databaru;
	do {
		cout<<endl;
		cout<<"|---------------------------------|"<<endl;
		cout<<"| SINGLE LINKED LIST NON CIRCULAR |"<<endl;
		cout<<"|---------------------------------|"<<endl;
		cout<<"\n1. Insert Depan";
		cout<<"\n2. Insert Belakang";
		cout<<"\n3. Delete Depan";
		cout<<"\n4. Delete Belakang";
		cout<<"\n5. Tampil Data";
		cout<<"\n6. Selesai";
		cout<<"\n---------------------------------";
		cout<<"\nSilahkan Masukan Pilihan Anda : ";cin>>pil;
		cout<<"\n";
		
		switch (pil) {
			case 1:
				{system ("cls");
				cout<<"Masukkan Data = ";
				cin>>databaru;
				insertDepan(databaru);
				break;
				}
			case 2:
				{system ("cls");
				cout<<"Masukkan Data = ";
				cin>>databaru;
				insertBelakang(databaru);
				break;
				}
			case 3:
				{system ("cls");
				hapusDepan();
				break;
				}
			case 4:
				{system ("cls");
				hapusBelakang();
				break;
				}
			case 5:
				{system ("cls");
				tampil();
				break;
				}
			case 6:
				{cout<<"Selesai";
				break;
				}
			default :
				{
				cout<<"\n Maaf, Tidak ada dalam pilihan";
				}
		}
	} while(pil>=1 && pil<= 5);
}