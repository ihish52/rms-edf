#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

int numTask;
string temp;
vector <int> priority;
int superP;
int misses = 0;

int getLcm(vector <int> _periods);
vector <int> getPriority(vector <int> _periods);

vector <int> deadlines;

int main()
{
	//open file stream to read input file
	ifstream inFile;
	inFile.open("input.txt");
	inFile >> temp >> numTask;
	cout << "\n\nNumber of Tasks: " << numTask << "\n";
	
	//initialise variables to store periods and execution times
	vector <int> exTimes;
	vector <int> periods;
	int exTime, period;
	
	//store periods and execution times
	for (int i = 0; i < numTask; i++)
	{
		inFile >> temp >> exTime >> period;
		exTimes.push_back(exTime);
		periods.push_back(period);
	}
	
	//get Super Period and priorities
	superP = getLcm(periods);
	priority = getPriority(periods);
	cout << "Super Period: " << superP << "\n\n";
	
	//for (auto x : priority) cout << x << " ";
	//cout << "\n";
	
	//variable to keep track of current task time
	vector <int > taskTimes = exTimes;
	
	vector <int> deadlines = periods;
	vector <int> timeToDdl = periods;
	
	//opening output file stream to write
	ofstream outfile;
	outfile.open("output_edf.txt");
	
	cout << "-----------------------------\n";
	outfile << "-----------------------------\n";
	
//////////////////edf code imlpementation/////////////////////////////
	
	for (int timeStep = 0; timeStep <= superP; timeStep++)
	{
		
		timeToDdl = deadlines;
		for (int d = 0; d < timeToDdl.size(); d++)
		{	
			if ((timeToDdl[d] - timeStep) != 0)
			{
				timeToDdl[d] -= timeStep;
			} 
			else timeToDdl[d] = periods[d];
		} 
		priority = getPriority(timeToDdl);
		
		for (int i = 0; i < periods.size(); i++)
		{
			//check for misses
			if (timeStep % periods[i] == 0 && taskTimes[i] != 0 && timeStep != 0)
			{
				misses += 1;
				
				cout << timeStep;
				cout << " Task " << i+1 << " Misses\n";
				
				outfile << timeStep;
				outfile << " Task " << i+1 << " Misses\n";
				
			}
			if (timeStep % periods[i] == 0 && timeStep != 0)
			{
				taskTimes[i] = exTimes[i];
				deadlines[i] += periods[i];
			}
			
		}
		
		//exiting loop after checking misses for last time step
		if (timeStep == superP) break;
		
		for (auto x : priority)
		{
			//compute execution of tasks
			if (taskTimes[x] != 0)
			{
				taskTimes[x] -= 1;
				cout << timeStep;
				cout << " Task " << x+1 << " Executes\n";
				
				outfile << timeStep;
				outfile << " Task " << x+1 << " Executes\n";
				
				//check if a task has been completed
				if (taskTimes[x] == 0)
				{
					cout << timeStep;
					cout << " Task " << x+1 << " Completes\n";
					
					outfile << timeStep;
					outfile << " Task " << x+1 << " Completes\n";
				}
				
				break;
			}
			
		}
			
	}
	
	cout << "-----------------------------\n\n";
	cout << "Scheduling Finishes\n\n";
	cout << "Total Deadline Misses: " << misses << "\n\n\n";
	
	outfile << "-----------------------------\n";
	outfile << "Total Deadline Misses: " << misses << "\n";
	
	//close output file
	outfile.close();
	
	
	return 0;
	
	
}

//function to calculate priority of tasks
vector<int> getPriority(vector <int> _periods)
{
	vector <int> pPriority = _periods;
	vector <int> priority;
	vector <int> indList;

	sort(pPriority.begin(), pPriority.end());

	for (int i = 0; i < pPriority.size(); i++)
	{	
		for (int j = 0; j < pPriority.size(); j++)
		{
			if (pPriority[i] == _periods[j] && count(indList.begin(), indList.end(), j) == 0)
			{
				priority.push_back(j);
				indList.push_back(j);
				break;
			}
		}	
	}
		
	//for (auto x : priority) cout << x << " ";
	//cout << "\n";
	
	return priority;
}

//function to calculate LCM for Super Period
int getLcm(vector <int> _periods)
{
	int lcm = _periods[0];
	int zeroFlag = 0;
	
	for (int i = 0; i < _periods.size(); i++)
	{
		if (_periods[i+1] > lcm) lcm = _periods[i+1];
		if ( _periods.size() == i + 1) break;
	}	
	
	while(1) {
		for (int i = 0; i < _periods.size(); i++)
		{
			if (lcm%_periods[i] != 0)
			{
				zeroFlag = 1;
				break;
			}
		}
		if (zeroFlag == 1)
		{
			lcm++;
			zeroFlag = 0;
		}
		else break;
   }
   
   return lcm;
}
