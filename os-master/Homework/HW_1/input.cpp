#include <fstream>
#include <iostream>

using namespace std;

int main(int argc, char **argv) {
    ofstream myfile(argv[1], std::fstream::app);
    if (myfile.is_open()) {
        myfile << argv[2];
        myfile.close();
    } else
        cout << "Unable to open file";
}