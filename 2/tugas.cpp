// program mendata kelulusan mahasiswa

#include <iostream>
#include <conio.h>

using namespace std;

int data_kel[3][2] = {
	{
		24,
		42
	},
	{
		69,
		96
	},
	{
		21,
		12
	}
};
	
int total_kel, rata_kel;

main() {
	cout << "[ DATA KELULUSAN MAHASISWA ]";
	cout << endl << "[--------------------------]";
	
	for (int i = 0; i < 3; i++) {
		cout << endl << "Data Kelulusan TI-SK th ke-" << i+1 << ":";
		for (int i2 = 0; i2 < 2; i2++) {
			printf("\nProdi-%d: %d", i2+1, data_kel[i][i2]);
			total_kel += data_kel[i][i2];
		}
	}
	
	rata_kel = total_kel / 6;
	
	cout << "\n\nData Kelulusan\n";
	
	printf("   Prodi:  TI   SK");
	for (int i = 0; i < 3; i++) {
		printf("\nTh ke- %d   %d   %d", i+1, data_kel[i][0], data_kel[i][1]);
	}
	
	cout << "\n\nTotal kelulusan     = " << total_kel;
	cout << "\nRata-rata kelulusan = " << rata_kel;
	
	getch();
}
