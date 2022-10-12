#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>

//creation sruct
struct etudiant{
    char prenom[30];
    char nom[30];
    char rue[30];
    char ville[30];
    short notes[2];
    };


int main(){
    const int NBR_ELEVE = 5;
    //init data
    char Tprenom[NBR_ELEVE][30] = {"Adrein ", "Pierre ", "Louis ", "Martin ", "Hugues "};
    char Tnom[NBR_ELEVE][30] = {"Dalb ", "Tlp ", "Telep ", "Cov ", "Fart "};
    char True[NBR_ELEVE][30] = {"Blv ", "rue ", "chm ", "imp ", "rocade "};
    char Tville[NBR_ELEVE][30] = {"lille ", "Lyon ", "marseille ", "paris ", "charbo "};
    short Tnotes[NBR_ELEVE][2] = {{12,10}, {12,10}, {13,10}, {12,10}, {12,10}};
    
    struct etudiant petite_classe[5];

    //utilisation de la structure
    for (int i=0; i<NBR_ELEVE; i++){
        strcpy(petite_classe[i].prenom, Tprenom[i]);
        strcpy(petite_classe[i].nom, Tnom[i]);
        strcpy(petite_classe[i].rue, True[i]);
        strcpy(petite_classe[i].ville, Tville[i]);
        petite_classe[i].notes[0] = Tnotes[i][0];
        petite_classe[i].notes[1] = Tnotes[i][1];
    }

    int fd;
    char *nom_de_fichier = "data.txt";
    fd = open(nom_de_fichier, O_CREAT|O_WRONLY, S_IRUSR|S_IWUSR);
    if (fd < 0) {return -1;}

    
    for (int i = 0; i < NBR_ELEVE; i++) {
        char str_notes[2][3];
        int size;
        sprintf(str_notes[0], "%hd", petite_classe[i].notes[0]); //il faut passer un chaine de char
        sprintf(str_notes[1], "%hd",petite_classe[i].notes[1]);
        size = write(fd, petite_classe[i].prenom, strlen(petite_classe[i].prenom));
        size = write(fd, petite_classe[i].nom, strlen(petite_classe[i].nom));
        size = write(fd, petite_classe[i].rue, strlen(petite_classe[i].rue));
        size = write(fd, petite_classe[i].ville, strlen(petite_classe[i].ville));
        size = write(fd, str_notes[0], strlen(str_notes[0]));
        write(fd, " ", 1);
        size = write(fd, str_notes[1], strlen(str_notes[1]));
        write(fd, "\n", 1);
        if (size <0) return -1;
    }

    for (int i = 0; i < 6; i++){
        char input[100];
        scanf("%s", input);
        write(fd, input, strlen(input));
        write(fd, " ", 1);
    }

    close(fd);
    return 0;
 
}