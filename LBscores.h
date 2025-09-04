//
// Created by danielp on 9/4/25.
//

#ifndef SNEK_LBSCORES_H
#define SNEK_LBSCORES_H

struct partita {
    int punt;
    char nome[20];
};
class LBscores {
public:
    void saveScore(const char* testo,char* nome, int score);

    int loadScore(const char* testo, partita* punteggi, int maxPunteggi);

private:
    void LBsort(partita* punteggi, int count);
};


#endif //SNEK_LBSCORES_H