#include <stdio.h>

#define MAX_EST 1000
#define N_ASIG 3
#define NOTA_APR 6.0

void pedirNotas(int nEst, float notas[][N_ASIG]);
void calcProms(int nEst, float notas[][N_ASIG], float promEst[], float promAsig[]);
void buscarExt(int nEst, float notas[][N_ASIG], float maxEst[], float minEst[], float maxAsig[], float minAsig[]);
void contarApr(int nEst, float notas[][N_ASIG], int apr[], int rep[]);

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
    calcProms(nEst, notas, promEst, promAsig);
    buscarExt(nEst, notas, maxEst, minEst, maxAsig, minAsig);
    contarApr(nEst, notas, apr, rep);
    
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

void calcProms(int nEst, float notas[][N_ASIG], float promEst[], float promAsig[]) {
    for (int i = 0; i < nEst; i++) {
        float sum = 0;
        for (int j = 0; j < N_ASIG; j++) {
            sum += notas[i][j];
        }
        promEst[i] = sum / N_ASIG;
    }
    
    for (int j = 0; j < N_ASIG; j++) {
        float sum = 0;
        for (int i = 0; i < nEst; i++) {
            sum += notas[i][j];
        }
        promAsig[j] = sum / nEst;
    }
}

void buscarExt(int nEst, float notas[][N_ASIG], float maxEst[], float minEst[], float maxAsig[], float minAsig[]) {
    for (int i = 0; i < nEst; i++) {
        maxEst[i] = notas[i][0];
        minEst[i] = notas[i][0];
        for (int j = 1; j < N_ASIG; j++) {
            if (notas[i][j] > maxEst[i]) maxEst[i] = notas[i][j];
            if (notas[i][j] < minEst[i]) minEst[i] = notas[i][j];
        }
    }
    
    for (int j = 0; j < N_ASIG; j++) {
        maxAsig[j] = notas[0][j];
        minAsig[j] = notas[0][j];
        for (int i = 1; i < nEst; i++) {
            if (notas[i][j] > maxAsig[j]) maxAsig[j] = notas[i][j];
            if (notas[i][j] < minAsig[j]) minAsig[j] = notas[i][j];
        }
    }
}

void contarApr(int nEst, float notas[][N_ASIG], int apr[], int rep[]) {
    for (int j = 0; j < N_ASIG; j++) {
        apr[j] = 0;
        rep[j] = 0;
        for (int i = 0; i < nEst; i++) {
            if (notas[i][j] >= NOTA_APR) apr[j]++;
            else rep[j]++;
        }
    }
}
