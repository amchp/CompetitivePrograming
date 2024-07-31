#include <bits/stdc++.h>

#define fi first
#define se second
#define forn(i,n) for(int i=0; i< (int)n; ++i)
#define for1(i,n) for(int i=1; i<= (int)n; ++i)
#define fore(i,l,r) for(int i=(int)l; i<= (int)r; ++i)
#define ford(i,n) for(int i=(int)(n) - 1; i>= 0; --i)
#define fored(i,l,r) for(int i=(int)r; i>= (int)l; --i)
#define pb push_back
#define el '\n'
#define db(x) cout<< #x<< " " << x<<el
#define ri(n) scanf("%d",&n)
#define sz(v) int(v.size())
#define all(v) v.begin(),v.end()

using namespace std;

typedef long long ll;
typedef double ld;
typedef pair<int,int> ii;
typedef pair<ll,ll> pll;
typedef tuple<int, int, int> iii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<ll> vll;
typedef vector<ld> vd;


const int inf = 1e9 + 100;
const int nax = 2e5+200;
const ld pi = acos(-1);
const ld eps= 1e-9;

int dr[] = {1,-1,0, 0,1,-1,-1, 1};
int dc[] = {0, 0,1,-1,1, 1,-1,-1};

vi g[nax];
int a[nax];

int dfs(int u, int p){
    if(sz(g[u]) == 1)return a[u];
    int ans = inf;
    for(int& v : g[u]){
        if(v == p)continue;
        ans = min(ans, dfs(v, u));
    }
    if(a[u] >= ans)return ans;
    int mid = a[u] + (ans - a[u]) / 2;
    return mid;
}

void sol(){
    int n;
    cin >> n;
    forn(i, n)g[i].clear();
    forn(i, n)cin >> a[i];
    for1(u, n - 1){
        int p;
        cin >> p;
        --p;
        g[p].pb(u);
        g[u].pb(p);
    }
    int ans = inf;
    for(int& v : g[0]){
        ans = min(ans, dfs(v, 0));
    }
    // db(ans);
    // db(a[0]);
    cout << ans + a[0] << el;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cout << setprecision(20)<< fixed;
    int t;
    cin >> t;
    while(t--){
        sol();
    }
}