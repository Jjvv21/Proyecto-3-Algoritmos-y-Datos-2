//
// Created by diabloget on 6/28/21.
//

#ifndef TECFS_DISCN_H
#define TECFS_DISCN_H
#include <iostream>
#include <fstream>
#include <string>

class DiscN {
public:
    DiscN(std::string path);
    void write(std::string bin);
    int global;
    bool read(int start, int end);
    bool Check();
    std::string path;

};


#endif //TECFS_DISCN_H
