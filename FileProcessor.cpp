#include "FileProcessor.h"
#include <iostream>
#include <fstream>

// creates new instance of the translator to translate languge from english to new language
FileProcesser::FileProcesser(){
    t = new Translator();
}

// deletes instance of translator to free up memory
FileProcesser::~FileProcesser(){
    delete t;
}


// opens both files and checks if it is found, if so reads each line of the file
// and runs it through the translator and inputs it into an html page as per the
// style guidlines
void FileProcesser::processFile(string input_file, string output_file){
    ifstream ifs(input_file);

    if(!ifs){
        cerr << "No file found" << endl;
        return;
    }

    ofstream ofs(output_file);
    if (!ofs) {
        std::cerr << "Can't create file" << endl;
        return;
    }

    string line;
    // Outputs to file in English and bold
    ofs << "<!DOCTYPE html>";
    ofs << "<html><head><title>English to Robber Translation</title></head><body><p><b>";
    while(getline(ifs,line)){
        ofs << "<p>";
        ofs << line << "<br></p>";
    }

    //start at beggining of file again
    ifs.clear();
    ifs.seekg(0, ios::beg);

    // outputs to file in the language and italizized
    ofs << "</b></p><br/><p><i>";
    string out;
    while(getline(ifs,line)){
        ofs << "<p>";
        out = t->translateEnglishSentence(line);
        ofs << out << "<br></p>";
    }
    ofs << "</i></p></body></html>";
    ifs.close();
    ofs.close();
}