/**
 * File: main.cpp
 * Developer: Hytham Abdelkarim
 * Email: abdelkarimh@student.vvc.edu
 * Description : A concordance generator program that will list of all the words found in a text file with a count of the number of times the word occurred and a comma delimited list of the line numbers of where  the word occurred.
**/
#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <algorithm>
struct Word {
  int line;
  std::string word;
};

void remove_punctuation(std::string &p);
std::vector<Word> extract_words (std::string &p);
  

std::string input = "Develop a concordance generator program.\nThe concordance will be a list of all the words found in a text file with a count of the number of times the word occurred and a comma delimited list of the line numbers of where the word occurred.\nFor each line of text, all punctuation must be removed and all letters in the string forced to lowercase.\nThen, separate out the words and check each word against your list.\nKeep track of the current line number and check if the word has been found before.\nIf the word has not been seen before, put it in some sort of collection data structure (an array or vector for example) and keep track of the line number.\nIf the word has been found before, store the line number of where the word occurred.\nWhen the text file has been scanned, print the words and line numbers in the following format:";

int main() { 
   std::map<std::string, Word > concordance;
   remove_punctuation(input);
   std::cout << input << std::endl;
   std::vector<Word> words = extract_words(input);
   for(int i = 0;i < words.size(); i++)
   {
     std::cout << words[i].word << std::endl;
   }
   return 0;
}

void remove_punctuation(std::string &p){
  
  p.erase (std::remove_if (p.begin (), p.end (), ispunct), p.end ());
}

std::vector<Word> extract_words(std::string &p){
 std::vector<Word> words;
  int lines = 1;
  while(p.length() > 1){
    int e = p.find(' ');
    int new_line = p.find('\n');
    if(new_line == -1 ){
      std::cout << "no nl" << std::endl;
    }
      if(e+1 <= p.length()){
        Word w;
        w.line = lines;
        w.word = p.substr(0,e);
        words.push_back(w);
        if(e != -1)
        {
          p.erase(0,e + 1);
        }
        else{
          break;
        }
        
      }
  }
  return words;
}
