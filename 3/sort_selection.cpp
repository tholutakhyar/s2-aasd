#include<stdio.h>
#include<conio.h>

using namespace std;

int main() {
	int i,j,n,idx,temp,min,a[30];
	
	printf("masukkan jumlah angka:");
	scanf("%d",&n);
	printf("\nmasukkan angka\n");
	
	for(i=0;i<n;i++) {
		scanf("%d",&a[i]);
	}
	
	for(i=0;i<n-1;i++) {
		min=a[i];
		idx=i;
		for(j=i+1;j<n;j++) {
			if(min>a[j]) {
				min=a[j];
				idx=j;
			}
		}
		temp=a[i];
		a[i]=a[idx];
		a[idx]=temp;
	}
	
	printf("\nHasil pengurutan\n");
	
	for(i=0;i<n;i++) {
		printf("%d ",a[i]);
	}
}

