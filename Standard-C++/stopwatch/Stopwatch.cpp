#include <iostream>
#include <chrono>
#include <thread>

using namespace std;

int main() {
    cout << "Timer/Stoppuhr startet..." << endl;
    cout << "Drücke 'Enter' um zu starten und 'Enter' zu drücken um zu stoppen." << endl;
    cin.get();  // Warten auf die Eingabe des Benutzers (Start des Timers)

    // Startzeit erfassen
    auto start = chrono::high_resolution_clock::now();

    cout << "Timer läuft... Drücke 'Enter' um zu stoppen." << endl;
    cin.get();  // Warten auf die Eingabe des Benutzers (Stoppen des Timers)

    // Endzeit erfassen
    auto end = chrono::high_resolution_clock::now();

    // Berechne die verstrichene Zeit
    chrono::duration<double> duration = end - start;

    // Zeige die verstrichene Zeit in Sekunden an
    cout << "Verstrichene Zeit: " << duration.count() << " Sekunden" << endl;

    return 0;
}
