#include "pch.h"
#include "Crossover.h"
#include <ctime>
#include <iostream>
#include <vector>
#include <random> 
#include <cmath>

Crossover::Crossover()
{
}

void Crossover::pmx(Population& population, int numberOfCities, Selection& selection, int bestInThisGen)
{
		//vector<int> tmp;
	int c = 0;

	for (int y = 0; y < population.populationSize; y=y+2) {
		

		vector<int> cutPoint(2);
		vector<int> parents;

	/*	for (int i = 0; i < population.populationSize; i++)
		{
			tmp.push_back(i);
		}

		srand(unsigned(time(NULL)));
		random_shuffle(tmp.begin(), tmp.end());*/


///////////////////////////
	/*	int x = 0;
		while (x != population.populationSize - 2) {
			for (int i = 0; i < population.populationSize - 1; i = i + 2)
			{
				if (selection.selectedChromosomes.at(i) == selection.selectedChromosomes.at(i + 1))
				{
					srand(unsigned(time(NULL)));
					random_shuffle(selection.selectedChromosomes.begin(), selection.selectedChromosomes.end());
					break;
				}
				x = i;
			}
		}*/
/////////////////////////////


		do {
			abs(cutPoint.at(0) = rand() % (numberOfCities - 2) + 1);
			abs(cutPoint.at(1) = rand() % (numberOfCities - 2) + 1);
		} while (cutPoint.at(0) == cutPoint.at(1));

		//srand(unsigned(time(NULL)));
		//random_shuffle(selection.selectedChromosomes.begin(), selection.selectedChromosomes.end());

		for (int i = 0; i < 2; i++)
		{
			parents.push_back(selection.selectedChromosomes.at(c));
			c++;
			//selection.selectedChromosomes.erase(selection.selectedChromosomes.begin() + 0);
		}
	
		if (cutPoint.at(0) > cutPoint.at(1))
		{
			int tmp;
			tmp = cutPoint.at(0);
			cutPoint.at(0) = cutPoint.at(1);
			cutPoint.at(1) = tmp;
		}

		/*	srand(time(NULL));
			int ran = 1 + rand() % 100;
			if (ran < 90)
			{*/

				for (int i = cutPoint.at(0); i < cutPoint.at(1); i++)
				{
					population.childChromosomes[y][i] = population.parentChromosomes[parents.at(0)][i];
					population.childChromosomes[y + 1][i] = population.parentChromosomes[parents.at(1)][i];

				}

				for (int i = cutPoint.at(0); i < cutPoint.at(1); i++)
				{
					bool ifFound = false;

					for (int j = 0; j < numberOfCities - 1; j++) {
						if (population.parentChromosomes[parents.at(1)][i] == population.childChromosomes[y][j])
						{
							ifFound = true;
							break;
						}
					}
					if (ifFound == false)
					{
						int tmp = population.parentChromosomes[parents.at(0)][i];
						bool end = false;
						while (end == false)
						{
							for (int z = 0; z < numberOfCities - 1; z++)
							{
								if (population.parentChromosomes[parents.at(1)][z] == tmp)
								{
									if (z < cutPoint.at(0) || z >= cutPoint.at(1))
									{
										population.childChromosomes[y][z] = population.parentChromosomes[parents.at(1)][i];
										end = true;
									}
									else
										tmp = population.parentChromosomes[parents.at(0)][z];
									break;
								}
							}
						}
					}
				}

				for (int i = cutPoint.at(0); i < cutPoint.at(1); i++)
				{
					bool ifFound = false;

					for (int j = 0; j < numberOfCities - 1; j++) {
						if (population.parentChromosomes[parents.at(0)][i] == population.childChromosomes[y + 1][j])
						{
							ifFound = true;
							break;
						}
					}
					if (ifFound == false)
					{
						int tmp = population.parentChromosomes[parents.at(1)][i];
						bool end = false;
						while (end == false)
						{
							for (int z = 0; z < numberOfCities - 1; z++)
							{
								if (population.parentChromosomes[parents.at(0)][z] == tmp)
								{
									if (z < cutPoint.at(0) || z >= cutPoint.at(1))
									{
										population.childChromosomes[y + 1][z] = population.parentChromosomes[parents.at(0)][i];
										end = true;
									}
									else
										tmp = population.parentChromosomes[parents.at(1)][z];
									break;
								}
							}
						}
					}
				}

				for (int i = 0; i < numberOfCities - 1; i++)
				{
					if (population.childChromosomes[y][i] == -1)
					{
						population.childChromosomes[y][i] = population.parentChromosomes[parents.at(1)][i];
					}

					if (population.childChromosomes[y + 1][i] == -1)
					{
						population.childChromosomes[y + 1][i] = population.parentChromosomes[parents.at(0)][i];
					}
				}
			/*}
			else
			{
				for (int i = 0; i < numberOfCities - 1; i++)
				{
						population.childChromosomes[y][i] = population.parentChromosomes[parents.at(1)][i];
						population.childChromosomes[y + 1][i] = population.parentChromosomes[parents.at(0)][i];
				}
			}*/
	}

	for (int i = 0; i < population.populationSize; i++)
	{
		for (int j = 0; j < numberOfCities - 1; j++)
		{
			//if(i!=bestInThisGen)
			population.parentChromosomes[i][j]= population.childChromosomes[i][j];
			population.childChromosomes[i][j] = -1;
			//cout << population.parentChromosomes[i][j]<< " ";
		}
		//cout << "\n";
	}
	//cout << "\n\n\n";

	//for (int i = 0; i < population.populationSize; i++)
	//{
	//	for (int j = 0; j < numberOfCities - 1; j++)
	//	{
	//		cout<< population.parentChromosomes[i][j] << "  ";
	//	}
	//	cout << "\n";
	//}
	//cout << "\n\n\n";
}

void Crossover::mutation(Population & population, int numberOfCities, Selection & selection)
{

	srand(time(NULL));
	for (int i = 0; i < population.populationSize; i++)
	{
		
		int ran = 1 + rand() % 100;
		if (ran <= 80)
		{
			
			int x, y;
			do {
				abs(x = rand() % (numberOfCities - 1) + 0);
				abs(y = rand() % (numberOfCities - 1) + 0);
			} while (x == y);

			if (x > y)
			{
				int tmp;
				tmp = x;
				x = y;
				y = tmp;
			}

			//for (int j = 0; j < numberOfCities - 1; j++)
			//{
			//	cout << population.parentChromosomes[i][j] << "  ";
			//}
			//cout << "\n";

			int *tmp=new int[y-x];
			int cnt = 0;
			for (int j = x; j < y; j++)
			{
					tmp[cnt] = population.parentChromosomes[i][j];
					cnt++;
			}

			cnt = 0;

			for (int j = y-1; j >= x; j--)
			{
				population.parentChromosomes[i][j]=tmp[cnt];
				cnt++;
			}

		/*	for (int j = 0; j < numberOfCities - 1; j++)
			{
				cout << population.parentChromosomes[i][j] << "  ";
			}
			cout << "\n\n";*/

			/*int tmp = population.parentChromosomes[i][x];
			population.parentChromosomes[i][x] = population.parentChromosomes[i][y];
			population.parentChromosomes[i][y] = tmp;*/
			
		}
	}

	//for (int i = 0; i < population.populationSize; i++)
	//{
	//	for (int j = 0; j < numberOfCities - 1; j++)
	//	{
	//		cout << population.parentChromosomes[i][j] << "  ";
	//	}
	//	cout << "\n";
	//}
	//cout << "\n\n\n";
}


Crossover::~Crossover()
{
}
