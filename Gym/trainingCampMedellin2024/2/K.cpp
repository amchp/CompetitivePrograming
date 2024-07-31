#include<bits/stdc++.h>

#define forn(i,n) for(int i = 0; i < n; ++i)
#define for1(i, n) for(int i = 1; i <= n; ++i)
#define el '\n'
#define all(x) x.begin(), x.end()
#define d(x) cerr<<#x<<" "<<x<<el
using namespace std;

typedef long long ll;
typedef vector<int> vi;
const ll inf = 2e18;

bool sol(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    int turn = true;
    forn(i, n - 1){
        char& c1 = s[i];
        char& c2 = s[i + 1];
        if(c1 != c2 && c1 != 'W'){
            turn = !turn;
            s[i] = 'W';
            s[i + 1] = 'W';
        }
    }
    d(s);
    int rd = 0;
    int bl = 0;
    forn(i, n){
        char& c = s[i];
        rd += c == 'R';
        bl += c == 'B';
    }
    d(turn);
    if(rd == bl)return !turn;
    if(rd > bl)return true;
    return false;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        if(sol())cout << "Alice" << el;
        else cout << "Bob" << el;
    }
}