#ifndef DICE_H
#define DICE_H
#include <vector>
#include <random>

using namespace std;


//create class Dice and define the parameter of dice, so as the functions
class Dice {
private:

    vector<int> dice;
    vector<bool> hold;
    mt19937 gen;


public:
    Dice();
    void roll();
    void toggleHold(int index);
    bool isHeld(int index) const;
    const vector<int>& getDice() const;
    void resetHolds();
    void printDice() const;
};

#endif