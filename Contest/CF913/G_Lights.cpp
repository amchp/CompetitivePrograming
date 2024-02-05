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

vector<vi> lps;
vector<bool> vis;
string li;
int in[nax];
int a[nax];
vi cur;
vi ansv;

void dfs(int ind){
    vis[ind] = true;
    cur.pb(ind);
    if(!vis[a[ind]])dfs(a[ind]);
}

void addmv(int u){
    li[u] = '0';
    if(li[a[u]] == '0')li[a[u]] = '1';
    else li[a[u]] = '0';
    ansv.pb(u);
}

int sol(){
    int n;
    cin >> n;
    cin >> li;
    lps.clear();
    vis = vector<bool>(n, false);
    forn(i, n)in[i] = 0;
    forn(i, n){
        cin >> a[i];
        --a[i];
        ++in[a[i]];
    }
    queue<int> q;
    forn(i, n){
        if(in[i] == 0){
            q.push(i);
        }
    }
    while(!q.empty()){
        int u = q.front();
        q.pop();
        vis[u] = true;
        if(li[u] == '1'){
            addmv(u);
        }
        --in[a[u]];
        if(in[a[u]] == 0)q.push(a[u]);
    }
    forn(i, n){
        if(!vis[i]){
            dfs(i);
            lps.pb(cur);
            cur.clear();
        }
    }
    for(vi& vec : lps){
        vi dist;
        int fst = -1;
        int snd = -1;
        int prv = -1;
        forn(i, sz(vec)){
            int v = vec[i];
            // cout << v << ' ';
            if(li[v] == '1'){
                if(prv == -1){
                    prv = i;
                    fst = i;
                    continue;
                }
                if(snd == -1)snd = i;
                dist.pb(i - prv);
                prv = i;
            }
        }
        // cout << el;
        if(fst == -1)continue;
        dist.pb((fst - prv + sz(vec)) % sz(vec));
        if(sz(dist) % 2 == 1){
            return -1;
        }
        int ev = 0, od = 0;
        forn(i, sz(dist)){
            if(i % 2 == 0){
                ev += dist[i];
            }else{
                od += dist[i];
            }
        }
        int st;
        int i;
        if(ev < od){
            st = vec[fst];
            i = vec[(fst + 1) % sz(vec)];
        }else{
            st = vec[(snd)];
            i = vec[(snd + 1) % sz(vec)];
        }
        addmv(st);
        // int iter = 0;
        while(i != st){
            // assert(iter < 3e5);
            if(li[i] == '1')addmv(i);
            i = a[i];
            // iter++;
        }
    }
    return 1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << setprecision(20);
    int t;
    cin >> t;
    while(t--){
        ansv.clear();
        int ans = sol();
        if(ans == -1){
            cout << -1 << el;
            continue;
        }
        cout << sz(ansv) << el;
        for(int& v : ansv){
            cout << v + 1 << ' ';
        }
        cout << el;
    }
}
