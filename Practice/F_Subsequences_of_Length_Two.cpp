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
#define db(x) cerr<< #x<< " " << x<<el
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
typedef vector<vll> vvll;
typedef vector<vvll> vvvll;


const ll inf = 1e18;
const int nax = 1e5+200;
const ld pi = acos(-1);
const ld eps= 1e-9;

int dr[] = {1,-1,0, 0,1,-1,-1, 1};
int dc[] = {0, 0,1,-1,1, 1,-1,-1};

int n;
vvvll dp;
string s;
string t;

ll go(int i, int k, int fst){
    if(k == -1)return -inf;
    if(i == n)return 0;
    // db(i), db(k), db(fst);
    ll& ans = dp[i][k][fst];
    if(ans != -1)return ans;
    ll addfst = t[0] == s[i] ? 1 : 0;
    ll addsnd = t[1] == s[i] ? fst : 0;
    if(t[0] == t[1]){
        ans = max(
            go(i + 1, k, fst + addfst) + addsnd,
            go(i + 1, k - 1, fst + 1) + fst
        );
        return ans;
    }
    ans = max({
        go(i + 1, k, fst + addfst) + addsnd,
        go(i + 1, k - 1, fst + 1),
        go(i + 1, k - 1, fst) + fst,
    });
    return ans;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cout << setprecision(20)<< fixed;
    int k;
    cin >> n >> k;
    cin >> s >> t;
    dp = vvvll(n, vvll(k + 1, vll(n + 1, -1)));
    cout << go(0, k, 0) << el;
}