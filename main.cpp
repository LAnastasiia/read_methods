//Read whole file into buffer; Return number of symbols aside from whitespaces.

#include <iostream>
#include <unistd.h>
#include <fstream>
#include <vector>
#include <bits/stdc++.h>



// Read file word-by-word and return (size_t) the total length of words read.     | (-1) if file couldn't be opened
int read_word_by_word(const std::string &file_name){
    using std::cout;
    using std::endl;
    using std::string;

    std::ifstream in_file(file_name);

    if (in_file.is_open() && !in_file.rdstate()){

        int s_len =0;
        std::string word;

        while (in_file >> word)
            { s_len += word.length(); }

        in_file.close();
        return s_len;

    } else { return -1;}
}


int read_copy_iterate(const std::string &file_name){
    using std::cout;
    using std::endl;
    using std::string;

    std::ifstream in_file(file_name);
    if (in_file.is_open() && !in_file.rdstate())
    {
        auto content_str = std::string{};
        std::copy_if(std::istreambuf_iterator<char>{in_file},     // copy non-space text from buffer into content_str
                     std::istreambuf_iterator<char>{},
                     std::back_inserter(content_str),
                     [](auto c) { return ! isspace (c); });       // predicate - (lambda-func 1 if char is not a space)
        in_file.close();
        return int (content_str.length());     // boost::numeric_cast<int>(content_str.length());
    }
}

int read_into_ostream(const std::string &file_name) {
    using std::cout;
    using std::endl;
    using std::string;

    std::ifstream in_file(file_name);
    if (in_file.is_open() && !in_file.rdstate()){

        auto content_str = std::string{};
        auto content_stream = std::ostringstream{};         // initialize another stream

        content_stream << in_file.rdbuf();                  // assign to a pointer to a stream buffer object

        std::cout << content_stream.str() << std::endl;
    }
}


int main() {
    using std::cout;
    using std::endl;
    using std::string;

    std::cout << read_word_by_word("in_data_big.txt")<< std::endl;

    return 0;
}

