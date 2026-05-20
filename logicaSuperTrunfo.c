#include <stdio.h>

/**
 * Desafio Super Trunfo - Países
 * Nível Aventureiro: Menu Interativo e Comparação Dinâmica
 */

int main() {
    // Variáveis da Carta 1
    char estado1, codigo1[5], cidade1[50];
    unsigned long int populacao1;
    float area1, pib1, densidade1;
    int pontos_turisticos1;

    // Variáveis da Carta 2
    char estado2, codigo2[5], cidade2[50];
    unsigned long int populacao2;
    float area2, pib2, densidade2;
    int pontos_turisticos2;

    int opcao_menu;

    // ==========================================
    // 1. CADASTRO DAS CARTAS
    // ==========================================
    printf("--- Cadastro da Carta 1 ---\n");
    printf("Estado (A-H): ");
    scanf(" %c", &estado1);
    printf("Código da Carta (ex: A01): ");
    scanf("%s", codigo1);
    printf("Nome da Cidade: ");
    scanf(" %[^\n]", cidade1);
    printf("População: ");
    scanf("%lu", &populacao1);
    printf("Área (km²): ");
    scanf("%f", &area1);
    printf("PIB (bilhões): ");
    scanf("%f", &pib1);
    printf("Número de Pontos Turísticos: ");
    scanf("%d", &pontos_turisticos1);

    // Cálculo da densidade populacional
    densidade1 = (float)populacao1 / area1;

    printf("\n--- Cadastro da Carta 2 ---\n");
    printf("Estado (A-H): ");
    scanf(" %c", &estado2);
    printf("Código da Carta: ");
    scanf("%s", codigo2);
    printf("Nome da Cidade: ");
    scanf(" %[^\n]", cidade2);
    printf("População: ");
    scanf("%lu", &populacao2);
    printf("Área (km²): ");
    scanf("%f", &area2);
    printf("PIB (bilhões): ");
    scanf("%f", &pib2);
    printf("Número de Pontos Turísticos: ");
    scanf("%d", &pontos_turisticos2);

    densidade2 = (float)populacao2 / area2;

    // ==========================================
    // 2. MENU INTERATIVO (SWITCH)
    // ==========================================
    printf("\n====================================\n");
    printf("      MENU SUPER TRUNFO - PAÍSES    \n");
    printf("====================================\n");
    printf("Escolha o atributo para a comparação:\n");
    printf("1 - População\n");
    printf("2 - Área Total\n");
    printf("3 - PIB\n");
    printf("4 - Pontos Turísticos\n");
    printf("5 - Densidade Populacional\n");
    printf("Sua opção: ");
    scanf("%d", &opcao_menu);

    printf("\n====================================\n");
    printf("            RESULTADO               \n");
    printf("====================================\n");

    // ==========================================
    // 3. LÓGICA DE COMPARAÇÃO ANINHADA
    // ==========================================
    switch (opcao_menu) {
        case 1:
            printf("Atributo Escolhido: População\n");
            printf("%s: %lu hab | %s: %lu hab\n", cidade1, populacao1, cidade2, populacao2);
            
            if (populacao1 > populacao2) {
                printf("Vencedor: Carta 1 (%s)!\n", cidade1);
            } else if (populacao2 > populacao1) {
                printf("Vencedor: Carta 2 (%s)!\n", cidade2);
            } else {
                printf("Resultado: Empate de populações!\n");
            }
            break;

        case 2:
            printf("Atributo Escolhido: Área Total\n");
            printf("%s: %.2f km² | %s: %.2f km²\n", cidade1, area1, cidade2, area2);
            
            if (area1 > area2) {
                printf("Vencedor: Carta 1 (%s)!\n", cidade1);
            } else if (area2 > area1) {
                printf("Vencedor: Carta 2 (%s)!\n", cidade2);
            } else {
                printf("Resultado: Empate de áreas!\n");
            }
            break;

        case 3:
            printf("Atributo Escolhido: PIB\n");
            printf("%s: %.2f bilhões | %s: %.2f bilhões\n", cidade1, pib1, cidade2, pib2);
            
            if (pib1 > pib2) {
                printf("Vencedor: Carta 1 (%s)!\n", cidade1);
            } else if (pib2 > pib1) {
                printf("Vencedor: Carta 2 (%s)!\n", cidade2);
            } else {
                printf("Resultado: Empate de PIB!\n");
            }
            break;

        case 4:
            printf("Atributo Escolhido: Pontos Turísticos\n");
            printf("%s: %d | %s: %d\n", cidade1, pontos_turisticos1, cidade2, pontos_turisticos2);
            
            if (pontos_turisticos1 > pontos_turisticos2) {
                printf("Vencedor: Carta 1 (%s)!\n", cidade1);
            } else if (pontos_turisticos2 > pontos_turisticos1) {
                printf("Vencedor: Carta 2 (%s)!\n", cidade2);
            } else {
                printf("Resultado: Empate de pontos turísticos!\n");
            }
            break;

        case 5:
            printf("Atributo Escolhido: Densidade Populacional\n");
            printf("(Regra Especial: Menor valor vence!)\n");
            printf("%s: %.2f hab/km² | %s: %.2f hab/km²\n", cidade1, densidade1, cidade2, densidade2);
            
            // Lógica invertida: < determina o vencedor
            if (densidade1 < densidade2) {
                printf("Vencedor: Carta 1 (%s)!\n", cidade1);
            } else if (densidade2 < densidade1) {
                printf("Vencedor: Carta 2 (%s)!\n", cidade2);
            } else {
                printf("Resultado: Empate de densidade!\n");
            }
            break;

        default:
            printf("Opção Inválida! Escolha um número de 1 a 5.\n");
            break;
    }

    return 0;
}