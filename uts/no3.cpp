#include <iostream> 

using namespace std;

char input_char[100], find_char;
int count_char, count_find_char;
string status = "tidak ada";

int main() {
	cout << "[program pencari dan penghitung karakter]" << endl;
	
	cout  << endl;
	cout << "[input]" << endl;
	// input kalimat
	cout << "masukkan kalimat (max 100 karakter terimasuk spasi): ";
	gets(input_char);
	
	// input karater yang ingin dicari
	cout << "satu karakter yang ingin dicari: ";
	cin >> find_char;
	
	count_char = strlen(input_char); // menghitung jumlah karakter dari input
	
	// proses pencarian karakter satu per satu
	for (int i = 0; i < count_char ; i++) {
		if (input_char[i] == find_char) {
			count_find_char++;
		}
	}
	
	// jika yang ditemukan lebih dari 0 maka status menjadi ada
	if (count_find_char > 0) {
		status = "ada";
	}
	
	cout  << endl;
	
	// hasil
	cout << "[output/hasil]" << endl;
	cout << "karakter yang dicari: " << find_char << endl;
	cout << "status: " << status << endl;
	cout << "jumlah karater " << find_char << ": " << count_find_char << endl;
	cout << "jumlah total karakter: " << count_char << endl;                   	    
}
