#include <stdio.h>

#define MAX_EST 1000  /* Numero maximo de estudiantes */
#define N_ASIG 3      /* Numero de asignaturas */
#define NOTA_APR 6.0  /* Nota minima para aprobar */

/* Prototipos de funciones */
void pedirNotas(int nEst, float notas[][N_ASIG]);
void calcProms(int nEst, float notas[][N_ASIG], float promEst[], float promAsig[]);
void buscarExt(int nEst, float notas[][N_ASIG], float maxEst[], float minEst[], float maxAsig[], float minAsig[]);
void contarApr(int nEst, float notas[][N_ASIG], int apr[], int rep[]);
void mostrarRes(int nEst, float notas[][N_ASIG], float promEst[], float promAsig[], float maxEst[], float minEst[], float maxAsig[], float minAsig[], int apr[], int rep[]);

int main() {
    int nEst;
    
    /* Solicitar numero de estudiantes */
    printf("=== GESTION DE CALIFICACIONES ===\n");
    printf("Ingrese el numero de estudiantes (max %d): ", MAX_EST);
    scanf("%d", &nEst);
    
    /* Validar cantidad de estudiantes */
    if (nEst <= 0 || nEst > MAX_EST) {
        printf("Error: El numero debe estar entre 1 y %d.\n", MAX_EST);
        return 1;
    }
    
    /* Declaracion de matrices y vectores */
    float notas[MAX_EST][N_ASIG];  /* Matriz de calificaciones */
    float promEst[MAX_EST];         /* Promedios por estudiante */
    float promAsig[N_ASIG];        /* Promedios por asignatura */
    float maxEst[MAX_EST];          /* Maximos por estudiante */
    float minEst[MAX_EST];          /* Minimos por estudiante */
    float maxAsig[N_ASIG];         /* Maximos por asignatura */
    float minAsig[N_ASIG];         /* Minimos por asignatura */
    int apr[N_ASIG];               /* Aprobados por asignatura */
    int rep[N_ASIG];               /* Reprobados por asignatura */
    
    /* Llamada a funciones en orden */
    pedirNotas(nEst, notas);
    calcProms(nEst, notas, promEst, promAsig);
    buscarExt(nEst, notas, maxEst, minEst, maxAsig, minAsig);
    contarApr(nEst, notas, apr, rep);
    mostrarRes(nEst, notas, promEst, promAsig, maxEst, minEst, maxAsig, minAsig, apr, rep);
    
    return 0;
}

/* Funcion para solicitar calificaciones con validacion de rango */
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

/* Funcion para calcular promedios por estudiante y por asignatura */
void calcProms(int nEst, float notas[][N_ASIG], float promEst[], float promAsig[]) {
    /* Promedio por estudiante */
    for (int i = 0; i < nEst; i++) {
        float sum = 0;
        for (int j = 0; j < N_ASIG; j++) {
            sum += notas[i][j];
        }
        promEst[i] = sum / N_ASIG;
    }
    
    /* Promedio por asignatura */
    for (int j = 0; j < N_ASIG; j++) {
        float sum = 0;
        for (int i = 0; i < nEst; i++) {
            sum += notas[i][j];
        }
        promAsig[j] = sum / nEst;
    }
}

/* Funcion para encontrar calificaciones maximas y minimas */
void buscarExt(int nEst, float notas[][N_ASIG], float maxEst[], float minEst[], float maxAsig[], float minAsig[]) {
    /* Extremos por estudiante */
    for (int i = 0; i < nEst; i++) {
        maxEst[i] = notas[i][0];
        minEst[i] = notas[i][0];
        for (int j = 1; j < N_ASIG; j++) {
            if (notas[i][j] > maxEst[i]) maxEst[i] = notas[i][j];
            if (notas[i][j] < minEst[i]) minEst[i] = notas[i][j];
        }
    }
    
    /* Extremos por asignatura */
    for (int j = 0; j < N_ASIG; j++) {
        maxAsig[j] = notas[0][j];
        minAsig[j] = notas[0][j];
        for (int i = 1; i < nEst; i++) {
            if (notas[i][j] > maxAsig[j]) maxAsig[j] = notas[i][j];
            if (notas[i][j] < minAsig[j]) minAsig[j] = notas[i][j];
        }
    }
}

/* Funcion para contar aprobados y reprobados por asignatura */
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

/* Funcion para mostrar todos los resultados de manera organizada */
void mostrarRes(int nEst, float notas[][N_ASIG], float promEst[], float promAsig[], float maxEst[], float minEst[], float maxAsig[], float minAsig[], int apr[], int rep[]) {
    printf("\n========================================\n");
    printf("         RESULTADOS GENERALES\n");
    printf("========================================\n");
    
    /* Tabla de calificaciones y promedios */
    printf("\n--- PROMEDIOS POR ESTUDIANTE ---\n");
    printf("%-12s %-8s %-8s %-8s %-10s\n", "Estudiante", "Asig. 1", "Asig. 2", "Asig. 3", "Promedio");
    printf("-------------------------------------------------------\n");
    for (int i = 0; i < nEst; i++) {
        printf("%-12d ", i + 1);
        for (int j = 0; j < N_ASIG; j++) {
            printf("%-8.2f ", notas[i][j]);
        }
        printf("%-10.2f\n", promEst[i]);
    }
    
    /* Promedios por asignatura */
    printf("\n--- PROMEDIO POR ASIGNATURA ---\n");
    for (int j = 0; j < N_ASIG; j++) {
        printf("Asignatura %d: %.2f\n", j + 1, promAsig[j]);
    }
    
    /* Extremos por estudiante */
    printf("\n--- EXTREMOS POR ESTUDIANTE ---\n");
    for (int i = 0; i < nEst; i++) {
        printf("Estudiante %d: Max = %.2f, Min = %.2f\n", i + 1, maxEst[i], minEst[i]);
    }
    
    /* Extremos por asignatura */
    printf("\n--- EXTREMOS POR ASIGNATURA ---\n");
    for (int j = 0; j < N_ASIG; j++) {
        printf("Asignatura %d: Max = %.2f, Min = %.2f\n", j + 1, maxAsig[j], minAsig[j]);
    }
    
    /* Aprobados y reprobados */
    printf("\n--- APROBADOS/REPROBADOS ---\n");
    for (int j = 0; j < N_ASIG; j++) {
        printf("Asignatura %d: Aprobados = %d, Reprobados = %d\n", j + 1, apr[j], rep[j]);
    }
}