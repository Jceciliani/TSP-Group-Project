/************************************
* CS 325
* Final Project
* Joshua Louis Ceciliani - the man
* Jeremy Einhorn - the myth
* Michael Johnson - the legend
************************************/

#include <cstdlib>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <climits>
#include <ctime>
#include <math.h>

using std::cout;
using std::cin;
using std::endl;
using std::ifstream;
using std::ofstream;
using std::string;
using std::istringstream;
using std::vector;

struct Cities
{
	int city;
	int x;
	int y;
};

int calculate(vector<struct Cities>&, int, int);
void distance(vector<int>&, vector<struct Cities>&);
void aroundTheWorld(vector<int>&, vector<int>&, int&, int);
bool visited(vector<int>&, int);

//Calculate distance between cities
int calculate(vector<struct Cities>& city, int city1, int city2)
{
	double distance = sqrt(pow(city[city2].x - city[city1].x, 2) + pow(city[city2].y - city[city1].y, 2));

	int rounded = round(distance);

	return rounded;
}

// Distance between all cities
void distance(vector<int>& distancesCities, vector<struct Cities>& city)
{
	int min = INT_MAX,
		x;
	for (size_t i = 0; i < city.size(); i++)
	{
		for (size_t j = 0; j < city.size(); j++)
		{
			int dist = calculate(city, i, j);
			distancesCities.push_back(dist);
		}
	}
}

bool visited(vector<int>& visit, int city)
{
	for (int i = 0; i < visit.size(); i++)
	{
		if (visit[i] == city)
			return true;
	}
	return false;
}

// Take a tour around the cities
void aroundTheWorld(vector<int>& visit, vector<int>& distances, int& dist, int totalCities)
{
	int start = 12;
	if (totalCities < start)
	{
		start = 0;
	}

	visit.push_back(start);

	while (visit.size() < totalCities)
	{
		int minNum = INT_MAX;
		int i = -1;

		for (int j = 0; j < totalCities; j++)
		{
			if (distances[start * totalCities + j] < minNum && !visited(visit, j))
			{
				minNum = distances[start * totalCities + j];
				i = j;
			}
		}

		dist += minNum;
		visit.push_back(i);
		start = i;
	}
}

int main()
{
	ifstream		 inputFile;			//create input file object
	ofstream         outputFile;
	string			 fileName,
				     str;
	int              count = 0,
					 dist = 0;
	vector<Cities>   citiesList;
	vector<int>      adjMatrix;
	vector<int>      visited;

	cout << "What file do you want to read from?" << endl;
	getline(cin, fileName);

	srand(size_t(time(NULL)));
	clock_t t1,
		t2;

	t1 = clock();						//start time

	//open the file
	cout << "Opening input file." << endl;
	inputFile.open(fileName);

	//if it doesn't open, close the program
	if (!inputFile)
	{
		cout << "File open error!" << endl;
		cin.get();
		return 0;
	}

	while (getline(inputFile, str, '\n'))
	{
		citiesList.push_back(Cities());
		istringstream num(str);
		num >> citiesList[count].city;
		num >> citiesList[count].x;
		num >> citiesList[count].y;
		count++;
	}

	distance(adjMatrix, citiesList);

	aroundTheWorld(visited, adjMatrix, dist, citiesList.size());

	dist += adjMatrix[visited[visited.size() - 1] * citiesList.size() + visited[0]];

	cout << "Opening output file." << endl;
	outputFile.open(fileName + ".tour");

	//if it doesn't open, close the program
	if (!outputFile)
	{
		cout << "File open error!" << endl;
		cin.get();
		return 0;
	}

	outputFile << dist << endl;
	for (size_t i = 0; i < visited.size(); i++)
	{
		outputFile << visited[i] << endl;
	}

	//close the output file
	outputFile.close();

	cout << "File closed." << endl;

	t2 = clock();									//stop time

	double time((double)t2 - (double)t1);		//total time
	double totalTime = time / CLOCKS_PER_SEC;		//total time in seconds
	cout << "seconds: " << totalTime << endl;

	return 0;
}
