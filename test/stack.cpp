#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e6+5;
#define mod 1e9+7
const ll INF=mod;
struct stck{
    ll a[N];
    int top;
};
void push(struct stck *s,ll x){
    s->a[(s->top)]=x;
    s->top++;
    return;
}
void pop(struct stck *s){
    if(s->top==0){
        cout<<"stck is empty";
        return;
    }
    else{
        s->a[s->top-1]=INF;
        s->top--;
        return;
    }
}
int main(){
    struct stck s;
    s.top=0;
    ll t;
    cin>>t;
    while(t--){
        bool n;
        cin>>n;
        if(n==1){
            ll y;
            cin>>y;
            push(&s,y);
        }
        else{
            pop(&s);
        }
    }
    return 0;
}