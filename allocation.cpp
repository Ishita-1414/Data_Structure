#include<iostream>
using namespace std;
class Allocation
{
	int* memory_chunks;
	int* process;
	int* m2;
	int no;
	int Mno;
	int memory;
	int org;
	public:
		void input();
		void bestFit();
		void firstFit();
		void worstFit();
};
void Allocation::input()
{
	cout<<"Enter no. of processes: ";
	cin>>no;
	process=new int[no];
	cout<<"Enter size of memory required for the processes: "<<endl;
	cout<<"Process\tsize\n";
	for(int i=0;i<no;i++)
	{
		cout<<i+1<<"\t";
		cin>>process[i];
	}
	cout<<"Enter No. of memory chunks: ";
	cin>>Mno;
	memory_chunks=new int[Mno];
	cout<<"Enter size of memory chunks: "<<endl;
	cout<<"Chunks\tsize\n";
	m2=new int[Mno];
	for(int i=0;i<Mno;i++)
	{
		cout<<i+1<<"\t";
		cin>>memory_chunks[i];
	}
}
void Allocation::firstFit()
{
	for(int i=0;i<Mno;i++)
	{
		m2[i]=memory_chunks[i];
	}
	cout<<"Process\tsize\tmemory chunk\toriginal size\n";
	for(int i=0;i<no;i++)
	{
		memory=0;
		for(int j=0;j<Mno;j++)
		{
			if(m2[j]>=process[i])
			{
				memory=m2[j];
				m2[j]=m2[j]-process[i];
				org=memory_chunks[j];
				break;
			}
		}
		if(memory!=0)
			cout<<i+1<<"\t"<<process[i]<<"\t"<<memory<<"\t\t\t"<<org<<endl;
		else
			cout<<i+1<<"\t"<<process[i]<<"\tNo allocation"<<endl;
	}
}
void Allocation::bestFit()
{
	for(int i=0;i<Mno;i++)
	{
		m2[i]=memory_chunks[i];
	}
	int temp1;
	int temp2;
	cout<<"Process\tsize\tmemory chunk\toriginal size\n";
	for(int i=0;i<no;i++)
	{
		for(int i=1;i<Mno;i++)
		{
			for(int j=0;j<Mno-1;j++)
			{
				if(m2[j]>m2[j+1])
				{
					temp1=m2[j];
					temp2=memory_chunks[j];
					memory_chunks[j]=memory_chunks[j+1];
					m2[j]=m2[j+1];
					m2[j+1]=temp1;
					memory_chunks[j+1]=temp2;
				}
			}
			//cout<<m2[i];
		}
		memory=0;
		for(int j=0;j<Mno;j++)
		{
			if(m2[j]>=process[i])
			{
				memory=m2[j];
				m2[j]=m2[j]-process[i];
				org=memory_chunks[j];
				break;
			}
		}
		if(memory!=0)
			cout<<i+1<<"\t"<<process[i]<<"\t"<<memory<<"\t\t\t"<<org<<endl;
		else
			cout<<i+1<<"\t"<<process[i]<<"\tNo allocation"<<endl;
	}
}
void Allocation::worstFit()
{
	for(int i=0;i<Mno;i++)
	{
		m2[i]=memory_chunks[i];
	}
	int temp1;
	int temp2;
	cout<<"Process\tsize\tmemory chunk\toriginal size\n";
	for(int i=0;i<no;i++)
	{
		for(int i=1;i<Mno;i++)
		{
			for(int j=0;j<Mno-1;j++)
			{
				if(m2[j]<m2[j+1])
				{
					temp1=m2[j];
					temp2=memory_chunks[j];
					memory_chunks[j]=memory_chunks[j+1];
					m2[j]=m2[j+1];
					m2[j+1]=temp1;
					memory_chunks[j+1]=temp2;
				}
			}
			//cout<<m2[i];
		}
		memory=0;
		for(int j=0;j<Mno;j++)
		{
			if(m2[j]>=process[i])
			{
				memory=m2[j];
				m2[j]=m2[j]-process[i];
				org=memory_chunks[j];
				break;
			}
		}
		if(memory!=0)
			cout<<i+1<<"\t"<<process[i]<<"\t"<<memory<<"\t\t\t"<<org<<endl;
		else
			cout<<i+1<<"\t"<<process[i]<<"\tNo allocation"<<endl;
	}
}
int main()
{
	Allocation a;
	a.input();
	cout<<"Allocate memory\n";
	int choice,on;
	do{
		cout<<"Enter your choice\n";
		cout<<"1.First Fit\n";
		cout<<"2.Best Fit\n";
		cout<<"3.Worst Fit\n";
		cin>>choice;
		switch(choice)
		{
			case 1:{cout<<"Allocation by First Fit\n";
				a.firstFit();
				break;
			}
			case 2:{cout<<"Allocation by Best Fit\n";
				a.bestFit();
				break;
			}
			case 3:{cout<<"Allocation by Worst Fit\n";
				a.worstFit();
				break;
			}
			default:cout<<"Invalid Choice\n";
		}
		cout<<"To Continue, Press 1 : ";
		cin>>on;
	}while(on==1);
	return 0;
}
