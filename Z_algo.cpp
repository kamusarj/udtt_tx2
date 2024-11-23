#include<bits/stdc++.h>

using namespace std;

struct laptop{
	char brand[30];
	char desinfo[100];
	float price;
};

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

bool z_app(char *t,char *p){
	int p_size = strlen(p),t_size = strlen(t);
	char s[p_size + t_size + 2];
	strcpy(s,p);
	strcat(s,"$");
	strcat(s,t);
	int  n = strlen(s),z[n] = {0};
	bool check = false;
	z_algo(s,z);
	for (int i=0;i<n;i++){
		if(z[i] == p_size){
			check = true;
			break;
		}
	}
	return check;
}

int main(){
	int n = 6;
	laptop *d = new laptop[n];
	strcpy(d[0].brand, "Lenovo");
    strcpy(d[0].desinfo, "CPU I7 13500HX - RAM 16GB - 15 inchs - new");
    d[0].price = 25;
    
	strcpy(d[1].brand, "Dell");
    strcpy(d[1].desinfo, "CPU I5 12650H - RAM 16GB - 13.9 inchs - like new");
    d[1].price = 20;
    
	strcpy(d[2].brand, "HP");
    strcpy(d[2].desinfo, "CPU I5 13420H - RAM 16GB - 16 inchs - like new");
    d[2].price = 22.5;
	
	strcpy(d[3].brand, "Asus");
    strcpy(d[3].desinfo, "CPU I3 12650H - RAM 16GB - 14 inchs - 2hand");
    d[3].price = 15.9;
	
	strcpy(d[4].brand, "Acer");
    strcpy(d[4].desinfo, "CPU I5 12650H - RAM 16GB - 15 inchs - like new");
    d[4].price = 17.5;
	
	strcpy(d[5].brand, "Apple");
    strcpy(d[5].desinfo, "CPU I9 12650H - RAM 16GB - 15 inchs - new");
    d[5].price = 30;
    
    char display[30] = "15.7 inchs";
    int count = 0;
    for (int i=0;i<n;i++){
    	if(z_app(d[i].desinfo,display)) count++;
	}
	if(count>0) cout << count << endl;
	else cout << "Khong co may tinh nao co kich thuoc man hinh " << display << endl;
	return 0;
}