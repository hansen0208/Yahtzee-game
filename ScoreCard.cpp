#include "ScoreCard.h"
#include <algorithm>
#include <numeric>
using namespace std;

// calculating sum of dices of same number (e.g. 22345, then sum of 2 is 4)
int ScoreCard::sumOfNumber(const vector<int> &dice, int number) {
    return count(dice.begin(), dice.end(), number) * number;
}

// calculating sum of all dice number (e.g. 22345, them sum is 2+2+3+4+5 = 16)
int ScoreCard::sumAllDice(const vector<int> &dice) {
    return accumulate(dice.begin(), dice.end(), 0);
}

// count sum of all dice numbers when reaching 3 or 4 of a kind
int ScoreCard::countOfAKind(const vector<int> &dice, int n) {
    for (int i = 1; i <= 6; i++) {
        if (count(dice.begin(), dice.end(), i) >= n) {
            return sumAllDice(dice);
        }
    }
    return 0;
}

// bool check Full house by checking if the 5 dices has 2 and 3 identical numbers
bool ScoreCard::isFullHouse(const vector<int> &dice) {
    bool hasTwo = false, hasThree = false;
    for (int i = 1; i <= 6; i++) {
        int num = count(dice.begin(), dice.end(), i);
        if (num == 2) hasTwo = true;
        if (num == 3) hasThree = true;
    }
    if (hasTwo && hasThree){
        return true;
    }
}

// bool check if 4 or 5 numbers form a straight by sorting the dice by a vector, then compare each entry to check if they differ by 1 to see if it's a straight
bool ScoreCard::isStraight(const vector<int> &dice, int n) {
    vector<int> sorted = dice;
    sort(sorted.begin(), sorted.end());
    sorted.erase(unique(sorted.begin(), sorted.end()), sorted.end());
    
    if (sorted.size() < n) return false;
    
    for (size_t i = 0; i <= sorted.size() - n; i++) {
        if (sorted[i+n-1] - sorted[i] == n-1) {
            return true;
        }
    }
    return false;
}

// check if all dices are of the same number
bool ScoreCard::isYahtzee(const vector<int> &dice) {
    return all_of(dice.begin(), dice.end(), [&](int i){return i == dice[0];});
}

// calculate score function use different if statements to show different sceanrios and return corresponding store with the aforementioned int and bool function
int ScoreCard::calculateScore(const vector<int> &dice, const string &category) {
    if (category == "Ones") return sumOfNumber(dice, 1);
    if (category == "Twos") return sumOfNumber(dice, 2);
    if (category == "Threes") return sumOfNumber(dice, 3);
    if (category == "Fours") return sumOfNumber(dice, 4);
    if (category == "Fives") return sumOfNumber(dice, 5);
    if (category == "Sixes") return sumOfNumber(dice, 6);
    if (category == "Three of a Kind") return countOfAKind(dice, 3);
    if (category == "Four of a Kind") return countOfAKind(dice, 4);
    if (category == "Full House") return isFullHouse(dice) ? 25 : 0;
    if (category == "Small Straight") return isStraight(dice, 4) ? 30 : 0;
    if (category == "Large Straight") return isStraight(dice, 5) ? 40 : 0;
    if (category == "Yahtzee") return isYahtzee(dice) ? 50 : 0;
    if (category == "Chance") return sumAllDice(dice);
    return 0;
}

// check which categories are used and keep the remaining categories as available for player to choose
void ScoreCard::getAvailableCategories(const vector<string> &categories, const vector<bool> &usedCategories, vector<string> &available) {
    available.clear();
    for (size_t i = 0; i < categories.size(); i++) {
        if (!usedCategories[i]) {
            available.push_back(categories[i]);
        }
    }
}