#include <iostream>
#include <cstring>

using namespace std;

struct Studente {
    char  nome[31];
    char  cognome[31];
    int   matricola;
    float media;
};

void      stampa_studente(const Studente& s);
Studente* genera_studente(char  nome[],
                          char  cognome[],
                          int   matricola,
                          float media);


int main() {
    char  nome[31], cognome[31];
    int   matricola;
    float media;

    cin >> nome >> cognome >> matricola >> media;

    Studente *s = genera_studente(nome, cognome, matricola, media);
    stampa_studente(*s);

    delete s;

    return 0;
}

void stampa_studente(const Studente& s) {
    cout << "Studente (matricola: " << s.matricola << ") :" << endl;
    cout << "\tNome: " << s.nome << endl;
    cout << "\tCognome: " << s.cognome << endl;
    cout << "\tMedia: " << s.media << endl;
}

Studente* genera_studente(char *nome, char *cognome, int matricola,
                          float media) {
    Studente *s = new Studente;

    s->matricola = matricola;
    s->media     = media;
    strcpy(s->nome,    nome);
    strcpy(s->cognome, cognome);
    return s;
}
