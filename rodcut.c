#include "rodcut.h"
#include <string.h>

int maximize_rod_cut_profits(int rod_length, int prices[], int lengths[], int num_cuts, int cuts[], int cuts_size) {
    int max_profit_table[rod_length + 1];
    int best_piece_for_length[rod_length + 1];

    memset(max_profit_table, 0, sizeof(max_profit_table));
    memset(best_piece_for_length, 0, sizeof(best_piece_for_length));

    for (int current_length = 1; current_length <= rod_length; current_length++) {
        for (int available_cut_index = 0; available_cut_index < num_cuts; available_cut_index++) {
            if (lengths[available_cut_index] <= current_length) {
                int new_profit = prices[available_cut_index] + max_profit_table[current_length - lengths[available_cut_index]];
                if (new_profit > max_profit_table[current_length]) {
                    max_profit_table[current_length] = new_profit;
                    best_piece_for_length[current_length] = lengths[available_cut_index];
                }
            }
        }
    }

    for (int temp_length = rod_length; temp_length > 0; temp_length -= best_piece_for_length[temp_length]) {
        // Add a check to ensure that best_piece_for_length[temp_length] is within the valid range of cuts array indices
        if (best_piece_for_length[temp_length] >= 0 && best_piece_for_length[temp_length] < cuts_size) {
            cuts[best_piece_for_length[temp_length]]++;
        } else {
            // Handle the error (e.g., print an error message and return -1)
            fprintf(stderr, "Error: Invalid cut index\n");
            return -1; // Or handle the error appropriately
        }
    }

    return max_profit_table[rod_length];
}