#include<bits/stdc++.h>

using namespace std;

int findOverlap(char a[], char b[]) {
    int lenA = strlen(a);
    int lenB = strlen(b);
    int maxOverlap = 0;

    for (int i = 1; i <= lenA; ++i) {
        bool match = true;
        for (int j = 0; j < i; ++j) {
            if (a[lenA - i + j] != b[j]) {
                match = false;
                break;
            }
        }
        if (match) {
            maxOverlap = i;
        }
    }
    return maxOverlap;
}

int main() {
	int string_length = 100; 
    char a[string_length] = "hello";  
    char b[string_length] = "123"; 
    char c[string_length * 2];

    int lenA = strlen(a);
    int lenB = strlen(b);

    int overlap = findOverlap(a, b);

    strcpy(c, a); 
    strcpy(c + lenA, b + overlap); 

    cout << "Xau a: " << a << endl;
    cout << "Xau b: " << b << endl;
    cout << "Xau c ngan nhat: " << c << endl;

    return 0;
}
