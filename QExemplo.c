void main(int argc, char **argv)
{
    char arq_entrada[50];  
    char arq_saida[50];    

    gera_nomes_arquivos(arq_entrada, arq_saida, argv[1]);
    
    FILE *entrada = fopen(arq_entrada, "r");
    if (entrada == NULL) {
        printf("Erro ao abrir o arquivo de entrada: %s\n", arq_entrada);
        return;
    }

    int m = ler_valor(entrada);
    if (m <= 0) {
        printf("Erro: valor inválido de m (%d)\n", m);
        fclose(entrada);
        return;
    }

    int n = 0;
    int resposta = 1;
    no L[m];

    while (resposta != 0)
    {
        resposta = ler_valor(entrada);
        printf("Comando lido: %d\n", resposta);

        if (resposta == 0)
        {
            // sair
            printf("Finalizando programa...\n");
            fclose(entrada);
            return;
        }
        else if (resposta == 1)
        {
            // inserir
            no novo_no;
            novo_no.chave = ler_valor(entrada);
            novo_no.valor = ler_valor(entrada);
            printf("Inserindo chave: %d, valor: %d\n", novo_no.chave, novo_no.valor);

            int valor_retornado = inserir(L, n, m, novo_no);
            if (valor_retornado > 0)
            {
                n = valor_retornado;
                printf("Elemento inserido com sucesso. Tamanho atual: %d\n", n);
            }
            else
            {
                printf("Elemento já existe ou erro ao inserir.\n");
            }
        }
        else if (resposta == 2)
        {
            // remover
            int chave = ler_valor(entrada);
            printf("Removendo chave: %d\n", chave);

            no* no_removido = remover(chave, L, &n);
            if(no_removido != NULL){
                printf("Elemento removido.\n");
                free(no_removido);
            }
            else
            {
                printf("Chave não encontrada.\n");
            }
        }
        else if (resposta == 3)
        {
            // imprimir
            imprimir(L, n, arq_saida);
            printf("Lista impressa no arquivo: %s\n", arq_saida);
        }
    }
}
