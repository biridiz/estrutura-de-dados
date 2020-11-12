/*
 * Tarefa de laboratorio 07 - Armazenando e imprimindo informacoes sobre nomes
 *
 * GEX605 AB 2020/1
 *
 * Nome:      Luiz Roberto Dendea
 * Matricula: 1721101027
 *
 */

#include <stdio.h>
#include <string.h>

int main() {
  int numero_alunos, numero_testes, id, i, j;
  int r = 0;
  char nome[40], op;

  scanf("%d\n", &numero_alunos);
  if (numero_alunos < 50) {
    char alunos[numero_alunos][40];

    for (i=0; i<numero_alunos; i++) {
      fgets(nome, sizeof(nome), stdin);
      nome[strcspn(nome, "\n")] = '\0';
      
      j = 0;
      
      while (nome[j] != '\0') {
        alunos[i][j] = nome[j];
        j++;
      }
    }

    scanf("%d\n", &numero_testes);
    char result[numero_testes];

    for (i=0; i<numero_testes; i++) {
      scanf("%d %c", &id, &op);
      
      if (op == 'p') {
        result[r] = alunos[id][0];
        r++;
      }

      if (op == 'u') {
        for (j=0; j < sizeof(alunos[id]); j++) {
          if (alunos[id][j] == ' ') {
            result[r] = alunos[id][j+1];
          }
        }
        r++;
      }
    }

    for (i=0 ; i<r; i++) {
      printf("%c\n", result[i]);
    }
  }

  return 0;
}
