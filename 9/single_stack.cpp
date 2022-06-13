#include <iostream>
#include <conio.h>

using namespace std;
int nilai[5]; //variabel global
int top; //variabel global
int maks; //variabel global
int menu; //variabel untuk menu

void create() {
	top = -1;
	maks = 4;
}

bool isFull() {
	if (top == maks) {
		return true;
	}
	
	return false;
}

bool isEmpty() {
	if (top == -1) {
		return true;
	}
	
	return false;
}

int main() {
	create(); //panggil prosedur create, set nilai awal STACK
	home: //penanda/check point
	
	system("cls"); //untuk hapus layar
	cout<<"Pilih salah satu menu dibawah ini :"<<endl;
	cout<<"1. Push"<<endl;
	cout<<"2. Pop"<<endl;
	cout<<"3. Print"<<endl;
	cout<<"4. Clear"<<endl;
	cout<<"Masukkan pilihan anda (1-4) : ";
	cin>>menu;
	
	switch(menu) {
		case 1:
			if (isFull() == true) {
				cout<<"STOP...STACK Penuh..!!";
			} else {
				top++;
				cout<<"Masukkan data ke STACK : ";
				cin>>nilai[top];
				cout<<"Data "<<nilai[top]<<" masuk ke STACK";
			}
			
			getch();
			goto home;
			break;
		case 2:
			if (isEmpty() == true) {
				cout<<"STACK kosong!";
			} else {
				cout<<"Data yang keluar : ";
				cout<<nilai[top];
				top--;
			}
			getch();
			goto home;
			break;
		case 3:
			if (isEmpty() == true) {
				cout<<"STACK kosong, tidak dapat menampilkan data";
			} else {
				cout<<"Data yang masuk ke STACK : "<<endl;
				for(int i=0; i<=top; i++) {
					cout<<nilai[i]<<" ";
				}
			}
			getch();
			goto home;
			break;
		case 4:
			top = -1;
			cout<<"STACK sudah di kosongkan";
			getch();
			goto home;
			break;
	}
	getch();
}