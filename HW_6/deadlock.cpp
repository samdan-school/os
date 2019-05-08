// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

// #include "pch.h"
#include <stdio.h> 

// Banker's Algorithm 

#define n 5
#define m 4

int main()
{
	int i, j, k;
	int alloc[n][m] = { { 0, 0, 1, 2 }, // P0    // Allocation Matrix 
						{ 1, 0, 0, 0 }, // P1 
						{ 1, 3, 5, 4 }, // P2 
						{ 0, 6, 3, 2 }, // P3 
						{ 0, 0, 1, 4 } }; // P4 

	int max[n][m] = { { 0, 0, 1, 2 }, // P0    // MAX Matrix 
						{ 1, 7, 5, 0 }, // P1 
						{ 2, 3, 5, 6 }, // P2 
						{ 0, 6, 5, 2 }, // P3 
						{ 0, 6, 5, 6 } }; // P4 

	int avail[m] = { 1, 5, 2, 0 }; // Available Resources 

	int f[n], ans[n], ind = 0;
	for (k = 0; k < n; k++) {
		f[k] = 0;
	}
	int need[n][m];
	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++)
			need[i][j] = max[i][j] - alloc[i][j];
		printf("Need P%d ", i);
		for (j = 0; j < m; j++) {
			printf("%d ", need[i][j]);
		}
		printf("\n");
	}
	int y = 0;
	for (k = 0; k < n; k++) {
		for (i = 0; i < n; i++) {
			if (f[i] == 0) {
				int flag = 0;
				for (j = 0; j < m; j++) {
					if (need[i][j] > avail[j]) {
						flag = 1;
						break;
					}
				}

				if (flag == 0) {
					ans[ind++] = i;
					for (y = 0; y < m; y++)
						avail[y] += alloc[i][y];
					f[i] = 1;
				}
			}
		}
	}

	printf("\nProcess finish sequence\n");
	for (i = 0; i < n; i++)
		printf("P%d->", ans[i]);

	return (0);
}
