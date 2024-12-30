#include <iostream>
#include <cstdlib> // Für system("pause") oder andere Systembefehle
#include <ctime> // Für Zufallszahlengenerierung

int main() {
    std::srand(static_cast<unsigned>(std::time(nullptr))); // Seed für Zufallszahl

    int randomNumber = std::rand() % 100 + 1; // Zufallszahl zwischen 1 und 100
    int guess = 0;
    int attempts = 0;

    std::cout << "Willkommen zum Zahlenratespiel!" << std::endl;
    std::cout << "Ich habe mir eine Zahl zwischen 1 und 100 ausgedacht. Versuchen Sie, sie zu erraten!" << std::endl;

    do {
        std::cout << "Geben Sie Ihre Vermutung ein: ";
        std::cin >> guess;
        attempts++;

        if (guess < randomNumber) {
            std::cout << "Zu niedrig! Versuchen Sie es erneut." << std::endl;
        } else if (guess > randomNumber) {
            std::cout << "Zu hoch! Versuchen Sie es erneut." << std::endl;
        } else {
            std::cout << "Glückwunsch! Sie haben die Zahl " << randomNumber << " in " << attempts << " Versuchen erraten." << std::endl;
        }
    } while (guess != randomNumber);

    std::cout << "Drücken Sie die Eingabetaste, um das Programm zu beenden...";
    std::cin.ignore(); // Ignoriert eventuelle Reste im Eingabepuffer
    std::cin.get(); // Wartet auf Enter-Taste

    return 0;
}
