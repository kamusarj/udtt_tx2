#include<bits/stdc++.h>

using namespace std;

void normalizeText(char text[]) {
    int len = strlen(text);
    char result[1001];
    int index = 0;     

    int start = 0, end = len - 1;
    while (start < len && isspace(text[start])) start++;
    while (end >= 0 && isspace(text[end])) end--;

    bool capitalizeNext = true;
    for (int i = start; i <= end; ++i) {
        if (isspace(text[i])) {
            if (index > 0 && !isspace(result[index - 1])) {
                result[index++] = ' ';
            }
        }
        else if (text[i] == '.' || text[i] == ',') {
            if (index > 0 && result[index - 1] == ' ') {
                index--; 
            }
            result[index++] = text[i];
            capitalizeNext = (text[i] == '.'|| text[i] == '!');
        }
        else if ((text[i] != '.' && text[i] != ',') && (index > 0 && (result[index - 1] == '.' || result[index - 1] == ','))) {
            result[index++] = ' ';
            result[index++] = capitalizeNext ? toupper(text[i]) : tolower(text[i]);
            capitalizeNext = false;
        }
        else {
            result[index++] = capitalizeNext ? toupper(text[i]) : tolower(text[i]);
            capitalizeNext = false;
        }
    }

    if (index > 0 && result[index - 1] == ' ') {
        index--;
    }

    result[index] = '\0';

    strcpy(text, result);
}

int main() {
    char text[1001] = "  Hello   teacher.     I    am   a student   in    your     class,   please   give my    exercise  10 points.  ";

    cout << "Van ban truoc khi chuan hoa: " << text << endl;

    normalizeText(text);

    cout << "Van ban sau khi chuan hoa: " << text << endl;

    return 0;
}
