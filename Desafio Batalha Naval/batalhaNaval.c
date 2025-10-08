#include <stdio.h>

void inicializaTabuleiro(char tabuleiro[10][10]) {
    for (int linha = 0; linha < 10; linha++) {
        for (int coluna = 0; coluna < 10; coluna++) {
            tabuleiro[linha][coluna] = '~'; // Agua
        }
    }
}

void mostrarTabuleiro(char tabuleiro[10][10]) {
    printf("  0 1 2 3 4 5 6 7 8 9\n");
    for (int linha = 0; linha < 10; linha++) {
        printf("%d ", linha);
        for (int coluna = 0; coluna < 10; coluna++) {
            printf("%c ", tabuleiro[linha][coluna]);
        }
        printf("|\n");
    }

    printf("----------------------\n");
}

void posicionarNavios(char tabuleiro[10][10]) {

    // NOVO: Navio Quadrado 2x2 (4 casas)
    tabuleiro[0][0] = 'N';
    tabuleiro[0][1] = 'N';
    tabuleiro[1][0] = 'N';
    tabuleiro[1][1] = 'N';

    // NOVO: Navio em formato "L" (4 casas)
    tabuleiro[3][3] = 'N';
    tabuleiro[4][3] = 'N';
    tabuleiro[5][3] = 'N';
    tabuleiro[5][4] = 'N';
    
    // NOVO: Navio em cruz (4 casas)
    tabuleiro[7][5] = 'N';
    tabuleiro[7][6] = 'N';
    tabuleiro[7][7] = 'N';
    tabuleiro[8][6] = 'N';
    tabuleiro[6][6] = 'N';
}


int main(){

    char tabuleiro[10][10];
    int ataqueLinha, ataqueColuna;
    int partesDeNavioRestantes; // Total de partes dos navios
    int opcao; 

    printf("Bem-vindo ao jogo Batalha Naval!\n");
    inicializaTabuleiro(tabuleiro);
    posicionarNavios(tabuleiro);

    do {
        // Mostra o estado atual do jogo para o jogador
        mostrarTabuleiro(tabuleiro);

        // Pede as coordenadas do ataque
        printf("\nSua vez de atacar!\n");
        printf("Digite a LINHA para o ataque (0-9): ");
        scanf("%d", &ataqueLinha);
        printf("Digite a COLUNA para o ataque (0-9): ");
        scanf("%d", &ataqueColuna);

        // Validação simples da jogada
        if (ataqueLinha < 0 || ataqueLinha > 9 || ataqueColuna < 0 || ataqueColuna > 9) {
            printf("\nCoordenadas invalidas! Tente novamente.\n");
            continue; // Pula para a próxima iteração do loop
        }

        // --- 3. VERIFICA O RESULTADO DO ATAQUE ---
        if (tabuleiro[ataqueLinha][ataqueColuna] == 'N') {
            printf("\nFOGO! Voce acertou parte de um navio!\n");
            tabuleiro[ataqueLinha][ataqueColuna] = 'X'; // Marca como atingido
        } else if (tabuleiro[ataqueLinha][ataqueColuna] == 'X' || tabuleiro[ataqueLinha][ataqueColuna] == 'O') {
            printf("\nVoce ja atirou nessa posicao! Tente outra.\n");
        }
        else {
            printf("\nAGUA! Voce errou o tiro.\n");
            tabuleiro[ataqueLinha][ataqueColuna] = 'O'; // Marca como tiro na água
        }

        // Zera o contador e verifica o tabuleiro inteiro novamente
        partesDeNavioRestantes = 0;
        for (int linha = 0; linha < 10; linha++) {
            for (int coluna = 0; coluna < 10; coluna++) {
                if (tabuleiro[linha][coluna] == 'N') {
                    partesDeNavioRestantes++;
                }
            }
        }

    // O jogo continua ENQUANTO o número de partes de navio for maior que 0.
    } while (partesDeNavioRestantes > 0);


    printf("\n\n--- FIM DE JOGO ---\n");
    printf("PARABENS! Voce destruiu todos os navios inimigos!\n");
    mostrarTabuleiro(tabuleiro); // Mostra o tabuleiro final

    return 0;
}