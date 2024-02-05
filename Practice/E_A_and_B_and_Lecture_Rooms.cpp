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
const int nax = 1e5 + 200;
const ld pi = acos(-1);
const ld eps = 1e-9;

int dr[] = {1, -1, 0, 0, 1, -1, -1, 1};
int dc[] = {0, 0, 1, -1, 1, 1, -1, -1};

const int L = 24;
int timer, up[nax][L+1];
int in[nax], out[nax], dep[nax], cnt[nax];
int depth = 0;
vi g[nax];
int dfs(int u, int p){
  dep[u] = depth;
  in[u] = ++timer;
  up[u][0] = p;
  for1(i,L) up[u][i] = up[up[u][i-1]][i-1];
  for(int v: g[u]){
    if(v==p) continue;
    ++depth;
    cnt[u] += dfs(v,u);
    --depth;
  }
  out[u] = ++timer;
  ++cnt[u];
  return cnt[u];
}
bool anc(int u, int v){
  return in[u]<= in[v] && out[u]>= out[v];
}
void solve(int root){
  timer = 0;
  dfs(root,root);
}
int lca(int u, int v){
  if(anc(u,v)) return u;
  if(anc(v,u)) return v;
  for(int i= L; i>=0; --i){
    if(!anc(up[u][i],v))
      u = up[u][i];
  }
  return up[u][0];
}



int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << setprecision(20);
    int n;
    cin >> n;
    forn(i, n - 1){
        int u, v;
        cin >> u >> v;
        --u;
        --v;
        g[u].pb(v);
        g[v].pb(u);
    }
    solve(0);
    // forn(i, n){
    //     cout << cnt[i] << ' ';
    // }
    // cout << el;
    int m;
    cin >> m;
    while(m--){
        int u, v;
        cin >> u >> v;
        --u;
        --v;
        if(u == v){
            cout << n << el;
            continue;
        }
        if(anc(v, u)){
            swap(u, v);
        }
        if(anc(u, v)){
            int dst = dep[v] - dep[u] - 1;
            if(dst % 2 == 0){
                cout << 0 << el;
                continue;
            }
            int dst2 = dst / 2;
            int cur = v;
            ford(i, L){
                if(dst2 & (1 << i)){
                    cur = up[cur][i];
                }
            }
            int meet = up[cur][0];
            // d(cur);
            // d(meet);
            cout << cnt[meet] - cnt[cur] << el;
        }else{
            // cout << "HERE" << el;
            int la = lca(u, v);
            int dstu = dep[u] - dep[la];
            int dstv = dep[v] - dep[la];
            if(dstv < dstu){
                swap(u, v);
                swap(dstv, dstu);
            }
            int dst = dstu + dstv - 1;
            if(dst % 2 == 0){
                cout << 0 << el;
                continue;
            }
            int dst2 = dst / 2;
            // d(dst2);
            int cur = v;
            ford(i, L){
                if(dst2 & (1 << i)){
                    cur = up[cur][i];
                }
            }
            int meet = up[cur][0];
            if(dstu != dstv){
                // d(meet);
                // d(cur);
                cout << cnt[meet] - cnt[cur] << el;
                continue;
            }
            int cur2 = u;
            ford(i, L){
                if(dst2 & (1 << i)){
                    cur2 = up[cur2][i];
                }
            }
            // d(cur);
            // d(cur2);
            cout << (n - cnt[la]) + (cnt[la] - cnt[cur] - cnt[cur2]) << el;
        }
    }
}
