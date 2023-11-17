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
        int n;
        cin >> n;
        int a[n], ans[n];
        int l = 0, r = n -1;
        for(int i = 0; i < n; ++i)cin >> a[i];
        for(int i = 0; i < n; ++i){
            if(i % 2 == 0){
                ans[i] = a[l];
                l++;
            }else{
                ans[i] = a[r];
                r--;
            }
        }
        for(int i = 0; i < n; ++i)cout << ans[i] << " ";
        cout << el;
    }
}