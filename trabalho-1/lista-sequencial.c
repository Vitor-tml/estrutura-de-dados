#include <stdio.h>

int menu();
int main()
{
    if(menu() == 5)
        printf("Saindo.");
}

int menu()
{
    int op;
    // Título:
    printf("LISTA DE CLIENTES.\n");
    printf("O que voce quer fazer?\n");
    // Opções:
    printf("1) Inserir.\n");
    printf("2) Retirar.\n");
    printf("3) Pesquisar nome.\n");
    printf("4) Ler arquivo.\n");
    printf("5) Sair.\n");
    // Ler opção:
    scanf("%d", &op);

    switch (op)
    {
        case 1:
            printf("Inserir aonde?\n1)Inicio.\n2)Final.\n");
            scanf("%d", &op);
            break;
        case 2:
            printf("Retirar aonde?\n1)Inicio.\n2)Final.\n");
            scanf("%d", &op);
            break;
        default:
            op = 5; //sair
            break;
    }
    return op;
}