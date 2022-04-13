#ifndef NAIVEBAYESIMPLEMENTATION_UTILS_H
#define NAIVEBAYESIMPLEMENTATION_UTILS_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <dirent.h>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <unistd.h>
#include <list>


using namespace std;


class Utils {

public:
    static void errorExit(const string&);
    static bool isInteger(const string&);
    static string inputString();
    static int convertToInt(const string&);
    static list<std::string> * readDirectory(const string&);
    static ifstream openFile(const string& file, const string& datatype, const string& reviewtype);
    static string getCurrentPath();
};


#endif
