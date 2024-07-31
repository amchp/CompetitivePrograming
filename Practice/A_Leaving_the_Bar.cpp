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

struct pt{
    int x, y;
    pt(){}
    pt(int x, int y): x(x), y(y){}
    ll norm2(){ return 1LL*x*x + 1LL*y*y; }
    pt operator+(pt p){ return pt(x + p.x, y + p.y); }
    pt operator*(int i){ return pt(i*x, i*y); }
};

typedef pair<pt, int> ppti;

vi ans;
vi g[nax];
vector<ii> sgn = {{1, 1}, {-1, 1}, {1, -1}, {-1, -1}};

vector<ppti> sol(vector<ppti>& cur){
    pt mn = pt(1e8, 1e8);
    int ci = -1;
    int cj = -1;
    int si = 0;
    int sj = 0;
    forn(i, 3){
        pt a = cur[i].fi;
        fore(j, i + 1, 2){
            pt b = cur[j].fi;
            forn(k, 4){
                int csi  = sgn[k].fi;
                int csj = sgn[k].se;
                pt nxt = a*csi + b*csj;
                if(nxt.norm2() < mn.norm2()){
                    mn = nxt;
                    ci = i;
                    cj = j;
                    si = csi;
                    sj = csj;
                }
            }
        }
    }
    vector<ppti> ncur;
    ncur.pb(ppti(mn, sz(ans)));
    g[sz(ans)].pb(cur[ci].se);
    g[sz(ans)].pb(cur[cj].se);
    ans.pb(0);
    ans[cur[ci].se] = si;
    ans[cur[cj].se] = sj;
    forn(i, 3){
        if(i == ci || i == cj)continue;
        ncur.pb(cur[i]);
    }
    return ncur;
}

void dfs(int u, int mlt){
    // d(u);
    // d(ans[u]);
    ans[u] *= mlt;
    for(int& v : g[u]){
        dfs(v, ans[u]);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << setprecision(20);
    int n;
    cin >> n;
    vector<pt> pts(n);
    forn(i, n){
        int x, y;
        cin >> pts[i].x >> pts[i].y;
    }
    if(n == 1){
        cout << 1 << el;
        return 0;
    }
    if(n == 2){
        pt mn = pt(1e8, 1e8);
        int si = 0;
        int sj = 0;
        pt a = pts[0];
        pt b = pts[1];
        forn(k, 4){
            int csi  = sgn[k].fi;
            int csj = sgn[k].se;
            pt nxt = a*csi + b*csj;
            if(nxt.norm2() < mn.norm2()){
                mn = nxt;
                si = csi;
                sj = csj;
            }
        }
        cout << si << ' ' << sj << el;
        return 0;
    }
    forn(i, n){
        ans.pb(0);
    }
    vector<ppti> cur;
    forn(i, 3)cur.pb(ppti(pts[i], i));
    fore(i, 3, n - 1){
        cur = sol(cur);
        cur.pb({pts[i], i});
    }
    cur = sol(cur);
    pt mn = pt(1e8, 1e8);
    int si = 0;
    int sj = 0;
    pt a = cur[0].fi;
    pt b = cur[1].fi;
    forn(k, 4){
        int csi  = sgn[k].fi;
        int csj = sgn[k].se;
        pt nxt = a*csi + b*csj;
        if(nxt.norm2() < mn.norm2()){
            mn = nxt;
            si = csi;
            sj = csj;
        }
    }
    ans[cur[0].se] = si;
    ans[cur[1].se] = sj;
    // forn(i, 2*n){
    //     d(i);
    //     for(int& v : g[i]){
    //         cout << v << ' ';
    //     }
    //     cout << el;
    // }
    dfs(cur[0].se, 1);
    dfs(cur[1].se, 1);
    forn(i, n)cout << ans[i] << ' ';
    cout << el;
}
