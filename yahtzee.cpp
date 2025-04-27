#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

// Global Variables Array
int freedice = 5;
int dice[5];
int finaldice[5];

// Roll Function
void roll(int freedice){
    if (freedice != 0){
        for (int i = 0 ; i < 5; i++){
            if (finaldice[i]==0){
                dice[i] = rand() % 6 + 1;
            } else{
                dice[i] = finaldice[i];
            }
        
        }
    }
}

// Print Function
void print(){
    for (int i = 0; i < 5; i++){
        cout << char(65+i) << " " << dice[i] << endl;
    }
}

// Keep Function

void keep(string letters, int freedice){
    char letterbox[5] = {0};
    bool validInput = true;
    int numberofletters = (letters.length() + 1)/2;
    for (int i = 0; i < letters.length(); i++){
        if (int(letters[i]) == 65){
            letterbox[0] = char(letters[i]);
            validInput = true;
            freedice--; 
        } else if (int(letters[i]) == 66){
            letterbox[1] = char(letters[i]);
            validInput = true;
            freedice--;  
        } else if (int(letters[i]) == 67){
            letterbox[2] = char(letters[i]);
            validInput = true;
            freedice--; 
        } else if (int(letters[i]) == 68){
            letterbox[3] = char(letters[i]);
            validInput = true;
            freedice--; 
        } else if (int(letters[i]) == 69){
            letterbox[4] = char(letters[i]);
            validInput = true;
            freedice--; 
        } else{validInput = false;}
    }

    if (validInput == true){
        cout << "Valid input." << endl;
    } else{
        cout << "Invalid input. Please re-enter." << endl;
    }
    
    for (int i = 0; i < 5; i++){
        if (letterbox[i]!=0){
            finaldice[int(letterbox[i]-65)] = dice[int(letterbox[i]-65)];
        }
    }
    cout << finaldice[0] << " " << finaldice[1] << " " << finaldice[2] << " " << finaldice[3] << " " << finaldice[4] << endl;
}

void PointSystem(){
    int point = 0;
    int basepoint = 0;
    int kindpoint = 0;
    // Base point
    for (int i = 0; i < 5; i++){
        basepoint += finaldice[i];
    }

    // 2, 3 & 4 of a kind
    int freq[7] = {0};
    for (int i = 0; i < 5; i++){
        freq[finaldice[i]]++;
    }
    int maxCount = 0;
    int maxValue = 0;
    for (int i = 1; i <= 6; i++){
        maxCount = freq[i];
        maxValue = i;
    }
    if (maxCount == 2){
        
    }
}

// Main Function

int main(){
    srand(time(NULL));
    int numberofrolls;
    bool difficultyChosen = false;
    cout << "Choose Difficulty:" << endl;
    cout << "Easy" << endl;
    cout << "Medium" << endl;
    cout << "Hard" << endl;
    string difficulty;
    getline(cin, difficulty);
    while (!difficultyChosen){
        if (difficulty=="Easy"){
            numberofrolls = 4;
            difficultyChosen = true;
        }else if (difficulty=="Medium"){
             numberofrolls = 3;
             difficultyChosen = true;
        }else if (difficulty=="Hard"){
            numberofrolls = 2;
            difficultyChosen = true;
        }else{
            cout << "No difficulty chosen. Please choose again.";
        }
    }

    cout << "For roll / re-roll, type \"Roll\"." << endl;
    cout << "To keep certain dices, type the letter \"A\", \"B\", \"C\", \"D\" or \"E\", seperated by spaces." << endl;
    bool gameEnd = false;
        
    while (!gameEnd){
        string command;
        getline(cin, command);
        if (command=="Roll"){
            roll(freedice);
            print();
            numberofrolls--;
            if (numberofrolls == 0){
                    cout << "You are out of rolls!" << endl;
                    for (int i = 0; i < 5; i++){
                        finaldice[i] = dice[i];
                    }
                    cout << finaldice[0] << " " << finaldice[1] << " " << finaldice[2] << " " << finaldice[3] << " " << finaldice[4] << endl;
                    gameEnd = true;
            }
        } else if (command == "-1"){
            break;
        } else {
            keep(command, freedice);
            cout << endl;
        }
    
    }
    return 0;  
}
    


    

