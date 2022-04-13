#include "Preprocess.h"


string Preprocess::preprocess(string str)
{
    /** converts string to lower case and removes all special characters and whitespaces **/

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
    /** finds and removes all occurrences of a character in str **/
    size_t index = 0;
    index = str.find(ch, index);

    while (index != std::string::npos)
    {
        str.replace(index, 1, "");
        index = str.find(ch, index);
    }
    return str;
}
