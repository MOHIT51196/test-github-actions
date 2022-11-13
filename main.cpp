#include<iostream>
#include "config.h"

#ifdef USE_FILER
  #include "filer.hpp"
#endif

using namespace std;

int main(){
  // cout << "Version : " << FILESYS_VERSION_MAJOR << "." << FILESYS_VERSION_MINOR <<endl;
  #ifdef USE_FILER
    Filer f ("/Users/mohitmalhotra/Documents/github-actions/test-github-actions/README.md");
    f.write("Author of this repo is Mohit Malhotra");
    f.read();
  #else
    cout<<"Filer API is not supported"<<endl;
  #endif
  return EXIT_SUCCESS;
}
