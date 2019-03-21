//
// (5) Read whole file into buffer; Return number of symbols aside from whitespaces.


#include "time_measure.h"
#include "read methods.h"


int main(int argc, char *argv[]) {

    int read_method = std::stoi(argv[1]);
    std::cout << read_method << std::endl;

    /*
    auto start_t = get_current_time_fenced();
    auto finish_t = get_current_time_fenced();
    auto process_t = finish_t - start_t;

    std::cout << to_mcs(process_t)<< std::endl;
    std::cout << to_mls(process_t)<< std::endl;
    */

    return 0;
}


/* ToDo:
 * std:stoi;
 * exception for non-text files
 */