void Exemplo0719(char nome[100])
{
    FILE *arq;
    char Linha[100];
    char *result;
    int i = 0;
    int tamanho = 0;
    int contador = 0;

    // Abre um arquivo TEXTO para LEITURA
    arq = fopen(nome, "rt");// Abre um arquivo TEXTO para LEITURA
    if (arq == NULL)  // Se houve erro na abertura
    {
        printf("\n[ ! ] Erro na abertura do arquivo\n");
        return;
    }
    i = 1;
    while (!feof(arq))
    {
        // Lê uma linha (inclusive com o '\n')
        result = fgets(Linha, 100, arq);  // o 'fgets' lê até 99 caracteres ou até o '\n'
        if (result)  // Se foi possível ler
            tamanho = strlen(Linha);
            for (int x = 0; x < tamanho; x++)
            {
                if( 'a' <= Linha[x] && Linha[x] <= 'z' )
                {
                    contador = contador + 1;
                }
            }
        i++;
        FILE* arquivo = fopen("RESULTADO19.TXT", "at");
        fprintf ( arquivo, "%s:%d\n", Linha, contador );
        fclose(arquivo);
        contador = 0;
    }
    fclose(arq);
    //printf("\n%d\n", contador);
}
