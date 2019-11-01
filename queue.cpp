#include<iostream>
using namespace std;
template<class t>
class Queue
{
	t* arr;
	int size,front,rear;
	public:
		Queue()
		{
			size=1;
			front=-1;
			rear=-1;
			arr=new t[1];
		}
		Queue(int s)
		{
			size=s;
			front=-1;
			rear=-1;
			arr=new t[s];
		}
		void enqueue(t el);
		t dequeue();
		bool isempty();
		bool isfull();
		void display();
};
template<class t>
bool Queue<t>::isempty()
{
	if(front==-1&&rear==-1)
		return true;
	else
		return false;
}
template<class t>
bool Queue<t>::isfull()
{
	if(front==(rear+1)%size)
		return true;
	else
		return false;
}
template<class t>
void Queue<t>::enqueue(t el)
{
	if(!isfull())
	{
		if(isempty())
		{
			front++;
			arr[++rear]=el;
		}else
		{
			rear=(rear+1)%size;
			arr[rear]=el;
		}
	}else
		cout<<"Queue is full"<<endl;
}
template<class t>
t Queue<t>::dequeue()
{
	t el;
	if(!isempty())
	{
		if(front==rear)
		{
			el=arr[front];
			front=-1;
			rear=-1;
		}else
		{
			el=arr[front];
			front=(front+1)%size;
		}
		return el;
	}else
		throw el;
}
template<class t>
void Queue<t>::display()
{
	if(!isempty())
	{
		if(front>rear)
		{
			for(int i=front;i<size;i++)
			{
				cout<<i<<"\t"<<arr[i]<<endl;
			}
			for(int i=0;i<=rear;i++)
			{
				cout<<i<<"\t"<<arr[i]<<endl;
			}
		}else
		{
			for(int i=front;i<=rear;i++)
			{
				cout<<i<<"\t"<<arr[i]<<endl;
			}
		}
	}else
	{
		cout<<"Empty Queue"<<endl;
	}
}
