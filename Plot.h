#ifndef NAIVEBAYESIMPLEMENTATION_PLOT_H
#define NAIVEBAYESIMPLEMENTATION_PLOT_H

#include <vector>
#include <string>

#include "matplotlib-cpp-master/matplotlibcpp.h"
namespace plt = matplotlibcpp;
using namespace std;


class Plot {

public:
    static void plot(std::vector<double> *y, std::vector<double> *accuracyTrain, string const &datasetType, const string& metricName);

    static void plotAll(vector<double> *y, vector<double> *acc, vector<double> *prec, vector<double> *rec, vector<double> *f1,
                 const string &datasetType);
};


#endif
