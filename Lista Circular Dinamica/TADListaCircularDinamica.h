struct TpListaCircularDinamica{
    char elemento;
    TpListaCircularDinamica *prox;
};

TpListaCircularDinamica *novaCaixa(char elemento){
    TpListaCircularDinamica *caixa = new TpListaCircularDinamica;

    caixa->elemento = elemento;
    caixa->prox = NULL;
    return caixa;
}
TpListaCircularDinamica *inserir(TpListaCircularDinamica *head, char elemento){
    TpListaCircularDinamica *nc, *aux;

    nc = novaCaixa(elemento);
    if(head == NULL)
        head = nc;
    else{
        aux = head;
        while(aux->prox != NULL && aux->prox != head)
            aux = aux->prox;
        nc->prox = head;
        aux->prox = nc;
    }
    return head;
}
TpListaCircularDinamica *retirar(TpListaCircularDinamica *head, char elemento){
    TpListaCircularDinamica *atual, *anterior;

    if(head != NULL){

        if(head->elemento == elemento){//elemento ta no comeco

            //faz com que o ultimo elemento volte a apontar pra cabeça/começo da lista
            atual = head;
            while(atual->prox != NULL && atual->prox != head)
                atual = atual->prox;
            atual->prox = head->prox;

            atual = head;
            head = head->prox;
            delete(atual);
        }
        else{//elemento esta no fim ou meio

            atual = head;
            while(atual->prox != NULL && atual->prox != head && atual->elemento != elemento){
                anterior = atual;
                atual = atual->prox;
            }
            if(atual->elemento == elemento){
                anterior->prox = atual->prox;
                delete(atual);

                //faz com que o ultimo elemento volte a apontar pra cabeça/começo da lista
                atual = head;
                while(atual->prox != NULL && atual->prox != head)
                    atual = atual->prox;
                atual->prox = head;
            }
        }

    }
    return head;
}
void exibir(TpListaCircularDinamica *head){
    TpListaCircularDinamica *aux;

    aux = head;
    while(aux->prox != NULL && aux->prox != head){
        printf("\t %c", aux->elemento);
        aux = aux->prox;
    }
    printf("\t %c", aux->elemento);
}
