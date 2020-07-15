#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Funções
void limpa(){
	system("cls");  
}

void prepara(){
    
    printf("\n\n   Player1  X  Computador \n\n");
    printf("       O          O             \n");
    printf("      /|V        V|\\           \n");
    printf("      / \\        / \\          \n");
    printf("                                \n");
    printf("================================\n\n");
}

void jogada(num){
    switch (num){
    case 1 :
        printf("  PEDRA    \n");
        printf("    O/     \n");
        printf("   /|      \n");
        printf("   / \\    \n");
        printf("           \n");
        printf("===========\n\n");
    break;
    
    case 2 :
        printf("  PAPEL    \n");
        printf("    O/     \n");
        printf("   /|      \n");
        printf("   / \\    \n");
        printf("           \n");
        printf("===========\n\n");
    break;
    
    case 3 :
        printf(" TESOURA    \n");
        printf("    O/      \n");
        printf("   /|       \n");
        printf("   / \\     \n");
        printf("            \n");
        printf("============\n\n");
    break;
    
    default :
        printf("\n ===COMANDO INVALIDO!=== \n\n");
        printf("Escolha uma opcao valida!\n\n");
  }  

}

void vencedor(num){
    switch (num){
    case 1 :
        printf("         VENCEDOR!             \n");
        printf("\n   Player1  X  Computador    \n\n");
        printf("      \\O/         O           \n");
        printf("       |         /|\\          \n");
        printf("      / \\        / \\         \n");
        printf("                               \n");
        printf("===============================\n\n");
    break;
    
    case 2 :
        printf("         VENCEDOR!             \n");
        printf("\n   Player1  X  Computador    \n\n");
        printf("       O        \\O/           \n");
        printf("      /|\\        |            \n");
        printf("      / \\       / \\          \n");
        printf("                               \n");
        printf("===============================\n\n");
    break;
    }
}

//Função MAIN:
int main(){

    //Variaveis de Jogada e continue.
    int Player1 = 0, computador = 0, continuar = 1;
    //Variaveis de contagem.
    int contVitoria = 0, contDerrota = 0, contEmpate = 0, contRodada = 1;
    //Variavel para o fim do jogo.
    int  fimDoJogo = 0;

    do {
        limpa();
        //laco para o numero de vitorias ser maior que zero.
        while (fimDoJogo < 1){
            printf("\n\n ================================\n");
            printf(" ==                            ==\n");
            printf(" == => Bem Vindo ao JoKenPo <= ==\n");
            printf(" ==                            ==\n");
            printf(" ================================\n\n");
            printf("Quantas vitorias para definir um ganhador? ");
            scanf("%d", &fimDoJogo);
            limpa();
        }
        
        //Imprime o Placar.
        printf("\n\n  === => JoKenPo <= ===\n\n");
        printf("Quem chegar a %d vitorias primeiro vence!\n\n", fimDoJogo);
        printf(" ===== PLACAR =====\n");
        printf("\nPlayer1 Vitorias: %d\n", contVitoria);
        printf("Computador Vitorias: %d\n", contDerrota);
        printf("Empate(s): %d\n\n", contEmpate);
        printf(" ======= // =======\n\n");
        printf("  => RODADA: %d <=\n\n", contRodada);
        printf("   Faca a Sua Melhor Jogada!!!");
        prepara();

        //Jogada do Usuário.
        printf("Qual eh a sua Escolha?\n");
        printf("1.Pedra\n2.Papel\n3.tesoura\n\n");
        printf("Player1: ");
        scanf("%d", &Player1);
        limpa();
        printf("\n\n  === JoKenPo ===\n\n");
        printf("  => RODADA: %d <=\n\n", contRodada);
        printf("Player1: %d\n", Player1);
        jogada(Player1);

        //Jogada do Computador.
        if (Player1 >= 1 && Player1 <= 3){
            srand(time(NULL));
            computador = (rand() % 3) + 1;
            ceil(computador);
            printf("Computador: %d\n", computador);
            jogada(computador);

            //Verifica Empate e Ganhador.
            if (Player1 == computador){
                printf("\nDEU EMPATE! Tente novamente...\n\n\n");
                contEmpate++;
            } else if (Player1 == 1 && computador == 3){
                printf("\n Player 1 eh o:\n");
                vencedor(1);
                contVitoria++;
            } else if (Player1 == 2 && computador == 1){
                printf("\n Player 1 eh o:\n");
                vencedor(1);
                contVitoria++;
            } else if (Player1 == 3 && computador == 2){
                printf("\n Player 1 eh o:\n");
                vencedor(1);
                contVitoria++;
            } else {
                printf("\n Computador eh o:\n");
                vencedor(2);
                contDerrota++;
            }
            contRodada++;
        }
        //pausa do sistema para visualizar a jogada.
        if (continuar > 0){
            system("pause");
        }

        //Imprime o fim do Jogo.
        if (contVitoria >= fimDoJogo || contDerrota >= fimDoJogo){
            limpa();
            printf("\n\n==== FIM DE JOGO!!! ====\n");
            printf("\n ===== PLACAR =====\n\n");
            printf("Player1 Vitoria(s): %d\n", contVitoria);
            printf("Computador Vitoria(s): %d\n", contDerrota);
            printf("Empate(s): %d\n", contEmpate);
            printf("\n ======= // =======\n\n");
            printf("   => EM %d RODADA(S) <=\n\n", contRodada -1);
            if (contVitoria > contDerrota){
                vencedor(1);
                printf("\n==== PARABENS!!! ====\n\n");
                contDerrota = 0;
                contVitoria = 0;
                contRodada = 1;
                contEmpate = 0;
                fimDoJogo = 0;
            } else {
                vencedor(2);
                printf("\n==== NAO FOI DESTA VEZ! ====\n\n");
                contDerrota = 0;
                contVitoria = 0;
                contRodada = 1;
                contEmpate = 0;
                fimDoJogo = 0;
            }
            //Continue.
            printf("\nDeseja Jogar Novamente?\n0.Nao\n1.Sim\n");
            scanf("%d", &continuar);
        }

    } while (continuar);
    limpa();
    
    return 0;
}