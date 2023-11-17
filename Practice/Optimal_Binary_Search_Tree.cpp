
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

const ll inf = 1e18;
const int nax = 251;
const ld pi = acos(-1);
const ld eps = 1e-9;

int dr[] = {1, -1, 0, 0, 1, -1, -1, 1};
int dc[] = {0, 0, 1, -1, 1, 1, -1, -1};

int n;
int a[nax];
ll pre[nax];
ll dp[nax][nax];
int k[nax][nax];

ll C(int l, int r){
  if(l >= r)return 0;
  return pre[r] - pre[l];
}

void sol(){
  for(int len=1; len<n; ++len){
    for(int l=0; l< n-len; ++l){
      int r= l+len;
      ll &ans= dp[l][r];
      if(len == 1){
        if(a[l] <= a[r]){
          ans = a[l];
          k[l][r] = r;
        }else{
          ans = a[r];
          k[l][r] = l;
        }
        continue;
      }
      ans= inf;
      for(int i= k[l][r-1]; i<= k[l+1][r]; ++i){
        if(ans > dp[l][max(i - 1, l)] + C(l, i) + dp[min(i + 1, r)][r] + C(i + 1, r + 1)){
          ans = dp[l][max(i - 1, l)] + C(l, i) + dp[min(i + 1, r)][r] + C(i + 1, r + 1);
          k[l][r]= i;
        }
      }
    }
  }
  cout<< dp[0][n-1]<<el;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << setprecision(20);
    while(cin >> n){
      forn(i, n)cin >> a[i];
      for1(i, n)pre[i] = a[i - 1] + pre[i - 1];
      sol();
      // forn(i, n){
      //   forn(j, n){
      //     cout << dp[i][j] << ' ';
      //   }
      //   cout << el;
      // }
    }
}
