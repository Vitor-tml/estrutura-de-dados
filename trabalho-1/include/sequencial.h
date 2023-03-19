// Definição do Nó da lista sequencial
typedef struct
{
    char nome[15];
    int rg;
} No_sequencial;

typedef struct
{
    No_sequencial *data;
    int capacidade;
    int tamanho;
} Sequencial;

// Declaração das funções
void alocaListaSeq(Sequencial *lista);
void preencheSeq(Sequencial *lista);
void exibeSeq(Sequencial *lista);
