#ifndef NAIVEBAYESIMPLEMENTATION_NAIVEBAYES_H
#define NAIVEBAYESIMPLEMENTATION_NAIVEBAYES_H

#include "WordList.h"
#include "Preprocess.h"


class NaiveBayes {

    WordList * posWords;
    WordList * negWords;
    
    int posWordCount;
    int negWordCount;

    int trainSize;
    int wordsToSkip;
    int wordsToCheck;
    double smoothingFactor;

    int truePositives;
    int falsePositives;
    int trueNegatives;
    int falseNegatives;

public:

    NaiveBayes(double,int,int,int);
    ~NaiveBayes();

    void train();
    void evaluate(const string&, const string&);
    void resetValues();

    int getTruePositives() const;
    int getFalsePositives() const;
    int getTrueNegatives() const;
    int getFalseNegatives() const;
};

#endif
