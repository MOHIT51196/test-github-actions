#ifndef FILER
#define FILER

#include<fstream>
using namespace std;

class Filer{
    string path;
    fstream* file;
    
public:
    Filer(string path);
    string read();
    bool write(string);
    // bool append(string);
    ~Filer();
};

#endif