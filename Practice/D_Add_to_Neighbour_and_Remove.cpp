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

vector<int> factor(int sum, vector<int> f){
    vector<int> h;
    for(int i = 1; i < sqrt(sum); ++i){
        if(sum % i == 0){
            f.push_back(i);
            h.push_back(sum / i);
        }
    }
    for(int i = h.size() - 1; i > -1; --i)f.push_back(h[i]);
    return f;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, v, vv, sum, m, ind, mi, M, Mi, c = 0;
        cin >> n;
        vector<int> a, f;
        for(int i = 0; i < n; ++i){
            cin >> v;
            a.push_back(v);
        }
        m = INF;
        mi = 0;
        M = 0;
        Mi = 0;
        sum = 0;
        for(int i = 0; i < n; ++i){
            sum += a[i];
            if(m > a[i]){
                mi = i;
                m = a[i];
            }
            if(M < a[i]){
                Mi = i;
                M = a[i];
            }
        }
        f = factor(sum, f);
        for(int i = 0; i < f.size(); ++i){
            if(M <= f[i]){
                ind = i;
                break;
            }
            if(i == f.size() - 2){
                c = n - 1;
                goto end;
            }
        }
        while(m != M && a.size() > 1){
            if(mi == 0){
                a[1] += a[0];
                a.erase(a.begin());
            }else if(mi == a.size() - 1){
                a[mi - 1] += a[mi];
                a.erase(a.begin() + mi);
            }else{
                start:
                v = f[ind] - (a[mi - 1] + a[mi]);
                vv = f[ind] - (a[mi] + a[mi + 1]);
                if(v < 0 && vv < 0){
                    ind++;
                    if(ind == f.size() - 1){
                        c = n - 1;
                        goto end;
                    }
                    goto start;
                }else if(v < 0){
                    a[mi + 1] += a[mi];
                    a.erase(a.begin() + mi);
                }else if(vv < 0){
                    a[mi - 1] += a[mi];
                    a.erase(a.begin() + mi);
                }else if(v < vv){
                    a[mi - 1] += a[mi];
                    a.erase(a.begin() + mi);
                }else{
                    a[mi + 1] += a[mi];
                    a.erase(a.begin() + mi);
                }
            }
            c++;
            m = INF;
            mi = 0;
            M = 0;
            Mi = 0;
            for(int i = 0; i < a.size(); ++i){
                // cout << a[i] << " ";
                if(m > a[i]){
                    mi = i;
                    m = a[i];
                }
                if(M < a[i]){
                    Mi = i;
                    M = a[i];
                }
            }
            // cout << el;
        }
        end:
        std::cout << c << el;
    } 
}
