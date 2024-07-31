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
/// 1000234999, 1000567999, 1000111997, 1000777121, 999727999, 1070777777
const int MOD[] = { 1001864327, 1001265673 }, N = 1e6;
const ii BASE(257, 367), ZERO(0, 0), ONE(1, 1);
inline int add(int a, int b, int mod) { return a+b >= mod ? a+b-mod : a+b; }
inline int sbt(int a, int b, int mod) { return a-b < 0 ? a-b+mod : a-b; }
inline int mul(int a, int b, int mod) { return ll(a) * b % mod;} 
inline ll operator ! (const ii a) { return (ll(a.fi) << 32) | a.se; }
inline ii operator + (const ii& a, const ii& b) {
  return {add(a.fi, b.fi, MOD[0]), add(a.se, b.se, MOD[1])};}
inline ii operator - (const ii& a, const ii& b) {
  return {sbt(a.fi, b.fi, MOD[0]), sbt(a.se, b.se, MOD[1])};}
inline ii operator * (const ii& a, const ii& b) {
  return {mul(a.fi, b.fi, MOD[0]), mul(a.se, b.se, MOD[1])};}

struct stree{
  ii neutro = {0, 0};
  int n, l, r, pos;
  ii val; 
  vector<ii> t;
  stree(int n): n(n), t(n << 2){}
  stree(const vector<ii>& a): n(sz(a)), t(n<<2){ build(1, 0, n-1, a); }
  inline ii oper(ii a, ii b){ return a + b; }
  void build(int v, int tl, int tr, const vector<ii>& a){// solo para el 2. constructor
    if(tl == tr){ t[v] = a[tl];  return; }
    int tm = (tl + tr) >> 1;
    build(v << 1, tl, tm, a), build((v << 1) | 1, tm+1, tr, a);
    t[v] = oper(t[v << 1], t[(v << 1) | 1]);
  }
  ii query(int v, int tl, int tr){
    if(tl > r || tr < l) return neutro;  // estoy fuera
    if(l <= tl && tr <= r) return t[v];
    int tm = (tl + tr) >> 1;
    return oper(query(v << 1, tl, tm), query((v << 1) | 1, tm+1, tr));
  }
  void upd(int v, int tl, int tr){
    if(tl == tr){ t[v] = val;  return; }
    int tm = (tl + tr) >> 1;
    if(pos <= tm) upd(v << 1, tl, tm);
    else upd((v << 1) | 1, tm+1, tr);
    t[v] = oper(t[v << 1], t[(v << 1) | 1]);
  }
  void upd(int idx, ii num){ pos = idx, val = num, upd(1, 0, n-1);}
  ii query(int ql, int qr){ l = ql, r = qr;  return query(1, 0, n-1);}
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cout << setprecision(20)<< fixed;
    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;
    vector<ii> fwd(n);
    vector<ii> bck(n);
    vector<ii> pBASE(n);
    pBASE[0] = ONE;
    for1(i, n - 1){
        pBASE[i] = BASE * pBASE[i - 1];
    }
    forn(i, n){
        fwd[i] = ii{s[i], s[i]}*pBASE[i - 1] + pBASE[i];
    }
    reverse(all(s));
    forn(i, n){
        bck[i] = ii{s[i], s[i]}*pBASE[i - 1] + pBASE[i];
    }
    stree sfwd(fwd);
    stree sbck(bck);
    while(q--){
        int op, l;
        cin >> op >> l;
        --l;
        if(op == 1){
            char c;
            cin >> c;
            sfwd.upd(l, ii{c, c} + pBASE[l]);
            sbck.upd(n - 1 - l, ii{c, c} + pBASE[n - 1 - l]);
            d(l);
            d(n - 1 - l);
        }
        if(op == 2){
            int r;
            cin >> r;
            --r;
            ii qfwd = sfwd.query(l, r) - 
            ii{(r - l + 1), (r - l + 1)}*pBASE[l];
            ii qbck = sbck.query(n - 1 - r, n - 1 - l) - 
            ii{(r - l + 1), (r - l + 1)}*pBASE[n - 1 - r];
            d(l);
            d(r);
            d(n - 1 - r);
            d(n - 1 - l);
            cout << qfwd.fi << ' ' << qfwd.se << el;
            cout << qbck.fi << ' ' << qbck.se << el;
            if(qfwd == qbck){
                cout << "Yes" << el;
            }else{
                cout << "No" << el;
            }
        }
    }
}