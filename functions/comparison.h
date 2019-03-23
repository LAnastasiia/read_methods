//
// Script: Read whole file into memory using 4 different methods; Write results into comparison_out.txt.

#include <iostream>
#include "time_measure.h"
#include "read_methods.h"
using namespace std;

std::map <int, std::string> name_map = { {1, "read_word_by_word"},
                                         {2, "read_copy_to_str"},
                                         {3, "read_stringstream"},
                                         {4, "read_big_files"} };

std::map <std::string, function<size_t (const string&)>> method_map = { {"read_word_by_word", &read_word_by_word},
                                                                        {"read_copy_to_str", &read_copy_to_str},
                                                                        {"read_stringstream", &read_stringstream},
                                                                        {"read_big_files", &read_big_files} };


auto test_one(const std::string method_name,  const std::string &in_filename, const std::string &out_filename="")
{
    auto start_t = get_current_time_fenced();                       // Calculate time.
    size_t result = method_map[method_name](in_filename);
    auto finish_t = get_current_time_fenced();
    auto result_t = finish_t - start_t;

    if (!out_filename.empty()){                                     // File-Output.
        std::ofstream out_file(out_filename);
        out_file << result; out_file << std::endl;
        out_file.close();
    }
    return result_t;
}

int test_all(int expr_num, const std::string &in_filename, const std::string &out_filename=""){
    std::map< int, std::vector<std::chrono::duration<double>> > results;

    for(const auto &mi: name_map){
        for (int i=0; i < expr_num; i++){
            results[mi.first].push_back(test_one(mi.second, in_filename, out_filename));
        }
        return 0;
    }
}
