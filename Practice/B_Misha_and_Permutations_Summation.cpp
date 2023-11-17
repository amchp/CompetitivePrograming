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

#define neutro 0
struct stree{
  int n;  vector<int> t;
  stree(int m){
    n = m;   t.resize(n<<2);
  }
  stree(vector<int> &a){
    n = sz(a);
    t.resize(n<<2);
    build(1,0, n-1, a);
  }
  inline int oper(int a, int b){  return a+b; }
  void build(int v, int tl, int tr, vector<int> &a){
    if(tl==tr){
      t[v]= a[tl];  return ;
    }
    int tm = (tr+tl)/ 2;
    build(v*2, tl, tm, a);
    build(v*2+1, tm+1, tr, a);
    t[v] = oper(t[v*2],t[v*2+1]);
  }
  int query(int v, int tl, int tr, int l, int r){
    if(tl>r || tr<l) return neutro;
    if(l<=tl && tr<=r) return t[v];
    int tm = (tl+tr)/2;
    return oper(query(v*2, tl, tm, l, r),
           query(v*2+1, tm+1, tr, l, r));
  }
  int other_query(int v, int tl, int tr, int k){
    if(tl==tr){
      return tl;
    }
    int tm = (tr+tl)/ 2;
    if(k <= t[v << 1]){
      return other_query(v << 1, tl, tm, k);
    }else{
      return other_query(v << 1 | 1, tm + 1, tr, k - t[v << 1]);
    }
  }
  void upd(int v, int tl, int tr, int pos, int val){
    if(tl==tr){
      t[v] = val;  return ;
    }
    int tm = (tr+tl)/ 2;
    if(pos<= tm)  upd(v*2, tl, tm, pos, val);
    else  upd(v*2+1, tm+1, tr, pos, val);
    t[v] = oper(t[v*2], t[v*2+1]);
  }
  void upd(int pos, int val){ upd(1,0,n-1,pos,val); }
  int query(int l, int r){ return query(1,0,n-1,l,r); }
  int other_query(int k){ return other_query(1, 0, n - 1, k); }
};


int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cout << setprecision(20);
  int n;
  cin >> n;
  vi a(n), b(n);
  forn(i, n){
    cin >> a[i];
  }
  forn(i, n){
    cin >> b[i];
  }
  vi z(n, 0), on(n, 1);
  stree sA = stree(z);
  vi ans(n, 0);
  ford(i, n){
    ans[i] += sA.query(0, a[i] - 1);
    sA.upd(a[i], 1);
  }
  stree sB= stree(z);
  ford(i, n){
    ans[i] += sB.query(0, b[i] - 1);
    if(ans[i] >= (n - i)){
      ans[i - 1]++;
      ans[i] %= (n - i);
    }
    sB.upd(b[i], 1);
  }
  // forn(i, n){
  //   cout << ans[i] << ' ';
  // }
  // cout << el;
  stree sAns = stree(on);
  forn(i, n){
    int ind = sAns.other_query(ans[i] + 1);
    ans[i] = ind;
    sAns.upd(ind, 0);
  }
  forn(i, n){
    cout << ans[i] << ' ';
  }
  cout << el;
}