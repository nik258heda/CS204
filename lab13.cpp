#include <bits/stdc++.h>
#define ll long long int
#define mod 1e9 + 7
using namespace std;
const int N = 1023;
const int INF = mod;
int main(){
    ll n;
    cin>>n;
    string a[n];
    set<string> s;
    for(int i=0;i<n;i++){
        cin>>a[i];
        string b=a[i];
        reverse(b.begin(),b.end());
        if(b!=a[i]){
            s.insert(a[i]);
        }
    }
    ll x=s.size();
    for(int i=0;i<n;i++){
        string b=a[i];
        reverse(b.begin(),b.end());
        if(b!=a[i]){
            s.insert(b);
        }
    }
    ll z=s.size();
    if(z<2*x) cout<<"YES";
    else cout<<"NO";
    return 0;
}