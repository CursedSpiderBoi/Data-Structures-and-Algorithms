#include<iostream>

using namespace std;
template<typename t>//template can be used as any data type
struct node{
	t data;
	node *next;
	node(){
		data=0;
		next=nullptr;
	}
	node(t val){
		data=val;
		next=nullptr;
	}
	node(t val,node* forward){
		data=val;
		next=forward;
	}
};
template<typename t>
class SinglyLinkList{
private:
	node<t>* head;
	node<t>* tail;
	//it is always advised to make head and tail both
	//int size;//not required but can be added as per ease
public:
	SinglyLinkList(){
		head=tail=nullptr;
	}
	bool isEmpty(){
		return head==tail==nullptr;
	}
	int size(){
		int n=0;
		node<t> *temp=head;
		while(temp){
			temp=temp->next;
			n++;
		}
		return temp;
	}
	void InsertAtHead(t val){
		node<t> *temp=new node<t>(val);
		if(this->isEmpty())
			head=tail=temp;
		else{
			temp->next=head;
			head=temp;
		}
	}
	void InsertAtTail(t val){
		node<t> *temp=new node<t>(val);
		if(this->isEmpty())
			head=tail=temp;
		else{
			tail->next=temp;
			tail=temp;
		}
	}
	bool Exists(t val){
		if(this->isEmpty())
			return false;
		else{
			node<t> *temp=head;
			while(temp){
				if(temp->data==val)
					return true;
				temp=temp->next;
			}
		}
		return false;
	}
	void Delete(t val){
		node<t> *temp=head;
		while(temp){
			while(temp->next || temp->next->data==val){
				node<t> *cur=temp->next;
				if(temp->next->next)
					temp->next=temp->next->next;
				temp->next=nullptr;
				delete cur;
			}
			temp=temp->next;
		}
	}
	void Display(){
		node<t> * temp=head;
		while(temp){
			cout<<"->"<<temp->data;
			temp=temp->next;
		}
	}
};
