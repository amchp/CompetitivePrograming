#include <bits/stdc++.h>

#define forn(i, n) for(int i = 0; i < (int)n; ++i)
#define for1(i, n) for(int i = 1; i <= (int)n; ++i)
#define fore(i, l, r) for(int i = (int)l; i <= (int)r; ++i)
#define el '\n'
#define d(x) cerr << #x << ' ' << x << el
#define sz(x) x.size()
#define fi first
#define se second

using namespace std;

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef long long ll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    int ans = 0;
    for1(i, 9){
        int cnt = 0;
        ll num = i;
        while(num <= n){
            num*=10;
            num += i;
            ++cnt;
        }
        ans += cnt;
    }
    ans += max(1, int(log10(n)));
    cout << ans << el;
}