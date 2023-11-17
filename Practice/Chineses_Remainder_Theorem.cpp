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
#define RAYA cout << "########" << el;
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
const ll mod = 1e9 + 7;


int dr[] = {1, -1, 0, 0, 1, -1, -1, 1};
int dc[] = {0, 0, 1, -1, 1, 1, -1, -1};

int binpow(ll b, ll e, ll mod) {
	ll ans = 1;
	for (; e; b = 1LL*b*b%mod, e /= 2)
		if (e&1) ans = 1LL*ans*b%mod;
	return ans;
}

ll phi(ll n) { // O(sqrt(n))
  if(n==1) return 0;
  ll ans = n;
  for (ll i = 2; 1ll*i*i <= n; i++) {
    if(n % i == 0) {
      while(n % i == 0) n /= i;
      ans -= ans / i;
    }
  }
  if(n > 1) ans -= ans / n;
  return ans;
}

void sol(){
    ll a, n, b, m;
    cin >> a >> n >> b >> m;
    if(a > b){
        swap(a, b);
        swap(n, m);
    }
    ll gcd = __gcd(n, m);
    if((b - a) % gcd != 0){
        cout << "no solution" << el;
        return;
    }
    ll gm = m / gcd;
    ll gn = n / gcd;
    ll gba = (b - a) / gcd;
    ll pm = phi(gm) - 1;
    // d(gn);
    // d(gba);
    ll y = binpow(gn, pm, gm)*gba % gm;
    ll amod = m*n/gcd;
    // d(y);
    // d(a);
    // d(amod);
    ll x = (n*y) % amod + a;
    x %= amod;
    cout << x << ' ' << amod << el;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        sol();
    }
}