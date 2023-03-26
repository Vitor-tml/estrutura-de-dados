// Define o nó da Lista Encadeada.
typedef struct no_encadeada
{
    struct no_encadeada *anterior;
    char nome[15];
    int rg;
    struct no_encadeada *proximo;
}Registro_Encadeada;

// Cabeçalho da Lista Encadeada.
typedef struct lista_encadeada
{
    Registro_Encadeada *primeiro;
    Registro_Encadeada *ultimo;
    int tamanho;
}Encadeada;

void iniciaEncadeada(Encadeada *lista);
void exibeEncadeada(Encadeada *lista);
void preencheEncadeada(Encadeada *lista);
int contagemEncadeada(Encadeada *lista);