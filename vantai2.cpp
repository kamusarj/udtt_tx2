#include <bits/stdc++.h>
using namespace std;

void algorithm(int **f, int n, int k, int x[], int y[]) {
    for (int j = 0; j <= k; j++) f[0][j] = 0;
    for (int i = 1; i <= n; i++) { 
        for (int j = 0; j <= k; j++) {
            f[i][j] = f[i-1][j]; 
            if (y[i-1] <= j) { 
                int temp = x[i-1] + f[i-1][j-y[i-1]];
                if (f[i][j] < temp) {
                    f[i][j] = temp;
                }
            }
        }
    }
}

void result(int **f, int n, int k, int x[], int y[]) {
    cout << "Khoi luong lon nhat: " << f[n][k] << endl;
    int i = n, j = k;
    cout << "Cac vat duoc chon: ";
    while (i != 0) {
        if (f[i][j] != f[i-1][j]) { 
            cout << i << " "; 
            j -= y[i-1];
        }
        i--;
    }
    cout << endl;
}

int main() {
    
    int x[] = {5, 3, 6, 7, 2, 4, 8, 9, 1, 10}; // khoi luong
    int y[] = {1, 3, 5, 7, 4, 8, 9, 10, 2, 6}; // kich thuoc
    int k = 23;
	int n = sizeof(x) / sizeof(x[0]);
    int **f = new int*[n+1];
    for (int i = 0; i <= n; i++) {
        f[i] = new int[k+1];
    }

    algorithm(f, n, k, x, y);
    result(f, n, k, x, y);

    return 0;
}
