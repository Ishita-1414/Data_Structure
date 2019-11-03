#include<iostream>
//#include<conio.h>
using namespace std;
struct Process
{
	int burst_time;
	int waiting_time;
	int arrival_time;
	int priority;
	int turnaround;
	char name;
}*Sc;
class sch
{
	int pr;
	float totT,tw;
	public:
		void input();
		void fcfs();
		void sjf();
		void srtf();
		void RR();
		void priority();
		void pre_prio();
		void sort_at();
		void sort_bt();
		void sort_p();
};
void sch::sort_at()
{
	Process temp;
	for(int i=1;i<pr;i++)
	{
		for(int j=0;j<pr-1;j++)
		{
			if(Sc[j].arrival_time>Sc[j+1].arrival_time)
			{
				temp=Sc[j];
				Sc[j]=Sc[j+1];
				Sc[j+1]=temp;
			}
		}
	}
}
void sch::sort_bt()
{
	Process temp;
	for(int i=1;i<pr;i++)
	{
		for(int j=0;j<pr-1;j++)
		{
			if(Sc[j].burst_time>Sc[j+1].burst_time)
			{
				temp=Sc[j];
				Sc[j]=Sc[j+1];
				Sc[j+1]=temp;
			}
		}
	}
}
void sch::sort_p()
{
	Process temp;
	for(int i=1;i<pr;i++)
	{
		for(int j=0;j<pr-1;j++)
		{
			if(Sc[j].priority>Sc[j+1].priority)
			{
				temp=Sc[j];
				Sc[j]=Sc[j+1];
				Sc[j+1]=temp;
			}
		}
	}
}
void sch::input()
{
	cout<<"Enter no. of processes : ";
	cin>>pr;
	Sc=new struct Process[pr];
	cout<<"Enter names of processes: "<<endl;
	for(int i=0;i<pr;i++)
		cin>>Sc[i].name;
	cout<<"Enter burst time of processes: "<<endl;
	for(int i=0;i<pr;i++)
		cin>>Sc[i].burst_time;
	

	totT=0;
	tw=0;
}
void sch::fcfs()
{
	cout<<"Enter arrival time of processes: "<<endl;
	for(int i=0;i<pr;i++)
		cin>>Sc[i].arrival_time;
	sort_at();
	Sc[0].turnaround=Sc[0].burst_time;
	Sc[0].waiting_time=Sc[0].arrival_time;
	int com_time=Sc[0].burst_time+Sc[0].arrival_time;
	totT=Sc[0].turnaround;
	for(int i=1;i<pr;i++)
	{
		com_time=com_time+Sc[i].burst_time;
		Sc[i].turnaround=com_time-Sc[i].arrival_time;
		//totT+=tt[i];
		totT+=Sc[i].turnaround;
		Sc[i].waiting_time=Sc[i].turnaround-Sc[i].burst_time;
		tw+=Sc[i].waiting_time;
	}
	cout<<"process\tbt\tat\ttt\twt"<<endl;
	for(int i=0;i<pr;i++)
	{
		cout<<Sc[i].name<<"\t"<<Sc[i].burst_time<<"\t"<<Sc[i].arrival_time<<"\t"<<Sc[i].turnaround<<"\t"<<Sc[i].waiting_time<<endl;
	}
	cout<<"Average turn around time= "<<totT/pr<<endl;
	cout<<"Average waiting time= "<<tw/pr<<endl;
}
void sch::sjf()
{
	sort_bt();
	Sc[0].turnaround=Sc[0].burst_time;
	Sc[0].waiting_time=0;
	totT=Sc[0].turnaround;
	for(int i=1;i<pr;i++)
	{
		//totT+=Sc[i].burst_time;
		Sc[i].turnaround=Sc[i-1].turnaround+Sc[i].burst_time;
		totT+=Sc[i].turnaround;
		Sc[i].waiting_time=Sc[i].turnaround-Sc[i].burst_time;
		tw+=Sc[i].waiting_time;
	}
	cout<<"process\tbt\ttt\twt"<<endl;
	for(int i=0;i<pr;i++)
	{
		cout<<Sc[i].name<<"\t"<<Sc[i].burst_time<<"\t"<<Sc[i].turnaround<<"\t"<<Sc[i].waiting_time<<endl;
	}
	cout<<"Average turn around time= "<<totT/pr<<endl;
	cout<<"Average waiting time= "<<tw/pr<<endl;
}
void sch::srtf()
{
	int rt[pr];
	for(int i=0;i<pr;i++)
		rt[i]=Sc[i].burst_time;
	cout<<"Enter arrival time of processes: "<<endl;
	for(int i=0;i<pr;i++)
		cin>>Sc[i].arrival_time;
	int count=pr,t=0,minm=9999;
	int i=0,comp_t;
	bool check=false;
	while(count>0)
	{
		for(int j=0;j<pr;j++)
		{
			if((Sc[j].arrival_time<=t)&&(rt[j]<minm)&&rt[j]>0)
			{
				minm=rt[j];
				i=j;
				check=true;
			}
		}
		if(check==false)
		{
			t++;
			continue;
		}
		rt[i]--;
		minm=rt[i];
		if(rt[i]==0)
		{
			count--;
			minm=9999;
			comp_t=t+1;
			Sc[i].waiting_time=comp_t-Sc[i].burst_time-Sc[i].arrival_time;
		}
		t++;
	}
	for(int i=0;i<pr;i++)
	{
		Sc[i].turnaround=Sc[i].waiting_time+Sc[i].burst_time;
		totT+=Sc[i].turnaround;
		tw+=Sc[i].waiting_time;
	}
	cout<<"process\tbt\tat\ttt\twt"<<endl;
	for(int i=0;i<pr;i++)
	{
		cout<<Sc[i].name<<"\t"<<Sc[i].burst_time<<"\t"<<Sc[i].arrival_time<<"\t"<<Sc[i].turnaround<<"\t"<<Sc[i].waiting_time<<endl;
	}
	cout<<"Average turn around time= "<<totT/pr<<endl;
	cout<<"Average waiting time= "<<tw/pr<<endl;
}
void sch::RR()
{
	int quantum;
	int rem_time[pr];
	for(int i=0;i<pr;i++)
		rem_time[i]=Sc[i].burst_time;
	cout<<"Enter the time Quantum : ";
	cin>>quantum;
	int count=0;
	int t=0;
	while(count>0)
	{
		for(int i=0;i<pr;i++)
		{
			if(rem_time[i]>0)
			{
				if(rem_time[i]>quantum)
				{
					t+=quantum;
					rem_time[i]-=quantum;
				}else
				{
					t=t+rem_time[i];
					Sc[i].waiting_time=t-Sc[i].burst_time;
					rem_time[i]=0;
					count--;
				}
			}
		}
	}
	for(int i=0;i<pr;i++)
	{
		Sc[i].turnaround=Sc[i].waiting_time+Sc[i].burst_time;
		totT+=Sc[i].turnaround;
		tw+=Sc[i].waiting_time;
	}
	cout<<"process\tbt\ttt\twt"<<endl;
	for(int i=0;i<pr;i++)
	{
		cout<<Sc[i].name<<"\t"<<Sc[i].burst_time<<"\t"<<Sc[i].turnaround<<"\t"<<Sc[i].waiting_time<<endl;
	}
	cout<<"Average turn around time= "<<totT/pr<<endl;
	cout<<"Average waiting time= "<<tw/pr<<endl;
}
void sch::priority()
{
	cout<<"Enter priority of processes: "<<endl;
	for(int i=0;i<pr;i++)
		cin>>Sc[i].priority;
	sort_p();
	Sc[0].turnaround=Sc[0].burst_time;
	Sc[0].waiting_time=0;
	totT=Sc[0].turnaround;
	for(int i=1;i<pr;i++)
	{
		
		Sc[i].turnaround=Sc[i-1].turnaround+Sc[i].burst_time;
		//totT+=tt[i];
		Sc[i].waiting_time=Sc[i].turnaround-Sc[i].burst_time;
		tw+=Sc[i].waiting_time;
		totT+=Sc[i].turnaround;
	}
	cout<<"process\tbt\tpriority\ttt\twt"<<endl;
	for(int i=0;i<pr;i++)
	{
		cout<<Sc[i].name<<"\t"<<Sc[i].burst_time<<"\t\t"<<Sc[i].priority<<"\t"<<Sc[i].turnaround<<"\t"<<Sc[i].waiting_time<<endl;
	}
	cout<<"Average turn around time= "<<totT/pr<<endl;
	cout<<"Average waiting time= "<<tw/pr<<endl;
}
void sch::pre_prio()
{
	int rt[pr];
	for(int i=0;i<pr;i++)
		rt[i]=Sc[i].burst_time;
	cout<<"Enter priority of processes: "<<endl;
	for(int i=0;i<pr;i++)
		cin>>Sc[i].priority;
	cout<<"Enter arrival time of processes: "<<endl;
	for(int i=0;i<pr;i++)
		cin>>Sc[i].arrival_time;
	int rem_bt[pr];
	for(int i=0;i<pr;i++)
		rem_bt[i]=Sc[i].burst_time;
	int count=pr,t=0,minm=9999;
	int i=0,comp_t;
	bool check=false;
	while(count>0)
	{
		sort_p();
		for(int j=0;j<pr;j++)
		{
			if((Sc[j].arrival_time<=t)&&(rem_bt[j]<minm)&&rem_bt[j]>0)
			{
				minm=rt[j];
				i=j;
				check=true;
			}
		}
		if(check==false)
		{
			t++;
			continue;
		}
		rem_bt[i]--;
		minm=rem_bt[i];
		if(rt[i]==0)
		{
			count--;
			minm=9999;
			comp_t=t+1;
			Sc[i].waiting_time=comp_t-Sc[i].burst_time-Sc[i].arrival_time;
		}
		t++;
	}
	for(int i=0;i<pr;i++)
	{
		Sc[i].turnaround=Sc[i].waiting_time+Sc[i].burst_time;
		totT+=Sc[i].turnaround;
		tw+=Sc[i].waiting_time;
	}
	cout<<"process\tbt\tat\ttt\twt"<<endl;
	for(int i=0;i<pr;i++)
	{
		cout<<Sc[i].name<<"\t"<<Sc[i].burst_time<<"\t"<<Sc[i].arrival_time<<"\t"<<Sc[i].turnaround<<"\t"<<Sc[i].waiting_time<<endl;
	}
	cout<<"Average turn around time= "<<totT/pr<<endl;
	cout<<"Average waiting time= "<<tw/pr<<endl;
}
int main()
{
	sch S;
	int choice,on;
	cout<<"Scheduling Processes\n";
	do{
		cout<<"Enter Your Choice\n";
		cout<<"1.FCFS\n";
		cout<<"2.SJF\n";
		cout<<"3.SRTF\n";
		cout<<"4.Non-Preamptive Priority based Scheduling\n";
		cout<<"5.Preamptive Priority based Scheduling\n";
		cout<<"6.Round Robin\n";
		cin>>choice;
		switch(choice)
		{
			case 1:{S.input();
				S.fcfs();
				break;
			}
			case 2:{S.input();
				S.sjf();
				break;
			}
			case 3:{S.input();
				S.srtf();
				break;
			}
			case 4:{S.input();
				S.priority();
				break;
			}
			case 5:{S.input();
				S.pre_prio();
				break;
			}
			case 6:{S.input();
				S.RR();
				break;
			}
			default:cout<<"Invalid Choice\n";
		}
		cout<<"To Continue, Press 1: ";
		cin>>on;
	}while(on==1);
	return 0;
}
