#include <iostream>
#include <vector>
#include <windows.h>

using namespace std;

vector<int> tree;
int curr = 0;

bool empty() {
	if (curr == 0) return true;
	else return false;
}

void clear() {
	curr = 0;
	tree.assign(1000000, int());
}

void insert(int data, int node = 1) {
	if (tree[node] == int()) {
		tree[node] = data;
		curr++;
	} else if (data < tree[node]) {
		insert(data, 2*node);
	} else if (data > tree[node]) {
		insert(data, 2*node+1);
	}
}

void preorder(int node = 1) {
	int left = 2 * node;
	int right = 2 * node + 1;
	if (empty() == true) {
		cout << "Node Masih Kosong" << endl;
		return;
	}
	
	if (tree[node] != int()) {
		cout << tree[node] << "";
		
		if(tree[left] != int()) preorder(2*node);
		if(tree[right] != int()) preorder(2*node+1);
	}
}

void inorder(int node = 1) {
	int left = 2 * node;
	int right = 2 * node+1;
	
	if (empty() == true) {
		cout << "Node Masih Kosong"<<endl;
		return;
	}
	
	if (tree[node] != int()) {
		if (tree[left] != int()) {
			inorder(2*node);
		}
		
		cout<<tree[node]<< " ";
		
		if(tree[right] != int()) {
			inorder(2*node+1);
		}
	}
}

void postorder(int node = 1) {
	int left = 2 * node;
	int right = 2 * node + 1;
	
	if(empty() == true) {
		cout << "Node Masih Kosong" << endl;
		return;
	}
	
	if (tree[node] != int()) {
		if(tree[left] != int()) {
			postorder(2*node);
		}
		
		if(tree[right] != int()) {
			postorder(2*node+1);
		}
	}
}

void searchTree(int data, int node = 1) {
	if (tree[node] == int()) {
		cout << "data tidak di temukan" << endl;
		return;
	}
	
	if(data == tree[node]) {
		cout << "data ditemukan pada node ke : "<<node<<endl;
		return;
	} else if (data < tree[node]) {
		searchTree(data, node*2);
	} else if (data > tree[node]) {
		searchTree(data, 2*node+1);
	}
}

int main() {
	int data, menu;
	tree.assign(1000000, int());
	
	do {
		system("cls");
		cout << "MENU" << endl;
		cout << "1. Insert Data" << endl;
		cout << "2. Lihat Pre-Order" << endl;
		cout << "3. Lihat In-Order" << endl;
		cout << "4. Lihat Post-Order" << endl;
		cout << "5. Lihat Jumlah Node" << endl;
		cout << "6. Hapus Semua Node" << endl;
		cout << "7. Cari Data" << endl;
		cout << "8. Keluar" << endl;
		cout << "Pilih Menu : ";
		cin >> menu;
		cout << endl;
		
		switch(menu) {
			case 1:
				cout << "Masukkan Data :";
				cin >> data;
				cout << endl << endl;
				insert(data);
				break;
			case 2:
				preorder();
				cout << endl << endl;
				break;
			case 3:
				inorder();
				cout << endl << endl;
				break;
			case 4:
				postorder();
				cout << endl << endl;
				break;
			case 5:
				cout << curr << endl << endl;
				break;
			case 6:
				clear();
				cout << "data sudah terhapus" << endl << endl;
				break;
			case 7:
				cout << "Masukkan Data yang akan di cari : ";
				cin >> data;
				searchTree(data);
				cout << endl;
				break;
			default:
				cout << "pilihan yang anda masukan salah";
		}
	} while(menu != 8);
}