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
const ld inf = 2e7;
const int it = 600, nax = 4e7;

ll f[nax];
ll check(int p, int d, int c){
    if((p+d) % c)return 0;
    // assert(f[(p+d) / c]%2 == 0);
    return f[(p+d)/c];
}
void solve(){
    int c,d,x;
    cin>>c>>d>>x;
    ll ans = 0;
    for(int i = 1; i * i <= x; ++i){
        if(x%i == 0){
            ans += check(i,d,c);
            if(x/i != i){
                ans += check(x/i, d, c);
            }
        }
    }
    if(c>d&&x % (c-d) == 0) --ans;
    // for(int i = 1; i <= x*10; ++i){
    //     for(int j = 1; j <= i; ++j){
    //         if(lcm(i,j) * c- __gcd(i,j)*d == x)
    //         {
    //             d(i),d(j),d(__gcd(i,j)), d(lcm(i,j));
    //         cout<<"==="<<el;
    //         }
    //     }
    // }

    cout<<ans<<el;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.precision(20);
    fore(i,2,nax-1)f[i] = 1;
    f[0] = 2;
    f[1] = 2;
    fore(i,2, nax-1){
        if(f[i] == 1){
            f[i] = 2;
            for(int j = i+i; j<nax; j+=i){
                f[j] *= 2;
            }

        }
    }
    int t;
    cin>>t;
    while(t--)solve();
}