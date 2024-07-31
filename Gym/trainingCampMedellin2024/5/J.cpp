#include <bits/stdc++.h>

#define forn(i, n) for(int i = 0; i < n; ++i)
#define el '\n'
#define db(x) cerr<<#x<<" "<<x<<el
#define pb push_back
#define sz(a) (int) a.size()
using namespace std;

typedef vector<int> vi;
typedef long long ll;
typedef vector<ll> vll;
const int nax =2e5;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int pw2 = 256;
    ll cur = 0;
    vector<vi> ans(pw2, vi(pw2));
    forn(i, pw2 / 2){
        forn(j, pw2 / 2){
            int sti = i*2;
            int stj = j*2;
            ans[sti][stj] = cur;
            ans[sti][stj + 1] = cur + 1;
            ans[sti + 1][stj] = cur + 2;
            ans[sti + 1][stj + 1] = cur + 3;
            cur += 4;
        }
    }
    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        cout << n*m << el;
        forn(i, n){
            forn(j, m){
                cout << ans[i][j] << ' ';
            }
            cout << el;
        }

    }
}