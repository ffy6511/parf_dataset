#include <stdio.h>
#include <stdbool.h>
#define MAX_COLORS 500001 // Since the sum of nm across all test cases is 5e5
bool present[MAX_COLORS];
bool has_adjacent[MAX_COLORS];
int color_list[700 * 700]; // Maximum nm per test case is 700*700 = 490000
int main() {
 int t;
 scanf("%d", &t);
 while (t--) {
 int n, m;
 scanf("%d %d", &n, &m);
 int grid[n][m];
 for (int i = 0; i < n; i++) {
 for (int j = 0; j < m; j++) {
 scanf("%d", &grid[i][j]);
 }
 }
 int color_count = 0;
 // Process each cell to track present colors and their adjacency
 for (int i = 0; i < n; i++) {
 for (int j = 0; j < m; j++) {
 int c = grid[i][j];
 if (!present[c]) {
 present[c] = true;
 color_list[color_count++] = c;
 }
 if (!has_adjacent[c]) {
 // Check right neighbor
 if (j + 1 < m && grid[i][j + 1] == c) {
 has_adjacent[c] = true;
 }
 // Check down neighbor
 if (i + 1 < n && grid[i + 1][j] == c) {
 has_adjacent[c] = true;
 }
 }
 }
 }
 // Compute sum_all and max_step
 int sum_all = 0;
 int max_step = 0;
 for (int i = 0; i < color_count; i++) {
 int c = color_list[i];
 int steps = has_adjacent[c] ? 2 : 1;
 sum_all += steps;
 if (steps > max_step) {
 max_step = steps;
 }
 }
 int answer = sum_all - max_step;
 printf("%d\n", answer);
 // Reset present and has_adjacent for next test case
 for (int i = 0; i < color_count; i++) {
 int c = color_list[i];
 present[c] = false;
 has_adjacent[c] = false;
 }
 }
 return 0;
}