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
const int nax = 3e5 + 200;
const ld pi = acos(-1);
const ld eps = 1e-9;

int dr[] = {1, -1, 0, 0, 1, -1, -1, 1};
int dc[] = {0, 0, 1, -1, 1, 1, -1, -1};

struct node{
    ll val, r, sm;
    node(){}
    node(ll val, ll r, ll sm): val(val), r(r), sm(sm){}
};

struct lnode{
    ll val, r;
    bool psh;
    lnode(){}
    lnode(ll val, ll r): val(val), r(r), psh(true){}
};

const int N = 3e5 + 10;
node t[N << 2];
lnode lazy[N << 2];

ll smr(ll x){
    return x*(x + 1) / 2;
}

struct stree{
    int n, l, r, val, ur;
    ll neutro = 0;
    stree(vector<int> &rs, vector<int>& vals){ 
        n = sz(rs); forn(i, n << 2)lazy[i].psh = true;
        build(1, 0, n-1, rs, vals);
    }
    inline node operu(node& a, node& b){
        node c;
        if(a.r != b.r){
            c.val = 0;
            c.r = max(a.r, b.r);
        }
        else{
            c.val = a.val;
            c.r = a.r;
        }
        c.sm = a.sm + b.sm;
        return c;
    }
    inline ll operq(ll a, ll b){ return a + b; }
    inline void calc(int v, int tl, int tr){
        node& nd = t[v];
        if(nd.val == 0){
            nd.sm = 0;
            return;
        }
        int sr = nd.r - tl;
        int dst = nd.r - tr - 1;
        nd.sm = nd.val*(smr(sr)-smr(dst));
    }
    inline void push(int v, int tl, int tr){
        if(lazy[v].psh)return;
        int lft = v << 1;
        int rgt = (v << 1) | 1;
        int tm = (tl + tr) >> 1;;
        t[lft].val = lazy[v].val, t[lft].r = lazy[v].r;
        t[rgt].val = lazy[v].val, t[rgt].r = lazy[v].r;
        lazy[lft] = lazy[v];
        lazy[rgt] = lazy[v];
        calc(lft, tl, tm);
        calc(rgt, tm + 1, tr);
        lazy[v].psh = true;
    }
    void build(int v, int tl, int tr, vector<int> &rs, vector<int>& vals){
        if(tl == tr){
            t[v].r = rs[tl];
            t[v].val = vals[tl];
            calc(v, tl, tr);
            return;
        }
        int tm = (tl + tr) >> 1;
        build(v << 1, tl, tm, rs, vals), build((v << 1) | 1, tm+1, tr, rs, vals);
        t[v] = operu(t[v << 1], t[(v << 1) | 1]);
        // d(tl);
        // d(tr);
        // d(t[v].sm);
    }
    void upd(int v, int tl, int tr){
        if(tl > r || tr < l) return;
        if(l <= tl && tr <= r){
            // d(tl);
            // d(tr);
            t[v].r = ur;
            t[v].val = val;
            lazy[v].r = ur;
            lazy[v].val = val;
            lazy[v].psh = false;
            calc(v, tl, tr);
            // d(t[v].sm);
            return ;
        }
        push(v, tl, tr);  int tm = (tl + tr) >> 1;
        upd(v << 1, tl, tm);  upd((v << 1) | 1, tm+1, tr);
        t[v] = operu(t[v << 1], t[(v << 1) | 1]);
    }
    ll query(int v, int tl, int tr){
        if(tl > r || tr < l) return neutro;
        if(l <= tl && tr <= r){
            return t[v].sm;
        }
        push(v, tl, tr);  
        int tm = (tl + tr) >> 1;
        ll ans = operq(query(v << 1, tl, tm), query((v << 1) | 1, tm + 1, tr));
        return ans;
    }
    void update(int ql, int qr, int qval, int qur){  
        l = ql, r = qr, val = qval, ur = qur, upd(1, 0, n-1); }
    ll query(int ql, int qr){ l = ql, r = qr;  return query(1, 0, n-1); }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << setprecision(20);
    int n, m, q;
    cin >> n >> m >> q;
    vi ind(m);
    vi rs(n);
    vi vals(n);
    set<int> prts;
    forn(i, m){
        cin >> ind[i];
        --ind[i];
        prts.insert(ind[i]);
    }
    forn(i, m){
        int val;
        cin >> val;
        vals[ind[i]] = val;
    }
    for1(i, n - 1){
        if(vals[i] != 0)continue;
        vals[i] = vals[i - 1];
    }
    int prv = 0;
    for(int r: prts){
        fore(i, prv, r){
            rs[i] = r;
        }
        prv = r + 1;
    }
    stree st(rs, vals);
    while(q--){
        int op, f, s;
        cin >> op >> f >> s;
        if(op == 1){
            --f;
            auto ls = prts.upper_bound(f);
            auto gtr = ls;
            --ls;
            int l = (*ls);
            int r = (*gtr);
            st.update(f, f, s, f);
            st.update(l + 1, f, vals[l], f);
            st.update(f + 1, r, s, r);
            vals[f] = s;
            prts.insert(f);
        }else{
            --f, --s;
            cout << st.query(f, s) << el;
        }
    }
}
