#include <stdio.h>


void heapify(int a[],int n,int i){
	int l=2*i+1;
	int r=2*i+2;
	int m=i;
	if(l<n && a[l]>a[m])
		m=l;
	if(r<n && a[r]>a[m])
		m=r;
	if(m!=i){
		int t=a[i];
		a[i]=a[m];
		a[m]=t;
		heapify(a,n,m);
	}
}

void makeheap(int a[],int n){
	for(int i=n/2-1;i>=0;i--)
		heapify(a,n,i);
}

void heapsort(int a[],int n){
	makeheap(a,n);

	for(int i=n-1;i>=0;i--){
		int t=a[0];
		a[0]=a[i];
		a[i]=t;
		heapify(a,i,0);
	}

}

int main(){
	int a[100];
	int n;
	printf("Enter number of elements\n");
	scanf("%d",&n);
	printf("Enter elements:\n");
	for(int i=0;i<n;i++)
		scanf("%d",&a[i]);

	printf("^^^^^^\n");
	heapsort(a,n);
	printf("Result :");
	for(int i=0;i<n;i++)
		printf("%d ", a[i]);
	
}