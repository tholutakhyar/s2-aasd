#include <stdio.h>
#include <iostream>
#include <conio.h>
#define MAX 5

using namespace std;

typedef struct {
	int data[MAX];
	int head;
	int tail;
}

Queue;
Queue antrian;

void Create(){
	antrian.head=antrian.tail=-1;
}

int IsEmpty(){
	if(antrian.tail==-1)
		return 1;
	else
		return 0;
}

int IsFull() {
	if(antrian.tail==MAX-1)
		return 1;
	else
		return 0;
}

Enqueue(int data) {
	if(IsEmpty()==1) {
		antrian.head=antrian.tail=0;
		antrian.data[antrian.tail]=data;
		printf("%d sudah dimasukan",antrian.data[antrian.tail]);
	} else if(IsFull()==0) {
		antrian.tail++;
		antrian.data[antrian.tail]=data;
		printf("%d sudah dimasukan",antrian.data[antrian.tail]);
	} else if(IsFull()==1)
		printf("Queue penuh");
	}

int Dequeue() {
	int i;
	int e = antrian.data[antrian.head];
	for(i=antrian.head; i<=antrian.tail-1;i++) {
		antrian.data[i]=antrian.data[i+1];
	}
	
	antrian.tail--;
	printf("Data %d sudah diambil",e);
	
	return e;
}

void Clear() {
	antrian.head=antrian.tail=-1;
	printf("Data sudah dibersihkan");
}

void Tampil() {
	printf("Data Queue:");
	if(IsEmpty()==0) {
		for(int i=antrian.head;i<=antrian.tail;i++) {
			printf(" %d",antrian.data[i]);
		}
	} else {
		printf("data kosong!\n");
	}
}

main() {
	int pil;
	int data;
	
	Create();
	do {
		system ("cls");
		cout<<" |============================|"<<endl;
		cout<<" |\t--Program Queue--     |"<<endl;
		cout<<" |============================|"<<endl;
		cout<<" | 1. Tambah Data (Enqueue)   | "<<endl;
		cout<<" | 2. Ambil Data (Dequeue)    | "<<endl;
		cout<<" | 3. Tampilkan Data          | "<<endl;
		cout<<" | 4. Bersihkan Data          | "<<endl;
		cout<<" | 5. Keluar                  | "<<endl;
		cout<<" |============================|"<<endl;
		cout<<" Tentukan Pilihan : ";cin>>pil;
		
		switch(pil) {
			case 1:
				cout<<"Masukan Data : ";cin>>data;
				Enqueue(data);
				break;
			case 2:
				Dequeue();
				break;
			case 3:
				Tampil();
				break;
			case 4:
				Clear();
				break;
			case 5:
				break;
		}
	
		getch();
	} while(pil != 5);
	
	return 0;
}