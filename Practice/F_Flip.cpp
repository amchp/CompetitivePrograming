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
    int pre, suf, len;
    ll sm;
    node(){}
    node(int pre, int suf, int len, ll sm): pre(pre), suf(suf), len(len), sm(sm){}
};

ll sm2(int x){
    return (ll(x)*(x + 1)) / 2;
}

struct stree{
  node neutro = node(0, 0, 0, 0);
  int n, l, r, pos, val;
  vector<node> t;
  stree(int n): n(n), t(n << 2){}
  stree(const vi& a): n(sz(a)), t(n<<2){ build(1, 0, n-1, a); }
  inline node oper(node a, node b){
    int presuf = a.suf + b.pre;
    int pre = a.pre == a.len ? presuf : a.pre;
    int suf = b.suf == b.len ? presuf : b.suf;
    ll sm = a.sm + b.sm + sm2(presuf) - sm2(a.suf) - sm2(b.pre);
    return node(pre, suf, a.len + b.len, sm);
  }
  void build(int v, int tl, int tr, const vi& a){// solo para el 2. constructor
    if(tl == tr){
        t[v] = node(a[tl], a[tl], 1, a[tl]);
        // d(tl);
        // d(tr);
        // cout << t[v].pre << ' ' << t[v].sm << ' ' << t[v].suf << el;
        return;
    }
    int tm = (tl + tr) >> 1;
    build(v << 1, tl, tm, a), build((v << 1) | 1, tm+1, tr, a);
    t[v] = oper(t[v << 1], t[(v << 1) | 1]);
    // d(tl);
    // d(tr);
    // cout << t[v].pre << ' ' << t[v].sm << ' ' << t[v].suf << el;
  }
  node query(int v, int tl, int tr){
    if(tl > r || tr < l) return neutro;  // estoy fuera
    if(l <= tl && tr <= r){
        // d(tl);
        // d(tr);
        // d(t[v].sm);
        // cout << el;
        return t[v];
    }
    int tm = (tl + tr) >> 1;
    node nd = oper(query(v << 1, tl, tm), query((v << 1) | 1, tm+1, tr));
    // d(tl);
    // d(tr);
    // d(nd.sm);
    // cout << el;
    return nd;
  }
  void upd(int v, int tl, int tr){
    if(tl == tr){
        t[v] = node(val, val, 1, val); 
        // d(tl);
        // d(tr);
        // cout << t[v].pre << ' ' << t[v].sm << ' ' << t[v].suf << el; 
        return;
    }
    int tm = (tl + tr) >> 1;
    if(pos <= tm) upd(v << 1, tl, tm);
    else upd((v << 1) | 1, tm+1, tr);
    t[v] = oper(t[v << 1], t[(v << 1) | 1]);
    // d(tl);
    // d(tr);
    // cout << t[v].pre << ' ' << t[v].sm << ' ' << t[v].suf << el;
  }
  void upd(int idx, int num){ pos = idx, val = num, upd(1, 0, n-1);}
  ll query(int ql, int qr){ 
    if(ql > qr)return 0;
    l = ql, r = qr;  return query(1, 0, n-1).sm;
  }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cout << setprecision(20)<< fixed;
    int n, q;
    cin >> n >> q;
    vi a(n);
    vi dif(n - 1);
    forn(i, n)cin >> a[i];
    forn(i, n - 1){
        dif[i] = a[i] != a[i + 1];
        // cout << dif[i] << ' ';
    }
    // cout << el;
    stree st = stree(dif);
    while(q--){
        int op, l, r;
        cin >> op >> l >> r;
        --l;
        --r;
        if(op == 1){
            --l;
            if(l != -1){
                dif[l] = !dif[l];
                st.upd(l, dif[l]);
            }
            // cout << el;
            if(r != n - 1){
                dif[r] = !dif[r];
                st.upd(r, dif[r]);
            }
            // cout << el;
        }
        if(op == 2){
            ll ans = st.query(l, r - 1);
            // d(ans);
            // d(l);
            // d(r);
            cout << (r - l + 1) + ans << el;
        }
    }
}