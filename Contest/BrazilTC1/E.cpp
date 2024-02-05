#include <bits/stdc++.h>

#define forn(i, n) for(int i = 0; i < (int)n; ++i)
#define for1(i, n) for(int i = 1; i <= (int)n; ++i)
#define fore(i, l, r) for(int i = (int)l; i <= (int)r; ++i)
#define el '\n'
#define d(x) cerr << #x << ' ' << x << el
#define sz(x) x.size()
#define fi first
#define se second

using namespace std;

typedef vector<int> vi;
typedef pair<int, int> ii;

const int nax = 2510;
const int mod = 1e9 + 7;

int n;
int dp[nax][26];
int p[nax][26];
string s;

int sol(int ind, int pc){
    if(ind == sz(s))return 0;
    int& ans = dp[ind][pc];
    if(ans != -1)return ans;
    if(s[ind] != '.'){
        p[ind][pc] = s[ind] - 'A';
        return ans = sol(ind + 1, s[ind] - 'A') + (int(s[ind] - 'A') != pc);
    }
    forn(nc, n){
        int cans = sol(ind + 1, nc) + (nc != pc);
        if(ans < cans){
            ans = cans;
            p[ind][pc] = nc;
        }
    }
    return ans;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    cin >> s;
    // d(n);
    // d(s);
    forn(i, sz(s)){
        forn(j, n)dp[i][j] = -1;
    }
    int mx = -1;
    int mxind = -1;
    if(s[0] != '.'){
        mx = sol(1, s[0] - 'A');
        mxind = s[0] - 'A';
    }
    else{
        forn(nc, n){
            int cans = sol(1, nc);
            if(mx < cans){
                mx = cans;
                mxind = nc;
            }
        }
    }
    // forn(i, sz(s)){
    //     forn(j, n){
    //         cout << dp[i][j] << ' ';
    //     }
    //     cout << el;
    // }
    // cout << mx << el;
    int cur = mxind;
    for1(i, sz(s)){
        char c = 'A' + cur;
        cout << c;
        cur = p[i][cur];
    }
    cout << el;
}