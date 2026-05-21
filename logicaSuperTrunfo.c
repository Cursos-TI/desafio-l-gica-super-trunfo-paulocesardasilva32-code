#include <stdio.h>

/**
 * Desafio Super Trunfo - Países
 * Nível Mestre: Dois Atributos, Operadores Ternários e Menu Dinâmico
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

    // Variáveis de controle do jogo
    int attr1, attr2;
    float valor1_attr1 = 0, valor2_attr1 = 0;
    float valor1_attr2 = 0, valor2_attr2 = 0;
    int pontos_carta1 = 0, pontos_carta2 = 0;

    // ==========================================
    // 1. CADASTRO DAS CARTAS
    // ==========================================
    printf("--- Cadastro da Carta 1 ---\n");
    printf("Estado (A-H): "); scanf(" %c", &estado1);
    printf("Código (ex: A01): "); scanf("%s", codigo1);
    printf("Cidade: "); scanf(" %[^\n]", cidade1);
    printf("População: "); scanf("%lu", &populacao1);
    printf("Área (km²): "); scanf("%f", &area1);
    printf("PIB (bilhões): "); scanf("%f", &pib1);
    printf("Pontos Turísticos: "); scanf("%d", &pontos_turisticos1);
    densidade1 = (float)populacao1 / area1;

    printf("\n--- Cadastro da Carta 2 ---\n");
    printf("Estado (A-H): "); scanf(" %c", &estado2);
    printf("Código: "); scanf("%s", codigo2);
    printf("Cidade: "); scanf(" %[^\n]", cidade2);
    printf("População: "); scanf("%lu", &populacao2);
    printf("Área (km²): "); scanf("%f", &area2);
    printf("PIB (bilhões): "); scanf("%f", &pib2);
    printf("Pontos Turísticos: "); scanf("%d", &pontos_turisticos2);
    densidade2 = (float)populacao2 / area2;

    // ==========================================
    // 2. MENU DINÂMICO - ESCOLHA DO ATRIBUTO 1
    // ==========================================
    printf("\n====================================\n");
    printf("        ESCOLHA O 1º ATRIBUTO       \n");
    printf("====================================\n");
    printf("1 - População\n2 - Área\n3 - PIB\n4 - Pontos Turísticos\n5 - Densidade Populacional\n");
    printf("Escolha: ");
    scanf("%d", &attr1);

    // Validação básica de entrada
    if (attr1 < 1 || attr1 > 5) {
        printf("Opção inválida! Encerrando o programa.\n");
        return 1;
    }

    // ==========================================
    // 3. MENU DINÂMICO - ESCOLHA DO ATRIBUTO 2
    // ==========================================
    printf("\n====================================\n");
    printf("        ESCOLHA O 2º ATRIBUTO       \n");
    printf("====================================\n");
    printf("(Escolha um atributo diferente do primeiro)\n");
    printf("1 - População\n2 - Área\n3 - PIB\n4 - Pontos Turísticos\n5 - Densidade Populacional\n");
    printf("Escolha: ");
    scanf("%d", &attr2);

    if (attr2 < 1 || attr2 > 5 || attr2 == attr1) {
        printf("Opção inválida ou repetida! Encerrando o programa.\n");
        return 1;
    }

    // ==========================================
    // 4. ATRIBUIÇÃO DINÂMICA DOS VALORES
    // ==========================================
    // Atributo 1
    switch (attr1) {
        case 1: valor1_attr1 = populacao1; valor2_attr1 = populacao2; break;
        case 2: valor1_attr1 = area1; valor2_attr1 = area2; break;
        case 3: valor1_attr1 = pib1; valor2_attr1 = pib2; break;
        case 4: valor1_attr1 = pontos_turisticos1; valor2_attr1 = pontos_turisticos2; break;
        case 5: valor1_attr1 = densidade1; valor2_attr1 = densidade2; break;
    }

    // Atributo 2
    switch (attr2) {
        case 1: valor1_attr2 = populacao1; valor2_attr2 = populacao2; break;
        case 2: valor1_attr2 = area1; valor2_attr2 = area2; break;
        case 3: valor1_attr2 = pib1; valor2_attr2 = pib2; break;
        case 4: valor1_attr2 = pontos_turisticos1; valor2_attr2 = pontos_turisticos2; break;
        case 5: valor1_attr2 = densidade1; valor2_attr2 = densidade2; break;
    }

    // ==========================================
    // 5. LÓGICA DE DECISÃO COMPLEXA (AVANÇADA)
    // ==========================================
    printf("\n====================================\n");
    printf("         CONFRONTO MESTRE           \n");
    printf("====================================\n");

    // Avaliação do Atributo 1
    printf("Atributo 1 - ");
    if (attr1 == 5) { // Regra especial para Densidade (Menor vence)
        printf("Densidade Populacional:\n");
        printf("-> %s: %.2f | %s: %.2f\n", cidade1, valor1_attr1, cidade2, valor2_attr1);
        pontos_carta1 += (valor1_attr1 < valor2_attr1) ? 1 : 0;
        pontos_carta2 += (valor2_attr1 < valor1_attr1) ? 1 : 0;
    } else { // Regra padrão (Maior vence)
        printf("Atributo Geral:\n");
        printf("-> %s: %.2f | %s: %.2f\n", cidade1, valor1_attr1, cidade2, valor2_attr1);
        pontos_carta1 += (valor1_attr1 > valor2_attr1) ? 1 : 0;
        pontos_carta2 += (valor2_attr1 > valor1_attr1) ? 1 : 0;
    }

    // Avaliação do Atributo 2
    printf("\nAtributo 2 - ");
    if (attr2 == 5) { // Regra especial para Densidade
        printf("Densidade Populacional:\n");
        printf("-> %s: %.2f | %s: %.2f\n", cidade1, valor1_attr2, cidade2, valor2_attr2);
        pontos_carta1 += (valor1_attr2 < valor2_attr2) ? 1 : 0;
        pontos_carta2 += (valor2_attr2 < valor1_attr2) ? 1 : 0;
    } else {
        printf("Atributo Geral:\n");
        printf("-> %s: %.2f | %s: %.2f\n", cidade1, valor1_attr2, cidade2, valor2_attr2);
        pontos_carta1 += (valor1_attr2 > valor2_attr2) ? 1 : 0;
        pontos_carta2 += (valor2_attr2 > valor1_attr2) ? 1 : 0;
    }

    // ==========================================
    // 6. EXIBIÇÃO DO VENCEDOR FINAL (TERNÁRIO ANINHADO)
    // ==========================================
    printf("\n====================================\n");
    printf("         RESULTADO FINAL            \n");
    printf("====================================\n");
    printf("Placar: %s %d x %d %s\n", cidade1, pontos_carta1, pontos_carta2, cidade2);

    // Uso de operador ternário aninhado para definir o veredito
    (pontos_carta1 > pontos_carta2) ? printf("🏆 PARABÉNS! %s VENCEU O CONFRONTO!\n", cidade1) :
    (pontos_carta2 > pontos_carta1) ? printf("🏆 PARABÉNS! %s VENCEU O CONFRONTO!\n", cidade2) :
    printf("🤝 INCRÍVEL! O confronto terminou em EMPATE geral!\n");

    return 0;
}