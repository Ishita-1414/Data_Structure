#include<iostream>
using namespace std;
template <class t>
class node
{
	public:
		t info;
		node* next;
		node()
		{
			next=NULL;
		}
		node(t in,node* ne=NULL)
		{
			info=in;
			next=ne;
		}
};
template<class t>
class QueueLL
{
	node<t>* head;
	public:
		QueueLL()
		{
			head=NULL;
		}
		void enqueue(t el);
		t dequeue();
		bool isempty();
		void display();
};
template<class t>
bool QueueLL<t>::isempty()
{
	if(head==NULL)
		return true;
	else
		return false;
}
template<class t>
void QueueLL<t>::enqueue(t el)
{
	node<t>* ins=new node<t>(el);
	node<t>* temp=head;
	if(head==NULL)
	{
		head=ins;
	}else
	{
		while(temp->next!=NULL)
			temp=temp->next;
		temp->next=ins;
	}
	temp=NULL;
	ins=NULL;
	delete temp;
	delete ins;	
}
template<class t>
t QueueLL<t>::dequeue()
{
	t el;
	if(!isempty())
	{
		el=head->info;
		node<t>* temp=head;
		head=head->next;
		temp->next=NULL;
		temp=NULL;
		delete temp;
		return el;
	}else
		throw el;
}
template<class t>
void QueueLL<t>::display()
{
	node<t>* temp=head;
	if(head==NULL)
	{
		cout<<"Empty Queue"<<endl;
	}else
	{
		while(temp!=NULL)
		{
			cout<<temp->info<<"\t";
			temp=temp->next;
		}
		cout<<endl;
	}
	temp=NULL;
	delete temp;
}
