#pragma once
#include "UserWords.h"
#include <ctime>
#include <iostream>
using namespace std;

class Menu {

private:
	int attemptCounter = 0;
	int roundCounter = 1;

public:
    void setAttemptCounter();
    int getAttemptCounter();

    void setRoundCounter();
    int getRoundCounter();

    int showStartMenu();
    void showOutcome(bool checkUnderline);
    void showGameStatisticsMenu(string hiddenWord, UserWords& letters);
    int showRoundMenu();
};