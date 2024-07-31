#include <bits/stdc++.h>

#define forn(i, n) for (int i = 0; i < n; ++i)
#define el '\n'
#define d(x) cerr << #x << ' ' << x << el;

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n, k;
    cin >> n >> k;
    // assert(n != 2);
    vl a(n);
    forn(i, n)cin >> a[i];
    ll ans = a[n - 1] - a[0];
    cout << max(0LL, abs(ans) - k) << el;
}