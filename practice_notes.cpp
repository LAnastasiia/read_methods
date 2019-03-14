#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <map>
#include <iomanip>


int basis() {
    using std::cout;
    using std::endl;
    using std::string;

    std::ifstream in_file("data.txt");  // file in current dir
//    std::cout << in_file.is_open() << std::endl;  // 1 - file opened successfully

    std::vector<string> words;
    string word;
    in_file >> word; // read word between whitespaces (or skip first spaces read until end of word)
    in_file >> word; // read next word

    std::map<std::string, int> words_counter;
    while (in_file >> word){
        ++words_counter[word];  // add 1 to word's value in dict map
//        words.push_back(word);
    }
    cout << words.size() << endl;
    std::ofstream out_file("res.txt"); // write in another file (if res.txt exists - cut at the beginning and write new content)
    std::sort(words.begin(), words.end());


//    for (auto&& w: words) {
//        out_file << w << '\n';
//    }



//    out_file << std::left;                     // orient text to left
    out_file << std::left << std::setfill('*');  // * instead of spaces
    for (auto&& w: words_counter){
        out_file << std::setw(20) << w.first << ' ' << w.second << '\n';   // setw(int) -- set width -- маніпулятор з аргументом
    }
    out_file.close();
    return 0;
}





// cout - змінна типу ostream інстанційована для char
// istream - обʼєкт інстанціювання cin --> ifstream, ifstringstream


//bit fail -- noncritical error (e.g. cin reads into int and can't find anything matching int value) -- but file not damaged
//bit bad -- file damaged / buffer damaged
//EOF -- while trying to read after end of file


// Статичний аналізатор коду PVS-Studio