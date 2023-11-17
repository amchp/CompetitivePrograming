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
    long long n, q, m, v;
    cin >> n >> q;
    long long arr[(int) 3e5 + 1];
    long long order[(int) 3e5];
    long long maxArr[(int) 3e5 + 1];
    m = -INF;
    for(int i = 0; i < n; ++i){
        cin >> arr[i];
        if(m < arr[i]){
            if(i != 0)order[i-1] = m;
            m = arr[i];
        }else if(i != 0)order[i - 1] = arr[i];
        maxArr[i] = m;
    }
    for(int i = 0; i < q; ++i){
        cin >> v;
        if(v < n){
            cout << maxArr[v-1] << " " << arr[v] << el;
        }else{
            cout << m << " " << order[(v-1) % (n-1)] << el;
        }
    }
}