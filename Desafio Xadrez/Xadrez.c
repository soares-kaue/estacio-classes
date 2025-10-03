#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int main(){

    srand(time(NULL));

    int opcao;

    do { 
    printf("=== Bem-vindo! ===\n");
    printf("=== Xadrez Game ===\n");
    printf("1. Jogar!\n");
    printf("2. Regras.\n");
    printf("3. Sair do jogo.\n");
    scanf("%d", &opcao);

    

    switch (opcao) {
        case 1:
            int tor;
            int bis;
            int rai;
            int BorW = rand() % 2;
            if (BorW == 1 ){
            printf("Voce vai comecar com as brancas!\n");
            } else {
                printf("Voce vai comecar com as pretas!\n");
            }

            printf("Escolha qual peca voce deseja mover:\n");
            printf("1. Torre.\n");
            printf("2. Rainha.\n");
            printf("3. Bispo.\n");
            scanf("%d", &opcao);

            switch (opcao){

            char movimento[20];

            case 1:

                
               do { 
                printf("Escolha o movimento: [Direita|Esquerda|Cima|Baixo]\n");
                scanf(" %19s", movimento);                           

                if (strcmp(movimento, "Direita") == 0){
                    for (int i = 0; i < 5; i++){
                        printf("Direita\n");
                    } 
                } else if (strcmp(movimento, "Esquerda") == 0){
                    for (int i = 0; i < 5; i++){
                        printf("Esquerda\n");
                    }
                } else if (strcmp(movimento, "Cima") == 0){
                    for (int i = 0; i < 5; i++){
                        printf("Cima\n");
                    }
                } else if (strcmp(movimento, "Baixo") == 0) {
                    for (int i = 0; i < 5; i++){
                        printf("Baixo\n");
                    }

                } else {
                    printf("Movimento invalido. Tente novamente.\n");
                    }

                } while (1);

                break;
            case 2:

                do { 
                printf("Escolha o movimento: [Direita|Esquerda|Cima|Baixo|DireitaCima|DireitaBaixo|EsquerdaCima|EsquerdaBaixo]\n");
                scanf(" %19s", movimento);
                           
                if (strcmp(movimento, "Direita") == 0){
                    for (int i = 0; i < 5; i++){
                        printf("Direita\n");
                    } 
                } else if (strcmp(movimento, "Esquerda") == 0){
                    for (int i = 0; i < 5; i++){
                        printf("Esquerda\n");
                    }
                } else if (strcmp(movimento, "Cima") == 0){
                    for (int i = 0; i < 5; i++){
                        printf("Cima\n");
                    }
                } else if (strcmp(movimento, "Baixo") == 0){
                    for (int i = 0; i < 5; i++){
                        printf("Baixo\n");
                    }

                } else if (strcmp(movimento, "DireitaCima") == 0){
                    for (int i = 0; i < 5; i++){
                        printf("DireitaCima\n");
                    }
                } else if (strcmp(movimento, "DireitaBaixo") == 0){
                    for (int i = 0; i < 5; i++){
                        printf("DireitaBaixo\n");
                    }
                } else if (strcmp(movimento, "EsquerdaCima") == 0){
                    for (int i = 0; i < 5; i++){
                        printf("EsquerdaCima\n");
                    }
                } else if (strcmp(movimento, "EsquerdaBaixo") == 0){
                    for (int i = 0; i < 5; i++){
                        printf("EsquerdaBaixo\n");
                    }
                } else {
                    printf("Movimento invalido. Tente novamente.\n");
                    }

            } while (1);
                
                break;
            case 3:

                do { 
                printf("Escolha o movimento: DireitaCima|DireitaBaixo|EsquerdaCima|EsquerdaBaixo]\n");
                scanf(" %19s", movimento);

                if (strcmp(movimento, "DireitaCima") == 0){
                    for (int i = 0; i < 5; i++){
                        printf("DireitaCima\n");
                    } 
                } else if (strcmp(movimento, "DireitaBaixo") == 0){
                    for (int i = 0; i < 5; i++){
                        printf("DireitaBaixo\n");
                    }
                } else if (strcmp(movimento, "EsquerdaCima") == 0){
                    for (int i = 0; i < 5; i++){
                        printf("EsquerdaCima\n");
                    }
                } else if (strcmp(movimento, "EsquerdaBaixo") == 0) {
                    for (int i = 0; i < 5; i++){
                        printf("EsquerdaBaixo\n");
                    }
                }else {
                    printf("Movimento invalido. Tente novamente.\n");
                    }

            } while (1);

                break;
            
            }


            break;
        case 2:
            printf("Regras...");
            break;
        case 3:
            printf("Saindo...");
            break;
        default:
            printf("Opcao invalida. Tente novamente.\n");
        break;

    }
    } while(opcao != 3);

}