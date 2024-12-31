#include <iostream>
#include <cstdlib>
#include <ctime>

class NumberGuessGame {
private:
    int targetNumber;
    int maxTries;
    int currentTries;

public:
    NumberGuessGame(int maxNumber = 100, int maxAttempts = 10) {
        // Seed the random number generator and set the target number
        std::srand(static_cast<unsigned>(std::time(0)));
        targetNumber = std::rand() % maxNumber + 1;
        maxTries = maxAttempts;
        currentTries = 0;
    }

    void play() {
        std::cout << "Welcome to the Number Guessing Game!\n";
        std::cout << "I have selected a number between 1 and " << (targetNumber > 100 ? "100" : std::to_string(targetNumber)) << ".\n";
        std::cout << "You have " << maxTries << " attempts to guess it. Good luck!\n\n";

        while (currentTries < maxTries) {
            int guess;
            std::cout << "Enter your guess: ";
            std::cin >> guess;

            currentTries++;

            if (guess == targetNumber) {
                std::cout << "Congratulations! You guessed the number in " << currentTries << " tries.\n";
                return;
            } else if (guess < targetNumber) {
                std::cout << "Too low! Try again.\n";
            } else {
                std::cout << "Too high! Try again.\n";
            }

            if (currentTries == maxTries) {
                std::cout << "Sorry, you've used all your attempts. The number was " << targetNumber << ".\n";
                return;
            }

            std::cout << "Attempts remaining: " << (maxTries - currentTries) << "\n";
        }
    }
};

int main() {
    NumberGuessGame game(100, 10);
    game.play();
    return 0;
}
