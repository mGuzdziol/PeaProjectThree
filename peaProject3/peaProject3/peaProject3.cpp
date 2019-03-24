// peaProject3.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include "pch.h"
#include <iostream>
#include<vector>
#include <iostream>
#include "Population.h"
#include "ReadFile.h"
#include <string>
#include "Selection.h"
#include "Crossover.h"

int main()
{
	int numberOfCities;
	int **edges;
	int opt = 0;
	//int stop = 400;
	//int choice = 1;
	int populationSize=300;
	int minCost = INT32_MAX;
	int *shortestPath;
	int bestInThisGen=0;

	std::string fileName = "Brak wczytanego pliku!";

	ReadFile file;
	std::cout << "Podaj nazwe pliku: "; std::cin >> fileName;
	edges = file.openFile(numberOfCities, opt, fileName);
	shortestPath = new int[numberOfCities - 1];

	Population population(populationSize, numberOfCities);
	Selection selection;
	Crossover crossover;

	population.initPopulation();

	while (true) {
		selection.computeAdaptation(population, numberOfCities, edges, minCost, shortestPath,bestInThisGen);
		selection.roulette(population);
		crossover.pmx(population, numberOfCities, selection, bestInThisGen);
		crossover.mutation(population, numberOfCities, selection);
	}
	selection.computeAdaptation(population, numberOfCities, edges, minCost, shortestPath, bestInThisGen);

	cout << minCost;

	//for (int i = 0; i < numberOfCities; i++) {
	//	for (int j = 0; j < numberOfCities; j++) {
	//		std::cout << edges[i][j];
	//		std::cout << " ";
	//	}
	//	std::cout << "\n";
	//}
	//std::cout << "\n";
}

