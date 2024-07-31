#include <bits/stdc++.h>

#define el '\n'
#define forn(i, n) for(int i = 0; i < n; ++i)
#define for1(i, n) for(int i = 1; i <= n; ++i)
#define fore(i, l, r) for(int i = (int)l; i <= (int)r; ++i)
#define all(x) x.begin(), x.end()
#define allr(x) x.rbegin(), x.rend()
#define pb push_back
#define sz(x)(int) x.size()
#define fi first
#define se second
#define db(x) cerr << #x << ' ' << x << el

using namespace std;

typedef long long ll;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef array<int, 3> v3;
typedef vector<ii> vii;


const ll inf = 1e18;

struct edge{
    int to, rev; ll cap, cos, f{0};
    edge(int to, int rev, ll cap, ll cos): to(to), rev(rev), cap(cap), cos(cos){}
};

struct MCMF{
    int n, s, t;
    vector<vector<edge>> g;
    vi p; vll dis;
    MCMF(int n): n(n), g(n){}
    void addEdge(int s, int t, ll cap, ll cos){
        g[s].pb(edge(t, sz(g[t]), cap, cos));
        g[t].pb(edge(s, sz(g[s])-1, 0, -cos));
    }
    void spfa(int v0){
        dis.assign(n, inf); dis[v0] = 0;
        p.assign(n, -1);
        vector<bool> inq(n);
        queue<int> q({v0});
        while(sz(q)){
            int u = q.front(); q.pop();
            inq[u] = 0;
            for(auto&[v, rev, cap, cos, f] : g[u]){
                if(cap - f > 0 && dis[v] > dis[u] + cos){
                    dis[v] = dis[u] + cos, p[v] = rev;
                    if(!inq[v]) inq[v] = 1, q.push(v);
                }
            }
        }
    }
    ll min_cos_flow(ll K){
        ll flow = 0, cost = 0;
        while(flow < K){
            spfa(s);
            if(dis[t] == inf)break;
            ll f = K - flow;
            int cur = t;
            while(cur != s){
                int u = g[cur][p[cur]].to, rev = g[cur][p[cur]].rev;
                f = min(f, g[u][rev].cap - g[u][rev].f);
                cur = u;
            }
            flow += f, cost += f * dis[t], cur = t;
            while(cur != s){
                int u = g[cur][p[cur]].to, rev = g[cur][p[cur]].rev;
                g[u][rev].f += f, g[cur][p[cur]].f -= f;
                cur = u;
            }
        }
        if(flow < K)return -1;
        return cost;
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string wrd;
    cin >> wrd;
    map<char, int> wrdcnt;
    for(char& c : wrd){
        ++wrdcnt[c];
    }
    int n;
    cin >> n;
    int N = n + 26 + 2;
    int s = N - 2, t = N - 1;
    MCMF mcmf = MCMF(N);
    mcmf.s = s, mcmf.t = t;
    vector<string> ss(n);
    vector<map<char, int>> sscnt(n);
    vi mt(n);
    forn(i, n){
        cin >> ss[i];
        for(char& c : ss[i])++sscnt[i][c];
        cin >> mt[i];
    }
    forn(i, n){
        mcmf.addEdge(s, i, mt[i], i + 1);
    }
    for(auto& [c, cnt] : wrdcnt){
        mcmf.addEdge(n + int(c - 'a'), t, cnt, 0);
    }
    forn(i, n){
        for(auto& [c, cnt] : sscnt[i]){
            mcmf.addEdge(i, n + int(c - 'a'), sscnt[i][c], 0);
        }
    }
    cout << mcmf.min_cos_flow(sz(wrd)) << el;
}
