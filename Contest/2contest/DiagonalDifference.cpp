#include <iostream>

using namespace std;

int main(){
    string s;
    getline (cin, s);
    int n = int(stoi(s));
    int a[n][n];
    int p;
    for(int i = 0; i < n; i++){
        getline (cin, s);
        s = s + " ";
        for(int j = 0; j < n; j++){
            p = s.find(" ");
            a[i][j] = stoi(s.substr(0, p));
            s = s.substr(p+1, s.length());
        }
    }
    int sum1 = 0;
    int sum2 = 0;
    for(int i = 0; i < n; i++){
        sum1 += a[i][i];
        sum2 += a[i][n-i-1];
    }
    int sum = abs(sum1 - sum2);
    cout << sum;
}