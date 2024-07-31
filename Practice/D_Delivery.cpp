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
#define d(x) cerr<< #x<< " " << x<<el
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


const int inf = 1e9;
const int nax = 1e5+200;
const ld pi = acos(-1);
const ld eps= 1e-9;

int dr[] = {1,-1,0, 0,1,-1,-1, 1};
int dc[] = {0, 0,1,-1,1, 1,-1,-1};

int n;
vi g[nax];

int bfs(int st){
    queue<int> q;
    vector<bool> vis(n);
    q.push(st);
    int d = -1;
    vis[st] = true;
    while(!q.empty()){
        ++d;
        int e = sz(q);
        forn(_, e){
            int u = q.front();
            q.pop();
            for(int& v : g[u]){
                if(!vis[v]){
                    vis[v] = true;
                    q.push(v);
                }
            }
        }
    }
    return d;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cout << setprecision(20)<< fixed;
    int mx, mn;
    cin >> mx >> mn;
    if(!(mn <= mx && mx <= 2*mn)){
        cout << "-1" << el;
        return 0;
    }
    n = 2*mn + (mx - mn);
    int lpnds = 2*mn;
    vector<ii> edg;
    forn(i, lpnds){
        int u = i;
        int v = (i + 1) % (lpnds);
        if(v + 1 == u)continue;
        edg.pb({u, v});
        g[u].pb(v);
        g[v].pb(u);
    }
    forn(i, mx - mn){
        edg.pb({lpnds-1+i,lpnds+i});
        g[lpnds-1+i].pb(lpnds+i);
    }
    cout << n << ' ' << sz(edg) << el;
    for(auto& [u, v] : edg){
        assert(u >= 0 && u < n);
        assert(v >= 0 && v < n);
        cout << u + 1 << ' ' << v + 1 << el;
    }
    int mxdst = bfs(mn - 1);
    assert(mxdst == mx);
    int mndst = bfs(2*mn - 1);
    assert(mndst == mn);
}