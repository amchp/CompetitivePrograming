#include <bits/stdc++.h>

#define el '\n'

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin >> n>>m;

    while(m--){
        int l,r;
        cin>>l>>r;
    }
    string s(n,'0');
    for(int  i =0 ;i < n; ++i){
        s[i] = '0' + (i & 1);
    }
    cout<<s<<el;
}