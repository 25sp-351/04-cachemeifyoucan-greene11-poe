#include "rodcut.h"
#include "input_output.h" // Include the header file
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <limits.h>

int main(int argc, char **argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <supplied rod length>\n", argv[0]);
        return 1;
    }

    char *endptr;
    // Pass argv[1] directly to strtol
    long int supplied_rod_length = strtol(argv[1], &endptr, 10); 

    if (errno == ERANGE || *endptr != '\0' || supplied_rod_length > INT_MAX || supplied_rod_length < 0) {
        fprintf(stderr, "Invalid rod length: %s\n", argv[1]);
        return 1;
    }

    process_input_and_output(supplied_rod_length);

    return 0;
}