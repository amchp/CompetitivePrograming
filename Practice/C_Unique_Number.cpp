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
        int x, l = 0, h = 0, d, ans = -1;
        cin >> x;
        for(int i = 0; i < 9; ++i){
            h += 9 - i;
            if(x <= h && h > l){
                d = i + 1;
                int a[d], sum;
                for(int j = 0; j < d; ++j)a[j] = j+1;
                while(true){
                    bool pass = false;
                    if(a[d - 1] == 10){
                        for(int j = 1; j < d; ++j){
                            if(a[d - 1 - j] + 1 != 10 - j){
                                a[d - 1 - j]++;
                                for(int k = (d - 1 - j) + 1; k < d; ++k){
                                    a[k] = a[(d - 1 - j)] + k - (d - 1 - j); 
                                }
                                pass = true;
                                break;
                            }
                        }
                        if(!pass){
                            ans = -1;
                            goto stop;
                        }
                    }else{
                        sum = 0;
                        // for(int j = 0; j < d; ++j)cout << a[j] << " ";
                        // cout << el;
                        for(int j = 0; j < d; ++j)sum += a[j];
                        if(sum == x){
                            ans = 0;
                            for(int j = 0; j < d; ++j){
                                ans += a[d - 1 - j] * pow(10, j);
                            }
                            goto stop;
                        }
                        a[d - 1]++;
                    }
                }
            }
            l += 9 - i;
        }
        stop:
        cout << ans << el;
    }
}