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
#define d(x) cerr<< #x<< " " << x<<el
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
typedef __int128_t i128;


const ld inf = 1e300;
const int nax = 1e5+200;
const ld pi = acos(-1);
const ld eps= 1e0;

int dr[] = {1,-1,0, 0,1,-1,-1, 1};
int dc[] = {0, 0,1,-1,1, 1,-1,-1};


ll p, q;
ll fact[10];

int C(int n, int r){
    return fact[n] / (fact[r]*fact[n - r]);
}

ld binpow(ld b, int e) {
	ld ans = 1;
	for (; e; b = b*b, e /= 2)
		if (e&1) ans = 1.0L*ans*b;
	return ans;
}

ld sm(i128 n, int m){
    ld inner_sm = 0;
    fore(i, 2, m + 1){
        inner_sm += C(m + 1, i)*sm(n, m + 1 - i);
    }
    return (binpow(n + 1, m + 1) - 1.0L - inner_sm) / (m + 1);
}

ld f(i128 x, bool over){
    return ld(q)*sm(x, 5) - ld(p)*(x + over);
}

ld ternary_search(i128 l, i128 r) {
  while (l + 5 < r) {
    i128 m1 = l + (r - l) / 3;
    i128 m2 = r - (r - l) / 3;
    ld f1 = f(m1, true), f2 = f(m2, true);
    if (f1 > f2) l = m1;
    else r = m2;
  }
  ld ans = inf;
  fore(i, l, r){
    ans = min(ans, f(i, true));
  }
  return ans;
}

void print(i128 x){
    string ans = "";
    while(x > 0){
        ans.pb('0' + (x % 10));
        x /= 10;
    }
    reverse(all(ans));
    cout << ans << el;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cout << setprecision(0)<< fixed;
    fact[0] = 1;
    for1(i, 9){
        fact[i] = fact[i - 1] * i;
    }
    cin >> p >> q;
    i128 l = 0, r = 1e22 + 100;
    i128 x = ceil(-ternary_search(l, r));
    if(x < 0)x = 0;
    l = -1, r = 5e18 + 100;
    while(l + 1 < r){
        i128 mid = l + (r - l) / 2;
        // d(mid);
        if(x + f(mid, false) >= 1e99)r = mid;
        else l = mid;
    }
    i128 y = r;
    print(x);
    print(y);
}