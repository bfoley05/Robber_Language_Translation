#include "Model.h"

Model::Model(){
}

Model::~Model(){
}

// converts consonant to string and adds an o plus the same letter after
string Model::translateSingleConsonant(char c){
    string out(1,c);
    c = tolower(c);
    out += "o";
    out += c;
    return out;
}

// just converts vowel from char to string
string Model::translateSingleVowel(char c){
    string out(1,c);
    return out;
}