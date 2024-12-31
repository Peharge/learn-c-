#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

// Funktion zum Hinzufügen von Notizen
void addNote(const string& filename) {
    ofstream file(filename, ios::app); // Datei im Anhang-Modus öffnen
    if (!file.is_open()) {
        cout << "Fehler beim Öffnen der Datei!" << endl;
        return;
    }

    string note;
    cout << "Geben Sie Ihre Notiz ein (geben Sie 'END' ein, um zu beenden):" << endl;

    // Eingabe der Notiz
    while (true) {
        getline(cin, note);
        if (note == "END") {
            break;
        }
        file << note << endl;
    }

    file.close();
    cout << "Notiz gespeichert!" << endl;
}

// Funktion zum Anzeigen von Notizen
void viewNotes(const string& filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        cout << "Fehler beim Öffnen der Datei!" << endl;
        return;
    }

    string line;
    cout << "Ihre Notizen:" << endl;
    while (getline(file, line)) {
        cout << line << endl;
    }

    file.close();
}

// Funktion zum Bearbeiten von Notizen
void editNotes(const string& filename) {
    stringstream newContent;
    string line;

    // Alle aktuellen Notizen lesen
    ifstream file(filename);
    if (!file.is_open()) {
        cout << "Fehler beim Öffnen der Datei!" << endl;
        return;
    }

    cout << "Aktuelle Notizen:" << endl;
    while (getline(file, line)) {
        cout << line << endl;
        newContent << line << endl;
    }

    file.close();

    cout << "\nGeben Sie die neue Notiz ein, um die bestehende zu bearbeiten (geben Sie 'END' ein, um zu beenden):" << endl;

    // Neue Notiz eingeben
    ofstream file_out(filename, ios::trunc); // Datei im Schreibmodus (alte Datei überschreiben)
    if (!file_out.is_open()) {
        cout << "Fehler beim Öffnen der Datei zum Bearbeiten!" << endl;
        return;
    }

    while (true) {
        string newNote;
        getline(cin, newNote);
        if (newNote == "END") {
            break;
        }
        newContent << newNote << endl;
    }

    file_out << newContent.str(); // Neue Notizen speichern
    file_out.close();
    cout << "Notizen bearbeitet!" << endl;
}

int main() {
    string filename = "notizen.txt"; // Dateiname für Notizen
    int choice;

    while (true) {
        // Menü anzeigen
        cout << "\nNotizblock-Menü:" << endl;
        cout << "1. Notiz hinzufügen" << endl;
        cout << "2. Notizen anzeigen" << endl;
        cout << "3. Notizen bearbeiten" << endl;
        cout << "4. Beenden" << endl;
        cout << "Wählen Sie eine Option: ";
        cin >> choice;
        cin.ignore(); // Eingabepuffer leeren, um das 'Enter' nach Wahl zu entfernen

        switch (choice) {
            case 1:
                addNote(filename);
                break;
            case 2:
                viewNotes(filename);
                break;
            case 3:
                editNotes(filename);
                break;
            case 4:
                cout << "Programm beendet." << endl;
                return 0;
            default:
                cout << "Ungültige Wahl. Bitte versuchen Sie es erneut." << endl;
        }
    }

    return 0;
}
