#include<bits/stdc++.h>

#define forn(i,n) for(int i = 0; i< (int ) n;++i)
#define for1(i,n) for(int i = 1; i<= (int ) n;++i)
#define fore(i, l, r) for(int i = (int)l; i <= (int)r; ++i)
#define ford(i,n) for(int i = (int)n - 1; i >= 0; --i)
#define el '\n'
#define all(x) x.begin(), x.end()
#define sz(x) x.size()
using namespace std;

typedef vector<int> vi;
typedef long long ll;
typedef vector<ll> vl;
typedef double ld;
const ld PI = acos(-1.0L);
const ld one = 1;

const int MOD = 998244353;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    string s;
    string t;
    cin >> s;
    cin >> t;
    int M;
    cin >> M;
    ll ans = 0;
    ll pM = 1;
    forn(i, 26){
        ll sSm = 0;
        ll tSm = 0;
        pM = 1;
        for(char c : s){
            if(c != char('a' + i)){
                pM *= M;
                pM %= MOD;
                continue;
            }
            sSm += pM;
            sSm %= MOD;
            pM *= M;
            pM %= MOD;
        }
        pM = 1;
        for(char c : t){
            if(c != char('a' + i)){
                pM *= M;
                pM %= MOD;
                continue;
            }
            tSm += pM;
            tSm %= MOD;
            pM *= M;
            pM %= MOD;
        }
        ans += (sSm * tSm) % MOD;
        ans %= MOD;
    }
    cout << ans << el;
}