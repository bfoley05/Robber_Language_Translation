#include "Translator.h"
#include "Model.h"
#include <string>

// creates a new instance of model to translate each individual letter
Translator::Translator(){
    m = new Model();
}

// deletes instance of model
Translator::~Translator(){
    delete m;
}

// Takes in the english word and the returns the word in the new language after iterating through the word
// if it is a vowel the translateVowel is called else consonant to avoid errors in translation
string Translator::translateEnglishWord(string word){
    string out;
    for (int i = 0; i < word.length(); ++i){
        char letter = word[i];
        if(i != 0){
            letter = tolower(letter);
        }
        if(letter=='a' || letter=='e' || letter=='i' || letter=='o' || letter=='u' || letter=='A' || letter=='E' || letter=='I' || letter=='O' || letter=='U'){
            out += m->translateSingleVowel(letter);
        }else if(isalpha(letter)){
            out += m->translateSingleConsonant(letter);
        }else{
            out += letter;
        }
    }
    return out;
}

// splits the sentence into words and then calls the translateSingleWord and adds the word to the output
// returns string of the whole sentence
string Translator::translateEnglishSentence(string sentence){
    string out;
    int counter = 0;
    int index;
    for(int i = 0; i < sentence.length(); ++i){
        char letter = sentence[i];
        if(letter==' '){
            out += translateEnglishWord(sentence.substr(i-counter,counter)) + " ";
            counter = 0;
        }else{
            counter++;
        }
        index = i;
    }
    out += translateEnglishWord(sentence.substr(index-counter+1,counter+1)) + " ";
    return out;
}