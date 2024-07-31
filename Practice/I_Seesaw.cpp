#include <bits/stdc++.h>

#define fi first
#define se second
#define forn(i, n) for (int i = 0; i < (int)n; ++i)
#define for1(i, n) for (int i = 1; i <= (int)n; ++i)
#define fore(i, l, r) for (int i = (int)l; i <= (int)r; ++i)
#define ford(i, n) for (int i = (int)(n)-1; i >= 0; --i)
#define fored(i, l, r) for (int i = (int)r; i >= (int)l; --i)
#define pb push_back
#define el '\n'
#define d(x) cout << #x << " " << x << el
#define ri(n) scanf("%d", &n)
#define sz(v) ((int)v.size())
#define all(v) v.begin(), v.end()
#define allr(v) v.rbegin(), v.rend()

using namespace std;

typedef long long ll;
typedef double ld;
typedef pair<int, int> ii;
typedef pair<char, int> pci;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;

const int inf = 1e9;
const int nax = 2e4 + 10;
const ld pi = acos(-1);
const ld eps = 1e-9;

int dr[] = {1, -1, 0, 0, 1, -1, -1, 1};
int dc[] = {0, 0, 1, -1, 1, 1, -1, -1};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << setprecision(20);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vi lft(n), rgt(n);
        vi a, b;
        forn(i, n)cin >> lft[i];
        forn(i, n)cin >> rgt[i];
        ll s1 = 0, s2 = 0;
        forn(i, n){
            if(lft[i] == 1)a.pb(i + 1);
            if(rgt[i] == 2)b.pb(i + 1);
            s1 += 1LL* lft[i] * (i + 1);
            s2 += 1LL* rgt[i] * (i + 1);
        }
        if(s2 < s1 || s2 - s1 >= nax){
            cout << -1 << el;
            continue;
        }
        int dif = s2 - s1;
        vector<bitset<nax>> dp(sz(a) + 1);
        vector<bitset<nax>> dp2(sz(b) + 1);
        dp[0][0] = 1;
        dp2[0][dif] = 1;
        for(int& v : a){
            ford(i, sz(a)){
                dp[i + 1] |= dp[i] << v;
            }
        }
        for(int& v : b){
            ford(i, sz(b)){
                dp2[i + 1] |= dp2[i] >> v;
            }
        }
        bool pass = false;
        forn(i, min(sz(a), sz(b)) + 1){
            if((dp[i] & dp2[i]).any()){
                pass = true;
                cout << i << el;
                break;
            }
        }
        if(!pass)cout << -1 << el;
    } 
}
