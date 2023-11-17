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
    int t, n;
    cin >> t;
    while(t--){
        cin >> n;
        vector<int> a(n);
        int mi = 0;
        int s = 0;
        for(int i = 0; i < n; ++i){
            cin >> a[i];
            if(a[mi] < a[i]){
                s += a[mi];
                mi = i;
            }else{
                s += a[i];
            }
        }
        int l = 0;
        int r;
        while(l < n && (a[l] == 0 || l != mi || l != r))l++;
        r = l + 1;
        while(r < n && (a[r] == 0 || r != mi || l != r))r++;
        vector<array<int, 3> > v;
        int ans = 0;
        int b;
        while(l < n && r < n && s > a[mi]){
            b = min(min(a[l], a[r]), s - a[mi]);
            ans += b;
            array<int, 3> vv = {l+1, r+1, b};
            v.push_back(vv);
            a[l] -= b;
            a[r] -= b;
            if(a[l] == 0 && l < r)l = r + 1;
            while(l < n && (a[l] == 0 || l != mi || l != r))l++;
            if(a[r] == 0 && r < l)r = l + 1;
            while(r < n && (a[r] == 0 || r != mi || l != r))r++;
        }
        l = min(l , r);
        while(l < n && a[mi] > 0){
            b = min(a[l], a[mi]);
            ans += b;
            array<int, 3> vv = {l+1, mi+1, b};
            v.push_back(vv);
            a[l] -= b;
            a[mi] -= b;
            while(l < n && (a[l] == 0 || l != mi))l++;
        }
        cout << ans << el;
        for(int i = 0; i < v.size(); ++i){
            for(int j = 0; j < v[i][2]; ++j){
                cout << v[i][0] << " " << v[i][1] << el;
            }
        }
    }
}