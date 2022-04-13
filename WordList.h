#ifndef NAIVEBAYESIMPLEMENTATION_WORDLIST_H
#define NAIVEBAYESIMPLEMENTATION_WORDLIST_H

#include "Utils.h"
#include <bits/stdc++.h>


class WordList {
    multimap<int, string, greater<> > * words;

public:
    WordList();
    ~WordList();

    void add(const string& word);
    void add(int count, const string& word);
    pair<int, string> search(const string&);
    void changeValue(const string& key);
    int getWordCount(const string&);
    int getSize();
    void sortByValue();
    void cutWords(int,int);

    static bool comparator(pair<string, int>& , pair<string, int>&);
};


#endif

