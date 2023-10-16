#include <stdio.h>

int main() {
    int score;
    do{
        printf("\nEnter 0 or 1 to STOP\nEnter the NFL score: ");
        scanf("%d", &score);
        if (score <= 1) {
            return(0);
        }
        printf("\nPossible combinations of scoring plays:\n");
        for (int l = 0; l <= score; l += 8) { // touchdown + 2pt
            for (int m = 0; m <= score; m += 7) { // touchdown + field goal
                for (int i = 0; i <= score; i += 6) { // touchdown
                    for (int j = 0; j <= score; j += 3) { // field goal
                        for (int k = 0; k <= score; k += 2) { // safety
                            if (score == i+j+k+l+m) {
                                printf("%d TD + 2pt, %d TD + FG, %d TD, %d 3pt FG, %d Safety\n", l/8, m/7, i/6, j/3, k/2);
                            }
                        }
                    }
                }
            }
        }
    }
    while (score > 1);
}