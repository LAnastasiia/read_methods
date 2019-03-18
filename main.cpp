//Read whole file into buffer; Return number of symbols aside from whitespaces.

/* Example:
 * in_data:     83
 * in_data_big: 2275898
 */

#include <iostream>
#include <unistd.h>
#include <fstream>
#include <vector>
#include <bits/stdc++.h>
#include <boost/regex.hpp>
#include <boost/algorithm/string/erase.hpp>
#include <boost/numeric/conversion/cast.hpp>

using std::cout;
using std::endl;
using std::string;
using boost::numeric_cast;
using boost::regex;


// Read file word-by-word into vector of strings; return total length of words.        | (-1) if file couldn't be opened
int read_word_by_word(const std::string &file_name){

    std::ifstream in_file(file_name);

    if (in_file.is_open() && !in_file.rdstate()){

        int s_len =0;
        std::string word;
        std::vector<string> words;

        while (in_file >> word)
            { s_len += word.length();
              words.push_back(word); }

        in_file.close();
        return s_len;

    } else { return -1;}
}


// Copy non-space symbols one-by-one into content str; return length of content str.   | (-1) if file couldn't be opened
int read_copy_to_str(const std::string &file_name){

    std::ifstream in_file(file_name);

    if (in_file.is_open())
    {
        std::string content_str;
        std::copy_if(std::istreambuf_iterator<char>{in_file},     // copy non-space text from buffer into content_str
                     std::istreambuf_iterator<char>{},
                     std::back_inserter(content_str),
                     [](auto c) { return ! isspace (c); });       // predicate - lambda-func - 1 if char is non-space

        in_file.close();
        return int (content_str.length());

    } else { return -1; }
}


// Read into stringstream, get rid of spaces using regex; return length of final str.  | (-1) if file couldn't be opened
int read_stringstream(const std::string &file_name) {

    std::ifstream in_file(file_name);
    if (in_file.is_open() && !in_file.rdstate()) {

        std::stringstream content;      // init a stringstream
        content << in_file.rdbuf();     // load file-contents

        string s = content.str();                            // get string component from stringstream

        s = std::regex_replace(s, std::regex("\\s+"), "");   // replace all spaces using Regular Expressions
        in_file.close();
        return boost::numeric_cast<int>(s.length());

    } else { return -1; }
}


// Safe read method for big files - read into max stream possible.         | (-1) if file couldn't be opened
// !! Used this article:                                                   | (-2) if stream buffer fails
// https://web.archive.org/web/20180314195042/http://cpp.indi.frih.net/blog/2014/09/how-to-read-an-entire-file-into-memory-in-cpp/
int read_big_files(const std::string &file_name){

    std::ifstream in_file(file_name);
    if (in_file.is_open() && !in_file.rdstate())
    {
        auto max_buff = std::numeric_limits<std::streamsize>::max();            // get the max stream size available
        auto const start_pos = in_file.tellg();                                 // current shift state in_file the stream

        if (start_pos != -1)
        {
            in_file.ignore(max_buff);                                               // read given max stream capacity
            auto const char_count = static_cast<const size_t>(in_file.gcount());    // number of bytes read by ignore()
            in_file.seekg(start_pos);                                               // move cursor to a given start_pos
            auto s = std::string(char_count, char{});                               // string of same size as the stream
            in_file.read(&s[0], s.size());                                          // load into sized-above string s
            in_file.close();
            s.erase(remove_if(s.begin(), s.end(), isspace), s.end());               // remove space chars
            return boost::numeric_cast<int>(s.length());

        }else { in_file.close(); return -2; }
    } else { return -1; }
}



int main(int argc, char *argv[]) {

    return 0;
}


/* ToDo:
 * std:stoi;
 * exception for non-text files

 */


//std::cout << read_big_files("cpp_book1.pdf")<< std::endl;

// 2001651
// 1682587
