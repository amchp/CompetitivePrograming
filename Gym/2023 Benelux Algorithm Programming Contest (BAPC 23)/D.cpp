#include<bits/stdc++.h>
#define el '\n'
#define forn(i, n) for(int i = 0; i < (int)n; ++i)
#define d(x) cout << #x << ' ' << x << el;

using namespace std;
typedef long long ll;
typedef vector<int> vi;

int main(){
    int n, m;
    cin>>n >> m;
    vector<string> cn(n);
    forn(i, n){
        cin >> cn[i];
    }
    string s;
    forn(j, m){
        vi ch(26, 0);
        int mx = 0;
        char cmx = 'a';
        forn(i, n){
            char c = cn[i][j];
            ch[c - 'a']++;
            if(mx < ch[c - 'a'] || (mx == ch[c - 'a'] && c < cmx)){
                mx = ch[c - 'a'];
                cmx = c;
            }
        }
        s += cmx;
    }
    cout << s << el;
    return 0;
}