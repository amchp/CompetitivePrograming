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
#include <tuple>


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
    int n, m, sum, l;
    cin >> n >> m;
    vi a(n), b(n), c((int)2e5, 0);
    for(int i = 0; i < n; ++i)cin >> a[i];
    sum = 0;
    for(int i = n - 1; i > -1; --i){
        if(c[a[i]] == 0){
            sum++;
            c[a[i]] = 1;
        }
        b[i] = sum;
    }
    for(int i = 0; i < m; ++i){
        cin >> l;
        cout << b[l-1] << el;
    }
}