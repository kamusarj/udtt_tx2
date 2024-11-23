#include<bits/stdc++.h>

using namespace std;

void quick_sort(int a[],int l, int r){
	if(l<r){
		int k = (l+r)/2;
		int t = a[k];
		int i = l,j=r;
		do{
			while(a[i]>t) i++;
			while(a[j]<t) j--;
			if(i<=j){
				int tg = a[i];
				a[i] = a[j];
				a[j] = tg;
				i++;
				j--;
			}
		}while(i<=j);
		quick_sort(a,l,j);
		quick_sort(a,i,r);
	}
}

void A4(int t[], int m, int n){
	quick_sort(t,0,n-1);
	int i=0;
	while(m>0 && i<n){
		if((m-t[i])>=0) {
			cout << t[i] << " ";
			m -= t[i];
		}
		i++;
	}
	if (m > 0) {
        cout << "\nKhong the van chuyen het hang." << endl;
    } else {
        cout << "\nTat ca hang da duoc van chuyen." << endl;
    }
}

int main(){
	int m = 100, n = 8;
	int t[] = {4,6,2,3,7,5,8,10};
	A4(t,m,n);
	return 0;
}