#include <iostream>
#include <conio.h>

using namespace std;

void quick_sort(int arr[], int left, int right) {
	int i = left, j = right;int tmp;
	int pivot = arr[(left+right)/2];/* partition */
	
	while (i<j) {
		while (arr[i] < pivot)
		i++;
		while (arr[j] > pivot)
		j--;
		if (i<=j) {
			tmp = arr[i];
			arr[i] = arr[j];
			arr[j] = tmp;
			i++;j--;
		};
	};/*recursion*/
	
	if (left < j)
	quick_sort(arr, left, j);
	
	if (i < right)
	quick_sort(arr, i, right);
}

int main() {
	int i,n,data[50];
	
	cout<<"Masukan banyak data: ";cin>>n;
	for(i=0;i<n;i++) {
		cout<<"Masukan data ["<<i<<"] : ";cin>>data[i];
	}
	
	cout<<"\nData sebelum diurutkan: "<<endl;
	for(i=0;i<n;i++) {
		cout<<data[i]<<" ";
	}
	
	cout<<"\n";
	quick_sort(data,0,n-1);//hasil pengurutan
	cout<<"\nHasil pengurutan:\n";
	
	{
		int i;
		for (i=0;i<n;i++)
		cout<<data[i]<<" ";
		cout<<"\n";
	}
}
