#include <iostream>

using namespace std;

int main(){
    string s;
    getline (cin, s);
    int n = stoi(s);
    getline (cin, s);
    s = s + " ";
    int p;
    int a[n];
    for(int i = 0; i < n; i++){
        p = s.find(" ");
        a[i] = stoi(s.substr(0, p));
        s = s.substr(p+1, s.length());
    }
    int pos = 0;
    int neg = 0;
    int zero = 0;
    for(int i = 0; i < n; i++){
        if(a[i] > 0)pos++;
        else if(a[i] > 0)neg++;
        else zero++;
    }
    double posRatio = (double) pos / n;
    double negRatio = (double) neg / n;
    double zeroRatio = (double) zero / n;
    cout << posRatio << endl;
    cout << negRatio << endl;
    cout << zeroRatio;
}