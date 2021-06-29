//
// Created by diabloget on 6/28/21.
//

#include "Controller.h"


Controller::Controller(){
    this->index =0;
}

void Controller::addBook(std::string txtpath){
    this->txtpath = txtpath;
    this->text = "";

    this->books.push_back(Book());
    std::string tempName = "";
    for(int i = txtpath.size()-5; txtpath[i]!= '/'; i--){
        tempName.insert(0, 1, txtpath[i]);
    }
    books[books.size()-1].name = tempName;

    std::string line;
    std::ifstream myfile (txtpath);
    if (myfile.is_open()){
        while (getline (myfile,line)){
            this->text += line + "\n";
        }
        myfile.close();
    } else {
        std::cout << "Unable to open file\n";
    }
    std::cout << text;

    parse();

}

void Controller::parse(){
    int n = this->text.length();

    // declaring character array
    char char_array[n + 1];
    strcpy(char_array, this->text.c_str());

    books[books.size()-1].start = this->index;

    for (int i = 0; i < n; i++){
        //std::cout << char_array[i] << "\n";
        std::string char_to_str(char ch);
        std::bitset<8> temp(char_array[i]);

        //std::cout << temp.to_string() << "\n";

        this->A.write(std::to_string(temp[7]) + std::to_string(temp[6]));
        this->B.write(std::to_string(temp[5]) + std::to_string(temp[4]));
        this->C.write(std::to_string(temp[3]) + std::to_string(temp[2]));
        this->D.write(std::to_string(temp[1]) + std::to_string(temp[0]));
        this->P.write(calculateParidad(temp[7] + temp[5] + temp[3] + temp[1]) + calculateParidad(temp[6] + temp[4] + temp[2] + temp[0]));

        this->index++;

    }

    books[books.size()-1].end = this->index;

    //
}

//void Controller::paridad();

std::string Controller::calculateParidad(int par){
    if(par %2 ==0){
        return "1";
    } else {
        return "0";
    }
}
std::string Controller::reader(std::string fileName){
    std::string result;
    int start;
    int end;
    for(int a = 0; a<this->books.size(); a++){
        if(this->books[a].name == fileName){
            start = this->books[a].start;
            end = this->books[a].end;
            break;
        }
    }

    if(this->A.Check() & this->B.Check() & this->C.Check() & this->D.Check() & this->P.Check()){

    } else {



    }

    return "o";

}