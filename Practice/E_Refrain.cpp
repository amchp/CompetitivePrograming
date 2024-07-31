#include <bits/stdc++.h>

#define fi first
#define se second
#define forn(i,n) for(ll i=0; i< (ll)n; ++i)
#define for1(i,n) for(ll i=1; i<= (ll)n; ++i)
#define fore(i,l,r) for(ll i=(ll)l; i<= (ll)r; ++i)
#define ford(i,n) for(ll i=(ll)(n) - 1; i>= 0; --i)
#define fored(i,l,r) for(ll i=(ll)r; i>= (ll)l; --i)
#define pb push_back
#define el '\n'
#define d(x) cout<< #x<< " " << x<<el
#define ri(n) scanf("%d",&n)
#define sz(v) ll(v.size())
#define all(v) v.begin(),v.end()

using namespace std;

typedef long long ll;
typedef double ld;
typedef pair<ll,ll> ii;
typedef pair<ll,ll> pll;
typedef tuple<ll, ll, ll> iii;
typedef vector<ll> vi;
typedef vector<ii> vii;
typedef vector<ll> vll;
typedef vector<ld> vd;


const ll inf = 1e9;
const ll nax = 1e5+200;
const ld pi = acos(-1);
const ld eps= 1e-9;

ll dr[] = {1,-1,0, 0,1,-1,-1, 1};
ll dc[] = {0, 0,1,-1,1, 1,-1,-1};

struct SuffixArray {
	vi sa, lcp;
	SuffixArray(string& s, ll lim=256){
		ll n = sz(s) + 1, k = 0, a, b;
		s.pb(char(32));
		vi x(all(s)), y(n), ws(max(n, lim)), rank(n);
		sa = lcp = y, iota(all(sa), 0);
		for (ll j = 0, p = 0; p < n; j = max(1LL, j * 2), lim = p) {
			p = j;
			forn(i,n) y[i] = (sa[i] - j >= 0 ? 0 : n) + sa[i]-j;
			fill(all(ws), 0);
			forn(i,n) ws[x[i]]++;
			for1(i,lim-1) ws[i] += ws[i - 1];
			for (ll i = n; i--;) sa[--ws[x[y[i]]]] = y[i];
			swap(x, y), p = 1, x[sa[0]] = 0;
			for1(i,n-1) a = sa[i - 1], b = sa[i], x[b] =
				(y[a] == y[b] && y[a + j] == y[b + j]) ? p - 1 : p++;
		}
		for1(i,n-1) rank[sa[i]] = i;
		for (ll i = 0, j; i < n - 1; lcp[rank[i++]] = k)
			for (k && k--, j = sa[rank[i] - 1];
					s[i + k] == s[j + k]; k++);
	}
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cout << setprecision(20)<< fixed;
    ll n, m;
    cin >> n >> m;
    string s = string(n, 'A');
    forn(i, n){
        ll v;
        cin >> v;
		assert(v <= m);
        s[i] = 'A' + (v - 1);
    }
    SuffixArray sa = SuffixArray(s);
    ll sn = sz(sa.lcp);
    ll ans = n;
    stack<pll> st;
	ll find = 0;
	ll szs = n;
    forn(i, sn){
		ll lcp = sa.lcp[i];
		ll mind = i - 1;
		while(!st.empty() && st.top().fi >= lcp){
			ll ph = st.top().fi;
			ll ind = st.top().se;
			ll cans = 1LL*(i - ind)*ph;
			// d(ph);
			if(ans < cans){
				ans = cans;
				find = sa.sa[ind];
				szs = ph;
			}
			mind = ind;
			st.pop();
		}
		st.push({lcp, mind});
    }
	while(!st.empty()){
		ll ph = st.top().fi;
		ll ind = st.top().se;
		ll cans = 1LL*(sn - ind)*ph;
		if(ans < cans){
			ans = cans;
			find = sa.sa[ind];
			szs = ph;
		}
		st.pop();
	}
	cout << ans << el;
	cout << szs << el;
	fore(i, find, find + szs - 1){
		cout << ll(s[i] - 'A') + 1 << ' ';
	}
	cout << el;
}