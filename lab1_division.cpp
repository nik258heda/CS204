#include<bits/stdc++.h> 
using namespace std; 
int gr(string str1,string str2){
	int n1=str1.length();
	int n2=str2.length();
	if(n1>n2) return 1;
	if(n2>n1) return 0;
	else{
		int i;
		for(i=0;i<n1;i++){
			if(str1[i]>str2[i]) return 1;
			if(str2[i]>str1[i]) return 0;
		}
		if(i==n1) return 2;
	}
}
string sub(string str1,string str2)
{
	int sign;
	if(gr(str1,str2)==2) return "";
	else{
		if (gr(str1,str2)==0){
			swap(str1,str2);
			sign=1;
		}  
		string str = ""; 
		int n1 = str1.length(), n2 = str2.length(); 
	    	reverse(str1.begin(), str1.end()); 
	  	reverse(str2.begin(), str2.end()); 
	  	int carry = 0; 
		for (int i=0; i<n2; i++) 
		{ 
		        int sum = ((str1[i]-'0')-(str2[i]-'0')+carry);
			if(sum<0){
				carry=-1;
				sum=sum+10;
			}
			else carry=0; 
		        str.push_back(sum + '0'); 
		} 
		for (int i=n2;i<n1; i++) 
		{ 
			int sum = ((str1[i]-'0')+carry);
			if(sum<0){
				carry=-1;
				sum=sum+10;
			}
			else carry=0; 
		        str.push_back(sum + '0'); 
		}
		int i=str.length();
		while(str[i-1]=='0') {
			str.pop_back();
			i--;
		}
		if (sign==1) 
			str.push_back('-'); 
		reverse(str.begin(), str.end());
		return str; 
	}
}
int main(){
	string s1,s2,s="";
	cin>>s1>>s2;
	int n1=s1.length();
	int n2=s2.length();
	if(s2=="0") cout<<"Not defined";
	else if(gr(s1,s2)==0) cout<<0<<" "<<s1;
	else if(gr(s1,s2)==2) cout<<1<<" "<<0;
	else{
		string x="";
		int i;
		for(i=0;i<n2;i++){
			x.push_back(s1[i]);	
		}
		while(i<=n1){
			int h=0;
			while(1){
				if(gr(x,s2)==0){
					break;
				}
				else{
					string y=sub(x,s2);
					x=y;
					h++;
				}			
			}
			if(i!=n2 || h!=0) s.push_back(h+'0');
			if(i<n1) x.push_back(s1[i]);
			i++;			
		}
		if(x=="") x.push_back('0');
		cout<<s<<" "<<x;	
	}
	return 0;
}
