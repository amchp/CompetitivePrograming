#include <iostream>

using namespace std;

int main(){
    int i, j, k, nt, count = 0;
    string s, ns;
    cin >> i >> j >> k;
    for(int t = i; t <= j; ++t){
        s = to_string(t);
        ns = "";
        for(int c = s.length() - 1; c > -1; --c) ns = ns + s.at(c);
        nt = stoi(ns);
        if((t-nt) % k == 0)count++;
    }
    cout << count << endl;
}