#include <bits/stdc++.h>

#define forn(i, n) for(int i = 0; i < n; ++i)
#define fore(i, l, r) for(int i = l; i <= r; ++i)
#define fored(i, l, r) for(int i = r; i >= l; --i)
#define for1(i, n) for(int i = 1; i <= n; ++i)
#define el '\n'
#define pb push_back
#define all(x) x.begin(), x.end()
#define db(x) cerr<<#x<<" "<<x<<el
#define sz(x) x.size()
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef array<int,2> v2;

int invs(int x){
    string xs = to_string(x);
    int n = sz(xs);
    ll ans = 0;
    forn(i, n){
        fore(j, i + 1, n - 1){
            if(xs[i] < xs[j]){
                ++ans;
            }
        }
    }
    return ans;
}

int main(){
    ios_base::sync_with_stdio(false);
    freopen("bf.txt", "w", stdout);
    cin.tie(NULL);
    int n = 1e4;
    ll ans = 0;
    for1(i, n){
        ans += invs(i);
        cout << ans << el;
    }
}