#include <bits/stdc++.h>

#define fi first
#define se second
#define forn(i, n) for (int i = 0; i < (int)n; ++i)
#define for1(i, n) for (int i = 1; i <= (int)n; ++i)
#define fore(i, l, r) for (int i = (int)l; i <= (int)r; ++i)
#define ford(i, n) for (int i = (int)(n)-1; i >= 0; --i)
#define fored(i, l, r) for (int i = (int)r; i >= (int)l; --i)
#define pb push_back
#define el '\n'
#define d(x) cout << #x << " " << x << el
#define ri(n) scanf("%d", &n)
#define sz(v) ((int)v.size())
#define all(v) v.begin(), v.end()
#define allr(v) v.rbegin(), v.rend()

using namespace std;

typedef long long ll;
typedef double ld;
typedef pair<int, int> ii;
typedef pair<char, int> pci;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;

const int inf = 1e9;
const int nax = 1e5 + 200;
const ld pi = acos(-1);
const ld eps = 1e-9;

int dr[] = {1, -1, 0, 0, 1, -1, -1, 1};
int dc[] = {0, 0, 1, -1, 1, 1, -1, -1};

string s1, s2;
ll dp[64][2][2][2];

ll sol(int ind, int leq, int heq, int zero){
    if(ind == s2.size())return 0;
    if(!heq)return 3*(s2.size() - ind);
    // cout << "HI" << el;
    ll& ans = dp[ind][leq][heq][zero];
    if(ans != -1)return ans;
    ans = 0;
    if(leq){
        for(char c = s2[ind]; c >= s1[ind]; --c){
            ans = max(ans, (c - '0') + sol(ind + 1, s1[ind] == c, s2[ind] == c, zero && c == '0') + (!zero || c != '0'));
        }
    }else{
        for(char c = s2[ind]; c >= '0'; --c){
            ans = max(ans, (c - '0') + sol(ind + 1, 0, s2[ind] == c, zero && c=='0') + (!zero || c != '0'));
        }
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << setprecision(20);
    int t;
    cin >> t;
    while(t--){
        ll a, b;
        s1.clear();
        s2.clear();
        cin >> a >> b;
        while(a > 0){
            s1.pb((a % 3LL) + '0');
            a /= 3LL;
        }
        while(b > 0){
            s2.pb((b % 3LL) + '0');
            b /= 3LL;
        }
        while(s1.size() < s2.size())s1.pb('0');
        reverse(all(s1));
        reverse(all(s2));
        forn(i, s2.size()){
            forn(j, 2){
                forn(k, 2){
                    dp[i][j][k][0] = -1;
                    dp[i][j][k][1] = -1;
                }
            }
        }
        cout << sol(0, s1[0] == s2[0], 1, 1) << el;
    }
}
