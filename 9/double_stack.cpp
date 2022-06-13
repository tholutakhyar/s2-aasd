#include <iostream>
#include <conio.h>
#include <windows.h>
using namespace std;
int nilai [5];
int top1, top2, menu, stack, pop;

void create() {
	top1=-1;
	top2=5;
	stack=1;
	pop=1;
}

bool isfull() {
	if (top2-top1==1) {
		return true;
	} else {
		return false;
	}
}

bool isempty1() {
	if (top1==-1) {
		return true;
	} else {
		return false;
	}
}

bool isempty2() {
	if(top2==5) {
		return true;
	} else {
		return false;
	}
}

int main() {
	create();
	home:
	
	system("cls");
	cout<<"Pilih salah satu menu dibawah ini : "<<endl;
	cout<<"1. Push"<<endl;
	cout<<"2. Pop"<<endl;
	cout<<"3. Print"<<endl;
	cout<<"4. Clear"<<endl;
	cout<<"Masukkan pilihan anda (1-4): ";
	cin>>menu;
	
	switch(menu) {
		case 1:
			if(isfull()==true) {
				cout<<"Stack Penuh !";
			} else {
				if (stack==1) {
					top1++;
					cout<<"Masukkan data ke stack 1 : ";
					cin>>nilai[top1];
					stack++;
				} else if (stack==2) {
					top2--;
					cout<<"Masukkan data ke stack 2 : ";
					cin>>nilai[top2];
					stack--;
				}
			}
			
			getch();
			goto home;
			break;
		case 2:
			if (pop==1) {
				if(isempty1()==true) {
					cout<<"Stack 1 kosong !";
				} else {
					cout<<"Nilai yang keluar dari stack 1 : "<<nilai[top1];
					top1--;
					pop++;
				}
			} else if (pop==2) {
				if(isempty2()==true) {
					cout<<"Stack 2 kosong!";
				} else {
					cout<<"Nilai yang keluar dari stack 2 : "<<nilai[top2];
					top2++;
					pop--;
				}
			}
			
			getch();
			goto home;
			break;
		case 3:
			if(isempty1()==true) {
				cout<<"Stack 1 kosong !";
			} else {
				cout<<"Data pada stack :";
				
				for(int i=0; i<=top1; i++) {
					cout<<nilai[i]<<" ";
				}
				
				for (int i=(top1+1); i<=(top2-1); i++) {
				cout<<" _ ";
				}
			}
			
			if(isempty2()==true) {
				cout<<"Stack 2 kosong !";
			} else {
				for(int i=4; i>=top2; i--) {
					cout<<nilai[i]<<" ";
				}
			}
			
			getch();
			goto home;
			
			break;
		case 4:
			top1=-1;
			top2=5;
			
			cout<<"Stack sudah kosong!";
			getch();
			
			goto home;
			break;
	}
	getch();
}