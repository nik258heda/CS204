#include<bits/stdc++.h>
using namespace std;
#define ll unsigned long long
bool prime(ll n)
{
    ll c=0;
    for(ll i=2;i*i<=n;i++){
        if(n%i==0){
            c++;
        }
    }
    if(c==0)
    {
        return true;
    }
    else{
        return false;
    }
}
int main(){
	ll n;
	cin>>n;
	if(n==1) cout<<false;
	else if(n==2) cout<<true;
	else cout<<prime(n);
	return 0;	
}
