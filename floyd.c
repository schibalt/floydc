#include <omp.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void InitializeArrays();

char *filename;
int bidirectional, ncities, lcityname = 20;
int ** dist, **next;
char** cities;

int main(int argc, char *argv[]) {

	filename = argv[1];
	if (atoi(argv[2]))
		bidirectional = 1;
	else
		bidirectional = 0;

	InitializeArrays();
	return 1;
}

void InitializeArrays() {
	int i;
	FILE *fp = fopen(filename, "r");

	if (fp == NULL) {
		char cherray[80];
		strcpy(cherray, "Failed to open file ");
		strcat(cherray, filename);
		perror(cherray);
		exit(EXIT_FAILURE);
	}

	fscanf(fp, "%d", &ncities);
	printf("%d cities will now be read.\n", ncities);

	cities = (char**) malloc(ncities * sizeof(char*));
	dist = (int**) malloc(ncities * sizeof(int*));
	next = (int**) malloc(ncities * sizeof(int*));
	for (i = 0; i < ncities; i++) {
		cities[i] = (char*) malloc(lcityname * sizeof(char));
		dist[i] = (int*) calloc(ncities * sizeof(int));
		next[i] = (int*) calloc(ncities * sizeof(int));
	}
	fclose(fp);
}

//void FreeArrays() { // keep looping until you find the NULL one
//	for (int i = 0; cities[i] != NULL; i++) {
//		free(first_matrix[i]);
//	}
//	free(cities);
//	free(dist);
//	free(next);
//}
