#include <bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin>>t;
	for(int k=0;k<t;k++)
	{
	string s1,s2;
	cin>>s1>>s2;
	int n1=s1.length();
	int n2=s2.length();
	if (n2>n1) 
 	       swap(s1, s2); 
	n1=s1.length();
	n2=s2.length();
	vector<int> res(n1+n2,0);
    	reverse(s1.begin(), s1.end()); 
  	reverse(s2.begin(), s2.end());
	for(int i=0;i<n1;){
		int c=0;
		int j=0;
		for(j=0;j<n2;){
			int a;
			a=(s1[i]-'0')*(s2[j]-'0')+res[i+j]+c;
			c=a/10;
			res[i+j]=a%10;
			j++;
		}
		if(c>0) res[i+j]=res[i+j]+c;
		i++;
	}
	int i=res.size()-1;
	while(res[i]==0 && i>=0){
		i--;
	}
	if(i==-1) cout<<0<<"\n";
	else{
		while(i>=0){
			cout<<res[i];
			i--;
		}
		cout<<"\n";
	}
	}
	return 0;
}
