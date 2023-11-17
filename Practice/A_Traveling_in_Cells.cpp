#include <algorithm>
#include <array>
#include <cassert>
#include <complex>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <map>
#include <math.h>
#include <numeric>
#include <queue>
#include <set>
#include <unordered_set>
#include <sstream> // istringstream buffer(myString);
#include <stack>
#include <unordered_map>
#include <utility>
#include <vector>


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

struct streeS{
  int n;  vector<unordered_map<int, int>> t;
  streeS(int n): n(n), t(n<<2){}
  streeS(vi a): n(sz(a)), t(n<<2){ build(1, 0, n-1, a); }
  void oper(unordered_map<int, int>& uM, unordered_map<int, int>& a, unordered_map<int, int>& b){ 
    for(ii p : a){
      uM[p.first] += a[p.first];
    }
    for(ii p : b){
      uM[p.first] += b[p.first];
    }
  }
  void build(int v, int tl, int tr, vi& a){// solo para el 2. constructor
    if(tl == tr){ 
      t[v][a[tl]] = 1;
      return; 
    }
    int tm = (tr+tl)/ 2;
    build(v*2, tl, tm, a);
    build(v*2+1, tm+1, tr, a);
    oper(t[v], t[v*2], t[v*2+1]);
  }
  bool query(int v, int tl, int tr, int l, int r, vi& st){
    if(tl > r || tr < l) return true;  // estoy fuera
    if(l <= tl && tr <= r){
      if(st.size() < t[v].size())return false;
      int total = 0;
      for(int a : st){
        total += t[v][a];
      }
      return total == tr - tl + 1;
    }
    int tm = (tl+tr)/2;
    return query(v*2, tl, tm, l, r, st) && query(v*2+1, tm+1, tr, l, r, st);
  }
  void upd(int v, int tl, int tr, int& pos, int& val, int& pVal){
    t[v][pVal]--;
    if(!t[v][pVal])t[v].erase(pVal);
    t[v][val]++;
    if(tl==tr){ return; }
    int tm = (tr+tl)/ 2;
    if(pos<= tm) upd(v*2, tl, tm, pos, val, pVal);
    else upd(v*2+1, tm+1, tr, pos, val, pVal);
  }
  void upd(int pos, int val, int pVal){ upd(1, 0, n-1, pos, val, pVal);}
  ii query(int x, vi& st){ 
    int l = -1, r = x;
    while(l + 1 < r){
      int mid = l + (r - l) / 2;
      if(query(1, 0, n - 1, mid, x, st)){
        r = mid;
      }else{
        l = mid;
      }
    }
    ii ans = {r, -1};
    l = x, r = n;
    while(l + 1 < r){
      int mid = l + (r - l) / 2;
      if(query(1, 0, n - 1, x, mid, st)){
        l = mid;
      }else{
        r = mid;
      }
    }
    ans.second = l;
    return ans;
  }
};

struct streeA{
  int n, neutro = 0;  vector<ll> t;
  streeA(int n): n(n), t(n<<2){}
  streeA(vi a): n(sz(a)), t(n<<2){ build(1, 0, n-1, a); }
  inline ll oper(ll a, ll b){ return a + b; }
  void build(int v, int tl, int tr, vi& a){// solo para el 2. constructor
    if(tl == tr){ t[v]= a[tl];  return; }
    int tm = (tr+tl)/ 2;
    build(v*2, tl, tm, a);
    build(v*2+1, tm+1, tr, a);
    t[v] = oper(t[v*2], t[v*2+1]);
  }
  ll query(int v, int tl, int tr, int l, int r){
    if(tl > r || tr < l) return neutro;  // estoy fuera
    if(l <= tl && tr <= r) return t[v];
    int tm = (tl+tr)/2;
    return oper(query(v*2, tl, tm, l, r), query(v*2+1, tm+1, tr, l, r));
  }
  void upd(int v, int tl, int tr, int pos, int val){
    if(tl==tr){ t[v] = val;  return; }
    int tm = (tr+tl)/ 2;
    if(pos<= tm) upd(v*2, tl, tm, pos, val);
    else upd(v*2+1, tm+1, tr, pos, val);
    t[v] = oper(t[v*2], t[v*2+1]);
  }
  void upd(int pos, int val){ upd(1, 0, n-1, pos, val);}
  ll query(int l, int r){ return query(1, 0, n-1, l, r);}
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cout << setprecision(20);
  int t;
  cin >> t;
  while(t--){
    int n, q;
    cin >> n >> q;
    vi a(n), c(n);
    forn(i, n)cin >> c[i];
    forn(i, n)cin >> a[i];
    streeA stA = streeA(a);
    streeS stS = streeS(c);
    forn(i, q){
      int f, s, v;
      cin >> f >> s >> v;
      s--;
      if(f == 1){
        stS.upd(s, v, c[s]);
        c[s] = v;
      }else if(f == 2){
        stA.upd(s, v);
      }else{
        vi st(v);
        forn(j, v){
          cin >> st[j];
        }
        ii lr = stS.query(s, st);
        ll ans = stA.query(lr.first, lr.second);
        cout << ans << el;
      }
    }
  }
}
