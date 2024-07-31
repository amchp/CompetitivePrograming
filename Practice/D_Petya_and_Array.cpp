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

struct stree{
  int neutro = 0, n, l, r, pos;  vi t;
  stree(int n): n(n), t(n << 2){}
  stree(const vi& a): n(sz(a)), t(n<<2, 0){ build(1, 0, n-1, a); }
  inline int oper(int a, int b){ return a + b; }
  void build(int v, int tl, int tr, const vi& a){// solo para el 2. constructor
    if(tl == tr){ t[v] = a[tl];  return; }
    int tm = (tl + tr) >> 1;
    build(v << 1, tl, tm, a), build((v << 1) | 1, tm+1, tr, a);
    t[v] = oper(t[v << 1], t[(v << 1) | 1]);
  }
  int query(int v, int tl, int tr){
    if(tl > r || tr < l) return neutro;  // estoy fuera
    if(l <= tl && tr <= r) return t[v];
    int tm = (tl + tr) >> 1;
    return oper(query(v << 1, tl, tm), query((v << 1) | 1, tm+1, tr));
  }
  void upd(int v, int tl, int tr){
    if(tl == tr){ t[v]--;  return; }
    int tm = (tl + tr) >> 1;
    if(pos <= tm) upd(v << 1, tl, tm);
    else upd((v << 1) | 1, tm+1, tr);
    t[v] = oper(t[v << 1], t[(v << 1) | 1]);
  }
  void upd(int idx){ pos = idx, upd(1, 0, n-1);}
  int query(int ql, int qr){ l = ql, r = qr;  return query(1, 0, n-1);}
};

const int inf = 1e9;
const ld pi = acos(-1);
const ld eps = 1e-9;

int dr[] = {1, -1, 0, 0, 1, -1, -1, 1};
int dc[] = {0, 0, 1, -1, 1, 1, -1, -1};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << setprecision(20);
    int n;
    ll x;
    cin >> n >> x;
    vl a(n);
    vl pre(n);
    vl pres;
    ll ans = 0;
    forn(i, n){
        cin >> a[i];
        pre[i] = a[i] + (i != 0 ? pre[i - 1] : 0);
        if(pre[i] < x)++ans;
    }
    pres = pre;
    sort(all(pres));
    vi num;
    int cnt = 1;
    for1(i, n - 1){
        if(pres[i] == pres[i - 1])++cnt;
        else{
            num.pb(cnt);
            cnt = 1;
        }
    }
    num.pb(cnt);
    stree st = stree(num);
    pres.erase(unique(all(pres)), pres.end());
    forn(i, n - 1){
        x += a[i];
        int ind = lower_bound(all(pres), pre[i]) - pres.begin();
        st.upd(ind);
        ind = lower_bound(all(pres), x) - pres.begin();
        if(!ind)continue;
        --ind;
        ans += st.query(0, ind);
    }
    cout << ans << el;
}
