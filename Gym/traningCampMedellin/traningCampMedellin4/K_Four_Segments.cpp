#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <unordered_map>
#include <string.h>
#include <math.h>
#include <queue>
#include <set>
#include <functional>
#include <cstdio>
//  #pragma GCC optimize("O3,unroll-loops")
// #pragma GCC target("avx2,bmi,bmi2,popcnt,lzcnt")

#define DBG(x) cerr << #x << " = " << (x) << endl
#define RAYA cerr << "=============================" << endl

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
#define count1s(v) __builtin_popcount(v)
#define count1sll(v) __builtin_popcountll(v)
#define countL0s(v) __builtin_clz(v)
#define countL0sll(v) __builtin_clzll(v)
#define vii(a, n)     \
    vector<int> a(n); \
    forn(i, n) cin >> a[i];

using namespace std;

typedef long long ll;
typedef double ld;
typedef pair<int, int> ii;
typedef pair<pair<ll, ll>, ll> iii;

typedef pair<char, int> pci;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<char> vc;

const ll inf = 1e18;
const int MAXS = 1e5 + 2;
const int MAXT = 1e2 + 2;
const int nax = 5e3 + 1;

int dx[] = {1, -1, 0, 0, 1, -1, -1, 1};
int dy[] = {0, 0, 1, -1, 1, 1, -1, -1};
int val[nax];
vector<vector<vector<ll>>> dp;
int n;

vi resp;

void build(int i, int l, int container){
    d(i);
    d(l);
    d(container);
    if(i == n+1)return ;
    if(container < 3 && dp[i + 1][i][container + 1] + val[i] *  ((container & 1) ? 1LL : -1LL) == dp[i][l][container]){
        // cout<<i<<" ";
        // d(i);
        resp.pb(i);
        build(i+1,i,container + 1);
        return;
    }
    build(i+1,l,container);
}
void solve()
{
    cin >> n;
    for1(i, n) cin >> val[i];
    dp = vector<vector<vector<ll>>>(n + 1, vector<vector<ll>>(n + 1, vector<ll>(4, -inf)));

    // ll ans = go(1,1,0);
    // // d(ans);
    // build(1,1,0);
    dp[0][0][0] = 0;
    dp[0][1][0] = 0;
    forn(i, n)
    {
        forn(start, n)
        {
            forn(bucket, 4)
            {
                // v = max(dp[((i+1)&1)][start][bucket] + ) ,v);
                // dp[(i+1)&1][start][bucket] = -inf;
                dp[i + 1][start][bucket] = max(dp[(i + 1)][start][bucket], dp[i][start][bucket] + 1LL * val[i + 1] * ((bucket & 1) ? -1LL : 1LL));
                if (bucket < 3)
                {
                    //  dp[(i+1)&1][i+1][bucket+1]= -inf;
                    dp[i + 1][i + 1][bucket + 1] = max(dp[i + 1][i + 1][bucket + 1], dp[i][start][bucket] + 1LL * val[i + 1] * ((bucket & 1) ? 1LL : -1LL));
                }
            }
        }
    }
    // ll resp = -inf;

    // int star = -1, buck = -1;
    // forn(i, 3)
    // {
    //     forn(j, n + 1)
    //     {
    //         if (resp < dp[n][j][i])
    //         {
    //             resp = max(dp[n][j][i], resp);
    //             star = j, buck = i;
    //         }
    //     }
    //     // d(dp[n&1][n][i]);
    //     // d(dp[!(n&1)][n][i]);
    // }

    // d(resp);
    // while(true){

    // }
    build(0,0,0);
    forn(i,3){
        if(i >= resp.size()){
            cout<<n<<" ";
        }else cout<<resp[i]-1<<" ";
    }cout<<el;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    // cout.precision(5);
    int tt;
    tt = 1;
    // cin >> tt;
    while (tt--)
        solve();
    return 0;
}
// run g++ --std=c++17 A.cpp -o A