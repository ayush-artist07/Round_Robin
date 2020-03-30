//Sudesh is a linux expert who wants to have an online system where he can handle student queries.
// Since there can be multiple request at any time he wishes to dedicate a fixed amount of time
// to every request so that every one gets fair share of his time.
// He will log into the system from 10.00 am to 12.00 am only. 
// He wants to have separate request queues for students and faculty. 
// The summary at the end of the session should include the total time 
// he spent on handling queries and a average query time 


#include<iostream> 
using namespace std; 

void time_constraint(int hh,int mm,int total_burst)
{
	if(hh<10 && hh>=12)
	{
		cout<<"Inappropriate Time"<<endl;
		exit(0);
	}
	else if(mm>60)
	{
		cout<<"Inappropriate Time"<<endl;
		exit(0);
	}
	else if(12<(hh+(mm+total_burst)/60))
	{
		cout<<"No of queries should be reduced else some of them will be half executed \nas total burst time goes beyond the time I am free"<<endl;
		cout<<"Run the Programm Again";
		exit(0);
	}
	else
	{
		cout<<endl;
		cout<<"\t\t\t\t\t\tWelcome"<<endl;
	}
}


void findWaitingTime(int processes[], int n, 
			int bt[], int wt[], int quantum) 
{ 
	 
	int rem_bt[n]; 
	for (int i = 0 ; i < n ; i++) 
		rem_bt[i] = bt[i]; 

	int t = 0; 
 
	while (1) 
	{ 
		bool done = true; 
 
		for (int i = 0 ; i < n; i++) 
		{ 
			
			if (rem_bt[i] > 0) 
			{ 
				done = false; 

				if (rem_bt[i] > quantum) 
				{ 
					 
					t += quantum; 

					
					rem_bt[i] -= quantum; 
				} 

			
				else
				{ 
					
					t = t + rem_bt[i]; 

					 
					wt[i] = t - bt[i]; 

					 
					rem_bt[i] = 0; 
				} 
			} 
		} 

	 
		if (done == true) 
		break; 
	} 
} 

 
void findTurnAroundTime(int processes[], int n, 
						int bt[], int wt[], int tat[]) 
{ 
	
	for (int i = 0; i < n ; i++) 
		tat[i] = bt[i] + wt[i]; 
} 
 
void findavgTime(int processes[], int n, int bt[], 
									int quantum) 
{ 
	int wt[n], tat[n], total_wt = 0, total_tat = 0; 

	 
	findWaitingTime(processes, n, bt, wt, quantum); 

	
	findTurnAroundTime(processes, n, bt, wt, tat); 

	 
	cout << "Processes "<< " Burst time "
		<< " Waiting time " << " Turn around time\n"; 

	 
	for (int i=0; i<n; i++) 
	{ 
		total_wt = total_wt + wt[i]; 
		total_tat = total_tat + tat[i]; 
		cout << " " <<"P"<< i+1 << "\t\t" << bt[i] <<"\t "
			<< wt[i] <<"\t\t " << tat[i] <<endl; 
	} 

	cout << "Average waiting time = "
		<< (float)total_wt / (float)n; 
	cout << "\nAverage turn around time = "
		<< (float)total_tat / (float)n; 
}
void inst(){
	cout<<"\n\t\t\tWelcome, Please follow the instruction for proper functioning of the program"<<endl;
	cout<<"------------------------------------------------------------------------------------------------------------------------"<<endl;
	cout<<"INSTRUCTIONS:-";
	cout<<"\n-->Enter the time in 24 hours format.For example 10:30 am enter 10:30";
	cout<<"\n-->Enter the Queries in ascending order, i.e. one that comes first in real time should be first entered";
	cout<<"\n-->All Time units are in minutes. \n\n";
	cout<<"------------------------------------------------------------------------------------------------------------------------"<<endl;	
		}
	
int main() 
{	
	
	int siz_query,stu_fac,burst_time[siz_query],sum=0,h,m; 
	char c;
	
	inst();
	
	cout<<"Enter the time when the first query was reported:  ";
	cin>>h>>c>>m;
	time_constraint(h,m,sum);
	cout<<"Enter the number of processes: ";
	cin>>siz_query;
	cout<<endl;
 
	int processes[siz_query];
	for(int i=0;i<siz_query;i++)
	{
		cout<<"Select 1.Student 2.Faculty : ";
		cin>>stu_fac;
		cout<<"Enter the Burst Time of the Query:"<<i+1<<"  ";
		cin>>burst_time[i];
		sum=sum+burst_time[i];	
			}
			cout<<endl;
	int n = sizeof processes / sizeof processes[0];
	
 
	 
	int quantum;
	cout<<"Quantum Time for each Process ";
	cin>>quantum;
	cout<<endl;
	findavgTime(processes, n, burst_time, quantum);
	cout<<endl;
	cout<<"Total Time Spent = "<<sum;
	return 0; 
} 

