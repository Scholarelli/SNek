//
// Created by Emanuele Cianfanelli on 18/03/25.
//

#ifndef MENU_H
#define MENU_H
#include <vector>


class Menu {
    std::vector<std::string> entries;

public:
    explicit Menu(const std::vector<std::string> &entries)
        : entries(entries) {
    }
};



#endif //MENU_H
