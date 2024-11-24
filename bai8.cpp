#include<bits/stdc++.h>
using namespace std;

struct Conference {
    char topic[100]; 
    int start;       
    int end;         
};

void quick_sort(Conference a[],int l, int r){
	if(l<r){
		int k = (l+r)/2;
		int t = a[k].end;
		int i = l,j=r;
		do{
			while(a[i].end<t) i++;
			while(a[j].end>t) j--;
			if(i<=j){
				int tg = a[i].end;
				a[i].end = a[j].end;
				a[j].end = tg;
				i++;
				j--;
			}
		}
		while(i<=j);
		quick_sort(a,l,j);
		quick_sort(a,i,r);
	}
}

bool compare(Conference a, Conference b) {
    return a.end < b.end;
}

void intervalScheduling(Conference d[], int n, int &k, Conference result[]) {
    quick_sort(d, 0, n-1);

    k = 0; 
    int lastEnd = 0; 

    for (int i = 0; i < n; i++) {
        if (d[i].start >= lastEnd) {
            result[k++] = d[i]; 
            lastEnd = d[i].end; 
        }
    }
}

int main() {
    int n = 4; 
    Conference d[] = {
        {"Tim kiem viec lam", 1, 4},
        {"Ky nang mem", 3, 5},
        {"Tu duy sang tao", 0, 6},
        {"Giao tiep hieu qua", 5, 7}
    };

    Conference result[10]; 
    int k; 
    intervalScheduling(d, n, k, result);
    cout << "\nSo luong hoi thao toi da ma mot nguoi co the tham du: " << k << endl;
    cout << "Danh sach cac hoi thao:" << endl;
    for (int i = 0; i < k; i++) {
        cout << "- " << result[i].topic << " ("
             << result[i].start << " -> " << result[i].end << ")" << endl;
    }

    return 0;
}
