#ifndef SCORECARD_H
#define SCORECARD_H

#include <vector>
#include <string>

using namespace std;

// create a ScoreCard class to store all the functions used to calculate score and determine what available categories the dice form

class ScoreCard {
public:
    static int calculateScore(const vector<int> &dice, const string &category);
    static void getAvailableCategories(const vector<string> &categories, const vector<bool> &usedCategories, vector<string> &available);
    
private:
    static int sumOfNumber(const vector<int>& dice, int number);
    static int sumAllDice(const vector<int>& dice);
    static int countOfAKind(const vector<int>& dice, int n);
    static bool isFullHouse(const vector<int>& dice);
    static bool isStraight(const vector<int>& dice, int n);
    static bool isYahtzee(const vector<int>& dice);
};

#endif