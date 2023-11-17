#include <vector>
#include <map>
#include <cstdlib>
#include <fstream>
#include <iomanip>   
#include <iostream>  
#include <sstream>  // istringstream buffer(myString);
#include <stack>
#include <algorithm>
#include <cstring>
#include <cassert>
#include <math.h>
#include <unordered_map>
#include <queue>
#include <array>

// Useful constants 
#define INF                         (int)2e9 
#define EPS                         1e-9

#define el '\n'

#define MAXN                         (int)2e5

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;



int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, k, a, b, q;
    cin >> n >> k >> a >> b >> q;
    vector<int> v(n+1, 0);
    vector<int> sA;
    vector<int> sB;
    int f, s, t, ans;
    for(int i = 0; i < q; ++i){
        cin >> f;
        if(f == 1){
            cin >> s >> t;
            v[s] += t;
        }
        else{
            cin >> s;
            ans = 0;
            for(int i = 1; i < s; ++i){
                ans += min(v[i], b);
            }
            for(int i = s + k; i <= n; ++i){
                ans += min(v[i], a);
            }
            cout << ans << el;
        }
    }
}