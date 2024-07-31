#include <bits/stdc++.h>

#define forn(i, n) for(int i = 0; i < n; ++i)
#define el '\n'
#define pb push_back
#define all(x) x.begin(), x.end()
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

const int mod = 1e7 + 7;
const int nax = 1e3 + 100;

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

mint sm(ll x){
    assert(x <= 1e9);
    return mint((x*(x + 1) / 2) % mod);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<bool> sv(nax + 1);
    vi primes;
    for(int i = 2; i <= nax; ++i){
        if(sv[i])continue;
        primes.pb(i);
        for(int j = i + i; j <= nax; j += i){
            sv[j] = true;
        }
    }
    int n;
    vector<ii> nums;
    cin >> n;
    int idx = 0;
    while(n){
        nums.pb({n, idx});
        ++idx;
        cin >> n;
    }
    sort(all(nums));
    vi fans(idx);
    map<int, int> pp;
    idx = 2;
    for(auto& [cur, ind] : nums){
        while(idx <= cur){
            int tmp = idx;
            for(int& p : primes){
                while(tmp % p == 0){
                    ++pp[p];
                    tmp /= p;
                }
            }
            if(tmp != 1)++pp[tmp];
            ++idx;
        }
        mint ans = 1;
        for(auto& [p, cnt] : pp){
            ans = ans * sm(cnt + 1);
        }
        fans[ind] = ans.x;
    }
    for(int& v : fans)cout << v << el;
}