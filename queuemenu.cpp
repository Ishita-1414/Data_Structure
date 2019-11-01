#include<iostream>
#include"queue.cpp"
using namespace std;
template<class t>
void menu(Queue<t> &q)
{
	int choice,on;
	do{
		cout<<"Enter your choice"<<endl;
		cout<<"1.Enqueue"<<endl;
		cout<<"2.Dequeue"<<endl;
		cin>>choice;
		try{
			switch(choice)
			{
				case 1:{t el;
				cout<<"Enter element to be inserted : ";
				cin>>el;
				q.enqueue(el);
				q.display();
					break;
				}
				case 2:{cout<<"Element dequeued is : "<<q.dequeue()<<endl;
				q.display();
					break;
				}
				default:cout<<"Invalid choice"<<endl;
			}
		}
		catch(...)
		{
			cout<<"Empty Queue"<<endl;
		}
		cout<<"To continue, Press 1: ";
		cin>>on;
	}while(on==1);
}
int main()
{
	int sz;
	cout<<"enter sixe of Queue : ";
	cin>>sz;
	Queue<int> q(sz);
	menu(q);
	return 0;
}
