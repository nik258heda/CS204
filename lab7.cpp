#include<bits/stdc++.h>
using namespace std;
#define ll long long int
bool compare(string a,string b){
    string x=a+b;
    string y=b+a;
    if(x>y) return 0;
    else return 1;
}
int main(){
    ll t;
    cin>>t;
    while(t--){
        ll n;
        vector<string> v;
        cin>>n;
        while(n--){
            string s;
            cin>>s;
            v.push_back(s);
        } 
        sort(v.begin(),v.end(),compare);
        for(int i=0;i<v.size();i++){
            cout<<v[v.size()-i-1];
        }
    }
}