#include <bits/stdc++.h>

#define all(a) a.begin(),a.end()
#define forn(i,n) for(int i = 0; i< (int)n;++i)
#define fore(i,l,r) for(int i = l; i<= (int)r;++i)
#define for1(i,n) for(int i = 1; i<= (int)n;++i)
#define db(x) cerr<<#x<<" "<<x<<el
#define RAYA cerr<<"============="<<el
#define el '\n'
#define fi first
#define se second
using namespace std;

typedef vector<int> vi;
typedef long long ll;
typedef vector<ll> vl;
typedef long double ld;
typedef pair<ll,ll> pll;
typedef pair<int,int> ii;

const int nax = 2e5 + 10;
const int mod = 1e9 + 7;

int binpow(int b, int e) {
	int ans = 1;
	for (; e; b = 1LL*b*b%mod, e /= 2)
		if (e&1) ans = 1LL*ans*b%mod;
	return ans;
}

int inv(int a){
    return binpow(a, mod - 2);
}
int roll[11][2];
int ap[11];
int nap[11];
ii dp[nax][11];

int add(int a, int b){
    if(a + b >= mod) return a+b-mod;
    return a+b;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int n;
    cin>>n;
    int am = inv(6*6*6*6);
    int i10 = inv(10);
    for1(i, 6){
        for1(j, 6){
            for1(k, 6){
                for1(l, 6){
                    int r1 = i + j;
                    int r2 = k + l;
                    if(r1 > r2){
                        roll[r1 - r2][0]++;
                    }else{
                        roll[r2 - r1][1]++;
                    }
                }
            }
        }
    }
    forn(i, 11){
        forn(j, 2){
            roll[i][j] = 1LL*roll[i][j]*am % mod;
        }
    }
    
    for1(i, 10){
        ap[i] = 1LL * i *i10 % mod;
        nap[i] = 1LL * (10 - i) * i10 % mod;
    }

    forn(i, n) for1(m,10){
        forn(d,11){
            int &nali = dp[i+1][m].first;
            int &nbob = dp[i+1][m].second;

            nbob = add(nbob, 1LL * add(d, dp[i][1].second) * roll[d][1] % mod);
            nbob = add(nbob, (1LL * roll[d][0] * ap[d] % mod) * dp[i][d].second % mod);
            nbob = add(nbob,(1LL* dp[i][1].second * roll[d][0] % mod) * nap[d] % mod);

            nali = add(nali, 1LL * dp[i][1].first * roll[d][1] % mod);
            nali = add(nali, (1LL*add(dp[i][1].first,(1LL * m * d % mod)) * roll[d][0] % mod) * nap[d] % mod);
            nali = add(nali, (1LL*roll[d][0] * ap[d] % mod) * dp[i][d].first % mod);
        }
    }


    cout<<dp[n][1].fi<<" "<<dp[n][1].se<<el;
    return 0;
}
