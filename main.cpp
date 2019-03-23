//
// Task(5): Read whole file into memory; Return number of symbols aside from whitespaces.


#include <iostream>

#include "functions/time_measure.h"
#include "functions/read_methods.h"
#include "functions/comparison.h"


using namespace std;


int is_ext(const std::string& filename, const std::string& ext)
    { return filename.compare(filename.length()-ext.length(), ext.length(), ext); }





int main(int argc, char *argv[]) {
    if (argc < 2) { std::cout << "Too few arguments given." << std::endl; return -1; }
    int method_id;
    std::string in_filename, out_filename;

    std::stringstream s_method (argv[1]);
    if (s_method >> method_id){

        in_filename = argv[2];
        out_filename = argv[3];
        if (!in_filename.empty() || !out_filename.empty() || is_ext(in_filename, ".txt") || is_ext(out_filename, ".txt")){

            test_all(10, in_filename, out_filename);
            /*
            std::string method_name = name_map[method_id];
            auto result_t = test_one(method_name, in_filename, out_filename);

            // Output
            std::cout << "Reading " << in_filename << " using -" << method_name << "- method:" << std::endl;
            std::cout <<  to_mcs(result_t) << std::endl;
             */

        } else { std::cout << "Both 'in-' and 'out-' filename must be specified." << std::endl; exit(0); }
    } else { std::cout << "Invalid method specification." << std::endl; exit(0); }


    return 0;
}