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
const int nax = 1e7 + 200;
const ld pi = acos(-1);
const ld eps = 1e-9;

int dr[] = {1, -1, 0, 0, 1, -1, -1, 1};
int dc[] = {0, 0, 1, -1, 1, 1, -1, -1};




int mu[nax];
int lp[nax+1];
vector<int> pr;
void pre(){
  mu[0] = 0; mu[1] = 1;
  fore(i,2,nax){
    if (lp[i] == 0) {
      lp[i] = i; mu[i] = -1;
      pr.pb(i);
    }
    for (int j=0, mult= i*pr[j]; j<sz(pr) && pr[j]<=lp[i] && mult<=nax; ++j, mult= i*pr[j]){
      if(i%pr[j]==0) mu[mult] = 0;
      else mu[mult] = mu[i]*mu[pr[j]];
      lp[mult] = pr[j];
    }
  }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << setprecision(20);
    ll a, b, c, d;
    cin >> a >> b >> c >> d;
    pre();
    ll ans = 0;
    for1(i, nax){
        ans += (ll)mu[i]*(d / i - (c - 1)/ i)*(b / i - (a - 1) / i);
    }
    cout << ans << el;
}
