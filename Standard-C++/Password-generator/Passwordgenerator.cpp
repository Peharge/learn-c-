#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

string generatePassword(int length) {
    // Mögliche Zeichen für das Passwort
    const string characters = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789!@#$%^&*()-_=+[]{}|;:,.<>?";

    string password = "";

    // Initialisieren des Zufallsgenerators
    srand(time(0));

    for (int i = 0; i < length; ++i) {
        // Zufälliges Zeichen aus der Liste auswählen
        int randomIndex = rand() % characters.length();
        password += characters[randomIndex];
    }

    return password;
}

int main() {
    int passwordLength;

    cout << "Geben Sie die gewünschte Länge des Passworts ein: ";
    cin >> passwordLength;

    string password = generatePassword(passwordLength);

    cout << "Generiertes Passwort: " << password << endl;

    return 0;
}
