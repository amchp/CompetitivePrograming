#include <bits/stdc++.h>

#define forn(i, n) for(int i = 0; i < n; ++i)
#define for1(i, n) for(int i = 1; i <= (int)n; ++i)
#define fore(i, l, r) for(int i = (int)l; i <= (int)r; ++i)
#define ai128(x) x.begin(), x.end()
#define el '\n'
#define sz(x) x.size()
#define fi first
#define se second
#define pb push_back
#define d(x) cerr << #x << ' ' << x << el;

using namespace std;

typedef __int128_t i128;
typedef vector<int> vi;
typedef vector<i128> vi128;
typedef pair<int, int> ii;
typedef long double ld;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    // if(n == 1){
    //     cout << "ab" << el;
    //     cout << "ba" << el;
    //     return 0;
    // }
    string s, t;
    forn(i, n){
        s += 'a';
    }
    forn(i, n)s += 'b';
    forn(i, n - 1)t += 'a';
    t += 'b';
    t += 'a';
    forn(i, n - 1){
        t += 'b';
    }
    cout << s << el;
    cout << t << el;
    return 0;
}