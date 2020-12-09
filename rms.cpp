#include <iostream>
#include <string>
#include <fstream>
#include <vector>

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
	getPriority(periods);
	
	return 0;
	
}

vector<int> getPriority(vector <int> _periods)
{
	vector <int> priority;
	int currentNum = -1;
	int currentInd;
	int lastNum = -1;
	
	for (int k = 0; k < _periods.size(); k++)
	{
		for (int i = 0; i < _periods.size(); i++)
		{
			if (currentNum == -1 || (_periods[i] < currentNum && _periods[i] != lastNum))
			{
				currentNum = _periods[i];
				currentInd = i;
			}	
		}
		lastNum = currentNum;
		priority.push_back(currentInd);
	}
	
	cout << priority[0];
	cout << priority[1];
	cout << priority[2];
	cout << "\n";
	
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
