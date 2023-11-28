#include <iostream>
#include <fstream>

using namespace std;

struct nodo {
    int value;
    nodo* next;
};
typedef nodo* lista;


lista creaLista(char* inputFile);
void stampaLista(lista listaDiNumeri);
void distruggiLista(lista listaDiNumeri);
void distruggiListaRec(lista listaDiNumeri);

int main(int argc, char* argv[]) {

    int returnValue = 0;

    if (argc != 2) {
        cout << "Usage: ./a.out <nome_file>" << endl;
        returnValue = 1;
    }
    else {
        lista listaDiNumeri = creaLista(argv[1]);

        if (listaDiNumeri == NULL) {
            cout << "Il file e' vuoto oppure non esiste" << endl;
            returnValue = 2;
        }
        stampaLista(listaDiNumeri);
        distruggiListaRec(listaDiNumeri);
    }

    return returnValue;
}


lista creaLista(char* inputFile) {

    fstream input;
    lista listaDiNumeri = NULL;
    input.open(inputFile, ios::in);

    if (input.fail()) {
        cout << "Errore in lettura" << endl;
    }
    else {
        int numero;
        input >> numero;
        listaDiNumeri = new nodo{numero, NULL};
        nodo* nodoCorrente = listaDiNumeri;

        while(input >> numero) {
            nodo* nuovoNodo = new nodo{numero, NULL};
            nodoCorrente->next = nuovoNodo;
            nodoCorrente = nuovoNodo;
        }
    }

    input.close();

    return listaDiNumeri;
}


void stampaLista(lista listaDiNumeri) {
    while (listaDiNumeri != NULL) {
        cout << listaDiNumeri->value << " ";
        listaDiNumeri = listaDiNumeri->next;
    }
    cout << endl;
}


void distruggiLista(lista listaDiNumeri) {
    nodo* prossimoNodo;
    while (prossimoNodo != NULL) {
        prossimoNodo = listaDiNumeri->next;
        delete listaDiNumeri;
        listaDiNumeri = prossimoNodo;
    }
}

void distruggiListaRec(lista listaDiNumeri) {
    if (listaDiNumeri != NULL) {
        distruggiListaRec(listaDiNumeri->next);
        delete listaDiNumeri;
    }
}
