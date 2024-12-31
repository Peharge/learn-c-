#include <iostream>
#include <cuda_runtime.h>

// CUDA Kernel Funktion für die Vektoraddition
__global__ void addVectors(int* A, int* B, int* C, int N) {
    // Berechne die globalen Thread-IDs
    int index = threadIdx.x + blockIdx.x * blockDim.x;

    // Sicherstellen, dass der Thread innerhalb des Arraybereichs liegt
    if (index < N) {
        C[index] = A[index] + B[index];
    }
}

int main() {
    // Größe des Vektors
    int N = 100000;
    size_t size = N * sizeof(int);

    // Host-Vektoren
    int* h_A = new int[N];
    int* h_B = new int[N];
    int* h_C = new int[N];

    // Füllen der Vektoren A und B mit Werten
    for (int i = 0; i < N; i++) {
        h_A[i] = i;
        h_B[i] = i * 2;
    }

    // Device-Vektoren
    int *d_A, *d_B, *d_C;

    // Allokation des Speichers auf der GPU
    cudaMalloc(&d_A, size);
    cudaMalloc(&d_B, size);
    cudaMalloc(&d_C, size);

    // Kopieren der Daten von der Host- zur Device-Seite
    cudaMemcpy(d_A, h_A, size, cudaMemcpyHostToDevice);
    cudaMemcpy(d_B, h_B, size, cudaMemcpyHostToDevice);

    // Kernel-Start: Jeder Thread berechnet ein Element
    int threadsPerBlock = 256;
    int blocksPerGrid = (N + threadsPerBlock - 1) / threadsPerBlock;
    addVectors<<<blocksPerGrid, threadsPerBlock>>>(d_A, d_B, d_C, N);

    // Fehlerüberprüfung nach dem Kernel-Launch
    cudaError_t err = cudaGetLastError();
    if (err != cudaSuccess) {
        std::cerr << "CUDA Fehler: " << cudaGetErrorString(err) << std::endl;
    }

    // Kopiere das Ergebnis von der Device- zur Host-Seite
    cudaMemcpy(h_C, d_C, size, cudaMemcpyDeviceToHost);

    // Ausgabe der ersten 10 Ergebnisse
    for (int i = 0; i < 10; i++) {
        std::cout << "h_A[" << i << "] + h_B[" << i << "] = h_C[" << i << "] = " << h_C[i] << std::endl;
    }

    // Speicher freigeben
    delete[] h_A;
    delete[] h_B;
    delete[] h_C;
    cudaFree(d_A);
    cudaFree(d_B);
    cudaFree(d_C);

    return 0;
}
