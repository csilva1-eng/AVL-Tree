#include<iostream>
#include "captureInput.h"
#include "AVL.h"


int main()
{
	captureInput runner;

	runner.setRunXTimes();

	runner.getInstructions();

	runner.determineInstructions();

	return 0;
}
