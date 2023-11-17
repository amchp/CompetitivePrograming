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

// Useful constants 
#define INF                         (int)1e9 
#define EPS                         1e-9 

#define el '\n'

using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, l, r;
        string ans = "NO";
        cin >> n;
        int a[n];
        for(int i = 0; i < n; ++i) cin >> a[i];
        for(int i = 0; i < n; ++i){
            for(int j = i+2; j < n; ++j){
                if(a[i] == a[j]){
                    bool pass = true;
                    l = i;
                    r = j;
                    while(l < r){
                        l++;
                        r--;
                        if(a[i] != a[j]){
                            pass = false;
                            break;
                        }
                    }
                    if(pass){
                        ans = "YES";
                        goto stop;
                    }
                }
            }
        }
        stop:
        cout << ans << el;
    }
}