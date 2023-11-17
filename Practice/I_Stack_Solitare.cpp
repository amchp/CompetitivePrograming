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
const ld pi = acos(-1);
const ld eps = 1e-9;

int dr[] = {1, -1, 0, 0, 1, -1, -1, 1};
int dc[] = {0, 0, 1, -1, 1, 1, -1, -1};



const int nax = 1e3+20;
const ll inf = 1e18;
int a[nax];
ll pre[nax];
ll dp[nax][nax];
int k[nax][nax];

int main(){
  int n;
  cin >> n;
  while(n){
    forn(i, n){
      cin >> a[i];
    }
    pre[0] = 0;
    for1(i, n){
      pre[i] = pre[i - 1] + a[i - 1];
      // cout << pre[i] << ' ';
    }
    // cout << el;
    for(int len=1; len<n; ++len){
      for(int l=0; l< n-len; ++l){
        int r= l+len;
        ll &ans= dp[l][r];
        if(len== 1){
          k[l][r]= l;
          ans= pre[r + 1] - pre[l];
          continue;
        }
        ans= inf;
        for(int i= k[l][r-1]; i<= k[l+1][r]; ++i){
          if(ans > dp[l][i]+ dp[i+1][r]){
            ans= dp[l][i] + dp[i+1][r];
            k[l][r]= i;
          }
        }
        ans+= pre[r + 1] - pre[l];
      }
    }
    // forn(i, n){
    //   forn(j, n){
    //     cout << dp[i][j] << ' ';
    //   }
    //   cout << el;
    // }
    cout<< dp[0][n-1] <<el;
    cin >> n;
  }
}
