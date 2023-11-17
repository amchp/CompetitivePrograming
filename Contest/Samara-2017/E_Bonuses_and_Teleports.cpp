#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <unordered_map>
#include <string.h>
#include <math.h>
#include <queue>
#include <set>
#include <map>
#include <unordered_set>
 
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
 
using namespace std;
 
typedef long long ll;
typedef double ld;
typedef pair<int, int> ii;
typedef pair<pair<ll, ll>, ll> iii;
 
typedef pair<char, int> pci;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<char> vc;
 
const int inf = 1e9;
const int MAXS = 1e5 + 2;
const int MAXT = 1e2 + 2;
 
int dx[] = {1, -1, 0, 0, 1, -1, -1, 1};
int dy[] = {0, 0, 1, -1, 1, 1, -1, -1};
const int MAX = 1e7 + 100;
void solve()
{
    int n,m;cin>>n>>m;
    vll t(n),b(m);
    forn(i,n)cin>>t[i];
    forn(i,m)cin>>b[i];
    sort(all(t)),sort(all(b));
    t.erase(unique(all(t)),t.end()),b.erase(unique(all(b)),b.end());
    m = b.size(),n = t.size();
    ll ans = 0;

    forn(i, n - 1){
        ll lT = t[i], rT = t[i + 1];
        ll k = (rT - lT - 1) / 2LL;
        ll lB = upper_bound(all(b), lT + k) - b.begin(), rB = lower_bound(all(b), rT - k) - b.begin();
        if(lB == 0 || b[lB - 1] < lT || rB == m || rT < b[rT])continue;
        lB--;
        ans += min(((b[lB] - lT) * 2LL) + ((rT - b[rB]) * 2LL), rT - lT);
    }


    ans+= max(0LL,(1LL*b[m-1] - t[n-1]) * 2);
    ans+=max(0LL,(1LL*t[0]-b[0]) * 2);
    cout<<ans<<el;
 
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