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

struct stree{
  int neutro = 0, n, l, r, pos, val, pval, mx;  vector<set<ii>> t;
  stree(int n): n(n), t(n << 2){}
  int query(int v, int tl, int tr){
    if(tl > r || tr < l) return neutro;  // estoy fuera
    int tm = (tl + tr) >> 1;
    if(l <= tl && tr <= r){
        int ans = 0;
        auto it = t[v].begin();
        while(it != t[v].end() && (*it).first <= mx){
            ++ans;
            pos = (*it).second;
            pval = (*it).first;
            it++;
            ers(1, 0, n - 1);
        }
        // d(ans);
        return ans;
    }
    return query(v << 1, tl, tm) + query((v << 1) | 1, tm+1, tr);
  }
  void ers(int v, int tl, int tr){
    t[v].erase({pval, pos});
    if(tl == tr){ 
        return; 
    }
    int tm = (tl + tr) >> 1;
    if(pos <= tm)ers(v << 1, tl, tm);
    else ers((v << 1) | 1, tm+1, tr);
  }
  void upd(int v, int tl, int tr){
    auto it = t[v].find({pval, pos});
    if(it != t[v].end()){
        t[v].erase(it);
    }
    t[v].insert({val, pos});
    if(tl == tr){ 
        return; 
    }
    int tm = (tl + tr) >> 1;
    if(pos <= tm)upd(v << 1, tl, tm);
    else upd((v << 1) | 1, tm+1, tr);
  }
  void uupd(int idx, int num, int pnum){ pos = idx, val = num, pval = pnum, upd(1, 0, n-1);}
  int uquery(int ql, int qr, int num){ l = ql, r = qr; mx = num;  return query(1, 0, n-1);}
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << setprecision(20);
    int n, m;
    cin >> n >> m;
    vi a(n, 0);
    stree st(n);
    forn(i, m){
        int op;
        cin >> op;
        if(op == 1){
            int pos, val;
            cin >> pos >> val;
            // cout << a[pos] << el;
            st.uupd(pos, val, a[pos]);
            a[pos] = val;
        }else{
            int l, r, p;
            cin >> l >> r >> p;
            r--;
            cout << st.uquery(l, r, p) << el;
        }
    }
}
