#include <stdio.h>

#define MAX_EST 1000
#define N_ASIG 3
#define NOTA_APR 6.0

void pedirNotas(int nEst, float notas[][N_ASIG]);

int main() {
    int nEst;
    
    printf("=== GESTION DE CALIFICACIONES ===\n");
    printf("Ingrese el numero de estudiantes (max %d): ", MAX_EST);
    scanf("%d", &nEst);
    
    if (nEst <= 0 || nEst > MAX_EST) {
        printf("Error: El numero debe estar entre 1 y %d.\n", MAX_EST);
        return 1;
    }
    
    float notas[MAX_EST][N_ASIG];
    float promEst[MAX_EST];
    float promAsig[N_ASIG];
    float maxEst[MAX_EST];
    float minEst[MAX_EST];
    float maxAsig[N_ASIG];
    float minAsig[N_ASIG];
    int apr[N_ASIG];
    int rep[N_ASIG];
    
    pedirNotas(nEst, notas);
    
    return 0;
}

void pedirNotas(int nEst, float notas[][N_ASIG]) {
    for (int i = 0; i < nEst; i++) {
        printf("\n--- Estudiante %d ---\n", i + 1);
        for (int j = 0; j < N_ASIG; j++) {
            do {
                printf("Asignatura %d (0-10): ", j + 1);
                scanf("%f", &notas[i][j]);
                if (notas[i][j] < 0 || notas[i][j] > 10) {
                    printf("Error: Fuera de rango. Intente de nuevo.\n");
                }
            } while (notas[i][j] < 0 || notas[i][j] > 10);
        }
    }
}