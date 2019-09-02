#include<bits/stdc++.h>
using namespace std;
#define ll long long int 
int main(){
    pair<ll,ll> m;
    m={-1,-1};
    ll q;
    ll n;
    cin>>n>>q;
    vector<ll> a(n+1,0);
    int x=0;
    while(q--){
        cin>>x;
        if(x==1){
            int b,c;
            cin>>b>>c;
            a[b]=a[b]+c;
            if(a[b]>m.second){
                m={b,a[b]};
            }
        }
        if(x==2){
            if(m.first==-1){
                cout<<"Data Not Found";
            }
            else{
                cout<<m.first<<"\n";
            }
        }
    }
}