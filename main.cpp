//
// Task(5): Read whole file into memory; Return number of symbols aside from whitespaces.


#include <iostream>
#include <fstream>
#include <vector>
#include <unistd.h>
#include <bits/stdc++.h>
#include <boost/regex.hpp>
#include <boost/algorithm/string/erase.hpp>
#include <boost/numeric/conversion/cast.hpp>
#include <chrono>
#include <atomic>

#include <stdexcept>
#include <string>
#include <cstdlib>

#include "time_measure.h"
#include "read methods.h"


using namespace std;

int is_ext(const std::string& filename, const std::string& ext)
    { return filename.compare(filename.length()-ext.length(), ext.length(), ext); }


int main(int argc, char *argv[]) {

    if (argc < 2) { std::cout << "Too few arguments given." << std::endl; return -1; }

    int method_id;
    std::string in_filename, out_filename;
    // Map for choosing the read method_id.
    std::map<int, function<size_t (const string&)>> method_map = { {1, &read_word_by_word},
                                                                   {2, &read_copy_to_str},
                                                                   {3, &read_stringstream},
                                                                   {4, &read_big_files} };
    std::stringstream s_method (argv[1]);
    if (s_method >> method_id){

        in_filename = argv[2];
        out_filename = argv[3];
        if (!in_filename.empty() || !out_filename.empty() || is_ext(in_filename, ".txt") || is_ext(out_filename, ".txt")){

            // Calculate time.
            auto start_t = get_current_time_fenced();
            size_t result = method_map[method_id](in_filename);
            auto finish_t = get_current_time_fenced();
            auto process_t = to_mcs(finish_t - start_t);

            // Output
            std::cout << process_t << std::endl;
            std::ofstream out_file(out_filename);
            out_file << result;
            out_file.close();

        } else { std::cout << "Both 'in-' and 'out-' filename must be specified." << std::endl; exit(0); }
    } else { std::cout << "Invalid method specification." << std::endl; exit(0); }

    return 0;
}


/* ToDo:
 * exception for non-text files
 */


/*


std::cout << to_mcs(process_t)<< std::endl;
std::cout << to_mls(process_t)<< std::endl;
*/