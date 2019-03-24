// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: http://www.viva64.com

// Compare all methods, return min time for each. Write back results.

#include <iostream>
#include "functions/time_measure.h"
#include "functions/read_methods.h"
#include "functions/comparison.h"


int main(int argc, char *argv[]){
    if (argc < 2) { std::cout << "Too few arguments given." << std::endl; return -1; }
    int nexp;
    std::string in_filename, out_filename;

    std::stringstream s_nexp (argv[1]);
    if (s_nexp >> nexp){

        in_filename = argv[2];
        out_filename = argv[3];
        if (!in_filename.empty() || !out_filename.empty() || is_ext(in_filename, ".txt") || is_ext(out_filename, ".txt")){

            // Clear prev data from out-file.
            std::ofstream allout_file(out_filename, std::ofstream::out | std::ofstream::trunc);
            allout_file.close();

            auto all_results = test_all(nexp, in_filename, out_filename);

            // Output
            std::cout << "Experimenting on reading " << in_filename << ": " << std::endl;

            for(const auto &mi: all_results){
                std::cout << "# " << left << setw(24)
                          << name_map[mi.first] << "~ "
                          << to_mcs(*std::min_element(mi.second.begin(),
                                                      mi.second.end())) << std::endl;
            }

            // Tell if all results were equal.
            std::ifstream res_file(out_filename);
            std::string tmp1, tmp2;
            res_file >> tmp1;
            int i = 1;
            while (i < all_results.size() && res_file >> tmp2)
            {
                if (tmp2.compare(tmp1))
                { std::cout << "Results are NOT all equal." << std::endl; exit(0);}
            }
            std::cout << std::endl << "Results are all equal." << std::endl;

        } else { std::cout << "Both 'in-' and 'out-' filename must be specified." << std::endl; exit(0); }
    } else { std::cout << "Invalid number of experiments." << std::endl; exit(0); }

    return 0;
}

