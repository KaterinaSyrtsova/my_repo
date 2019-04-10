#include <stdlib.h>
#include <stdio.h>
#include <dirent.h>
#include <sys/types.h>
#include <string.h>

#define STRING_SIZE 3000	
#define STARTING_DIR "./labyrinth"

typedef struct FilePath {
	char fileName[STRING_SIZE];
}FilePath;

typedef struct FilesList {
	FilePath *files;
	int size;
}FilesList;

int findFile(const char *dirStart, char originalFileName[STRING_SIZE], FilesList  *fileNames) {
	DIR *dir = opendir(dirStart);
	char *dirName;
	int d,k = 0;
	if (dir) {
		struct dirent *n = readdir(dir);
		while (n) {
			if (strstr(n->d_name, ".txt") != NULL) {
				if (strcmp(n->d_name, originalFileName) == 0) {
					dirName = (char*)malloc((strlen(dirStart) + strlen(n->d_name) + 3) * sizeof(char));
					strcpy(dirName, dirStart);
					strcat(dirName, "/");
					strcat(dirName, n->d_name);
					FILE *file = fopen(dirName, "r");
					char fileInfo[STRING_SIZE];
					while (fscanf(file, "%s\n", fileInfo) != EOF) {
						if (strcmp(fileInfo, "Deadlock") == 0) {
							return 0;
						}
						if (strcmp(fileInfo, "Minotaur") == 0) {
							fileNames->files = (FilePath*)malloc(1 * sizeof(FilePath));
							strcpy(fileNames->files[fileNames->size].fileName, dirName);
							++fileNames->size;	
							closedir(dir);
							return 1;
						}
						if (strcmp(fileInfo, "@include") != 0) {
							k += findFile(STARTING_DIR, fileInfo, fileNames);
							if (k == 1) {
								fileNames->files = (FilePath*)realloc(fileNames->files, (fileNames->size + 2) * sizeof(FilePath));
								strcpy(fileNames->files[fileNames->size].fileName, dirName);
								++fileNames->size;
								return 1;
							}
						}
					}
				}
			}
			if (strcmp(n->d_name, ".") != 0 && strcmp(n->d_name, "..") != 0) {
				dirName = (char*)malloc((strlen(dirStart) + strlen(n->d_name) + 3) * sizeof(char));
				strcpy(dirName, dirStart);
				strcat(dirName, "/");
				strcat(dirName, n->d_name);
				k += findFile(dirName, originalFileName, fileNames);
			}
			n = readdir(dir);
		}
	closedir(dir);
	}
	return k;
}

int main() {
	FilesList fileNames;
	fileNames.size = 0;
	findFile(STARTING_DIR, "file.txt", &fileNames);
	FILE* resultFile;
	resultFile = fopen("result.txt", "w");
	for (int i = fileNames.size - 1; i > -1; i--) {
		fprintf(resultFile, "%s\n", fileNames.files[i].fileName);
	}
	fclose(resultFile);
	return 0;
}
