#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    string s;
    cin>>s;
    int f=0;
    int b=0;
    char ant = 'x';
    for(int i = 0 ; i < s.size() ; ++i){
        if(s[i]=='+'){
            if(ant != 'f'){
                f++;
                ant = 'f';
            }
        }else{
            if(ant != 'b'){
                b++;
                ant = 'b';
            }
        }
        i++;
    }
    cout<<min(f,b)<<'\n';
    return 0;
}