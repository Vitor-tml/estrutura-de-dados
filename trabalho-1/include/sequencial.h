// Define os registros da Lista Sequencial como Nome e RG.
typedef struct no_sequencial
{
    char nome[15];
    int rg;
} Registro_Sequencial;

// Cabeçalho da Lista Sequencial.
typedef struct lista_sequencial
{
    Registro_Sequencial *registro;
    int nElementos;
    int nMax;
} Sequencial;

void iniciaSequencial(Sequencial *lista, int nRegistros);
void exibeSequencial(Sequencial *lista);
void preencheSequencial(Sequencial *lista);
