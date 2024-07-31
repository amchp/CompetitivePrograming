#include <iostream>

using namespace std;

int main(){
    string s;
    int a[5];
    getline (cin, s);
    s = s + " ";
    int p;
    for(int i = 0; i < 5; i++){
        p = s.find(" ");
        a[i] = stol(s.substr(0, p));
        s = s.substr(p+1, s.length());
    }
    int sum = 0;
    int max;
    int min;
    for(int i = 0; i < 5; i++){
        sum = 0;
        for(int j = 0; j < 5; j++){
            if(i == j) continue;
            sum += a[j];
        }
        if(i == 0){
            max = sum;
            min = sum;
        }
        if(sum > max) max = sum;
        if(sum < min) min = sum;
    }
    cout << min << " " << max;
}