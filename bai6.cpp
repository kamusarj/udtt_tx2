#include<bits/stdc++.h>

using namespace std;

const int max_len = 100;
const int max_n = 10;

void G(char d[max_n][max_len],int n,int k,char p[max_len*max_n]){
	p[0] = '\0';
	int len_p = 0;
	for (int i=0;i<n && len_p < k;i++){
		int len_d = strlen(d[i]);
		int len_add = (len_p + len_d <= k) ? len_d : (k-len_p);
		strncat(p,d[i],len_add);
		len_p += len_add;
	}
}

int char_in_string(char ch, const char s[]){
	int x = 0;
	while(s[x]!='\0'){
		if(s[x] == ch) return x;
		x++;
	}
	return -1;
}

bool BMH(const char p[],const char t[]){
	int v = strlen(p), i = v-1;
	while(i<strlen(t)){
		int k = v-1;
		while(k>-1 && t[i] == p[k]){
			i--;
			k--;
		}
		if(k<0) return true;
		else{
			int x = char_in_string(t[i],p);
			if(x<0) i = i+v;
			else i = i+v-x-1;
		}
	}
	return false;
}

void z_algo(const char *s,int *z){
	int n = strlen(s), left =0, right = 0;
	for (int i=1;i<n;i++){
		if(i>right){
			left = right = i;
			while(right<n && s[right-left] == s[right]) right++;
			z[i] = right - left;
			right--;
		}
		else if (z[i - left] < right - i + 1){
			z[i] = z[i - left];
		}
		else {
			left = i;
			while(right<n && s[right-left] == s[right]) right++;
			z[i] = right - left;
			right--;
		}
	}
}

int z_app(char *t,char *p){
	int p_size = strlen(p),t_size = strlen(t);
	char s[p_size + t_size + 2];
	strcpy(s,p);
	strcat(s,"$");
	strcat(s,t);
	int  n = strlen(s),z[n] = {0},count=0;
	z_algo(s,z);
	for (int i=0;i<n;i++){
		if(z[i] == p_size){
			count++;
			break;
		}
	}
	return count;
}

int main(){
	int n = 5; 
    int k = 100; 

    char d[max_n][max_len] = {
        "are",
        "the child are playing in the garden",
        "teachers are the key to a child's future",
        "every child deserves a happy childhood",
        "we are protecting children's rights"
    };
	
    char p[max_len * max_n];
    G(d,n,k,p);
    cout << p << endl;
    
    int count = 0;    
    char f[30] = "child";
    for (int i=0;i<n;i++){
    	if(BMH(f,d[i])){
    		count++;
    		cout << d[i] << endl;
		}
	}
	cout << count << endl;
	cout << d[0] << " xuat hien trong cac xau:" << endl;
	for (int i=1;i<n;i++){
		int dem = z_app(d[i],d[0]);
		if(dem) {
			cout << setw(40) << d[i] << "| " <<  dem << " lan" << endl;
		}
	}
	return 0;
}