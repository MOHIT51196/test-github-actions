#include "filer.hpp"

#include <iostream>
#include <stdexcept>

Filer::Filer(string filePath) : path(filePath), file(new fstream) {}

string Filer::read(){
    this->file->open(this->path, ios::in);
    if(!this->file) throw runtime_error("Unable to open the file to read");

    string input;
    while(!this->file->eof()){
        getline(*this->file, input);
        cout<< input <<endl;
    }
    this->file->close();
    return input;
}

bool Filer::write(string data){
    this->file->open(this->path, ios::out | ios::app | ios::ate);
    if(!this->file) throw runtime_error("Unable to open the file to write");

    (*this->file) << data << endl;
    this->file->close();
    return true;
}

Filer::~Filer(){
    if(this->file) {
        delete this->file;
        this->file = nullptr;
    }
}