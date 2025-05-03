# Team Member
 - 3036395853 Mak Ka Po
 - 3036386539 Leung Yat Long
 - 3036293378 Kwok Chun Hei
 - 3036392813 Ng Sze Hon
 - 3036386553 Tsang Yat Long

# DEMO Video
https://youtu.be/H9dTp_mkFE0
 - Feature: User Interface, Easy&Hard Mode, Game Flow, Error Message for Invalid Input, How to start the game.

# Yahtzee Game in C++

## Description
A text-based implementation of the classic Yahtzee dice game for 1-4 players, featuring 'Easy' and 'Hard' difficulty and complete scoring rules. Players roll dice to achieve specific combinations and compete for the highest score over 13 rounds.

## Features Implemented

### Core Features
- **Random Event Generation**:
  - Dice rolls using <random> library
  - Fair probability distribution for all dice values

- **Data Structures**:
  - map for score tracking (category → score)
  - vector for dice management and category lists
  - Custom `Player` and `Dice` classes for game state

- **Memory Management**:
  - Automatic RAII for all resources
  - STL containers handle dynamic allocation

- **Multi-file Architecture**:
  - Separation of concerns across 4 header/implementation pairs:
    - main.cpp - Game flow
    - Player.h/cpp - Player state and scoring
    - Dice.h/cpp - Dice rolling mechanics
    - ScoreCard.h/cpp - Scoring logic

### Gameplay Features
- **Multiple Difficulty Levels**:
  - **Easy Mode**: 
    - 2 re-rolls per turn
    - Shows potential scores before category selection
  - **Hard Mode**:
    - 1 re-roll per turn
    - No score previews
    - Requires memorization of scoring rules

- **Complete Yahtzee Rules**:
  - All standard categories (Upper/Lower sections)
  - 35-point bonus for ≥63 in Upper Section
  - Yahtzee bonuses (not implemented in base version)

## Libraries Used
| Library | Purpose | Feature Supported |
|---------|---------|-------------------|
| `<iostream>` | Input/output | Game interface |
| `<vector>` | Dynamic arrays | Dice storage, category lists |
| `<map>` | Key-value storage | Score tracking |
| `<random>` | Random number generation | Dice rolls |
| `<iomanip>` | Output formatting | Scorecard display |
| `<string>` | String handling | Player names, categories |
| `<limits>` | Input validation | Preventing crashes |

## Game Instructions

### Setup
1. Compile with: bash
   run the following code to create executable 'yahtzee'
   use cd to find access the file Yahtzee on your computer
   g++ main.cpp Player.cpp Dice.cpp ScoreCard.cpp -o yahtzee

2. Run with ./yahtzee

YAHTZEE GAME INSTRUCTIONS
=========================

1. STARTING THE GAME
--------------------
- Compile and run the game
- Enter number of players (1-4)
- Enter player names
- Select difficulty level:
  * Easy (Enter 1): 2 re-rolls, see potential scores
  * Hard (Enter 2): 1 re-roll, no score previews

2. TURN STRUCTURE
-----------------
Each turn has 3 phases:
1. First roll (automatic)
2. Re-roll phase (0-2 times)
3. Category selection

## Re-roll phase
---------------
After initial roll, you can:
- HOLD dice to keep them
- RE-ROLL unheld dice
- SKIP to score directly

Dice Control Commands:
----------------------
[1-5]    - Toggle hold on die 1-5
          (Held dice show with (H) marker)
[0]      - Stop holding dice (proceed to score)
[-1]     - Execute re-roll with current holds
[Enter]  - Confirm final selection

Example Turn:
-------------
1. First roll: 3 5 1 4 2
2a. Want to keep the 5 and 4 then reroll:
   - Enter '2' then press Enter (holds the 2nd die: 5)
   - Enter '4' then press Enter (holds the 4thdie: 4)
   - Screen shows: 3 5(H) 1 4(H) 2
   - Enter '-1' then press Enter
   - New roll (only dice 1,3,5 change): 6 5(H) 2 4(H) 1
2b. Want to score directly since it is a Large Straight:
   - Enter '0' then press Enter (proceed to score)

3. SCORING
----------
After final roll:
- Available categories are listed
- In EASY mode, potential scores are shown
- Enter the NUMBER of your chosen category

Scoring Tips:
- Upper Section (1-6): Sum of specific numbers
- Three/Four of a Kind: Sum of all dice if you have 3/4 matching
- Full House: 25 pts (3+2 of different numbers)
- Straights: 
  - Small (30 pts): 4 consecutive numbers
  - Large (40 pts): 5 consecutive numbers
- Yahtzee: 50 pts (all 5 dice same)
- Chance: Sum of all dice

5. WINNING
---------
- Game lasts 13 rounds (1 per category)
- Highest total score wins
- 35-point bonus if Upper Section total ≥63

6. QUITTING
[Ctrl-C] to exit the game at any time.
