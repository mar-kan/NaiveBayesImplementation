#include "Metrics.h"
#include "Plot.h"

int main() {
    cout<<endl<<"Enter number of repetitions"<<endl;
    int repetitions = Utils::convertToInt(Utils::inputString());

    auto * trainMetrics = new Metrics(repetitions);        // stores train metrics of every repetition
    auto * testMetrics = new Metrics(repetitions);         // stores test metrics of every repetition
    auto * trainSizes = new vector<double>(repetitions);     // stores train sizes of every repetition

    for(int i=0;i<repetitions;i++)
    {
        cout<<"Enter training size (maximum 12500)"<<endl;
        int size = Utils::convertToInt(Utils::inputString());

        auto * nb = new NaiveBayes(0.02, size*6, 5, size);
        trainSizes->at(i)=size;

        if (repetitions != 1)
            cout << "-----Iteration "<<i+1<<"-----"<<endl;

        /** training and evaluating training set **/
        nb->train();
        nb->evaluate("train", "positive");
        nb->evaluate("train", "negative");
        trainMetrics->calculateAllMetrics(nb, i);

        nb->resetValues();

        /** evaluating test set **/
        nb->evaluate("test", "positive");
        nb->evaluate("test", "negative");
        testMetrics->calculateAllMetrics(nb, i);

        /** printing metrics for both sets **/
        cout<<endl<<"Evaluation metrics of the training dataset"<<endl;
        trainMetrics->print(i);
        cout<<endl<<"Evaluation metrics of the test dataset"<<endl;
        testMetrics->print(i);

        delete nb;
    }

    /** plotting a graph for each set containing all the metrics **/
    Plot::plot(trainSizes, trainMetrics->getAccuracy(), trainMetrics->getPrecision(), trainMetrics->getRecall(), trainMetrics->getF1(), "training");
    Plot::plot(trainSizes, testMetrics->getAccuracy(), testMetrics->getPrecision(), testMetrics->getRecall(), testMetrics->getF1(), "test");

    delete trainMetrics;
    delete testMetrics;
    delete trainSizes;
}
