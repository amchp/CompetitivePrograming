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
const int nax = 1e3+200;
const ld pi = acos(-1);
const ld eps= 1e-9;

int dr[] = {1,-1,0, 0,1,-1,-1, 1};
int dc[] = {0, 0,1,-1,1, 1,-1,-1};

int n;
ll pre[nax][nax];

ll sm(int i, int j){
    // d(i);
    // d(j);
    if(i < n && j < n){
        // d(pre[i][j]);
        return pre[i][j];
    }
    if(i < n){
        int mj = j % n;
        ll nj = j / n;
        ll ans = pre[i][mj] + pre[i][n - 1]*nj;
        // d(ans);
        return ans;
    }
    if(j < n){
        int mi = i % n;
        ll ni = i / n;
        ll ans = pre[mi][j] + pre[n - 1][j]*ni;
        // d(ans);
        return ans;
    }
    int mi = i % n;
    int mj = j % n;
    ll ni = i / n;
    ll nj = j / n;
    // d(pre[mi][mj]);
    // d(pre[n - 1][mj]);
    // d(pre[mi][n - 1]);
    // d(ni);
    // d(nj);
    // d(ni*nj*pre[n - 1][n - 1]);
    ll ans = pre[mi][mj] + ni*pre[n - 1][mj] + nj*pre[mi][n - 1] + ni*nj*pre[n - 1][n - 1];
    // d(ans);
    return ans;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cout << setprecision(20)<< fixed;
    int q;
    cin >> n >> q;
    forn(i, n){
        forn(j, n){
            char c;
            cin >> c;
            if(c == 'B')pre[i][j] = 1;
        }
    }
    for1(i, n - 1){
        pre[i][0] += pre[i - 1][0];
        pre[0][i] += pre[0][i - 1];
    }
    for1(i, n - 1){
        for1(j, n - 1){
            pre[i][j] += pre[i - 1][j] + pre[i][j - 1] - pre[i - 1][j - 1];
        }
    }
    // forn(i, n){
    //     forn(j, n)cout << pre[i][j] << ' ';
    //     cout << el;
    // }
    while(q--){
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        // cout << a << ' ' << b << ' '<< c << ' ' << d << el;
        ll ans = sm(c, d);
        if(a){
            ans -= sm(a - 1, d);
        }
        if(b){
            ans -= sm(c, b - 1);
        }
        if(a && b){
            ans += sm(a - 1, b - 1);
        }
        cout << ans << el;
    }
}