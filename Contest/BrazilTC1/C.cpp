#include <bits/stdc++.h>

#define forn(i, n) for(int i = 0; i < (int)n; ++i)
#define for1(i, n) for(int i = 1; i <= (int)n; ++i)
#define fore(i, l, r) for(int i = (int)l; i <= (int)r; ++i)
#define el '\n'
#define d(x) cerr << #x << ' ' << x << el
#define sz(x) x.size()
#define fi first
#define se second
#define all(x) x.begin(), x.end()

using namespace std;

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef long double ld;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<ld> prb(n);
    forn(i, n)cin >> prb[i];
    sort(all(prb));
}