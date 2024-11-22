#include "random.h"
#include <string>
#include <iostream>

std::string generateComputerChoice() {
    int randomNumber { Random::get(0, 2) };

    if (randomNumber == 0) {
        return "rock";
    } else if (randomNumber == 1) {
        return "paper";
    } else if (randomNumber == 2) {
        return "scissors";
    } else {
        return "unknown";
    }
}

void calculateWinner(std::string_view userChoice, std::string_view computerChoice) {
    if (userChoice == computerChoice) {
        std::cout << "It's a tie!" << "\n";
        return;
    };

    if ((userChoice == "rock" && computerChoice == "scissors") ||
        (userChoice == "paper" && computerChoice == "rock") ||
        (userChoice == "scissors" && computerChoice == "paper")) {
        std::cout << "You win!" << "\n";
    }
    
    if ((computerChoice == "rock" && userChoice == "scissors") ||
        (computerChoice == "paper" && userChoice == "rock") ||
        (computerChoice == "scissors" && userChoice == "paper")) {
        std::cout << "Computer wins!" << "\n";
    }
}

int main() {
    std::cout << "Let's play rock, paper, scissors!" << "\n";
    
    std::string userChoice {};
    do {
        std::cout << "Enter a valid choice: ";
        std::cin >> userChoice;
    } while (userChoice != "rock" && userChoice != "paper" && userChoice != "scissors");
    
    std::cout << "...deciding..." << "\n";
    
    std::string computerChoice { generateComputerChoice() };
    
    std::cout << "Computer chose " << computerChoice << "\n";
    
    calculateWinner(userChoice, computerChoice);
    
    return 0;
}
