//
// Created by danielp on 8/28/25.
//

#include "Levels.h"


Levels::~Levels() {
    Node* tmp = root;
    while (tmp != nullptr) {
        Node* next = tmp->next;
        delete tmp;
        tmp = next;
    }
}


void Levels::addLevel(int l, int tD, int sL, int sS, int b, int tB) {
    Node* newLevel= new Node{l, tD, sL, sS, b, tB, nullptr, nullptr};
    if (root == nullptr) {
        root = newLevel;
        current = root;
    }else {
        Node* tmp = root;
        while (tmp->next != nullptr) {
            tmp = tmp->next;
        }
        tmp->next = newLevel;
        newLevel->prev = tmp;
    }
}

bool Levels::nextLevel() {
    if (current != nullptr && current->next != nullptr) {
        current = current->next;
        return true;
    }
    return false;
}

bool Levels::previousLevel() {
    if (current != nullptr && current->prev != nullptr) {
        current = current->prev;
        return true;
    }
    return false;
}