#include "Location.h"
#include "Item.h"
#include "Enemy.h"
#include "GameWorld.h"
#include "Puzzle.h"
#include "NPC.h"
#include <iostream>
#include <string>

using namespace std;

int main() {
    // Initialize the game world
    initializeGameWorld();

    string current_location = "entrance_hall";

    // Introduction
    cout << "Welcome to the Cavern of Shadows. Your quest is to find the legendary treasure hidden deep within." << endl;

    while (true) {
        describeLocation(current_location);
        string command;
        cin >> command;

        // Handle commands
        if (command == "go") {
            string direction;
            cin >> direction;
            move(direction, current_location);
        }
        else if (command == "take") {
            string item_name;
            cin >> item_name;
            takeItem(item_name, current_location);
        }
        else if (command == "attack") {
            string enemy_name;
            cin >> enemy_name;
            combat(enemy_name);
        }
        else if (command == "solve") {
            string puzzle_name;
            cin >> puzzle_name;
            solvePuzzle(puzzle_name);
        }
        else if (command == "talk") {
            string npc_name;
            cin >> npc_name;
            interactNPC(npc_name);
        }
        else {
            cout << "Invalid command." << endl;
        }

        // Check if the player has reached the Treasure Room
        if (current_location == "treasure_room") {
            cout << "Congratulations! You have found the legendary treasure!" << endl;
            break; // End the game
        }
    }

    return 0;
}
