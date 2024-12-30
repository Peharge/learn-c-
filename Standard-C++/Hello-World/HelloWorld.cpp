#include <iostream>
#include <cstdlib> // Für system("pause") oder andere Systembefehle

int main() {
    // Ausgabe von "Hello, World!"
    std::cout << "Hello, World!" << std::endl;

    // System-spezifische Möglichkeit, das Fenster offen zu halten
    // Option 1: Mit system("pause") (Standard auf Windows)
    // system("pause");

    // Option 2: Besser: Warten auf Benutzereingabe
    std::cout << "Drücken Sie die Eingabetaste, um das Programm zu beenden...";
    std::cin.get(); // Wartet auf Enter-Taste

    return 0;
}
