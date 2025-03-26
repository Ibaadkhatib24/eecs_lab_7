#include <stdio.h>

void findCombinations(int score) {
    printf("possible combinations for score %d:\n\n", score);
    
    // loop through all possible touchdown and 2 point counts
    for (int td_2pt = 0; td_2pt * 8 <= score; td_2pt++) {
        // loops through all the possible touch down and field goal counts with remaining points
        for (int td_fg = 0; td_fg * 7 <= (score - td_2pt * 8); td_fg++) {
            // loops through all the possible td counts with the remaining points
            for (int td = 0; td * 6 <= (score - td_2pt * 8 - td_fg * 7); td++) {
                // loops through all the possible fg counts with remaining points
                for (int fg = 0; fg * 3 <= (score - td_2pt * 8 - td_fg * 7 - td * 6); fg++) {
                    // calculates the remaining points after the current combo
                    int remaining = score - td_2pt * 8 - td_fg * 7 - td * 6 - fg * 3;
                    // check if remaining can be safeties (must be even)
                    if (remaining % 2 == 0) {
                        int safety = remaining / 2;
                        // safety doesnt count since it can't be negative
                        if (safety >= 0) {
                            // prints the combinations the code can output
                            printf("%d td+2pt, %d td+fg, %d td, %d fg, %d safety\n",
                                   td_2pt, td_fg, td, fg, safety);
                        }
                    }
                }
            }
        }
    }
}

int main() {
    int score;

    while (1) {
        printf("enter nfl score (0 or 1 to stop): ");
        scanf("%d", &score);

        // exits if score is 0 or 1
        if (score <= 1) {
            break;
        }

        // finds all the compbinations and printst the output 
        findCombinations(score);
    }

    return 0;
}