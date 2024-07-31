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

typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;


const int nax = 5e4 + 100;
const int inf = 1e9;

vector<ii> g[nax];
vector<vi> ans;
vector<bool> vise(nax);

void bfs(int st){
    if(g[st].empty())return;
    queue<ii> q;
    q.push({st, st});
    vector<bool> visn(nax);
    vi prt(nax, -1);
    prt[st] = st;
    visn[st] = true;
    while(!q.empty()){
        auto& [u, cp] = q.front();
        q.pop();
        for(auto& [v, ind] : g[u]){
            if(vise[ind])continue;
            if(visn[v]){
                vi cans;
                int p = u;
                while(p != st){
                    cans.pb(p);
                    p = prt[p];
                }
                cans.pb(p);
                reverse(all(cans));
                p = v;
                while(p != st){
                    cans.pb(p);
                    p = prt[p];
                }
                cans.pb(p);
                ans.pb(cans);
                break;
            }
            visn[v] = true;
            prt[v] = u;
            vise[ind] = true;
            q.push({v, u});
        }
    }
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cout << setprecision(20)<< fixed;
    int m;
    cin >> m;
    int mn = inf;
    forn(i, m){
        int u, v;
        cin >> u >> v;
        g[u].pb({v, i});
        g[v].pb({u, i});
        mn = min({mn, u, v});
    }
    forn(i, nax)bfs(i);
    cout << sz(ans) << el;
    for(vi& vec : ans){
        cout << sz(vec) << ' ';
        for(int& v : vec)cout << v << ' ';
        cout << el;
    }
}
