#include <iostream>

class listaPrioridades{

private:
    struct node{

        int prioridade;
        int value;
        node *nextValue;

    };

    node *head;
    static int size;

public:

    listaPrioridades(){
        this->head = nullptr;
    }

    void inserirElemento(int prioridade, int valor){

        node *newnode = new node;
        newnode->value = valor;
        newnode->prioridade = prioridade;
        newnode->nextValue = nullptr;

        if(head == nullptr){
            head = newnode;
            size+=1;
            return;
        }

        //caso especial em que a prioridade e menor do que o que está na cabeça
        if(prioridade < head->prioridade){
            newnode->nextValue = head;
            head = newnode;
        }

        else{

            node *tmp = head;
            while (tmp->nextValue != nullptr && tmp->nextValue->prioridade < prioridade){
                tmp = tmp->nextValue;
            }

            //atualizando a referencia dos ponteiros
            newnode->nextValue = tmp->nextValue;
            //inserindo na nova referencia o conteudo da maior prioridade subsequente
            tmp->nextValue = newnode;

        }
        size+=1;
    }

    void limparLista(){

        node *tmp = head;
        node *prox = nullptr;

        while (tmp != nullptr){

            prox = tmp->nextValue;
            delete tmp;
            tmp = prox->nextValue;

        }

        head = nullptr;
        size = 0;

    }

    int peek(){
        int v = head->value;
        return v;
    }

    int dequeue(){

        if(head == nullptr){
            return -1;
        }

        int elementoRemovido = head->value;
        node *tmp = head;
        head = head->nextValue;
        delete tmp;
        size-=1;
        return elementoRemovido;

    }

    static int tamanhoLista(){

        return listaPrioridades::size;

    }

    void impressaoListaPrioridade(){

        if(head == nullptr){
            std::cout << "lista esta vazia";
            return;
        }

        node *tmp = head;
        while(tmp != nullptr){

            std::cout << tmp->prioridade << " : " << tmp->value << std::endl;
            tmp = tmp->nextValue;

        }

    }
};

int listaPrioridades::size = 0;

int main() {
    listaPrioridades l{};
    l.inserirElemento(0, 25);
    l.inserirElemento(-1, 35);
    l.limparLista();
    l.impressaoListaPrioridade();

    return 0;
}
