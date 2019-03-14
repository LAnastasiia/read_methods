//Read whole file into buffer; Return number of symbols aside from whitespaces.

#include <iostream>
#include <unistd.h>
#include <fstream>
#include <vector>
#include <bits/stdc++.h>
#include<string.h>



// Read file word-by-word and return (int) the total length of words read.     | (-1) if file couldn't be opened
int read_word_by_word(const std::string &file_name){
    using std::cout;
    using std::endl;
    using std::string;

    std::ifstream in_file(file_name);

    if ( in_file.is_open() ){

        std::string word;
        int s_len = 0;

        while (in_file >> word)
        {
            s_len += word.length();
            if (in_file.rdstate() == std::ios::eofbit) { return s_len; }
        }
        in_file.close();
    }
    return -1;
}


int main() {
    using std::cout;
    using std::endl;
    using std::string;

    std::cout << read_word_by_word("in_data.txt")<< std::endl;
    return 0;
}


/*
 *  std::cout << typeid(in_file).name() << std::endl;
 *  std::cout << "word:     " << word << std::endl;
 *  std::cout << "bit-flag: " << in_file.rdstate() << '\n' << std::endl;
 *  std::cout << in_file.rdstate() << std::endl;
    auto content = std::string{"ert"};
    std::cout << content << std::endl;


    std::cout << *std::istreambuf_iterator<char>{in_file} << std::endl;


    // Copy read content into the 'content' string

    std::copy(std::istreambuf_iterator<char>{in_file},   // begin ~ ptr on the beginning of a buffer with file contents
              std::istreambuf_iterator<char>{},          // end ~ ? (next cell after content's end)
              std::back_inserter(content));
    std::cout << content << std::endl;


    std::cout << "2: " << std::endl;

    std::vector<string> words;
    string word;
    in_file >> word;
    std::cout << word << std::endl;
*/






// Get curr dir
//
//char buff[FILENAME_MAX];
//GetCurrentDir( buff, FILENAME_MAX );
//std::string current_working_dir(buff);
//std::cout << current_working_dir << std::endl;