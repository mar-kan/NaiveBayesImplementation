#include "Utils.h"


void Utils::errorExit(const string& msg)
{
    perror(("Error: "+msg).c_str());
    exit(EXIT_FAILURE);
}


bool Utils::isInteger(const string& str)
{
    string::const_iterator it = str.begin();
    while (it != str.end() && std::isdigit(*it)) ++it;
    return !str.empty() && it == str.end();
}


string Utils::inputString()
{
    string reps;
    cin >> reps;

    return reps;
}

int Utils::convertToInt(const string& str)
{
    if (!isInteger(str))
        Utils::errorExit("Input is not an integer.");

    return stoi(str);
}

list<string> * Utils::readDirectory(const string& dirPath)
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

ifstream Utils::readFile(const string& file, const string& datatype, const string& reviewtype)
{
    string fullPath = Utils::getCurrentPath();
    fullPath.append("/imdb/").append(datatype).append("/").append(reviewtype.substr(0,3)).append("/").append(file);

    ifstream infile(fullPath);
    if (!infile)
        Utils::errorExit("File "+fullPath+" does not exist");

    return infile;
}

string Utils::getCurrentPath()
{
    char cwd[PATH_MAX];
    getcwd(cwd, sizeof(cwd));
    return (string)cwd;
}

