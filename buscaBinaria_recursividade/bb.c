int busca_binaria(int *vet, int inicio, int fim, int chave) {
    int meio;

    if (inicio > fim) {
        return -1;
    }

    meio = (inicio + fim) / 2;

    if (vet[meio] == chave) {
        return meio;
    }

    if (chave > vet[meio])
        return busca_binaria(vet, meio+1, fim, chave);
    else
        return busca_binaria(vet, inicio, meio-1, chave);
}