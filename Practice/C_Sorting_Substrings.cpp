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
typedef array<ll, 3> a3;


ll inf = 1e18;
const int nax = 1e5+200;
const ld pi = acos(-1);
const ld eps= 1e-9;

int dr[] = {1,-1,0, 0,1,-1,-1, 1};
int dc[] = {0, 0,1,-1,1, 1,-1,-1};

struct SuffixArray { // test line 11
	vi sa, lcp;
	SuffixArray(string& s, int lim=256){
		int n = sz(s) + 1, k = 0, a, b;
		s.pb(char(32));
		vi x(all(s)), y(n), ws(max(n, lim)), rank(n);
		sa = lcp = y, iota(all(sa), 0);
		for (int j = 0, p = 0; p < n; j = max(1, j * 2), lim = p) {
			p = j;
			forn(i,n) y[i] = (sa[i] - j >= 0 ? 0 : n) + sa[i]-j;
			fill(all(ws), 0);
			forn(i,n) ws[x[i]]++;
			for1(i,lim-1) ws[i] += ws[i - 1];
			for (int i = n; i--;) sa[--ws[x[y[i]]]] = y[i];
			swap(x, y), p = 1, x[sa[0]] = 0;
			for1(i,n-1) a = sa[i - 1], b = sa[i], x[b] =
				(y[a] == y[b] && y[a + j] == y[b + j]) ? p - 1 : p++;
		}
		for1(i,n-1) rank[sa[i]] = i;
		for (int i = 0, j; i < n - 1; lcp[rank[i++]] = k)
			for (k && k--, j = sa[rank[i] - 1];
					s[i + k] == s[j + k]; k++);
	}
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cout << setprecision(20)<< fixed;
    string s;
    cin >> s;
    SuffixArray sa = SuffixArray(s);
    int n;
    cin >> n;
    vector<vi> lr(sz(s));
    forn(i, n){
        int l, r;
        cin >> l >> r;
        --l, --r;
        lr[l].pb(r);
    }
    int sn = sz(s);
    ll cur = 0;
    // vll curs(sn);
    vector<pll> st;
    vector<a3> fnl;
    forn(i, sn){
        int sfx = sa.sa[i];
        int lcp = sa.lcp[i];
        while(!st.empty() && st.back().fi >= lcp)st.pop_back();
        st.push_back({lcp, cur});
        ll mnv = cur;
        for(int& r : lr[sfx]){
            int l = sfx;
            ll dif = r - l;
            auto it = upper_bound(all(st), pll({dif, inf}));
            --it;
            ll val = (*it).se + (dif - (*it).fi);
            fnl.pb({val, l, r});
        }
        cur += (sn - 1 - sfx) - lcp;
    }
    assert(sz(fnl) == n);
    sort(all(fnl));
    forn(i, n){
        cout << fnl[i][1] + 1 << ' ' <<  fnl[i][2] + 1 << el;
    }
}