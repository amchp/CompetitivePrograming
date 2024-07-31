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
const int nax = 2e5 + 200;
const ld pi = acos(-1);
const ld eps = 1e-9;

int dr[] = {1, -1, 0, 0, 1, -1, -1, 1};
int dc[] = {0, 0, 1, -1, 1, 1, -1, -1};

vi g[nax];
int seen[nax];
bool dfs(int u){
  seen[u] = 1;
  for(int v: g[u]){
    if (!seen[v])
      dfs(v);
    if(seen[v] == 1)return false;
  }
  seen[u] = 2;
  return true;
}
bool topo(int n){
  forn(i,n){
    if (!seen[i]){
        if(!dfs(i))return false;
    }
  }
  return true;
}

bool sol(){
    int n, k;
    cin >> n >> k;
    vector<vi> a(k, vi(n));
    forn(i, k){
        forn(j, n){
            cin >> a[i][j];
            --a[i][j];
            if(j < 2)continue;
            g[a[i][j - 1]].pb(a[i][j]);
            // cout << a[i][j - 1] << ' ' << a[i][j] << el;
        }
    }
    bool ans = topo(n);
    forn(i, n){
        seen[i] = 0;
        g[i].clear();
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << setprecision(20);
    int t;
    cin >> t;
    while(t--){
        if(sol()){
            cout << "YES" << el;
        }else{
            cout << "NO" << el;
        }
        
    }
}
