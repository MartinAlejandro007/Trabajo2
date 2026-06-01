#include <stdio.h>

#define MAX_EST 1000
#define NOTA_APR 6.0

int main() {
    int nEst;
    float asig1[MAX_EST], asig2[MAX_EST], asig3[MAX_EST];
    float promEst[MAX_EST];
    float promAsig1, promAsig2, promAsig3;
    float maxEst[MAX_EST], minEst[MAX_EST];
    float maxAsig1, minAsig1, maxAsig2, minAsig2, maxAsig3, minAsig3;
    int apr1, apr2, apr3;
    int rep1, rep2, rep3;
    
    printf("=== GESTION DE CALIFICACIONES ===\n");
    printf("Ingrese el numero de estudiantes (max %d): ", MAX_EST);
    scanf("%d", &nEst);
    
    if (nEst <= 0 || nEst > MAX_EST) {
        printf("Error: El numero debe estar entre 1 y %d.\n", MAX_EST);
        return 1;
    }
    
    // Entrada de datos con validacion
    for (int i = 0; i < nEst; i++) {
        printf("\n--- Estudiante %d ---\n", i + 1);
        do {
            printf("Asignatura 1 (0-10): ");
            scanf("%f", &asig1[i]);
            if (asig1[i] < 0 || asig1[i] > 10) printf("Error: Fuera de rango.\n");
        } while (asig1[i] < 0 || asig1[i] > 10);
        
        do {
            printf("Asignatura 2 (0-10): ");
            scanf("%f", &asig2[i]);
            if (asig2[i] < 0 || asig2[i] > 10) printf("Error: Fuera de rango.\n");
        } while (asig2[i] < 0 || asig2[i] > 10);
        
        do {
            printf("Asignatura 3 (0-10): ");
            scanf("%f", &asig3[i]);
            if (asig3[i] < 0 || asig3[i] > 10) printf("Error: Fuera de rango.\n");
        } while (asig3[i] < 0 || asig3[i] > 10);
    }
    
    // Calculo de promedios por estudiante
    for (int i = 0; i < nEst; i++) {
        promEst[i] = (asig1[i] + asig2[i] + asig3[i]) / 3.0;
    }
    
    // Calculo de promedios por asignatura
    float sum1 = 0, sum2 = 0, sum3 = 0;
    for (int i = 0; i < nEst; i++) {
        sum1 += asig1[i];
        sum2 += asig2[i];
        sum3 += asig3[i];
    }
    promAsig1 = sum1 / nEst;
    promAsig2 = sum2 / nEst;
    promAsig3 = sum3 / nEst;
    
    // Extremos por estudiante
    for (int i = 0; i < nEst; i++) {
        maxEst[i] = asig1[i];
        minEst[i] = asig1[i];
        if (asig2[i] > maxEst[i]) maxEst[i] = asig2[i];
        if (asig2[i] < minEst[i]) minEst[i] = asig2[i];
        if (asig3[i] > maxEst[i]) maxEst[i] = asig3[i];
        if (asig3[i] < minEst[i]) minEst[i] = asig3[i];
    }
    
    // Extremos por asignatura
    maxAsig1 = minAsig1 = asig1[0];
    maxAsig2 = minAsig2 = asig2[0];
    maxAsig3 = minAsig3 = asig3[0];
    for (int i = 1; i < nEst; i++) {
        if (asig1[i] > maxAsig1) maxAsig1 = asig1[i];
        if (asig1[i] < minAsig1) minAsig1 = asig1[i];
        if (asig2[i] > maxAsig2) maxAsig2 = asig2[i];
        if (asig2[i] < minAsig2) minAsig2 = asig2[i];
        if (asig3[i] > maxAsig3) maxAsig3 = asig3[i];
        if (asig3[i] < minAsig3) minAsig3 = asig3[i];
    }
    
    // Aprobados y reprobados
    apr1 = apr2 = apr3 = 0;
    rep1 = rep2 = rep3 = 0;
    for (int i = 0; i < nEst; i++) {
        if (asig1[i] >= NOTA_APR) apr1++; else rep1++;
        if (asig2[i] >= NOTA_APR) apr2++; else rep2++;
        if (asig3[i] >= NOTA_APR) apr3++; else rep3++;
    }
    
    // Mostrar resultados
    printf("\n========================================\n");
    printf("         RESULTADOS GENERALES\n");
    printf("========================================\n");
    
    printf("\n--- PROMEDIOS POR ESTUDIANTE ---\n");
    printf("%-12s %-8s %-8s %-8s %-10s\n", "Estudiante", "Asig. 1", "Asig. 2", "Asig. 3", "Promedio");
    printf("-------------------------------------------------------\n");
    for (int i = 0; i < nEst; i++) {
        printf("%-12d %-8.2f %-8.2f %-8.2f %-10.2f\n", i + 1, asig1[i], asig2[i], asig3[i], promEst[i]);
    }
    
    printf("\n--- PROMEDIO POR ASIGNATURA ---\n");
    printf("Asignatura 1: %.2f\n", promAsig1);
    printf("Asignatura 2: %.2f\n", promAsig2);
    printf("Asignatura 3: %.2f\n", promAsig3);
    
    printf("\n--- EXTREMOS POR ESTUDIANTE ---\n");
    for (int i = 0; i < nEst; i++) {
        printf("Estudiante %d: Max = %.2f, Min = %.2f\n", i + 1, maxEst[i], minEst[i]);
    }
    
    printf("\n--- EXTREMOS POR ASIGNATURA ---\n");
    printf("Asignatura 1: Max = %.2f, Min = %.2f\n", maxAsig1, minAsig1);
    printf("Asignatura 2: Max = %.2f, Min = %.2f\n", maxAsig2, minAsig2);
    printf("Asignatura 3: Max = %.2f, Min = %.2f\n", maxAsig3, minAsig3);
    
    printf("\n--- APROBADOS/REPROBADOS ---\n");
    printf("Asignatura 1: Aprobados = %d, Reprobados = %d\n", apr1, rep1);
    printf("Asignatura 2: Aprobados = %d, Reprobados = %d\n", apr2, rep2);
    printf("Asignatura 3: Aprobados = %d, Reprobados = %d\n", apr3, rep3);
    
    return 0;
}
