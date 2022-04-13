#include "Plot.h"
#include "Utils.h"


void Plot::plot(vector<double>* y, vector<double> * metric, const string& datasetType, const string& metricName)
{
    // plots figure using matplotlib for c++
    plt::figure_size(1200, 780);
    plt::named_plot(metricName, *metric, *y, "bo");

    plt::title(metricName+" of "+datasetType+" data");
    plt::ylabel("training size");
    plt::xlabel(metricName);
    plt::legend();

    // saves figure
    string filename = "./results/";
    filename.append(metricName).append("_").append(datasetType).append(".png");
    plt::save(filename);

    plt::show();
}

void Plot::plotAll(vector<double>* y, vector<double> * acc, vector<double> * prec, vector<double> * rec, vector<double> * f1, const string& datasetType)
{
    // plots figure using matplotlib for c++
    plt::figure_size(1200, 780);
    plt::named_plot("Accuracy", *acc, *y, "bo");
    plt::named_plot("Precision", *prec, *y, "ro");
    plt::named_plot("Recall", *rec, *y, "co");
    plt::named_plot("F1 Score", *f1, *y, "yo");

    plt::title("Metrics of "+datasetType+" data");
    plt::ylabel("training size");
    plt::xlabel("Metrics");
    plt::legend();

    // saves figure
    string filename = "./results/";
    filename.append("allMetrics").append("_").append(datasetType).append(".png");
    plt::save(filename);

    plt::show();
}
