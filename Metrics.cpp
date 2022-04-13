#include "Metrics.h"


Metrics::Metrics(int size)
{
    accuracy = new vector<double>(size);
    precision = new vector<double>(size);
    recall = new vector<double>(size);
    f1 = new vector<double>(size);
}

Metrics::~Metrics()
{
    delete accuracy;
    delete precision;
    delete recall;
    delete f1;
}


void Metrics::calculateAllMetrics(NaiveBayes * nb, int rep)
{
    accuracy->at(rep) = calculateAccuracy(nb);
    precision->at(rep) = calculatePrecision(nb);
    recall->at(rep) = calculateRecall(nb);
    f1->at(rep) = calculateF1(rep);
}

void Metrics::print(int rep)
{
    cout<<"\tAccuracy: "<<accuracy->at(rep)*100<<"%"<<endl<<"\tPrecision: "<<precision->at(rep)*100<<"%"<<endl<<"\tRecall: "<<recall->at(rep)*100<<"%"<<endl<<"\tF1-score: "<<f1->at(rep)*100<<"%"<<endl;
}

double Metrics::calculateAccuracy(NaiveBayes *nb)
{
    return (double) (nb->getTruePositives()+nb->getTrueNegatives()) / (nb->getTrueNegatives()+nb->getTruePositives()+nb->getFalseNegatives()+nb->getFalsePositives());
}

double Metrics::calculatePrecision(NaiveBayes *nb)
{
    return (double) (nb->getTruePositives())/(nb->getTruePositives()+nb->getFalsePositives());
}

double Metrics::calculateRecall(NaiveBayes *nb)
{
    return (double) (nb->getTruePositives())/(nb->getTruePositives()+nb->getFalseNegatives());
}

double Metrics::calculateF1(int rep)
{
    return 2*(precision->at(rep) * recall->at(rep))/(precision->at(rep)+recall->at(rep));
}

vector<double> *Metrics::getAccuracy() const {
    return accuracy;
}

vector<double> *Metrics::getPrecision() const {
    return precision;
}

vector<double> *Metrics::getRecall() const {
    return recall;
}

vector<double> *Metrics::getF1() const {
    return f1;
}
