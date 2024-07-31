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

string s;
string s1;

bool sol(int ind){
    // d(s.substr(ind));
    // d(s1);
    // d((s.substr(ind, sz(s1)) <= s1));
    return s.substr(ind, sz(s1)) <= s1;
}

bool sol2(int ind){
    // d(s.substr(ind));
    // d(s1);
    // d((s.substr(ind, sz(s1)) <= s1));
    return s.substr(ind, sz(s1)) < s1;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cout << setprecision(20)<< fixed;
    cin >> s;
    // vector<string> tsa;
    // forn(i, sz(s))tsa.pb(s.substr(i));
    // sort(all(tsa));
    // for(string& ts : tsa)cout << ts << el;
    SuffixArray sa = SuffixArray(s);
    s.pop_back();
    int n;
    cin >> n;
    forn(i, n){
        cin >> s1;
        int l = -1;
        int r = sz(sa.sa);
        while(l + 1 < r){
            int mid = l + (r - l) / 2;
            if(sol(sa.sa[mid])){
                l = mid;
            }else{
                r = mid;
            }
        }
        int ub = r;
        l = -1, r = sz(sa.sa);
        while(l + 1 < r){
            int mid = l + (r - l) / 2;
            // d(mid);
            if(sol2(sa.sa[mid])){
                l = mid;
            }else{
                r = mid;
            }
        }
        int lb = r;
        // d(ub);
        // d(lb);
        cout << ub - lb << el;
    }
}