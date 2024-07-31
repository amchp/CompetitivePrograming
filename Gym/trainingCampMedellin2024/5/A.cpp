#include <bits/stdc++.h>

#define forn(i, n) for(int i = 0; i < n; ++i)
#define for1(i, n) for(int i = 1; i <= n; ++i)
#define el '\n'
#define db(x) cerr<<#x<<" "<<x<<el
#define pb push_back
#define sz(a) (int) a.size()
#define all(x) x.begin(), x.end()

using namespace std;

typedef vector<int> vi;
typedef long long ll;
typedef vector<ll> vll;
typedef array<int, 3>  a3;
const int nax = 2e5 + 100;

struct stree{
    int neutro = 0, n, l, r, pos, val;
    vi t;
    stree(int n): n(n), t(n << 2){}
    inline int oper(int a, int b){ return a + b; }
    int query(int v, int tl, int tr){
        if(tl > r || tr < l)return neutro;
        if(l <= tl && tr <= r)return t[v];
        int tm = (tl + tr) >> 1;
        return oper(query(v << 1, tl, tm), query((v << 1) | 1, tm + 1, tr));
    }
    void upd(int v, int tl, int tr){
        if(tl == tr){ t[v] = val; return; }
        int tm = (tl + tr) >> 1;
        if(pos <= tm) upd(v << 1, tl, tm);
        else upd((v << 1) | 1, tm+1, tr);
        t[v] = oper(t[v << 1], t[(v << 1) | 1]);
    }
    void upd(int idx, int num){ pos = idx, val = num, upd(1, 0, n - 1); }
    int query(int ql, int qr){ l = ql, r = qr; return query(1, 0, n - 1); }
};

vi g[nax];
int num = 0;
int in[nax], out[nax];
int hjs[nax];

void dfs(int u, int p){
    in[u] = num++;
    hjs[u] = 1;
    for(int& v : g[u]){
        if(v == p)continue;
        dfs(v, u);
        hjs[u] += hjs[v];
    }
    out[u] = num;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    forn(i, n - 1){
        int u, v;
        cin >> u >> v;
        --u, --v;
        g[u].pb(v);
        g[v].pb(u);
    }
    dfs(0, -1);
    stree st(n + 10);
    vll pre(n + 10);
    forn(u, n){
        int lst = st.query(in[u], out[u] - 1);
        int lost = u - lst;
        db(lst);
        db(lost);
        pre[in[u]] += lost;
        pre[out[u]] -= lost;
        pre[0] += lst;
        pre[in[u] + 1] -= lst;
        pre[out[u]] += lst;
        pre[n] -= lst;
        st.upd(in[u], 1);
    }
    for1(i, n){
        pre[i] += pre[i - 1];
    }
    vll ans(n);
    forn(i, n){
        ans[i] = pre[in[i]];
    }
    forn(i, n)cout << ans[i] << ' ';
    cout << el;
}