#include <stdio.h>
#include <string.h>

/**
 * Super Trunfo: Rio de Janeiro vs New York
 * Nível Novato - Comparação de Atributos
 */

int main() {
    // --- Dados da Carta 1: Rio de Janeiro ---
    char estado1 = 'R'; 
    char codigo1[] = "R01";
    char cidade1[] = "Rio de Janeiro";
    unsigned long int populacao1 = 6211423; // Censo aproximado
    float area1 = 1200.25;                  // km²
    float pib1 = 329.43;                    // Bilhões de Reais
    int pontos_turisticos1 = 50;
    float densidade1 = (float)populacao1 / area1;

    // --- Dados da Carta 2: New York ---
    char estado2 = 'N';
    char codigo2[] = "N01";
    char cidade2[] = "New York";
    unsigned long int populacao2 = 8467513; // Estimativa
    float area2 = 783.84;                   // km² (Apenas terra)
    float pib2 = 1000.00;                   // Valor ilustrativo em Bilhões
    int pontos_turisticos2 = 100;
    float densidade2 = (float)populacao2 / area2;

    // --- Exibição das Cartas ---
    printf("=== CARTA 1: %s ===\n", cidade1);
    printf("População: %lu\nArea: %.2f km²\nDensidade: %.2f hab/km²\n\n", populacao1, area1, densidade1);

    printf("=== CARTA 2: %s ===\n", cidade2);
    printf("População: %lu\nArea: %.2f km²\nDensidade: %.2f hab/km²\n\n", populacao2, area2, densidade2);

    // --- Comparação de População (Maior vence) ---
    printf("--- Resultado: População ---\n");
    if (populacao1 > populacao2) {
        printf("Vencedor: %s\n", cidade1);
    } else {
        printf("Vencedor: %s\n", cidade2);
    }

    // --- Comparação de Densidade (Menor vence) ---
    printf("\n--- Resultado: Densidade Populacional ---\n");
    if (densidade1 < densidade2) {
        printf("Vencedor: %s (Menos lotada!)\n", cidade1);
    } else {
        printf("Vencedor: %s (Menos lotada!)\n", cidade2);
    }

    // --- Comparação de Área (Maior vence) ---
    printf("\n--- Resultado: Área Total ---\n");
    if (area1 > area2) {
        printf("Vencedor: %s (Cidade maior geograficamente)\n", cidade1);
    } else {
        printf("Vencedor: %s (Cidade maior geograficamente)\n", cidade2);
    }

    return 0;
}