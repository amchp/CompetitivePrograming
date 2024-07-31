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
typedef array<int, 2> a2;
typedef array<int, 3> a3;


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
        cin >> n;
        vi a(n);
        forn(i, n)cin >> a[i];
        map<a2, int> db1, db2, db3;
        map<a3, int> tp;
        ll ans = 0;
        forn(i, n - 2){
            a2 v1 = {a[i], a[i + 1]};
            a2 v2 = {a[i], a[i + 2]};
            a2 v3 = {a[i + 1], a[i + 2]};
            a3 v = {a[i], a[i + 1], a[i + 2]};
            int d1 = db1[v1];
            int d2 = db2[v2];
            int d3 = db3[v3];
            int tr = tp[v];
            ans += d1 + d2 + d3 - 3*tr;
            ++db1[v1];
            ++db2[v2];
            ++db3[v3];
            ++tp[v];
        }
        cout << ans << el;
    }
}