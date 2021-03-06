#include <iostream>
#include <vector>

using namespace std;

int main(){
	int i,n,time,remain,temps=0,time_quantum;
	int wt=0,tat=0;
	cout<<"Enter the total number of process = ";
	cin>>n;
	remain=n;
	vector<int>at(n);
	vector<int>bt(n);
	vector<int>rt(n);
	cout<<"Enter the Arrival time, Burst time for All the processes"<<endl;

	for(i=0;i<n;i++)
	{
		cin>>at[i];
		cin>>bt[i];
		rt[i]=bt[i];
	}

	cout<<"Enter the value of time QUANTUM : ";
	cin>>time_quantum;

	cout<<"\nProcess\t:\tTurnaround Time\t:\tWaiting Time\n";

	for(time=0,i=0;remain!=0;)
	{
		if(rt[i]<=time_quantum && rt[i]>0)
		{
			time += rt[i];
			rt[i]=0;
			temps=1;
		}
		else if(rt[i]>0)
		{
			rt[i] -= time_quantum;
			time += time_quantum;
		}

		if(rt[i]==0 && temps==1)
		{
			remain--;
			cout<<"Process"<< i+1 << "\t"<<":"<<"\t"<<time-at[i]<<"\t:\t"<<time-at[i]-bt[i]<<endl;
			wt += time-at[i]-bt[i];
			tat += time-at[i];
			temps=0;
		}
		if(i == n-1)
			i=0;
		else if(at[i+1] <= time)
			i++;
		else
			i=0;
	}

	cout<<"Average waiting time "<<wt*1.0/n<<endl;
	cout<<"Average turn around time "<<tat*1.0/n;
	cout<<endl;

	return 0;
}
