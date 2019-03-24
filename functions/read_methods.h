//
// Created by anastasiia on 21.03.19.
//

#ifndef CHEKER_READ_METHODS_H
#define CHEKER_READ_METHODS_H

#include <iostream>
#include <fstream>
#include <vector>
#include <unistd.h>
#include <bits/stdc++.h>
#include <boost/regex.hpp>
#include <boost/algorithm/string/erase.hpp>
#include <boost/numeric/conversion/cast.hpp>

using std::cout;
using std::endl;
using std::string;
using boost::numeric_cast;
using boost::regex;


//Check if a file really has a given extension.
int is_ext(const std::string& filename, const std::string& ext)
{ return filename.compare(filename.length()-ext.length(), ext.length(), ext); }


// Read file word-by-word into vector of strings; return total length of words.        | (-1) if file couldn't be opened
size_t read_word_by_word(const std::string &file_name)
{
    std::ifstream in_file(file_name);
    if (in_file.is_open() && !in_file.rdstate()){

        size_t s_len =0;
        std::string word;
        std::vector<string> words;

        while (in_file >> word)
        { s_len += word.length();
            words.push_back(word); }

        in_file.close();
        return s_len;

    } else { return (size_t) -1u;}
}



// Copy non-space symbols one-by-one into content str; return length of content str.   | (-1) if file couldn't be opened
size_t read_copy_to_str(const std::string &file_name)
{
    std::ifstream in_file(file_name);
    if (in_file.is_open())
    {
        std::string content_str;
        std::copy_if(std::istreambuf_iterator<char>{in_file},     // copy non-space text from buffer into content_str
                     std::istreambuf_iterator<char>{},
                     std::back_inserter(content_str),
                     [](auto c) { return ! isspace (c); });       // predicate - lambda-func - 1 if char is non-space

        in_file.close();
        return (size_t) content_str.length();

    } else { return (size_t) -1u; }
}




// Read into stringstream, get rid of spaces using regex; return length of final str.  | (-1) if file couldn't be opened
size_t read_stringstream(const std::string &file_name)
{
    std::ifstream in_file(file_name);
    if (in_file.is_open() && !in_file.rdstate()) {

        std::stringstream content;      // init a stringstream
        content << in_file.rdbuf();     // load file-contents

        string s = content.str();                            // get string component from stringstream

        s = std::regex_replace(s, std::regex("\\s+"), "");   // replace all spaces using Regular Expressions
        in_file.close();
        return boost::numeric_cast<size_t>(s.length());

    } else { return (size_t) -1u; }
}



// Used this article:
// https://web.archive.org/web/20180314195042/http://cpp.indi.frih.net/blog/2014/09/how-to-read-an-entire-file-into-memory-in-cpp/

// Safe read into max stream possible.                   | (-1) if file couldn't be opened | (-2) if stream buffer fails
size_t read_big_files(const std::string &file_name)
{
    std::ifstream in_file(file_name);
    if (in_file.is_open() && !in_file.rdstate())
    {
        auto max_buff = std::numeric_limits<std::streamsize>::max();          // get the max stream size available
        auto const start_pos = in_file.tellg();                               // current shift state in_file the stream

        if (start_pos != -1)
        {
            in_file.ignore(max_buff);                                              // read given max stream capacity
            auto const char_count = static_cast<const size_t>(in_file.gcount());   // number of bytes read by ignore()
            in_file.seekg(start_pos);                                              // move cursor to a given start_pos
            auto s = std::string(char_count, char{});                              // string of same size as the stream
            in_file.read(&s[0], s.size());                                         // load into sized-above string s
            in_file.close();
            s.erase(remove_if(s.begin(), s.end(), isspace), s.end());              // remove space chars
            return boost::numeric_cast<size_t>(s.length());

        }else { in_file.close(); return (size_t) -2u; }
    } else { return (size_t) -1u; }
}


#endif //CHEKER_READ_METHODS_H
