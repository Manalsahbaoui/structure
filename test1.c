#include <stdio.h>
#include <string.h>

struct Adresse {
    char rue[50];
    char ville[50];
    int codePostal;
};

struct Apprenant {
    char nom[50];
    char prenom[50];
    int age;
    float note;
    struct Adresse adresse;
};

int main() {
    struct Apprenant apprenant[100];
    int nbapprenant = 0;

    while (1) {
        printf("\n---------------Menu:-----------------\n");
        printf("1. Ajouter une apprenant\n");
        printf("2. Afficher toutes les apprenant\n");
        printf("3. Modifier une apprenant\n");
        printf("4. Supprimer une apprenant\n");
        printf("5. Quitter\n");

        int choix;
        printf("Votre choix : ");
        scanf("%d", &choix);
      

        switch (choix) {
            case 1:
                if (nbapprenant < 100) {
                    printf("Entrez les informations de la nouvelle apprenant:\n");
                    printf("Nom: ");
                    scanf("%s", apprenant[nbapprenant].nom);
                    printf("Prenom: ");
                    scanf("%s", apprenant[nbapprenant].prenom);
                    printf("Age: ");
                    scanf("%d", &apprenant[nbapprenant].age);
                    printf("Note: ");
                    scanf("%f", &apprenant[nbapprenant].note);
                    printf("Rue: ");
                    scanf("%s", apprenant[nbapprenant].adresse.rue);
                    printf("Ville: ");
                    scanf("%s", apprenant[nbapprenant].adresse.ville);
                    printf("Code postal: ");
                    scanf("%d", &apprenant[nbapprenant].adresse.codePostal);
                    nbapprenant++;
                } else {
                    printf("Tableau plein.\n");
                }
                break;

            case 2:
                if (nbapprenant == 0) {
                    printf("Aucune apprenant enregistree.\n");
                } else {
                    printf("Liste des apprenant:\n");
                    for (int i = 0; i < nbapprenant; i++) {
                        printf("apprenant %d:\n", i+1);
                        printf("Nom: %s\n", apprenant[i].nom);
                        printf("Prenom: %s\n", apprenant[i].prenom);
                        printf("Age: %d ans\n", apprenant[i].age);
                        printf("Note: %.2f\n", apprenant[i].note);
                        printf("Adresse: %s, %s (%d)\n", apprenant[i].adresse.rue, apprenant[i].adresse.ville, apprenant[i].adresse.codePostal);
                    }
                }
                break;

            case 3:
                if (nbapprenant == 0) {
                    printf("Aucune apprenant enregistree.\n");
                } else {
                    int indice;
                    printf("Entrez l'indice de la apprenant a modifier : ");
                    scanf("%d", &indice);
                    indice--; 
                    if (indice >= 0 && indice < nbapprenant) {
                        printf("Nouvelles informations pour la apprenant %d :\n", indice+1);
                        printf("Nom: ");
                        scanf("%s", apprenant[indice].nom);
                        printf("Prenom: ");
                        scanf("%s", apprenant[indice].prenom); 
                        printf("Age: ");
                        scanf("%d", &apprenant[indice].age);
                        printf("Note: ");
                        scanf("%f", &apprenant[indice].note); 
                        printf("Rue: ");
                        scanf("%s", apprenant[indice].adresse.rue);
                        printf("Ville: ");
                        scanf("%s", apprenant[indice].adresse.ville);
                        printf("Code postal: ");
                        scanf("%d", &apprenant[indice].adresse.codePostal);
                    } else {
                        printf("Indice invalide.\n");
                    }
                }
                break;

            case 4:
                if (nbapprenant == 0) {
                    printf("Aucune apprenant à supprimer.\n");
                } else {
                    int indice;
                    printf("Entrez l'indice de la apprenant à supprimer : ");
                    scanf("%d", &indice);
                    indice--;
                    if (indice >= 0 && indice < nbapprenant) {
                        for (int i = indice; i < nbapprenant - 1; i++) {
                            apprenant[i] = apprenant[i+1];
                        }
                        nbapprenant--;
                        printf("apprenant supprimee.\n");
                    } else {
                        printf("Indice invalide.\n");
                    }
                }
                break;

            case 5:
                printf("Au revoir!\n");
                return 0;

            default:
                printf("Choix invalide.\n");
        }
    }

    return 0;
}