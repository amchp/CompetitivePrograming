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
    int t, n, l, r, lb, rb, m, lf, rf, sum;
    cin >> t;
    while(t--){
        cin >> n >> l >> r;
        vector<int> a(n);
        for(int i = 0; i < n; ++i)cin >> a[i];
        sort(a.begin(), a.end());
        for(int i = 0; i < n; ++i){
            sum = 0;
            lb = i + 1;
            rf = n - 1;
            while(lb + 1 < rb){
                m = (lb + rb) / 2;
                if(a[i] + a[m] < l)lb = m;
                else rb = m;
            }
            if(a[i] + a[lb] >= l)lf = lb;
            else lf = rb;
            lb = i + 1;
            rb = n - 1;
            while(lb + 1 < rb){
                m = (lb + rb) / 2;
                if(a[i] + a[m] <= r)lb = m;
                else rb = m;
            }
            if(a[i] + a[rb] <= r)rf = lb;
            else rf = rb;
            cout << i << " " <<  a[i] + a[lf] << " " <<  a[i] + a[rf] << el;
            if(a[i] + a[lf] >= l && a[i] + a[rf] <= r) sum += rf - lf;
        }
        cout << sum << el;
    }
}