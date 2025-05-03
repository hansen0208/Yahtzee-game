#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <map>
#include <iomanip>

using namespace std;
//create Player class, define parameters & functions
class Player {
private:
    string name;
    map<string, int> scores;
    bool upperBonus;
    bool difficulty; // if true then it chooses hard mode, if false then it chooses easy mode
    
public:
    static const string categories[13];
    
    Player(const string& playerName, bool isHard);
    
    void addScore(const string& category, int score);
    int getScore(const string& category) const;
    int getTotalScore() const;
    bool hasUsedCategory(const string& category) const;
    void printScoreCard() const;
    const string& getName() const;
    bool getDifficulty() const { return difficulty; }
};

//Declaring functions of adding the score, recording the score, recording the total score, marking the used catgeory, printing the scorecard, getting the name of player and recieving the difficulty

#endif