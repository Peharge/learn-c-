#include <iostream>
#include <string>
using namespace std;

// Funktion zur Ausgabe der Frage und Überprüfung der Antwort
bool frageBeantworten(const string& frage, const string& richtigeAntwort) {
    string antwort;
    cout << frage << endl;
    cout << "Antwort: ";
    getline(cin, antwort);
    return (antwort == richtigeAntwort);
}

int main() {
    int punkte = 0;

    // Begrüßung
    cout << "Willkommen zum C++ Quiz!" << endl;
    cout << "Beantworte die folgenden Fragen:" << endl;

    // Fragen und Antworten
    if (frageBeantworten("Wie heißt der Erfinder von C++?", "Bjarne Stroustrup")) {
        cout << "Richtig!" << endl;
        punkte++;
    } else {
        cout << "Leider falsch. Die richtige Antwort ist: Bjarne Stroustrup" << endl;
    }

    if (frageBeantworten("Was ist die Standardbibliothek für Eingabe und Ausgabe in C++?", "iostream")) {
        cout << "Richtig!" << endl;
        punkte++;
    } else {
        cout << "Leider falsch. Die richtige Antwort ist: iostream" << endl;
    }

    if (frageBeantworten("Welches Schlüsselwort wird verwendet, um eine Variable zu deklarieren, die nicht verändert werden kann?", "const")) {
        cout << "Richtig!" << endl;
        punkte++;
    } else {
        cout << "Leider falsch. Die richtige Antwort ist: const" << endl;
    }

    if (frageBeantworten("Welche der folgenden Klassen wird in C++ verwendet, um dynamischen Speicher zu verwalten? \n A) vector \n B) array \n C) string \n D) malloc", "A")) {
        cout << "Richtig!" << endl;
        punkte++;
    } else {
        cout << "Leider falsch. Die richtige Antwort ist: A) vector" << endl;
    }

    // Ergebnis anzeigen
    cout << "Du hast " << punkte << " von 4 Punkten erreicht!" << endl;

    return 0;
}
