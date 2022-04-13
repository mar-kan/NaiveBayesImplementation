#include "Metrics.h"
#include "Plot.h"

int main() {
    cout<<endl<<"Enter number of repetitions"<<endl;
    int repetitions = Utils::convertToInt(Utils::inputString());

    auto * trainMetrics = new Metrics(repetitions);
    auto * testMetrics = new Metrics(repetitions);
    auto * trainSizes = new vector<double>(repetitions);

    for(int i=0;i<repetitions;i++)
    {
        cout<<"Enter training size (maximum 12500)"<<endl;
        int size = Utils::convertToInt(Utils::inputString());
        auto * nb = new NaiveBayes(0.02, size*6, 5, size);

        trainSizes->at(repetitions-1)=size;
        if (repetitions != 1)
            cout << "-----Iteration "<<i+1<<"-----"<<endl;

        nb->train();
        nb->evaluate("train", "positive");
        nb->evaluate("train", "negative");
        trainMetrics->calculateAllMetrics(nb, i);

        nb->resetValues();

        nb->evaluate("test", "positive");
        nb->evaluate("test", "negative");
        testMetrics->calculateAllMetrics(nb, i);

        delete nb;

        cout<<endl<<"Evaluation metrics of the training dataset"<<endl;
        trainMetrics->print(repetitions-1);
        cout<<endl<<"Evaluation metrics of the test dataset"<<endl;
        testMetrics->print(repetitions-1);
    }

    auto * plot = new Plot();
    Plot::plot(trainSizes, trainMetrics->getAccuracy());
    Plot::plot(trainSizes, trainMetrics->getPrecision());
    Plot::plot(trainSizes, trainMetrics->getRecall());
    Plot::plot(trainSizes, trainMetrics->getF1());

    Plot::plot(trainSizes, testMetrics->getAccuracy());
    Plot::plot(trainSizes, testMetrics->getPrecision());
    Plot::plot(trainSizes, testMetrics->getRecall());
    Plot::plot(trainSizes, testMetrics->getF1());

    delete trainMetrics;
    delete testMetrics;
    delete trainSizes;
    delete plot;
}
