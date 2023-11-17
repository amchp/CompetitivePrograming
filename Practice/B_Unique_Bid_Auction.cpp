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

// Useful constants 
#define INF                         (int)1e9 
#define EPS                         1e-9

#define el '\n'

using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, ans, mi;
        cin >> n;
        int a[n];
        unordered_map<int , int> m;
        for(int i = 0; i < n; ++i){
            cin >> a[i];
            m[a[i]]++;
        }
        m[-1] = 0;
        ans = -1;
        mi = INF;
        for(int i = 0; i < n; ++i){
            if(a[i] < mi && m[a[i]] < 2){
                ans = i + 1;
                mi = a[i];
            }
        }
        cout << ans << el;
    }
}