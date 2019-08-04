#include<bits/stdc++.h>
using namespace std;
#define ll unsigned long long
string prime(ll n)
{
    ll c=0;
    for(ll i=2;i*i<=n;i++){
        if(n%i==0){
            c++;
        }
    }
    if(c==0)
    {
        return "Prime";
    }
    else{
        return "Not a Prime";
    }
}
int main(){
	int t;
	cin>>t;
	for(int k=0;k<t;k++)
	{	
	ll n;
	cin>>n;
	if(n==1) cout<<"Not a Prime"<<"\n";
	else if(n==2) cout<<"Prime"<<"\n";
	else cout<<prime(n)<<"\n";
	}
	return 0;	
}
