#include "FileProcessor.h"
#include "Model.h"
#include "Translator.h"
#include <iostream>
using namespace std;

int main(){
    FileProcesser *f = new FileProcesser();

    f->processFile("original.txt", "translation.html");

    delete f;

    return 0;
}