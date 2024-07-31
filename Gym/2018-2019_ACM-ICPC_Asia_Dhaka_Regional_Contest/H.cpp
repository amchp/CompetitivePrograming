#include <bits/stdc++.h>

#define forn(i, n) for(int i = 0; i < n; ++i)
#define fored(i, l, r) for(int i = r; i >= l; --i)
#define for1(i, n) for(int i = 1; i <= n; ++i)
#define el '\n'
#define pb push_back
#define sz(a) (int) a.size()
#define all(x) x.begin(), x.end()
#define d(x) cerr<<#x<<" "<<x<<el
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef array<int,2> v2;

const int mod = 78294349;
const int nax = 1e6, L = 21;

struct mint{
    int x;
    mint(){}
    mint(ll x): x(x % mod){}
    mint operator+(mint b){
        return mint(1LL*x + b.x);
    }
    mint operator*(mint b){
        return mint(1LL*x*b.x%mod);
    }
};


void solve(int cas){
    int r,c;
    cin>>r>>c;
    vector<vi> mat(r, vi(c));
    int cnt = 0;
    forn(i,r){
        forn(j,c){
            cin>>mat[i][j];

            cnt+= mat[i][j] == '#';
        }
    }
    
    cout<<"Case "<<cas<<": "<<el;

}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int id = 1;
    int tt;cin>>tt;
    while(tt--){
        solve(id++);
    }
}