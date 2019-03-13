#include <fstream>
#include <iostream>

using namespace std;

int main(int argc, char **argv) {
    std::ofstream outfile(argv[1]);
    outfile.close();
}