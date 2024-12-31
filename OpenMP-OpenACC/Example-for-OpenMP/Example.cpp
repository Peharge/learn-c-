#include <iostream>
#include <omp.h>

int main() {
    const int N = 1000000;
    int arr[N];
    int sum = 0;

    // Initialisiere das Array mit Werten
    for (int i = 0; i < N; i++) {
        arr[i] = 1;  // Einfaches Array mit 1en
    }

    // Parallele Berechnung der Summe mit OpenMP
#pragma omp parallel for reduction(+:sum)
    for (int i = 0; i < N; i++) {
        sum += arr[i];
    }

    // Ausgabe der berechneten Summe
    std::cout << "Summe des Arrays: " << sum << std::endl;

    return 0;
}
