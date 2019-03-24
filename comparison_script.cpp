// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: http://www.viva64.com

// Compare all methods, return min time for each. Write back results.



int main_2(int argc, char *argv[]){
    if (argc < 2) { std::cout << "Too few arguments given." << std::endl; return -1; }
    int nexp;
    std::string in_filename, out_filename;

    std::stringstream s_nexp (argv[1]);
    if (s_nexp >> nexp){

        in_filename = argv[2];
        out_filename = argv[3];
        if (!in_filename.empty() || !out_filename.empty() || is_ext(in_filename, ".txt") || is_ext(out_filename, ".txt")){

            auto all_results = test_all(, in_filename, out_filename);

            // Output
            std::cout << "Experimenting on reading " << in_filename << ": " << std::endl;
            for(const auto &mi: all_results){
                std::cout <<  mi.first;
            }

        } else { std::cout << "Both 'in-' and 'out-' filename must be specified." << std::endl; exit(0); }
    } else { std::cout << "Invalid number of experiments." << std::endl; exit(0); }

    return 0;
}

