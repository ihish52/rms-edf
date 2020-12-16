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

int getLcm(vector <int> _periods);
vector <int> getPriority(vector <int> _periods);

int main()
{
	
	ifstream inFile;
	inFile.open("input1.txt");
	inFile >> temp >> numTask;
	//cout << numTask << "\n";
	
	vector <int> exTimes;
	vector <int> periods;
	int exTime, period;
	
	for (int i = 0; i < numTask; i++)
	{
		inFile >> temp >> exTime >> period;
		exTimes.push_back(exTime);
		periods.push_back(period);
	}
	//cout << getLcm (periods) << "\n";
	superP = getLcm(periods);
	priority = getPriority(periods);
	cout << superP << "\n";
	for (auto x : priority) cout << x << " ";
	cout << "\n";
	
	vector <int > taskTimes = exTimes;
	//vector <int> periodTimes = periods;
	//int timeStep = 0;
	
	cout << "-----------------------------\n";
	
	for (int timeStep = 0; timeStep < superP; timeStep++)
	{
		
		for (int i = 0; i < periods.size(); i++)
		{
			if (timeStep % periods[i] == 0 && taskTimes[i] != 0 && timeStep != 0)
			{
				cout << timeStep;
				cout << " Task " << i+1 << " Misses\n";
			}
			if (timeStep % periods[i] == 0 && timeStep != 0)
			{
				//cout << "HERE\n";
				taskTimes[i] = exTimes[i];
				//cout<< " Task " << i << " Completes\n";
			}
			
		}
		
		for (auto x : priority)
		{
			if (taskTimes[x] != 0)
			{
				taskTimes[x] -= 1;
				cout << timeStep;
				cout << " Task " << x+1 << " Executes\n";
				
				
				if (taskTimes[x] == 0)
				{
					cout << timeStep;
					cout << " Task " << x+1 << " Completes\n";
				}
				
				break;
			}
			
		}
		
		
		
		
		/*cout << "\n";
		for (auto x : taskTimes) cout << x << " ";
		cout << "\n";*/
		
		
		/*for (int i = 0; i < taskTimes.size(); i++)
		{
			if (taskTimes[i] == 0)
			{
				cout << timeStep;
				cout << " Task " << i+1 << " Completes\n";
			}
		}*/
		
		
	}
	
	cout << "-----------------------------\n";
	
	
	
	
	return 0;
	
}

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
