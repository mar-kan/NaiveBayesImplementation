#include "Preprocess.h"


string Preprocess::preprocess(string str)
{
    std::transform(str.begin(), str.end(), str.begin(), [](unsigned char c){ return std::tolower(c); });

    str = removeAll(str, ' ');
    str = removeAll(str, '.');
    str = removeAll(str, '!');
    str = removeAll(str, '*');
    str = removeAll(str, '\"');
    str = removeAll(str, ',');
    str = removeAll(str, '^');
    str = removeAll(str, '(');
    str = removeAll(str, ')');
    str = removeAll(str, ';');
    str = removeAll(str, ':');
    str = removeAll(str, '<');
    str = removeAll(str, '>');
    str = removeAll(str, '?');
    str = removeAll(str, '%');
    str = removeAll(str, '/');
    str = removeAll(str, '&');
    str = removeAll(str, '+');
    str = removeAll(str, '#');
    str = removeAll(str, '*');
    str = removeAll(str, '\'');
    str = removeAll(str, '%');
    str = removeAll(str, '_');
    str = removeAll(str, '@');
    str = removeAll(str, '$');
    str = removeAll(str, '{');
    str = removeAll(str, '}');
    str = removeAll(str, '[');
    str = removeAll(str, ']');

    return str;
}

string Preprocess::removeAll(string str, char ch)
{
    size_t index = 0;

    index = str.find(ch, index);
    while (index != std::string::npos)
    {
        str.replace(index, 1, "");
        index = str.find(ch, index);
    }

    return str;
}
