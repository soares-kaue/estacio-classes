#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

void processarMovimento(const char* movimentosValidos[], int numeroMovimentos) {
    char movimentoInput[20];
    int movimentoValido = 0;
    int casas; // Guardar numero de casas


    //Loop para garantir que a escolha seja valida
    while(!movimentoValido){
        printf("Escolha o movimento: ");

        for (int i = 0; i < numeroMovimentos; i++){
            printf("[%s]", movimentosValidos[i]);
        }
        printf("\n>");
        scanf(" %19s", movimentoInput);

        // Verificar se a direcao escolhida esta na lista de movimentos validos
        for (int i = 0; i < numeroMovimentos; i++){
            if (strcmp(movimentoInput, movimentosValidos[i]) == 0){
                printf("Movendo %s...\n\n", movimentoInput);
                movimentoValido = 1; //Direcao valida
                break;
            }
        }
        if (!movimentoValido){
            printf("Movimento invalido. Tente novamente.\n");
        }
    }

    while(1){
        printf("Quantas casas deseja andar?\n");
        scanf("%d", &casas);

        if (casas > 0){

            printf("\nOk! Movimento  %s por %d casa(s)...\n\n");
            break;
        } else {

            printf("Numero de casas invalido. Por favor, insira um numero maior que zero.\n");
        }
    }
}

// Funcao principal do jogo
void jogar(){

    if (rand() % 2 == 1) {
        printf("Voce vai comecar com as brancas!\n");
    } else {
        printf("Voce vai comecar com as pretas!\n");
    }

    // Escolha da peca
    int escolhaPeca;
    printf("\nEscolha qual peca voce deseja mover:\n");
    printf("1. Torre\n");
    printf("2. Rainha\n");
    printf("3. Bispo\n");
    printf("4. Cavalo\n");
    printf("5. Voltar ao menu\n");
    printf("> ");
    scanf("%d", &escolhaPeca);

    // Definicao dos movimentos validos para cada peca
    const char* movimentosTorre[] = {"Direita", "Esquerda", "Cima", "Baixo"};
    const char* movimentosRainha[] = {"Direita", "Esquerda", "Cima", "Baixo", "DireitaCima", "DireitaBaixo", "EsquerdaCima", "EsquerdaBaixo"};
    const char* movimentosBispo[] = {"DireitaCima", "DireitaBaixo", "EsquerdaCima", "EsquerdaBaixo"};
    const char* movimentosCavalo[] = {"CimaCimaDireita", "CimaCimaEsquerda", "BaixoBaixoDireita", "BaixoBaixoEsquerda", "EsqEsqBaixo", "EsqEsqCima", "DirDirBaixo", "DirDirCima"};
    
    // Processar o movimento baseado na peca escolhida
    switch (escolhaPeca) {
        case 1: // Torre
            processarMovimento(movimentosTorre, 4);
            break;
        case 2: // Rainha
            processarMovimento(movimentosRainha, 8);
            break;
        case 3: // Bispo
            processarMovimento(movimentosBispo, 4);
            break;
        case 4: // Cavalo

            printf("O cavalo se move em 'L', mas vamos registrar a direcao.\n");
            processarMovimento(movimentosCavalo, 8);
            break;
        case 5: // Voltar
            printf("Voltando ao menu principal...\n\n");
            break;
        default:
            printf("Peca invalida.\n\n");
            break;
    }
}

int main(){

    srand(time(NULL));
    int opcao;

    do {
        printf("=== Bem-vindo! ===\n");
        printf("=== Xadrez Game ===\n");
        printf("1. Jogar!\n");
        printf("2. Regras.\n");
        printf("3. Sair do jogo.\n");
        printf("> ");
        scanf("%d", &opcao);
        printf("\n");

        switch (opcao){
        case 1:
            jogar();
            break;
        case 2:
            printf("Regras do xadrez...\n\n");
               
            break;
        case 3:
            printf("Obrigado por jogar! Saindo...\n");
            break;
        default:
            printf("Opcao invalida. Tente novamente.\n\n");
            break;
        }
    } while (opcao != 3);

    return 0;
}