#include <bits/stdc++.h>

#define forn(i,n) for(int i = 0; i< (int)n;++i)
#define for1(i,n) for(int i = 1; i<= (int)n;++i)
#define fore(i,l,r) for(int i = (int)l; i<= (int)r;++i)
#define ford(i,n) for(int i = (int)n - 1; i >= 0;--i)
#define pb push_back
#define sz(a) (int ) a.size()
#define el '\n'
#define all(x) x.begin(), x.end()
#define d(x) cout << #x << ' ' << x << el;

using namespace std;

typedef long double ld;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

const int nax = 1e5 + 100;
// const int nax = 1e3 + 100;

vector<ii> g[nax];
int vis[nax];
set<int> inloop;
vi loop;
vi keys;
bool edge;
int le, lei;

bool dfs(int u, int p){
    vis[u] = true;
    for(auto& [v, ind] : g[u]){
        if(v == p)continue;
        if(v == 1){
            edge |= u == 0;
            inloop.insert(u);
            loop.pb(u);
            le = u;
            lei = ind;
            return true;
        }
        if(vis[v])continue;
        if(dfs(v, u)){
            edge |= u == 0;
            inloop.insert(u);
            loop.pb(u);
            keys.pb(ind);
            return true;
        }
    }
    return false;
}

vi path;
vi dkeys;

bool dfs2(int u){
    vis[u] = true;
    for(auto& [v, ind] : g[u]){
        if(vis[v])continue;
        if(v == 0){
            edge |= u != 1 && inloop.count(u);
            if(edge)le = u;
            path.pb(u);
            dkeys.pb(ind);
            return true;
        }
        if(dfs2(v)){
            if(edge)return true;
            edge |= u != 1 && inloop.count(u);
            if(edge)le = u;
            path.pb(u);
            dkeys.pb(ind);
            return true;
        }
    }
    return false;
}

vector<string> zpath;
vi zkeys;
vi okeys;
vector<string> opath;

void output(){
    sort(all(zkeys));
    zkeys.erase(unique(zkeys.begin(), zkeys.end()), zkeys.end());
    for(int& v : zkeys)cout << v << ' ';
    cout << el;
    sort(all(okeys));
    okeys.erase(unique(okeys.begin(), okeys.end()), okeys.end());
    for(int& v : okeys)cout << v << ' ';
    cout << el;
    for(string& v : zpath){
        cout << v << el;
    }
    cout << "DONE" << el;
    for(string& v : opath){
        cout << v << el;
    }
    cout << "DONE" << el;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(20);
    int n, m;
    cin >> n >> m;
    forn(i, m){
        int u, v;
        cin >> u >> v;
        g[u].pb({v, i});
        g[v].pb({u, i});
    }
    bool pass = dfs(1, 1);
    if(!pass){
        cout << "No solution" << el;
        return 0;
    }
    reverse(all(loop));
    reverse(all(keys));
    if(edge){
        okeys.pb(lei);
        int ind;
        ford(i, sz(loop)){
            opath.pb("MOVE " + to_string(loop[i]));
            ind = i;
            if(loop[i] == 0)break;
            okeys.pb(keys[i - 1]);
        }
        ford(i, ind){
            zpath.pb("MOVE " + to_string(loop[i]));
            zkeys.pb(keys[i]);
        }
        output();
        return 0;
    }
    memset(vis, 0, sizeof(vis));
    dfs2(1);
    if(!edge){
        for(int& v : keys){
            zkeys.pb(v);
        }
        for(int& v : dkeys){
            zkeys.pb(v);
        }
        for(int& v : path){
            zpath.pb("MOVE " + to_string(v));
        }
        for1(i, sz(loop) - 1){
            zpath.pb("MOVE " + to_string(loop[i]));
        }
        zpath.pb("DROP ");
        for(int& v : dkeys){
            zpath.back().append(to_string(v) + " ");
        }
        ford(i, sz(loop) - 1){
            zpath.pb("MOVE " + to_string(loop[i]));
        }
        okeys.pb(lei);
        opath.pb("MOVE " + to_string(le));
        opath.pb("GRAB");
        opath.pb("MOVE 1");
        ford(i, sz(path) - 1){
            opath.pb("MOVE " + to_string(path[i]));
        }
        opath.pb("MOVE 0");
        output();
        return 0;
    }
    okeys.pb(lei);
    for(int& v : dkeys){
        zkeys.pb(v);
    }
    int ind;
    ford(i, sz(loop)){
        opath.pb("MOVE " + to_string(loop[i]));
        ind = i;
        if(loop[i] == le)break;
        okeys.pb(keys[i - 1]);
    }
    for(int& v : path){
        zpath.pb("MOVE " + to_string(v));
    }
    zpath.pb("DROP ");
    for(int& v : dkeys){
        zpath.back().append(to_string(v) + " ");
    }
    ford(i, ind){
        zpath.pb("MOVE " + to_string(loop[i]));
        zkeys.pb(keys[i]);
    }
    opath.pb("GRAB");
    ford(i, sz(path) - 1){
        opath.pb("MOVE " + to_string(path[i]));
    }
    opath.pb("MOVE 0");
    output();
    return 0;
}