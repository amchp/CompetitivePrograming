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
#define d(x) cout<< #x<< " " << x<<el
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


const int inf = 1e9;
const int nax = 1e5+200;
const ld pi = acos(-1);
const ld eps= 1e-9;

int dr[] = {1,-1,0, 0,1,-1,-1, 1};
int dc[] = {0, 0,1,-1,1, 1,-1,-1};

struct SuffixArray { // test line 11
	vi sa, lcp;
	SuffixArray(string& s, int lim=256){
		int n = sz(s) + 1, k = 0, a, b;
		s.pb('$');
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
    string s, t;
    cin >> s >> t;
    string st = s + "%" + t;
    SuffixArray sa = SuffixArray(st);
    int dv = sz(s);
    int n = sz(sa.sa);
    int inc = -1;
    int szs = -1;
    for1(i, n - 1){
        int prv = sa.sa[i - 1] > dv;
        int cur = sa.sa[i] > dv;
        if(prv != cur){
            if(szs < sa.lcp[i]){
                szs = sa.lcp[i];
                if(!prv)inc = sa.sa[i - 1];
                else inc = sa.sa[i];
            }
        }
    }
    assert(inc != -1);
    cout << s.substr(inc, szs) << el;
}