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
typedef vector<vector<vector<ll>>> vvvl;
typedef vector<vector<ll>> vvl;

const int inf = 1e9;
const int nax = 5000 + 10;
const int kax = (nax + 1) / 2 + 10;
const ld pi = acos(-1);
const ld eps = 1e-9;

int dr[] = {1, -1, 0, 0, 1, -1, -1, 1};
int dc[] = {0, 0, 1, -1, 1, 1, -1, -1};

ll dp[nax][kax][2];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << setprecision(20);
    int n;
    cin >> n;
    int k = (n + 1) / 2;
    vi a(n);
    forn(i, n)cin >> a[i];
    if(n == 1){
        cout << 0 << el;
        return 0;
    }
    if(n == 2){
        if(a[0]==a[1])cout<<1<<el;
        else cout<<0<<el;
        return 0;
    }
    forn(i, n + 1){
        forn(j, k + 1){
            forn(l, 2)dp[i][j][l] = inf;
        }
    }
    dp[0][0][0]=0;
    dp[0][1][1] = max(0, a[1] - a[0] + 1);
    dp[1][1][1] = max(0, a[0] - a[1] + 1) + max(0, a[2] - a[1] + 1);
    dp[1][1][0]=dp[0][1][1];
    dp[1][0][0]=dp[0][0][0];
    fore(ind, 2, n - 2){
        dp[ind][0][0] = 0;
        for1(val, k){
            dp[ind][val][0] = min(dp[ind - 1][val][0], dp[ind - 1][val][1]);
            ll cstb = max(0, a[ind - 1] - a[ind] + 1);
            ll cstb1 = max(0, min(a[ind - 2] - 1, a[ind - 1]) - a[ind] + 1);
            ll cstf = (a[ind] > a[ind + 1]) ? 0 : a[ind + 1] - a[ind] + 1;
            ll cst = cstb + cstf;
            ll cst1 = cstb1 + cstf;
            dp[ind][val][1] = min(dp[ind - 2][val - 1][0] + cst, dp[ind - 2][val - 1][1] + cst1);
        }
    }
    forn(val, k+1){
        int ind = n - 1;
        dp[ind][val][0] = min(dp[ind - 1][val][0], dp[ind - 1][val][1]);
        ll cstb = max(0, a[ind - 1] - a[ind] + 1);
        ll cstb1 = max(0, min(a[ind - 2] - 1, a[ind - 1]) - a[ind] + 1);
        if(val != 0)dp[ind][val][1] = min(dp[ind - 2][val - 1][0] + cstb, dp[ind - 2][val - 1][1] + cstb1);
    }
    for1(val, k){
        int ind = n - 1;
        cout << min(dp[ind][val][0], dp[ind][val][1]) << ' ';
    }
    cout << el;
}
