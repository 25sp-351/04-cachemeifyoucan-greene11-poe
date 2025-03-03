#include "input_output.h"
#include "rodcut.h"
#include <stdio.h>
#include <stdlib.h>

#define MAXIMUM_LENGTH 100
#define MAXIMUM_PRICE 100
#define LINE_BUFFER_MAXIMUM 64

void process_input_and_output(int supplied_rod_length) {
    int iteration = 0;
    int lengths[MAXIMUM_LENGTH];
    int prices[MAXIMUM_PRICE];
    char line[LINE_BUFFER_MAXIMUM];

    printf("Enter lengths and prices separated by a comma (e.g. 1, 2):\n");
    printf("Windows: Ctrl + Z, Enter to finish. Mac: Ctrl + D to finish.\n");

    while (fgets(line, sizeof(line), stdin)) {
        if (sscanf(line, "%d, %d", &lengths[iteration], &prices[iteration]) != 2) {
            break;
        }
        iteration++;
    }

    int cuts[MAXIMUM_LENGTH] = {0};
    int max_profit = maximize_rod_cut_profits(supplied_rod_length, prices, lengths, iteration, cuts, MAXIMUM_LENGTH);
    int remaining_length = supplied_rod_length;

    for (int i = 0; i < iteration; i++) {
        if (cuts[lengths[i]] > 0) {
            printf("\n%d @ %d = %d\n", cuts[lengths[i]], lengths[i], cuts[lengths[i]] * prices[i]);
            remaining_length -= cuts[lengths[i]] * lengths[i];
        }
    }

    printf("Remainder: %d\n", remaining_length);
    printf("Value: %d\n", max_profit);
}