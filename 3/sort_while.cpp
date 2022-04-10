#include <iostream>
#include <conio.h>

using namespace std;
int total = 10;
int data[10] = { 10, 9, 8, 7, 6, 5, 4, 3, 2, 1 };

show_data() {
	cout << endl;
	for (int i = 0; i < total; i++) {
		if (data[i] > 9) {
			cout << data[i] << " ";
		} else {
			cout << "0" << data[i] << " ";
		}
	}
	cout << endl;
}

sort_data() {
	bool on_progress = true;
	int pos = 0, pos_right = 0;
	while (on_progress) {
		if (pos <= total-1) {
			int pos_next = pos+1;
			cout << pos_next;
			if (data[pos] > data[pos_next]) {
				int temp = data[pos];
				data[pos] = data[pos_next];
				data[pos_next] = temp;
			} else {
				pos_right++;
			}
			pos++;
			
			//show_data();
			
			// mengecek jika posisi benar sama dengan total data maka proses while berhenti
			if (pos_right >= total) {
				on_progress = false;
			}
		} else {
			// pengecekan dan pengurutan dimulai dari pos awal
			//cout << "total/benar : " << total << "/" << pos_right << endl;
			pos_right = 0;
			pos = 0;
		}
	}
}

main() {
	cout << "sebelum pengurutan:";
	show_data();
	
	cout << endl << "data proses pengecekan:" << endl;
	sort_data();
	
	cout << endl << "hasil pengurutan:";
	show_data();
}
