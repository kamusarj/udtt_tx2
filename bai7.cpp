#include<bits/stdc++.h>

using namespace std;

void findC(int a[], int b[], int n, int m, int c[], int &len_c) {
	int dp[n + 1][m + 1] ; 
	for (int i = 0; i <= n; i++) {
	    for (int j = 0; j <= m; j++) {
	        dp[i][j] = 0;
	    }
	}

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (a[i - 1] == b[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    cout << "DP Table:" << endl;
	for (int i = 0; i <= n; i++) {
	    for (int j = 0; j <= m; j++) {
	        cout << dp[i][j] << " ";
	    }
	    cout << endl;
	}


    int i = n, j = m;
    len_c = dp[n][m]; 
    int index = len_c - 1;

    while (i > 0 && j > 0) {
        if (a[i - 1] == b[j - 1]) {
            c[index--] = a[i - 1];
            i--;
            j--;
        } else if (dp[i - 1][j] > dp[i][j - 1]) {
            i--;
        } else {
            j--;
        }
    }
}

int main() {
    int a[] = {1, 2, 3, 4, 5};
    int b[] = {3, 4, 1, 2, 1, 3, 5};
	int n = sizeof(a)/sizeof(a[0]), m = sizeof(b)/sizeof(b[0]);
    int c[100]; 
    int len_c = 0;

    findC(a, b, n, m, c, len_c);

    cout << "Day con chung dai nhat: ";
    for (int i = 0; i < len_c; i++) {
        cout << c[i] << " ";
    }
    cout << endl;

    return 0;
}
