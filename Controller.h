//
// Created by diabloget on 6/28/21.
//

#ifndef TECFS_CONTROLLER_H
#define TECFS_CONTROLLER_H


#include <string>
#include <cstring>
#include <iostream>
#include <fstream>
#include <bitset>
#include <vector>
#include "DiscN.h"
#include "Book.h"

class Controller {
public:
    Controller();
    void addBook(std::string txtpath);
    void parse();
    std::string text;
    std::string txtpath;
    int index;

    std::string calculateParidad(int par);

    std::vector<Book> books = std::vector<Book>();
    std::string reader(std::string fileName);

    DiscN A = DiscN("/home/diabloget/CLionProjects/TECFS/cmake-build-debug/diskA");
    DiscN B = DiscN("/home/diabloget/CLionProjects/TECFS/cmake-build-debug/diskB");
    DiscN C = DiscN("/home/diabloget/CLionProjects/TECFS/cmake-build-debug/diskC");
    DiscN D = DiscN("/home/diabloget/CLionProjects/TECFS/cmake-build-debug/diskD");
    DiscN P = DiscN("/home/diabloget/CLionProjects/TECFS/cmake-build-debug/diskP");

};


#endif //TECFS_CONTROLLER_H
