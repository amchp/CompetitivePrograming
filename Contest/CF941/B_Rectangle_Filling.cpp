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
        int n, m;
        cin >> n >> m;
        vector<vector<char>> a(n, vector<char>(m));
        forn(i, n){
            forn(j, m)cin >> a[i][j];
        }
        char c1 = a[0][0];
        char c2 = a[0][m - 1];
        char c3 = a[n - 1][0];
        char c4 = a[n - 1][m - 1];
        bool pass = false;
        if(c1 == c2 && c3 == c4 && c1 != c3){
            forn(j, m){
                if(c3 == a[0][j])pass = true;
            }
            forn(j, m){
                if(c1 == a[n - 1][j])pass = true;
            }
        }
        else if(c1 == c3 && c2 == c4 && c1 != c2){
            forn(i, n){
                if(c2 == a[i][0])pass = true;
            }
            forn(i, n){
                if(c1 == a[i][m - 1])pass = true;
            }
        }else{
            pass = true;
        }
        if(pass)cout << "YES" << el;
        else cout << "NO" << el;
    }
}