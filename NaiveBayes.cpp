#include "NaiveBayes.h"

NaiveBayes::NaiveBayes(double smooth,int toCheck,int toSkip,int size)
{
    posWords = new WordList();
    negWords = new WordList();
    posWordCount = 0;
    negWordCount = 0;

    smoothingFactor = smooth;
    wordsToCheck = toCheck;
    wordsToSkip = toSkip;
    trainSize = size;

    truePositives = 0;
    falsePositives = 0;
    trueNegatives = 0;
    falseNegatives = 0;
}

NaiveBayes::~NaiveBayes()
{
    delete posWords;
    delete negWords;
}

void NaiveBayes::train()
{
    cout<<endl<<"Training..."<<endl;

    char cwd[PATH_MAX];
    getcwd(cwd, sizeof(cwd));
    string currPath = (string)cwd;

    list<string> * posFiles = Utils::readDirectory(currPath+"/imdb/train/pos");
    list<string> * negFiles = Utils::readDirectory(currPath+"/imdb/train/neg");

    /* reads all files of the two directories */
    int count=0;
    for (const string& file : *posFiles)
    {
        if (count++ == trainSize)
            break;               // stops if the counter reaches the specified training size

        ifstream infile = Utils::openFile(file, "train", "pos");
        string word;

        // reads every word of each file and classifies its words as positive
        while (infile >> word)
        {
            word = Preprocess::preprocess(word);
            if (!word.empty() &&  word !=" " && word !="-")
            {
                posWords->add(word);
                posWordCount++;
            }
        }
    }
    count=0;
    for (const string& file : *negFiles)
    {
        if (count++ == trainSize)
            break;

        ifstream infile = Utils::openFile(file, "train", "neg");
        string word;

        // reads every word of each file and classifies its words as negative
        while (infile >> word)
        {
            word = Preprocess::preprocess(word);
            if (!word.empty() &&  word !=" " && word !="-")
            {
                negWords->add(word);
                negWordCount++;
            }
        }
    }
    posWords->sortByValue();
    negWords->sortByValue();

    // cutting the <wordsToSkip> most common words and keeping from the rest only the <wordsToCheck> most common words
    posWords->cutWords(wordsToSkip,wordsToCheck);
    negWords->cutWords(wordsToSkip,wordsToCheck);

    cout<<"Training complete!"<<endl;

    delete posFiles;
    delete negFiles;
}

void NaiveBayes::evaluate(const string& datatype, const string& restype)
{
    cout<<endl<<"Evaluating the "<<restype<<" review "<<datatype<<" dataset"<<endl;

    list<string> * files = Utils::readDirectory("imdb/"+datatype+"/"+restype.substr(0,3));
    int badMovies=0, goodMovies=0;
    int count=0;

    /* reads all files of the directory */
    for (const string& file : *files)
    {
        if (datatype=="train" && count++ == trainSize)
            break;           // stops only if the train set is used and the counter reaches the specified training size

        long double good = 1.0;
        long double bad = 1.0;

        ifstream infile = Utils::openFile(file, datatype, restype);
        if (!infile.is_open()) Utils::errorExit("File "+file+" cannot be opened");

        /* reads file word by word */
        string word;
        while (infile >> word)
        {
            word = Preprocess::preprocess(word);

            int size;
            if (datatype=="test")
                size=12500;
            else
                size=trainSize;

            // calculates the probability of the word to belong to each class
            good *= (long double)(posWords->getWordCount(word)+smoothingFactor)/(size+smoothingFactor*posWords->getSize());
            bad *= (long double)(negWords->getWordCount(word)+smoothingFactor)/(size+smoothingFactor*negWords->getSize());
        }

        /* classifies it in the class with the highest probability */
        if(good > bad)
        {
            goodMovies++;

            if (restype=="positive")
                truePositives++;
            else
                falsePositives++;
        }
        else if(bad > good)
        {
            badMovies++;

            if (restype=="positive")
                falseNegatives++;
            else
                trueNegatives++;
        }
    }
    cout<<"\tGood reviews: "<<goodMovies<<endl;
    cout<<"\tBad reviews: "<<badMovies<<endl;

    delete files;
}

void NaiveBayes::resetValues()
{
    // resets all evaluation values

    truePositives = 0;
    falsePositives = 0;
    trueNegatives = 0;
    falseNegatives = 0;
}


int NaiveBayes::getTruePositives() const {
    return truePositives;
}

int NaiveBayes::getFalsePositives() const {
    return falsePositives;
}

int NaiveBayes::getTrueNegatives() const {
    return trueNegatives;
}

int NaiveBayes::getFalseNegatives() const {
    return falseNegatives;
}
