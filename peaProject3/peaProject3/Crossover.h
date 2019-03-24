#pragma once
#include "Population.h"
#include "Selection.h"
class Crossover
{
public:

	Crossover();

	void pmx(Population& population,int numberOfCities,Selection& selection, int bestInThisGen);
	void mutation(Population& population, int numberOfCities, Selection& selection);
	~Crossover();
};

