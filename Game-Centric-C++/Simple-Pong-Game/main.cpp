#include <iostream>
#include <conio.h>  // Für _kbhit() und _getch()
#include <windows.h> // Für Sleep()

using namespace std;

// Spielfeldgrößen
const int width = 40;
const int height = 20;

// Spielfeld
char field[height][width];

// Paddel Positionen
int leftPaddleY = height / 2 - 1;
int rightPaddleY = height / 2 - 1;
int ballX = width / 2;
int ballY = height / 2;
int ballDirX = -1;  // Ball bewegt sich nach links
int ballDirY = 1;   // Ball bewegt sich nach unten

// Punkte
int leftScore = 0;
int rightScore = 0;

// Funktionen zum Zeichnen des Spielfelds und der Spielobjekte
void Draw() {
    system("cls"); // Lösche die Konsole
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (j == 0 || j == width - 1) {
                field[i][j] = '|';  // Spielfeldränder
            } else if (i == 0 || i == height - 1) {
                field[i][j] = '-';  // Spielfeldober- und unterkante
            } else {
                field[i][j] = ' ';  // Leeres Feld
            }
        }
    }

    // Paddel zeichnen
    field[leftPaddleY][1] = '|';
    field[leftPaddleY + 1][1] = '|';
    field[leftPaddleY + 2][1] = '|';

    field[rightPaddleY][width - 2] = '|';
    field[rightPaddleY + 1][width - 2] = '|';
    field[rightPaddleY + 2][width - 2] = '|';

    // Ball zeichnen
    field[ballY][ballX] = 'O';

    // Punkte anzeigen
    for (int i = 0; i < width; i++) {
        cout << "-";
    }
    cout << "\n";
    cout << "Score: Left " << leftScore << " - Right " << rightScore << endl;

    // Spielfeld ausgeben
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            cout << field[i][j];
        }
        cout << endl;
    }
}

// Funktion zum Bewegen der Paddel
void Input() {
    if (_kbhit()) {
        char current = _getch();
        if (current == 'w' && leftPaddleY > 0) leftPaddleY--;  // Bewegung des linken Paddels nach oben
        if (current == 's' && leftPaddleY < height - 3) leftPaddleY++; // Bewegung des linken Paddels nach unten
        if (current == 'i' && rightPaddleY > 0) rightPaddleY--;  // Bewegung des rechten Paddels nach oben
        if (current == 'k' && rightPaddleY < height - 3) rightPaddleY++; // Bewegung des rechten Paddels nach unten
    }
}

// Funktion für die Ballbewegung und Kollisionserkennung
void Logic() {
    // Ballbewegung
    ballX += ballDirX;
    ballY += ballDirY;

    // Kollision mit den Wänden
    if (ballY == 0 || ballY == height - 1) {
        ballDirY = -ballDirY; // Ball prallt an der oberen oder unteren Wand ab
    }

    // Kollision mit den Paddeln
    if ((ballX == 2 && ballY >= leftPaddleY && ballY <= leftPaddleY + 2) ||
        (ballX == width - 3 && ballY >= rightPaddleY && ballY <= rightPaddleY + 2)) {
        ballDirX = -ballDirX; // Ball prallt an einem Paddel ab
    }

    // Wenn der Ball das Spielfeld verlässt, Punkte vergeben
    if (ballX == 0) {
        rightScore++; // Rechter Spieler erhält einen Punkt
        ballX = width / 2;
        ballY = height / 2;
        ballDirX = 1;
    }

    if (ballX == width - 1) {
        leftScore++; // Linker Spieler erhält einen Punkt
        ballX = width / 2;
        ballY = height / 2;
        ballDirX = -1;
    }
}

// Main-Spiel-Schleife
int main() {
    while (true) {
        Draw();
        Input();
        Logic();
        Sleep(50); // Geschwindigkeit der Schleife anpassen (ms)
    }

    return 0;
}
