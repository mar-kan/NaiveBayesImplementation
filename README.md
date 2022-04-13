# NaiveBayesImplementation
A custom implementation of the Naive Bayes algorithm written in C++

-----------------

    compile instructions: run the included CMake file
    execute instructions: ./bin/NaiveBayesImplementation
    
------------------

- For the development of this project, the dataset used for the training and the testing is the Large Movie Review Dataset [1], containing 25,000 movie 
reviews from IMDB which are split in half for training and testing.

- Also, the library matplotlib-cpp [2] was used to plot graphs.

- The program can perform any iterations the user inputs, in order to be able to test different training sizes. 

- The evaluation metrics used are accuracy, presicion, recall and f1 score.

------------------------------------------

**Overview:** When the program starts, in requets from the console to input the number of repetitions. For each repetitions, it also requests to input the 
size of the training dataset. Then, it trains the algorithm, evaluates the training and test datasets and calculates and prints their accuracy 
metrics. Finally, a graph is printed for each dataset, including the metrics of all the iterations.

----------------------------------------

**Classes:**

- Metrics: calculates and stores all metrics of each iteration of the program.
- NaiveBayes: implements the algorithm's training and evaluation.
- Plot: plots a scatter graph using the abovementioned library.
- Preprocess: preprocesses a string
- Utils: implements various general functions used in the proogram.
- WordList: implements a hashmap where the words and the number of their occurences are stored.
----------------------------------------

[1] Andrew L. Maas, Raymond E. Daly, Peter T. Pham, Dan Huang, Andrew Y. Ng, and Christopher Potts. 2011. 
Learning Word Vectors for Sentiment Analysis. In Proceedings of the 49th Annual Meeting of the Association for Computational Linguistics: 
Human Language Technologies, pages 142–150, Portland, Oregon, USA. Association for Computational Linguistics.

[2] https://github.com/lava/matplotlib-cpp
