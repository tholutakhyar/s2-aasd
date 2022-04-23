#include <iostream>
#include <conio.h>

using namespace std;

int main() {
	int total_input, data_input[50], data_find, data_find_total = 0;
	string data_find_status = "tidak ada";
	
	cout << "[input data]";
	cout << "\nmasukan jumlah data array: ";
	cin >> total_input;
	
	for (int i = 0; i < total_input ; i++) {
		cout << "masukan data ke-"<< i + 1 <<": ";
		cin >> data_input[i];
	}
	
	cout << "\n\n[info data]";
	cout << "\ndata input: ";
	for (int i = 0; i < total_input ; i++) {
		cout << data_input[i] << " ";
	}
	cout << "\ndata input yang ingin dicari: ";
	cin >> data_find;
	
	for (int i = 0; i < total_input ; i++) {
		if (data_input[i] == data_find) {
			data_find_total++;
			//cout << "[" << data_input[i] << "] ";
		} /*else {
			cout << data_input[i] << " ";
		}*/
	}
	
	if (data_find_total > 0) {
		data_find_status = "ada";
	}
	
	cout << "\n\n[hasil pencarian]";
	cout << "\nangka yang dicari: " << data_find;
	cout << "\nstatus: " << data_find_status;
	cout << "\njumlah: " << data_find_total;
	getch();
}
