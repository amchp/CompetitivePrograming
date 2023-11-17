#include <bits/stdc++.h>

#define forn(i, n) for(int i = 0; i < (int)n; ++i)
#define el '\n'
#define sz(x) x.size()

using namespace std;

const int mod = 100;


int main(){
    int t;
    int arr[5] = {56, 96, 36, 76, 16};
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        if(s == "0"){
            cout << 1 << el;
            continue;
        }
        if(s == "1"){
            cout << 66 << el;
            continue;
        }
        else{
            int ind = ((s.back() - '0') - 2 + 5) % 5;
            cout << arr[ind] << el;
            continue;
        }
    }
}