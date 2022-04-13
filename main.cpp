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

    auto * plot = new Plot(); //accuracy noot precision
    Plot::plot(trainSizes, trainMetrics->getPrecision());
//    plot->addLinePlot("accuracy",y,accuracyTrain);
//    plot->setAxisLabels("training size","accuracy");
//    JFrame frame=new JFrame("accuracy for train data");
//    frame->setSize(800, 800);
//    frame->setContentPane(plot);frame->setVisible(true);
//    frame->setDefaultCloseOperation(JFrame->DISPOSE_ON_CLOSE);
//
//    Plot2DPanel plot2=new Plot2DPanel();
//    plot2->addLinePlot("precision",y,precisionTrain);
//    plot2->setAxisLabels("training size","precision");
//    JFrame frame2=new JFrame("precision for train data");
//    frame2->setSize(800, 800);
//    frame2->setContentPane(plot2);
//    frame2->setVisible(true);
//    frame2->setDefaultCloseOperation(JFrame->DISPOSE_ON_CLOSE);
//
//    Plot2DPanel plot3=new Plot2DPanel();
//    plot3->setAxisLabels("training size","recall");
//    plot3->addLinePlot("recall",y,recallTrain);
//    JFrame frame3=new JFrame("recall for train data");
//    frame3->setSize(800, 800);
//    frame3->setContentPane(plot3);
//    frame3->setVisible(true);
//    frame3->setDefaultCloseOperation(JFrame->DISPOSE_ON_CLOSE);
//
//    Plot2DPanel plot4=new Plot2DPanel();
//    plot4->addLinePlot("f1",y,f1Train);
//    plot4->setAxisLabels("training size","f1 score");
//    JFrame frame4=new JFrame("f1 score for train data");
//    frame4->setSize(800, 800);
//    frame4->setContentPane(plot4);
//    frame4->setVisible(true);
//    frame4->setDefaultCloseOperation(JFrame->DISPOSE_ON_CLOSE);
//
//    Plot2DPanel plot5=new Plot2DPanel();
//    plot5->addLinePlot("accuracy",y,accuracyTest);
//    plot5->setAxisLabels("training size","accuracy");
//    JFrame frame5=new JFrame("accuracy for test data");
//    frame5->setSize(800, 800);
//    frame5->setContentPane(plot5);
//    frame5->setVisible(true);
//    frame5->setDefaultCloseOperation(JFrame->DISPOSE_ON_CLOSE);
//
//    Plot2DPanel plot6=new Plot2DPanel();
//    plot6->addLinePlot("precision",y,precisionTest);
//    plot6->setAxisLabels("training size","precision");
//    JFrame frame6=new JFrame("precision for test data");
//    frame6->setSize(800, 800);
//    frame6->setContentPane(plot6);
//    frame6->setVisible(true);
//    frame6->setDefaultCloseOperation(JFrame->DISPOSE_ON_CLOSE);
//
//    Plot2DPanel plot7=new Plot2DPanel();
//    plot7->addLinePlot("recall",y,recallTest);
//    plot7->setAxisLabels("training size","recall");
//    JFrame frame7=new JFrame("recall for test data");
//    frame7->setSize(800, 800);
//    frame7->setContentPane(plot7);
//    frame7->setVisible(true);
//    frame7->setDefaultCloseOperation(JFrame->DISPOSE_ON_CLOSE);
//
//    Plot2DPanel plot8=new Plot2DPanel();
//    plot8->addLinePlot("f1",y,accuracyTrain);
//    plot8->setAxisLabels("training size","f1 score");
//    JFrame frame8=new JFrame("f1 score for test data");
//    frame8->setSize(800, 800);
//    frame8->setContentPane(plot8);
//    frame8->setVisible(true);
//    frame8->setDefaultCloseOperation(JFrame->DISPOSE_ON_CLOSE);
//    plt::plot({1,3,2,4});
//    plt::show();

    delete trainMetrics;
    delete testMetrics;
    delete trainSizes;
    delete plot;
}
