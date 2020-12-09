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
