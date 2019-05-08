#include <stdio.h>

int main(int argc, char **argv) {
    int result;
    result = remove(argv[1]);
    if (result != 0) perror("Error deleting file");
    return 0;
}