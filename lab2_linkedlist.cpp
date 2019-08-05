#include<bits/stdc++.h>
using namespace std;
struct Node{
	int x;
	int y;
	struct Node *next;	
};
struct Node* head =NULL;
float dis(int x, int y){
	float k;
	k=sqrt(x*x + y*y);
	return k;
}
void add_first(int x1,int y1){
	struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
	new_node->x=x1;
	new_node->y=y1;
	new_node->next=head;
	head =new_node;	
}
void del_first(){
	if(head==NULL)
	{
		cout<<"empty";	
	}
	else{
		Node *temp=head;
		head=head->next;
		temp->next=NULL;
		delete temp;
	}
}
void del(int x1,int y1) 
{ 
    struct Node* temp =head, *prev; 
    if (temp != NULL && temp->x == x1 && temp->y == y1) 
    { 
        head = temp->next;    
        free(temp);                
        return; 
    }  
    while (temp != NULL && (temp->x != x1 || temp->y != y1)) 
    { 
        prev = temp; 
        temp = temp->next; 
    }  
    if (temp == NULL) return; 
    prev->next = temp->next; 
    free(temp);
} 
string search(int x1,int y1) 
{ 
    struct Node* current = head; 
    while (current != NULL) 
    { 
        if (current->x == x1 && current->y == y1) 
            return "true"; 
        current = current->next; 
    } 
    return "false"; 
} 
void search_dis(float d) 
{ 
    struct Node* current = head; 
    while (current != NULL) 
    { 
	int a= current->x;
	int b= current->y;
        if (dis(a,b)<=d) 
            cout<<"("<<current->x<<","<<current->y<<")"; 
        current = current->next; 
    } 
    return;  
}
int length()  
{  
    int count = 0; 
    Node* current = head;  
    while (current != NULL)  
    {  
        count++;  
        current = current->next;  
    }  
    return count;  
}  
int main(){
	long long t;
	cin>>t;
	int i;
	for(long long j=0;j<t;j++){
		cin>>i;
		if(i==1){
			int x1,y1;
			cin>>x1>>y1;
			add_first(x1,y1);
		}
		if(i==2){
			del_first();
		}
		if(i==3){
			int x1,y1;
			cin>>x1>>y1;
			del(x1,y1);
		}
		if(i==4){
			int d;
			cin>>d;
			search_dis(d);
			cout<<"\n";
		}
		if(i==5){
			int x1,y1;
			cin>>x1>>y1;
			cout<<search(x1,y1)<<"\n";
		}
		if(i==6){
			cout<<length()<<"\n";
		}	
	}
	return 0;
}
