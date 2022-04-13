#ifndef NAIVEBAYESIMPLEMENTATION_METRICS_H
#define NAIVEBAYESIMPLEMENTATION_METRICS_H

#include "NaiveBayes.h"


class Metrics {
    vector<double> * accuracy;
    vector<double> * precision;
    vector<double> * recall;
    vector<double> * f1;

public:
    explicit Metrics(int size);
    ~Metrics();

    void calculateAllMetrics(NaiveBayes * nb, int rep);
    static double calculateAccuracy(NaiveBayes * nb);
    static double calculatePrecision(NaiveBayes * nb);
    static double calculateRecall(NaiveBayes * nb);
    double calculateF1(int rep);
    void print(int rep);

    vector<double> *getAccuracy() const;
    vector<double> *getPrecision() const;
    vector<double> *getRecall() const;
    vector<double> *getF1() const;
};



#endif
