#define TAM 15
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
void preencheEncadeada(Encadeada *lista, int tamanho);
int contagemEncadeada(Encadeada *lista);
void adicionaInicioEncadeada(char nome[TAM], int rg, Encadeada *lista);
void adicionaFinalEncadeada(char nome[TAM], int rg, Encadeada *lista);
void adicionaNEncadeada(char nome[TAM], int rg, int n, Encadeada *lista);
void removeInicioEncadeada(Encadeada *lista);
void removeFinalEncadeada(Encadeada *lista);
void removeNEncadeada(Encadeada *lista, int n);
void buscaEncadeada(Encadeada *lista, int rg);
void arquivoParaEncadeada(Encadeada *lista, FILE *arquivo, int nLinhas);
void encadeadaParaArquivo(Encadeada *lista, FILE *arquivo);
void desalocaEncadeada(Encadeada *lista_encadeada);
