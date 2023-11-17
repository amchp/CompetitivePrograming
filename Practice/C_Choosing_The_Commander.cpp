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
const int nax = 1 << 27;
const ld pi = acos(-1);
const ld eps = 1e-9;

int dr[] = {1, -1, 0, 0, 1, -1, -1, 1};
int dc[] = {0, 0, 1, -1, 1, 1, -1, -1};


struct stree{
    int n, neutro = 0;  vi t;
    stree(int n): n(n), t(n<<2){}
    stree(vi a): n(sz(a)), t(n<<2){ build(1, 0, n-1, a); }
    inline int oper(int a, int b){ return a + b; }
    void build(int v, int tl, int tr, vi& a){// solo para el 2. constructor
        if(tl == tr){ t[v]= a[tl];  return; }
        int tm = (tr+tl)/ 2;
        build(v*2, tl, tm, a);
        build(v*2+1, tm+1, tr, a);
        t[v] = oper(t[v*2], t[v*2+1]);
    }
    int query(int v, int tl, int tr, int l, int r){
        if(tl > r || tr < l) return neutro;  // estoy fuera
        if(l <= tl && tr <= r) return t[v];
        int tm = (tl+tr)/2;
        return oper(query(v*2, tl, tm, l, r), query(v*2+1, tm+1, tr, l, r));
    }
    void upd(int v, int tl, int tr, int pos, int val){
        if(tl==tr){ t[v] += val;  return; }
        int tm = (tr+tl)/ 2;
        if(pos<= tm) upd(v*2, tl, tm, pos, val);
        else upd(v*2+1, tm+1, tr, pos, val);
        t[v] = oper(t[v*2], t[v*2+1]);
    }
    void upd(int pos, int val){ upd(1, 0, n-1, pos, val);}
    int query(int l, int r){ return query(1, 0, n-1, l, r);}
};

stree seg(0);
vi cmpr;

int sol(int l, int r, int& x, int& y, int depth){
    if(l == r || depth == -1)return 0;
    int m = (r + l) / 2;
    int sm = 0;
    // d(l);
    // d(r);
    if(x & (1<<depth)){
        if(y & (1 << depth)){
            int ind1 = lower_bound(all(cmpr), l) - cmpr.begin();
            int ind2 = upper_bound(all(cmpr), m) - cmpr.begin();
            sm = seg.query(ind1, ind2 - 1);
            // d(sm);
        }
        return sm + sol(m + 1, r, x, y, depth - 1);
    }
    if(y & (1 << depth)){
        int ind1 = lower_bound(all(cmpr), m + 1) - cmpr.begin();
        int ind2 = upper_bound(all(cmpr), r) - cmpr.begin();
        sm = seg.query(ind1, ind2 - 1);
        // d(sm);
    }
    return sm + sol(l, m, x, y, depth - 1);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << setprecision(20);
    int q;
    cin >> q;
    vector<pair<int, ii>> queries(q);
    forn(i, q){
        int qq;
        cin >> qq;
        queries[i].first = qq;
        if (qq == 1)
        {
            int p;
            cin >> p;
            cmpr.pb(p);
            queries[i].second.first = p;
        }
        else if (qq == 2)
        {
            int p;
            cin >> p;
            cmpr.pb(p);
            queries[i].second.first = p;
        }
        else
        {
            int p, l;
            cin >> p >> l;
            cmpr.pb(p);
            cmpr.pb(l);
            queries[i].second.first = p;
            queries[i].second.second = l;
        }
    }
    sort(all(cmpr));
    cmpr.resize(distance(cmpr.begin(), unique(all(cmpr))));
    // for(int v : cmpr){
    //     cout << v << ' ';
    // }
    // cout << el;
    seg = stree(sz(cmpr));
    for(auto &[qq, pr] : queries){
        auto &[p, l] = pr;
        if(qq == 1){
            int ind = lower_bound(all(cmpr), p) - cmpr.begin();
            seg.upd(ind, 1);
        }else if(qq == 2){
            int ind = lower_bound(all(cmpr), p) - cmpr.begin();
            seg.upd(ind, -1);
        }else{
            int inv = l ^ p;
            // d(inv);
            // d(l);
            cout << sol(0, (1<<27) - 1, inv, l, 26) << el;
        }
    }
}
