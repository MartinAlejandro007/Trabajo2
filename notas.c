#include <stdio.h>

#define MAX_EST 1000
#define N_ASIG 3
#define NOTA_APR 6.0

void pedirNotas(int nEst, float notas[][N_ASIG]);
void calcularPromediosEstudiante(int nEst, float notas[][N_ASIG], float promEst[]);
void calcularPromediosAsignatura(int nEst, float notas[][N_ASIG], float promAsig[]);

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
    calcularPromediosEstudiante(nEst, notas, promEst);
    calcularPromediosAsignatura(nEst, notas, promAsig);
    
    printf("\n=== PROMEDIOS ===\n");
    printf("\n-- Por Estudiante --\n");
    for (int i = 0; i < nEst; i++) {
        printf("Estudiante %d: %.2f\n", i + 1, promEst[i]);
    }
    printf("\n-- Por Asignatura --\n");
    for (int j = 0; j < N_ASIG; j++) {
        printf("Asignatura %d: %.2f\n", j + 1, promAsig[j]);
    }
    
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

void calcularPromediosEstudiante(int nEst, float notas[][N_ASIG], float promEst[]) {
    for (int i = 0; i < nEst; i++) {
        float suma = 0;
        for (int j = 0; j < N_ASIG; j++) {
            suma += notas[i][j];
        }
        promEst[i] = suma / N_ASIG;
    }
}

void calcularPromediosAsignatura(int nEst, float notas[][N_ASIG], float promAsig[]) {
    for (int j = 0; j < N_ASIG; j++) {
        float suma = 0;
        for (int i = 0; i < nEst; i++) {
            suma += notas[i][j];
        }
        promAsig[j] = suma / nEst;
    }
}