#ifndef FILE_PROCCESSER
#define FILE_PROCCESSER

#include "Translator.h"
#include <iostream>
using namespace std;

class FileProcesser{
    public:
        FileProcesser();
        ~FileProcesser();
        void processFile(string file_in, string file_out);
    
    private:
        Translator *t;
};



#endif