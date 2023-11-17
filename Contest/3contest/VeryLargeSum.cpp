#include <iostream>

using namespace std;

int main(){
    string s;
    cin >> s;
    int n = stoi(s);
    cin >> s;
    s = s + " ";
    long a[n];
    int p;
    for(int i = 0; i < n; i++){
        p = s.find(" ");
        a[i] = stol(s.substr(0, p));
        s = s.substr(p+1, s.length());
    }

    long sum = 0;
    for(int i = 0; i < n; i++){
        sum += a[i];
    }
    cout << sum;
}