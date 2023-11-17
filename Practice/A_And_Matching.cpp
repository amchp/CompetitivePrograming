#include <algorithm>
#include <array>
#include <cassert>
#include <complex>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <map>
#include <math.h>
#include <numeric>
#include <queue>
#include <set>
#include <sstream> // istringstream buffer(myString);
#include <stack>
#include <unordered_map>
#include <utility>
#include <vector>

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

int n;

int bitWiseNot(int x){
    int n1 = n - 1;
    return (x^n1);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << setprecision(20);
    int t;
    cin >> t;
    while(t--){
        int x;
        cin >> n >> x;
        if(n == 4 && x == 3){
            cout << -1 << el;
            continue;
        }
        int bit = 0;
        forn(i, 32){
            if(n & 1<< i){
                bit = i - 1;
                break;
            }
        }
        if(x == 0){
            forn(i, n / 2){
                cout << i << ' ' << bitWiseNot(i) << el;
            }
        }else if(n - 1 == x){
            cout << 0 << ' ' << 2 << el;
            cout << 1 << ' ' << bitWiseNot(2) << el;
            fore(i, 3, n / 2 - 1){
                cout << i << ' ' <<  bitWiseNot(i) << el;
            }
            cout << n - 2 << ' ' << n - 1 << el;
        }else{
            cout << 0 << ' ' << bitWiseNot(x) << el;
            for1(i, n / 2 - 1){
                if(x == i || bitWiseNot(i) == x)continue;
                cout << i << ' ' << bitWiseNot(i) << el;
            }
            cout << x << ' ' << n - 1 << el;
        }
    }
}
