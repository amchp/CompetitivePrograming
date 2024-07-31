#include<bits/stdc++.h>

#define forn(i,n) for(int i = 0; i <(int)n;++i)
#define fore(i,l,r) for(int i = l ; i<= (int)r; ++i)
#define for1(i,n) for(int i = 1; i <= (int)n;++i)
#define ford(i,n) for(int i = (int)n - 1; i >= 0;--i)
#define el '\n'
#define sz(a) (int)a.size()
#define pb push_back
#define all(a) a.begin(),a.end()
#define d(x) cerr<<#x<<" "<<x<<el
using namespace std;

typedef vector<int> vi;
typedef long long ll;
typedef pair<int,int> ii;
typedef vector<ll> vl;
typedef long double ld;
typedef pair<ld, int> pldi;

const ll inf = 1e18;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int B, N;
    cin >> B >> N;
    vl w(B), p(B);
    forn(i, B){
        cin >> w[i];
        cin >> p[i];
    }
    ld area = 0;
    forn(i, N){
        ll a, b, c;
        cin >> a >> b >> c;
        // if(a == 0 || b == 0 || c == 0){
        //     cout << inf << el;
        //     return 0;
        // }
        ll num = (c*c-a*a-b*b);
        ll dem = 2*a*b;
        area += 0.5L*sqrt(1 - ((num*num) / (dem*dem)))*a*b;
    }
    int sm = 0;
    forn(i, B){
        sm += w[i];
    }
    if(sm == 0){
        cout << -1 << el;
        return 0;
    }
    forn(i, B){
        if(p[i] == 0){
            cout << 0 << el;
            return 0;
        }
    }
    area /= 30.0L;
    ll kg = ceil(area);
    ll l = 1;
    forn(i, N){
        if(w[i] == 0){
            continue;
        }
        l = lcm(l, w[i]);
    }
    vector<pldi> opt(B);
    forn(i, B){
        opt[i].first = ld(w[i]) / p[i];
        opt[i].second = i;
    }
    sort(all(opt), greater<pldi>());
    ll ans = (kg / l)*p[opt[0].second];
    kg %= l;
    vl coins(kg + 1, inf);
    coins[0] = 0;
    forn(i, kg){
        forn(j, B){
            int nxt = i + w[j];
            if(nxt > kg)nxt = kg;
            coins[nxt] = min(coins[i] + p[j], coins[nxt]);
        }
    }
    ans = ans + coins[kg];
    cout << ans << el;
    return 0;
}
