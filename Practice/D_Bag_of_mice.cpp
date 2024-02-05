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
const int nax = 1000 + 200;
const ld pi = acos(-1);
const ld eps = 1e-9;

int dr[] = {1, -1, 0, 0, 1, -1, -1, 1};
int dc[] = {0, 0, 1, -1, 1, 1, -1, -1};

ld dp[nax][nax][2];

ld sol(int w, int b, int p){
    if(w == 0)return 0.0L;
    if(b == 0){
        if(p == 0)return 1.0L;
        return 0.0L;
    }
    ld& ans = dp[w][b][p];
    if(ans != -1.0L)return ans;
    // d(w);
    // d(b);
    // d(p);
    // cout << "####" << el;
    if(p == 0){
        ans = ld(w) / ld(w + b);
        // d(ld(w) / ld(w + b));
        ld inv = 1.0L - ans;
        ans += inv*sol(w, b - 1, 1);
        // d(inv*sol(w, b - 1, 1));
    }else{
        ld inv = 1.0L - (ld(w) / ld(w + b));
        ld wj = ld(w) / ld(w + b - 1);
        ans = inv*wj*sol(w - 1, b - 1, 0);
        if(b >= 2){
            ld bj = 1.0L - wj;
            ans += inv*bj*sol(w, b - 2, 0);
        }
    }
    // d(ans);
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << setprecision(20);
    forn(i, nax){
        forn(j, nax){
            forn(k, 2)dp[i][j][k] = -1.0;
        }
    }
    int w, b;
    cin >> w >> b;
    cout << sol(w, b, 0) << el;
    // forn(i, w + 1){
    //     forn(j, b + 1)cout << dp[w][b][0] << ' ';
    //     cout << el;
    // }
    // cout << el;
    // forn(i, w + 1){
    //     forn(j, b + 1)cout << dp[w][b][1] << ' ';
    //     cout << el;
    // }
}
