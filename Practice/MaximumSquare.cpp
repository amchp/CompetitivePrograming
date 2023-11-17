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
#define MAXA                         (int)1e9

using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int a[n];
        for(int i = 0; i < n; ++i)cin >> a[i];
        sort(a, a+n);
        int acc = 0, m = 0;
        for(int i = n - 1; i > -1; --i){
            acc++;
            if(acc < a[i])m = acc;
            else if(acc >= a[i] && a[i] > m){
                m = a[i];
                break;
            }
        }
        cout << m << el;
    }
}