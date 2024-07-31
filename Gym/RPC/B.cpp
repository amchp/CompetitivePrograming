#include <bits/stdc++.h>
using namespace std;
int main(){
    long long days;
    long long d1,d2,m1,m2,y1,y2,n;
    cin>>d1>>m1>>y1>>n>>d2>>m2>>y2;
    days += (d2 - d1 + 30) % 30;
    // cout << (d2 - d1 + 30) % 30 << endl;
    if(d2 < d1){
        m2--;
        if(m2 == 0){
            y2--;
            m2 = 12;
        }
    }
    days += ((m2 - m1 + 12) % 12) * 30;
    // cout << ((m2 - m1 + 12) % 12) * 30 << endl;
    if(m2 < m1){
        y2--;
    }
    days += (y2 - y1)*360;
    days = (days + n) % 7;
    if(days==0)cout<<7<<endl;
    else cout<<days<<endl;
}