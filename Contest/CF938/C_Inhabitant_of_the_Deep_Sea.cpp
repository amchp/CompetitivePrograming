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

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cout << setprecision(20)<< fixed;
    int t;
    cin >> t;
    while(t--){
        int n;
        ll k;
        cin >> n >> k;
        vi a(n);
        forn(i, n)cin >> a[i];
        vll pre(n), suf(n);
        pre[0] = a[0];
        suf[0] = a[n - 1];
        for1(i, n - 1)pre[i] = pre[i - 1] + a[i];
        for1(i, n - 1)suf[i] = suf[i - 1] + a[n - 1 - i];
        int l = upper_bound(all(pre), (k + 1) / 2) - pre.begin();
        int r = n - 1 - (upper_bound(all(suf), k / 2) - suf.begin());
        if(r < l)cout << n << el;
        else if(l == r){
            if(pre[n - 1] <= k)cout << n << el;
            else cout << n - 1 << el;
        }
        else cout << n - (r - l + 1) << el;
    }
}