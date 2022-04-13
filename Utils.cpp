#include "Utils.h"


void Utils::errorExit(const string& msg)    // writes error message and exits
{
    perror(("Error: "+msg).c_str());
    exit(EXIT_FAILURE);
}


bool Utils::isInteger(const string& str)    // checks if a string is an integer
{
    string::const_iterator it = str.begin();
    while (it != str.end() && std::isdigit(*it))
        ++it;

    return !str.empty() && it == str.end();
}


string Utils::inputString()     // inputs a string from the console
{
    string reps;
    cin >> reps;

    return reps;
}

int Utils::convertToInt(const string& str)  // converts a string to an integer
{
    if (!isInteger(str))
        Utils::errorExit("Input is not an integer.");

    return stoi(str);
}

list<string> * Utils::readDirectory(const string& dirPath)  // reads and directory and stores all file names in a list
{
    auto * files = new list<string>();
    DIR *dir;
    struct dirent *ent;
    if ((dir = opendir(dirPath.c_str())))
    {
        while ((ent = readdir (dir)))
        {
            if ((string)ent->d_name == "." || (string)ent->d_name == "..")
                continue;
            files->push_back(ent->d_name);
        }
        closedir(dir);
    } else {
        errorExit("Could not open directory "+dirPath);
    }
    return files;
}

ifstream Utils::openFile(const string& file, const string& datatype, const string& reviewtype)  // opens a file for reading
{
    string fullPath = Utils::getCurrentPath();
    fullPath.append("/imdb/").append(datatype).append("/").append(reviewtype.substr(0,3)).append("/").append(file);

    ifstream infile(fullPath);
    if (!infile)
        Utils::errorExit("File "+fullPath+" does not exist");

    return infile;
}

string Utils::getCurrentPath()  // returns the path of the current directory
{
    char cwd[PATH_MAX];
    getcwd(cwd, sizeof(cwd));
    return (string)cwd;
}

