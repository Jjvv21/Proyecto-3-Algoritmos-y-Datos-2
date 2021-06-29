//
// Created by diabloget on 6/28/21.
//

#include "DiscN.h"
DiscN::DiscN(std::string path) {
    this->path = path;
    this->global = 0;

    std::ofstream myfile;
    myfile.open (this->path + "/disk.txt");
    myfile.close();
}

void DiscN::write(std::string bin) {
    this->global++;
    std::cout << "orden: " << bin << "\n";

    std::ofstream myfile;
    myfile.open (this->path + "/disk.txt", std::ios_base::app);
    myfile << bin << "\n";
    myfile.close();
}

bool DiscN::Check(){
    std::ifstream infile(this->path);
    bool temp = infile.good();
    infile.close();
    return temp;
}