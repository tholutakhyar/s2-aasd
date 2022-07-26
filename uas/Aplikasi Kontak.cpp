#include <iostream>
#include <conio.h>
#include <string>

using namespace std;

// pencarian
// stack system
// array, struct dan function

// CONFIG
const int max_kontak = 5; // jumlah kontak

bool lanjut = true;
char pilih_menu;
int top;
int maxx;

struct kontak {
	string nama;
	int no_telp;
};

kontak data_kontak[max_kontak];

void keluar() {
    char jawab;
    cout << "Apakah anda yakin ingin keluar? (y/t) ";
    cin >> jawab;
    if (jawab == 'Y' || jawab == 'y') {
        lanjut = false;
    }
}

void menu_tidak_ada() {
    cout << "Maaf menu tidak ada";
}

void bersih_terminal() {
    system("cls"); // membersihkan cmd
}

void init() {
	top = -1;
	maxx = max_kontak - 1; 
}

bool is_penuh() {
	if (top == maxx) {
		return true;
	} return false;
}

bool is_kosong() {
	if (top == -1) {
		return true;
	} return false;
}

void tambah_kontak() {
	if (is_penuh() == true) {
		cout << "yahh, kontak penuh :(";
	} else {
		string nama;
		int notelp;
		top++;
		
		cout << "masukan nama: ";
        cin >> nama;
        cout << "masukan no telp: ";
        cin >> notelp;
        data_kontak[top].nama = nama;
        data_kontak[top].no_telp = notelp;

        bersih_terminal();

        cout << "kontak berhasil ditambahkan";
	}
}

void hapus_kontak() {
	if (is_kosong() == true) {
		cout << "kontak masih kosong!";
	} else {
		cout << "kontak yang keluar : ";
		cout << endl << "nama: " << data_kontak[top].nama;
		cout << endl << "no telp: " << data_kontak[top].no_telp;
		top--;
	}
}

void hapus_semua_kontak() {
	top = -1;
	cout << "semua kontak berhasil dihapus";
}

void daftar_kontak() {
	if (is_kosong() == true) {
		cout<<"kontak masih kosong";
	} else { 
	 	cout<<"daftar kontak : "<<endl;
		for(int i=0; i<=top; i++) {
			cout << endl << "nama: " << data_kontak[i].nama;
			cout << endl << "no telp: " << data_kontak[i].no_telp;
			cout << endl << "----------------" << endl;
		}
	}
}

void cari_kontak() {
	if (is_kosong() == true) {
		cout<<"tidak bisa cari kontak, karena kontak masih kosong";
	} else {
		string nama_cari;
		cout << "masukan nama yang dicari: ";
        cin >> nama_cari;
        
		cout<<"daftar kontak hasil pencarian nama "<< nama_cari <<" : "<<endl;
		int jumlah_pencarian = 0;
		for(int i=0; i<=top; i++) {
			if (data_kontak[i].nama.find(nama_cari) != string::npos) { //jika tidak ada npos = -1
				cout << endl << "nama: " << data_kontak[i].nama;
				cout << endl << "no telp: " << data_kontak[i].no_telp;
				cout << endl << "----------------" << endl;
				jumlah_pencarian++;
			}
		}
		
		if (jumlah_pencarian == 0) {
			cout << "tidak ada :(";
		}
	}
}

//fungsi menu
void menu() {
	do {
        bersih_terminal();    
        
		cout << "Kontak App (Tugas UAS)";
        cout << "\n[ pilih menu ]";
        cout << "\n1. Tambah Kontak";
        cout << "\n2. Hapus Kontak";
        cout << "\n3. Hapus Semua Kontak";
        cout << "\n4. Daftar Kontak";
        cout << "\n5. Cari Kontak";
        cout << "\n6. Keluar";
        cout << "\nMasukan No Menu Yang ingin di Eksekusi (1 - 6): ";
        cin >> pilih_menu;

        bersih_terminal();

        switch (pilih_menu) {
            case '1': // menambah kontak
                tambah_kontak();
                break;
            case '2': // menghapus
                hapus_kontak();
                break;
            case '3': // menghapus semua kontak
                hapus_semua_kontak();
                break;
            case '4': // daftar kontak
                daftar_kontak();
                break;
            case '5': // cari kontak
            	cari_kontak();
            	break;
            case '6': // keluar aplikasi
                keluar();
                break;
            default: // default jika memilih menu yang tidak ada di case
                menu_tidak_ada();
                break;
        }

        if (lanjut) {
            cout << "\n(tekan tombol apa saja untuk kembali ke menu)";
            getch();
        }

    } while(lanjut);
}

int main() {
	init();
	menu();
}