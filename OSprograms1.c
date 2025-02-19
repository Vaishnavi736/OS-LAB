//1 Write programs using the following UNIX operating system calls for opendir and readdir and closedir
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
int main() {
    char buff[100];
    DIR *dirp;
    struct dirent *dptr;  // Declare inside main, not globally
    printf("\n\nEnter directory name: ");
    scanf("%s", buff);
    // Try opening the directory
    dirp = opendir(buff);
    if (dirp == NULL) {
        printf("The given directory does not exist.\n");
        exit(1);
    }

    // Read and print directory contents
    printf("Contents of directory %s:\n", buff);
    while ((dptr = readdir(dirp)) != NULL) {
        printf("%s\n", dptr->d_name);
    }
    // Close the directory stream
    closedir(dirp);
    return 0;
}
Enter directory name:Downloads
Contents of directory Downloads:
.
..
file1.txt
file2.c

    
//2 Write programs using the following UNIX operating system calls for fork, getpid
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>  // Required for exit()
int main() 
{
    int pid, pid1, pid2;
    pid = fork();  // Create a child process
    if (pid == -1) {
        printf("Error in process creation\n");
        exit(1);  // Exit if fork fails
    }
    if (pid != 0) {  // Parent process
        pid1 = getpid();
        printf("\nThe parent process ID is %d\n", pid1);
    } else {  // Child process
        pid2 = getpid();
        printf("\nThe child process ID is %d\n", pid2);
    }
    return 0;
}

//3.Program for simulation of cp unix commands
#include <stdio.h>
int main(int argc, char *argv[])
{
    FILE *fp;
    char ch;
    int sc = 0;
    if (argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }
    fp = fopen(argv[1], "r");
    if (fp == NULL) {
        printf("Unable to open the file: %s\n", argv[1]);
    } else {
        while ((ch = fgetc(fp)) != EOF) {
            if (ch == ' ') {
                sc++;
            }
        }
        printf("Number of spaces: %d\n", sc);
        fclose(fp);
    }
    return 0;
}
 

//4.PROGRAM FOR SIMULATION OF GREP UNIX COMMANDS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 1024
void usage()
{
    printf("usage:\t./a.out filename word\n");
}
int main(int argc, char *argv[])
{
    FILE *fp;
    char fline[MAX];
    char *newline;
    int count = 0;
    int occurrences = 0;
    if (argc != 3) {
        usage();
        exit(1);
    }
    fp = fopen(argv[1], "r");
    if (!fp) {
        printf("grep: could not open file: %s\n", argv[1]);
        exit(1);
    }
    while (fgets(fline, MAX, fp) != NULL) {
        count++;
        // Remove newline character if it's at the end of the line
        if ((newline = strchr(fline, '\n')) != NULL) {
            *newline = '\0';
        }
       // Check if the word is found in the line
        if (strstr(fline, argv[2]) != NULL) {
            printf("%s: %d %s\n", argv[1], count, fline);
            occurrences++;
        }
    }
    if (occurrences == 0) {
        printf("No occurrences of the word '%s' found.\n", argv[2]);
    }
    fclose(fp);
    return 0;
}

