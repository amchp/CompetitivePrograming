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
const int nax = 4e5+200;
const ld pi = acos(-1);
const ld eps= 1e-9;

int dr[] = {1,-1,0, 0,1,-1,-1, 1};
int dc[] = {0, 0,1,-1,1, 1,-1,-1};

const static int N = nax, alpha = 26;
ii pts[nax]; 

inline int conv(char ch){ return ch - 'a'; }

struct trie{
    int to[N][alpha], sz, in[N], out[N], timer = 0;
    vi cnt[N];
    trie(){ 
        forn(i, N)memset(to[i], 0, sizeof(to[i]));
        sz = 0;
    }
    void add(const string &s, int idx){
        int u = 0;
        for(char ch: s){
            int c = conv(ch);
            if(!to[u][c]) to[u][c] = ++sz;
            assert(sz < N);
            u = to[u][c];
        }
        cnt[u].pb(idx);
    }
    void dfs(int u, int& x){
        in[u] = ++timer;
        forn(i, alpha){
            if(to[u][i] == 0)continue;
            dfs(to[u][i], x);
        }
        out[u] = ++timer;
        for(int& idx : cnt[u]){
            if(x == 0)pts[idx].fi = in[u];
            else pts[idx].se = in[u];
        }
    }
};

struct node{
    int op, x;
    int y, y1, y2, idx;
    node(){}
    node(int x, int y): x(x), y(y), op(0){}
    node(int x, int y1, int y2, int idx, int op): x(x), y1(y1), y2(y2), idx(idx), op(op){}
    bool operator<(node b) const {
        if(x == b.x)return op < b.op;
        return x < b.x;
    }
};

trie pre = trie();
trie suf = trie();

vector<node> queries(int idx){
    string s1, s2;
    cin >> s1 >> s2;
    reverse(all(s2));
    int u = 0;
    for(char& ch : s1){
        int c = conv(ch);
        if(!pre.to[u][c])return {};
        u = pre.to[u][c];
    }
    ii qpre = {pre.in[u], pre.out[u]};
    u = 0;
    for(char& ch : s2){
        int c = conv(ch);
        if(!suf.to[u][c])return {};
        u = suf.to[u][c];
    }
    ii qsuf = {suf.in[u], suf.out[u]};
    assert(qpre.fi <= qpre.se);
    assert(qsuf.fi <= qsuf.se);
    return {
        node(qpre.fi, qsuf.fi, qsuf.se, idx, -1),
        node(qpre.se, qsuf.fi, qsuf.se, idx, 1)
    };
}

struct stree{
  int neutro = 1e9, n, l, r, pos;  vi t;
  stree(int n): n(n), t(n << 2){}
  inline int oper(int a, int b){ return a + b; }
  int query(int v, int tl, int tr){
    if(tl > r || tr < l) return neutro;  // estoy fuera
    if(l <= tl && tr <= r) return t[v];
    int tm = (tl + tr) >> 1;
    return oper(query(v << 1, tl, tm), query((v << 1) | 1, tm+1, tr));
  }
  void upd(int v, int tl, int tr){
    if(tl == tr){ ++t[v];  return; }
    int tm = (tl + tr) >> 1;
    if(pos <= tm) upd(v << 1, tl, tm);
    else upd((v << 1) | 1, tm+1, tr);
    t[v] = oper(t[v << 1], t[(v << 1) | 1]);
  }
  void upd(int idx){ pos = idx, upd(1, 0, n-1);}
  int query(int ql, int qr){ l = ql, r = qr;  return query(1, 0, n-1);}
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cout << setprecision(20)<< fixed;
    int n;
    cin >> n;
    forn(i, n){
        string s;
        cin >> s;
        pre.add(s, i);
        reverse(all(s));
        suf.add(s, i);
        pts[i] = {-1, -1};
    }
    int x = 0;
    pre.dfs(0, x);
    x = 1;
    suf.dfs(0, x);
    vector<node> qrs;
    forn(i, n){
        assert(pts[i] != ii(-1, -1));
        qrs.pb(node(pts[i].fi, pts[i].se));
    }
    int q;
    cin >> q;
    forn(i, q){
        vector<node> qr = queries(i);
        for(node& query : qr){
            qrs.pb(query);
        }
    }
    sort(all(qrs));
    vi ans(q, 0);
    stree ys(nax);
    for(node& qr : qrs){
        // cout << qr.x << ' ' << qr.op << el;
        if(qr.op == 0){
            assert(0 <= qr.y && qr.y < nax);
            ys.upd(qr.y);
        }else{
            assert(0 <= qr.y1 && qr.y2 < nax);
            ans[qr.idx] += qr.op*ys.query(qr.y1, qr.y2);
        }
    }
    forn(i, q)cout << ans[i] << el;
}