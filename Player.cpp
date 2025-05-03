#include "Player.h"
#include <iostream>
#include <iomanip>

const string Player::categories[13] = {
    "Ones", "Twos", "Threes", "Fours", "Fives", "Sixes",
    "Three of a Kind", "Four of a Kind", "Full House",
    "Small Straight", "Large Straight", "Yahtzee", "Chance"
};
// This array contains the different kinds of categories

Player::Player(const string& playerName, bool isHard) 
    : name(playerName), upperBonus(false), difficulty(isHard) {
    for (const auto& category : categories) {
        scores[category] = -1; // -1 means not scored yet
    }
}
//add new player with the parameters

void Player::addScore(const string& category, int score) {
    scores[category] = score;
    
    // Check for upper section bonus
    if (!upperBonus) {
        int upperTotal = 0;
        for (int i = 0; i < 6; i++) {
            if (scores.at(categories[i]) != -1) {
                upperTotal += scores.at(categories[i]);
            }
        }
        if (upperTotal >= 63) {
            upperBonus = true;
        }
    }
}
//This function records the score for the specified category in the score map
//If the bonus section has not been rewarded, it calculates the total score across first 6 categories. If total is 63 higher, it sets the UpperBonus flag to true

int Player::getScore(const string& category) const {
    auto it = scores.find(category);
    return (it != scores.end()) ? it->second : -1;
}
///get player's score in specified category

int Player::getTotalScore() const {
    int total = 0;
    for (const auto& pair : scores) {
        if (pair.second != -1) {
            total += pair.second;
        }
    }
    if (upperBonus) {
        total += 35;
    }
    return total;
}
///get player's total score

bool Player::hasUsedCategory(const string& category) const {
    return scores.at(category) != -1;
}
//Determine which category is used or not
//make the -1 in the score a boolean for convenient calculation

void Player::printScoreCard() const {
    cout << "\nScore Card for " << name << ":\n";
    cout << "---------------------------------\n";
    
    // Upper section
    cout << "Upper Section:\n";
    for (int i = 0; i < 6; i++) {
        cout << setw(15) << left << categories[i] << ": ";
        if (scores.at(categories[i]) != -1) {
            cout << scores.at(categories[i]);
        } else {
            cout << "-";
        }
        cout << endl;
    }
    
    // Upper bonus
    cout << setw(15) << left << "Upper Bonus" << ": ";
    cout << (upperBonus ? "35" : "0") << endl;
    
    // Lower section
    cout << "\nLower Section:\n";
    for (int i = 6; i < 13; i++) {
        cout << setw(15) << left << categories[i] << ": ";
        if (scores.at(categories[i]) != -1) {
            cout << scores.at(categories[i]);
        } else {
            cout << "-";
        }
        cout << endl;
    }
    
    cout << "---------------------------------\n";
    cout << setw(15) << left << "TOTAL SCORE" << ": " << getTotalScore() << endl;
}
//print the scorecard


const string& Player::getName() const {
    return name;
}
//Get the name of the player announcing the winner