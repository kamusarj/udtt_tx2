#include<bits/stdc++.h>

using namespace std;

void coin_changing(int coins[], int n, int m, int s[], int t[],int f[]) {
    f[0] = 0; 
    for (int i = 1; i <= m; i++) {
        for (int j = 0; j < n; j++) {
            if (i >= coins[j] && f[i - coins[j]] != 1e9 && f[i - coins[j]] + 1 < f[i]) {
                f[i] = f[i - coins[j]] + 1; 
                s[i] = j;                 
            }
        }
    }
}

void result(int coins[], int n, int m, int s[], int t[],int f[]){
	for (int i = 0; i < n; i++) t[i] = 0; 
    int current = m;
    while (current > 0) {
        int coin_index = s[current];
        if (coin_index == -1) break; 
        t[coin_index]++;
        current -= coins[coin_index];
    }
    if (f[m] == 1e9) {
        cout << "Khong the tra du so tien " << m << " voi cac menh gia tren" << endl;
    } else {
        cout << "so luong to tien can dung it nhat: " << f[m] << endl;
        cout << "danh sach so tien moi loai to tien can dung:" << endl;
        for (int i = 0; i < n; i++) {
            cout << "Menh gia " << coins[i] << ": " << t[i] << " to" << endl;
        }
    }
}

int main() {
    int m = 23; 
    int coins[] = { 2,10, 20,5}; 
    int n = sizeof(coins) / sizeof(coins[0]); 
    int s[m + 1]; 
    int t[n]; 
    int f[m + 1]; 
    for (int i = 0; i <= m; i++) {
        f[i] = 1e9; 
        s[i] = -1;      
    }
    coin_changing(coins, n, m, s, t,f);
	result(coins, n, m, s, t,f);
    return 0;
}
