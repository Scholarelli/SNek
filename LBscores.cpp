//
// Created by danielp on 9/4/25.
//

#include "LBscores.h"
#include <cstring>
#include <cstdio>

void LBscores::saveScore(const char* testo,char* nome, int score) {
    FILE* f = fopen(testo, "a");
    fprintf(f, "%s %d\n", nome, score);
    fclose(f);
}

int LBscores::loadScore(const char* testo, partita* punteggi, int maxPunteggi) {
    FILE* f = fopen(testo, "r");
    if (f == nullptr) return 0;
    int count = 0;
    while (count < maxPunteggi) {
        if (fscanf(f, "%19s %d", punteggi[count].nome, &punteggi[count].punt) != 2) {
            break;
        }
        count++;
    }
    fclose(f);

    if (count == 0) {
        strcpy(punteggi[0].nome, "Nessuno");
        punteggi[0].punt = 0;
        count = 1;
    }
    LBsort(punteggi, count);
    return count;
}

void LBscores::LBsort(partita* entries, int count) {
    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            if (entries[j].punt < entries[j+1].punt) {
                partita tmp = entries[j];
                entries[j] = entries[j+1];
                entries[j+1] = tmp;
            }
        }
    }
}