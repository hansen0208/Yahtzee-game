#include <iostream>
#include <vector>
#include <string>
#include <limits>
#include "Player.h"
#include "Dice.h"
#include "ScoreCard.h"


using namespace std;

///display the instructions
void displayWelcome() {
    cout << "Welcome to Yahtzee!\n";
    cout << "===================\n\n";
    cout << "Rules:\n";
    cout << "- Each player gets 13 turns to fill their score card\n";
    cout << "- Choose difficulty at start (affects re-rolls and score visibility)\n\n";
}


enum Difficulty { EASY, HARD };


///take input 1 or 2, then set the difficulty of easy or hard. invalid input will be warned and input is asked again
Difficulty selectDifficulty() {

    int choice;
    while (true) {
        cout << "Select difficulty:\n";
        cout << "1. Easy (2 re-rolls, see potential scores)\n";
        cout << "2. Hard (1 re-roll, no score preview)\n";
        cout << "Choice: ";
        cin >> choice;
        


        if (cin.fail() || (choice != 1 && choice != 2)) {
        
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter 1 or 2.\n";
        
        } else {
        
            break;
        
        
        }
    
    }
    return (choice == 1) ? EASY : HARD;
}

///take input 1~4, the function set the number of players. invalid input will be warned and input is asked again
int getNumberOfPlayers() {
    int numPlayers;


    while (true) {
    
        cout << "Enter number of players (1-4): ";
        cin >> numPlayers;
        if (cin.fail() || numPlayers < 1 || numPlayers > 4) {

            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter a number between 1 and 4.\n";
        
        } else {
            break;
        
        
        }
    }
    
    return numPlayers;
}


///take the current dice state and calculate the potential score before the score is selected. built for easy mode.
void showPotentialScores(const vector<string>& availableCategories, const vector<int>& dice) {
    cout << "\nPotential scores:\n";

    for (const auto& category : availableCategories) {
        int score = ScoreCard::calculateScore(dice, category);
        cout << "- " << setw(15) << left << category << ": " << score << endl;
    
    }
}


/// contribute to each turn of the game. takes input to 1:toggle holdness of each dice, 2:select to re-roll or skip roll to score, 3: to select category to score
void playerTurn(Player& player, Dice& dice) {

    cout << "\n" << player.getName() << "'s turn:\n";
    dice.resetHolds();
    
    int rollsLeft = (player.getDifficulty() == EASY) ? 2 : 1;
    
    // initial roll
    dice.roll();
    dice.printDice();
    


    // re-roll phase
    while (rollsLeft > 0) {
        cout << "\n" << rollsLeft << " re-roll(s) left.\n";
        cout << "Enter dice to hold (1-5, 0 to stop holding, -1 to re-roll): ";
        
        int choice;
        cin >> choice;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter a number.\n";
            continue;
        }
        
        if (choice == -1) {
            dice.roll();
            dice.printDice();
            rollsLeft--;
        }else if(choice == 0) {
            break;
        }else if(choice >= 1 && choice <= 5) {
            dice.toggleHold(choice - 1);
            dice.printDice();
        }else{
            cout << "Invalid choice. Please enter 1-5, 0, or -1.\n";
        }


    }
    
    // Scoring phase
    vector<string> availableCategories;
    vector<bool> usedCategories;
    

    for (const auto& category : Player::categories) {
        usedCategories.push_back(player.hasUsedCategory(category));
    }
    
    ScoreCard::getAvailableCategories(vector<string>(Player::categories, Player::categories + 13), usedCategories, availableCategories);
    


    if (player.getDifficulty() == EASY) {
        showPotentialScores(availableCategories, dice.getDice());
    }


    
    cout << "\nAvailable categories:\n";
    for (size_t i = 0; i < availableCategories.size(); i++) {
    
        cout << (i+1) << ". " << availableCategories[i] << endl;
    
    }
    
    int categoryChoice;

    //take category number, if wrong then take input again.
    while (true) {
        cout << "Choose a category to score (1-" << availableCategories.size() << "): ";
        cin >> categoryChoice;
        
        if (cin.fail() || categoryChoice < 1 || categoryChoice > static_cast<int>(availableCategories.size())) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid choice. Please try again.\n";
        } else {
            break;
        }
    }
    
    const string& chosenCategory = availableCategories[categoryChoice - 1];
    int score = ScoreCard::calculateScore(dice.getDice(), chosenCategory);
    
    player.addScore(chosenCategory, score);
    cout << "Scored " << score << " points in " << chosenCategory << " category.\n";
    player.printScoreCard();
}


///the main part
int main() {
    displayWelcome();
    
    Difficulty difficulty = selectDifficulty();
    int numPlayers = getNumberOfPlayers();
    
    vector<Player> players;

    ///input the name of the players, store them in players
    cin.ignore(); // Clear newline

    for (int i = 0; i < numPlayers; i++) {
        string name;

        cout << "Enter name for Player " << (i+1) << ": ";
    
        getline(cin, name);
        players.emplace_back(name, difficulty);
    
    
    }
    
    Dice dice;
    
    //main game loop of 13 rounds
    for (int round = 1; round <= 13; round++) {
        cout << "\n=== ROUND " << round << " ===\n";
        for (auto& player : players) {
            playerTurn(player, dice);
        }
    }
    
    //Game over and determine winner
    cout << "\n=== GAME OVER ===\n";
    cout << "Final Scores:\n";
    
    int highestScore = -1;
    vector<string> winners;
    

    for (const auto& player : players) {
    
        int score = player.getTotalScore();
        cout << player.getName() << ": " << score << endl;
        
        if (score > highestScore) {
            highestScore = score;
            winners.clear();
            winners.push_back(player.getName());
        } else if (score == highestScore) {
            winners.push_back(player.getName());
        }
    
    
    }
    
    if (winners.size() == 1) {

        cout << "\nThe winner is " << winners[0] << " with " << highestScore << " points!\n";

    } else {
        //draw between highest players
        cout << "\nIt's a tie between: ";

        for (size_t i = 0; i < winners.size(); i++) {
            if (i != 0) cout << ", ";
            cout << winners[i];

        }

        cout << " with " << highestScore << " points each!\n";
    }
    
    return 0;
}