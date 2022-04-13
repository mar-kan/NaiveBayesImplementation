#include "Plot.h"
#include "Utils.h"
#include "matplotlib-cpp-master/matplotlibcpp.h"
namespace plt = matplotlibcpp;


void Plot::plot(vector<double>* y, vector<double> * accuracyTrain)
{
    plt::figure_size(1200, 780);
    plt::named_plot("accuracy", *accuracyTrain, *y, "bo");

    plt::title("Accuracy of training data");
    plt::ylabel("training size");
    plt::xlabel("accuracy");

    plt::legend();
    plt::show();
    plt::save("./results/acc_train.png");
}