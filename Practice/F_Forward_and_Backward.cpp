#include <bits/stdc++.h>
using namespace std;
int main(){
    long long n;
    cin>>n;
    bool control1=true;
    for(int i=2;i<min((long long)1e6+1,n);i++){
        //cout<<i<<endl;
        vector<long long> v;
        long long t=n;
        while(t>0){
            v.push_back(t%i);
            t=t/i;
        }
        //for(int j=0;j<v.size();j++)cout<<v[j]<<" ";
        //cout<<endl;
        bool control=true;
        int tam=v.size();
        for(int j=0;j<=(int)(tam-1)/2;j++){
            if(v[j]==v[tam-j-1])continue;
            control=false;
        }
        if(control){
            control1=false;
            cout<<i<<" ";
        }
    }
    for(int i=1e6;i>=1;i--){
        if(n%i==0){
            if(n/i-1>1e6){
                control1=false;
                cout<<n/i-1<<" ";
            }
        }
    }
    if(control1)cout<<"*";
}