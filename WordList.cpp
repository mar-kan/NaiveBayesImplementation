#include "WordList.h"


WordList::WordList()
{
    words=new multimap<int, string, greater<> >();
}
WordList::~WordList()
{
    delete words;
}

void WordList::add(const string& word)  // adds a number to the map or increases its occurrences by 1
{
    pair<int, string> p = search(word);

    if(p.first == -1)
        words->insert(make_pair(1, word));
    else
        changeValue(word);
}

void WordList::add(int count, const string& word)   // adds new pair to the list
{
    words->insert(make_pair(count, word));
}

pair<int, string> WordList::search(const string& key)   // searches for a word in the map and returns its pair
{
    for (auto & pair : *words)
    {
        if (pair.second == key)
            return pair;
    }
    return make_pair(-1, "");
}

void WordList::changeValue(const string& key)           // increments the number of occurrences of a word
{
    for (auto it = words->begin(); it != words->end(); ++it)
    {
        if (it->second == key)
        {
            pair<int, string> pair = *it;
            words->erase(it);
            this->add(pair.first+1, pair.second);
            break;
        }
    }
}

int WordList::getWordCount(const string& word)           // returns the number of occurrences of a word
{
    pair<int, string> p = search(word);
    if(p.first == -1)
        return 0;

    return p.first;
}

void WordList::sortByValue()
{
    //sort(words->begin(), words->end(), comparator);
}

void WordList::cutWords(int skip, int check)
{
    // cuts <skip> words from the beginning
    auto it = words->begin();
    if (words->size() > skip)
        std::advance(it, skip-1);

    // keeps <check> words and cuts all the rest from the end
    if (words->size() > check)
    {
        it = words->begin();
        std::advance(it, check-1);
        words->erase(it,words->end());
    }
}

bool WordList::comparator(pair<string, int>& a, pair<string, int>& b)
{
    return a.second > b.second;
}

int WordList::getSize()
{
    return (int)words->size();
}
