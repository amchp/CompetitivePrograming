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
#define d(x) cout<< #x<< " " << x<<el
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

struct node{
    int dist, u, c;
    node(){}
    node(int dist, int u, int c): dist(dist), u(u), c(c){}
    bool operator>(node b) const{
        return dist > b.dist;
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cout << setprecision(20)<< fixed;
    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        vector<vector<ii>> g(n);
        vi clines;
        forn(i, m){
            int u, v, c;
            cin >> u >> v >> c;
            --u, --v;
            g[u].pb({v, c});
            g[v].pb({u, c});
            clines.pb(c);
        }
        sort(all(clines));
        clines.erase(unique(all(clines)), clines.end());
        vector<vi> lines(sz(clines));
        forn(u, n){
            for(auto& [v, c] : g[u]){
                c = lower_bound(all(clines), c) - clines.begin();
                lines[c].pb(u);
            }
        }
        int st, e;
        cin >> st >> e;
        --st;
        --e;
        vector<bool> vis(sz(clines));
        vi dp(n, inf);
        queue<int> q;
        dp[st] = 0;
        for(auto& [v, c] : g[st])q.push(c);
        int lvl = 1;
        while(sz(q)){
            int e = sz(q);
            forn(_, e){
                int line = q.front();
                q.pop();
                for(auto& v : lines[line]){
                    if(lvl < dp[v]){
                        dp[v] = lvl;
                        for(auto& [w, nline] : g[v]){
                            if(!vis[nline]){
                                q.push(nline);
                                vis[nline] = true;
                            }
                        }
                    }
                }
            }
            ++lvl;
        }
        cout << dp[e] << el;
    }
}