#include<bits/stdc++.h>


using namespace std;

#define forn(i,n) for(int i = 0; i< n;++i)
#define fore(i,l, r) for(int i = l ; i<= r;++i)
#define for1(i,n) for(int i = 1; i <= n;++i)
#define all(a) a.begin(), a.end()
#define db(x) cerr<<#x<<" "<<x<<el
#define pb push_back
#define el '\n'
typedef double ld;
typedef long long ll;
typedef array<int,2> v2;
typedef array<int,27> v27;
typedef pair<ll, ll> ii;
typedef vector<int> vi;

const int nax = 1e5 + 100;

int mu[nax], f[nax], h[nax];

void pre(){
    mu[0] = 0; mu[1] = 1;
    for(int i = 1; i < nax; ++i){
        if(mu[i] == 0)continue;
        for(int j = i + i; j < nax; j += i){
            mu[j] -= mu[i];
        }
    }

    for(int i = 1; i < nax; ++i){
        for(int j = i; j < nax; j += i){
            f[j] += h[i]*mu[j / i];
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    // cin.tie(NULL);
    cout.precision(20);
    pre();
    int t;
    cin >> t;
    // db(t);
    forn(_, t){
        int a, b, c, d, k;
        cin >> a >> b >> c >> d >> k;
        assert(a == 1 && c == 1);
        int n = b / k;
        int m = d / k;
        ll ans = 0;
        for1(d, nax - 1){
            ans += 1LL*mu[d]*(n/d)*(m/d);
        }
        cout << ans << el;
    }
}