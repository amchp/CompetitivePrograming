
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <unordered_map>
#include <string.h>
#include <math.h>
#include <queue>
#include <set>


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
typedef pair<ll, ll> ii;
typedef pair<pair<ll, ll>, ll> iii;

typedef pair<char, int> pci;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<char> vc;

const ll inf = 2e9;
const int MAXS = 1e5 + 2;
const int MAXT = 1e2 + 2;

int dx[] = {1, -1, 0, 0, 1, -1, -1, 1};
int dy[] = {0, 0, 1, -1, 1, 1, -1, -1};
const int nax = 2e5;

vector<int> g[nax];
vi paths;
double ans = 0.0;
void dfs(int i,int p,double prob, int sum){
    if(i == 0)prob/=g[i].size();
    else if(g[i].size() == 1) {
        ans+=prob * (double)sum;
    }
    else prob/=g[i].size()-1;
    for(int x: g[i]){
        if(x != p){
            dfs(x,i,prob, sum + 1);
        }
    }
}
void solve()
{
    int n;
    cin>>n;
    memset(g,0,sizeof(g));
    forn(i,n-1){
        int u,v;
        cin>>u>>v;
        u--,v--;
        g[u].pb(v),g[v].pb(u);
    }
    dfs(0,-1,1, 0);
    cout<<ans<<el;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.precision(8);
    int tt;
    tt = 1;
    // cin >> tt;
    while (tt--)
        solve();
    return 0;
}
//run g++ --std=c++17 A.cpp -o A