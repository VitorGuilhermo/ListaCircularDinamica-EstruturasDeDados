#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <conio2.h>
#include <string.h>
#include <windows.h>
#include "TADListaCircularDinamica.h"

int main(){
    TpListaCircularDinamica *head = NULL;

    head = inserir(head, 'A');
    head = inserir(head, 'B');
    head = inserir(head, 'C');
    head = inserir(head, 'D');


    //printf("\n%c\n", head->prox->prox->prox->prox->elemento); ->>>verifica se é circular msm
    head = retirar(head, 'C');
    exibir(head);
}
