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



int main(int argc, char *argv[]) {

    if (argc < 2) { return -1; }

    std::stringstream method_s(argv[1]);
    int method;

    return 0;
}


/* ToDo:
 * std:stoi;
 * exception for non-text files
 */


/*
auto start_t = get_current_time_fenced();
auto finish_t = get_current_time_fenced();
auto process_t = finish_t - start_t;

std::cout << to_mcs(process_t)<< std::endl;
std::cout << to_mls(process_t)<< std::endl;
*/