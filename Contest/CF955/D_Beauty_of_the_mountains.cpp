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
#define db(x) cout<< #x<< " " << x<<el
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
const int nax = 501;
const ld pi = acos(-1);
const ld eps= 1e-9;

int dr[] = {1,-1,0, 0,1,-1,-1, 1};
int dc[] = {0, 0,1,-1,1, 1,-1,-1};

ll vals[nax][nax];
int type[nax][nax];
ll pre[nax][nax];

bool sol(){
    // Input
    int n, m, k;
    cin >> n >> m >> k;
    forn(i, n){
        forn(j, m){
            cin >> vals[i][j];
        }
    }
    forn(i, n){
        string s;
        cin >> s;
        forn(j, m){
            if(s[j] == '0')type[i][j] = -1;
            else type[i][j] = 1;
        }
    }
    // Preffix
    pre[0][0] = type[0][0];
    for1(i, n - 1)pre[i][0] = pre[i - 1][0] + type[i][0];
    for1(j, m - 1)pre[0][j] = pre[0][j - 1] + type[0][j];
    for1(i, n - 1){
        for1(j, m - 1){
            pre[i][j] = pre[i - 1][j] + pre[i][j - 1] 
                        - pre[i - 1][j - 1] + type[i][j];
        }
    }
    // Find sums
    ll gcd = -1;
    fore(i, k - 1, n - 1){
        fore(j, k - 1, m - 1){
            ll sm = pre[i][j] - (i - k >= 0 ? pre[i - k][j] : 0) -
                (j - k >= 0 ? pre[i][j - k] : 0) + 
                (i - k >= 0 && j - k >= 0 ? pre[i - k][j - k] : 0);
            sm = abs(sm);
            // db(sm);
            if(sm == 0)continue;
            if(gcd == -1)gcd = sm;
            else gcd = __gcd(gcd, sm);
        }
    }
    // db(gcd);
    ll dif = 0;
    forn(i, n){
        forn(j, m)dif += type[i][j]*vals[i][j];
    }
    // db(dif);
    if(gcd == -1)return dif == 0;
    return dif % gcd == 0;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cout << setprecision(20)<< fixed;
    int t;
    cin >> t;
    while(t--){
        if(sol())cout << "YES" << el;
        else cout << "NO" << el;
    }
}