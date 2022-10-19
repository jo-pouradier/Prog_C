#include "repertoire.h"
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <stdbool.h>

void lire_dossier(char *filename){
    DIR *dirp = opendir(filename);
    struct dirent *entry;
    if (dirp == NULL) {
        printf("error opendir");
    }

    printf("Contents of dir: %s\n", filename);

    while ((entry = readdir(dirp)) != NULL){
        printf("  %s\n", entry->d_name);
    }
    closedir(dirp);
};

void lire_dossier_recursif_i(char *filename, int n){
    DIR *dirp = opendir(filename);
    struct dirent *entry;
    if (dirp == NULL) {
        for (int j = 0; j <n; j++) printf("%s ","   ");
        printf("le dossier %s n'a pas pue etre ouvert\n", filename);
        return;
    }

    while ((entry = readdir(dirp)) != NULL){
        for (int j = 0; j <n; j++) printf("%s ","   ");
        printf("  %s\n", entry->d_name);
        if (strcmp(entry->d_name,".")==0) {
            entry = readdir(dirp);
            for (int j = 0; j <n; j++) printf("%s ","   ");
            printf("  %s\n", entry->d_name);
        }
        else if (strcmp(entry->d_name,"..")==0) entry = readdir(dirp);
        else if (entry->d_type == DT_DIR) {
            char tpDir[100];
            strcat(strcpy(tpDir, filename), entry->d_name);
            strcat(tpDir,"/");
            lire_dossier_recursif_i(tpDir, n+1);
            }
    }
    closedir(dirp);
};

void lire_dossier_recursif(char *filename){
    lire_dossier_recursif_i(filename, 1);
};



void lire_dossier_iteratif(char* dir){
    char list_dir[200][1024] = {};
    for (int j = 0; j <200; j++) strcpy(list_dir[j], ""); 
    int n = 0;
    int count = 1;
    strcpy(list_dir[0], dir);
    printf("%s\n", list_dir[0]);

    while (n < sizeof(list_dir)){
        if (strcmp(list_dir[n], "")==0){
            printf("Plus de dossier a ouvrir\n");
            return;
        }
        // printf("tour n°%i\n", n);
        // printf("tour count %i\n", count);
        DIR *dirp = opendir(list_dir[n]);
        struct dirent *entry;
        //on verifie si on a bien ouvert le dossier
        if (dirp == NULL) {
            printf("le dossier %s n'a pas pue etre ouvert\n", list_dir[n]);
            return;
        }
        //affichage de tout les fichier et dossier
        printf("contents of dir : %s \n", list_dir[n]);
        while ((entry = readdir(dirp)) != NULL){
            printf("    %s\n", entry->d_name);
            if (entry->d_type == DT_DIR){
                if (strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..") != 0){
                    // printf("%i\n", count);
                    // printf("chemin de base: %s\n", list_dir[count]);
                    // printf("chemin a completer: %s\n", list_dir[n]);
                    // printf("nom truc a ajouter: %s\n", entry->d_name);

                    strcat(strcat(strcat(list_dir[count],list_dir[n]),entry->d_name),"/");// ajout d'un chemin dans la list_dir

                    // printf("chemin obtenu: %s\n", list_dir[count]);

                    count++;
                }
            }
        }
        closedir(dirp);
        n++;
        printf("\n");
    }
}
