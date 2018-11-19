#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Constante
#define MAX 3999
#define MIN 1
#define TEST 50
#define LNG_CHAINE 50
//Constantes de chiffres romains
#define M 1000
#define CM 900
#define D 500
#define CD 400
#define C 100
#define XC 90
#define L 50
#define XL 40
#define X 10
#define IX 9
#define V 5
#define IV 4
#define I 1

//Prototypes
//Entier vers romain
int verifTaille (int nEnt);
void saisiEnt (int *pEnt);
void convEntToRom (char cChaine[],int nEnt);
void afficheRom(char cChaine[], int nEnt);
void entToRom();
//Romain vars entier
int verifRom (const char cChaine[]);
void saisiRom (char cChaine[]);
void convRomToEnt (const char cChaine[]);
void afficheEnt(const char cChaine[],int nEnt);
void romToEnt();
//Menu
void menu();


int main()
{
    menu();
}




 //////FONCTION veriTaille///////////////////////////////////////////////////////////////////////////////////////////////////////////////
 // Description : La fonction verifTaille permet de s'assurer que l'entier à convertir est compris entre 1 et 399
 //
 // Entrée : La chaine constituant le chiffre romain.
 //
 // Sortie : La fonction retourne un pseudo "BOOLEEN" en réalité un entier, 0 pour vrai et 1 pour faux.
 //
 //
 // Note : aucune
 ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int verifTaille (int nEnt){
    if ((nEnt >= MIN) && (nEnt <= MAX)){
        return 0;//VRAI
    }
        else{
            return 1;//FAUX
        }
}




 ///////PROCEDURE saisiEnt/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
 // Description : La procedure saisiEnt permet d'entrer un entier à convertir en chiffre romain.
 //
 // Entrée : Un entier (Pouvant être 0 ou supérieur à 3999).
 //
 // Sortie : Un entier compris entre 1 et 3999.
 //
 // Note : aucune
 ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void saisiEnt (int *pEnt){

int nLire=0;

    printf("Saisissez un entier compris entre 1 et 3999 à écrire en chiffres romains.\n");
    scanf("%d",pEnt);

    while (verifTaille(*pEnt)==1){
        printf("Le nombre doit être compris entre 1 et 3999, recommencez svp.");
        scanf("%d",&nLire);
        *pEnt = nLire;
    }
}




 //////PROCEDURE convEntToRom///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
 // Description :La procedure convEntToRom soustrait peu a peu des sommes correspondant à des chiffres romains (de la plus grande à la plus petite.)
 //                pour justement recomposer un chiffre romain.
 //
 // Entrée :Un entier compris entre 1 et 3999
 //
 // Sortie : Un chiffre romain correspondant à l'entier saisi.
 //
 // Note : aucune
 ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void convEntToRom (char cChaine[],int nEnt){
//Déclaration et initialisation des variables.
int nStock=0;
nStock = nEnt;

    do{
        if (nEnt >= M){
            nEnt = nEnt - M;
            strcat(cChaine,"M");
        }   else if (nEnt >= CM){
                nEnt = nEnt - CM;
                strcat(cChaine,"CM");
            }   else if (nEnt >= D){
                    nEnt = nEnt - D;
                    strcat(cChaine,"D");
                }   else if (nEnt >= CD){
                        nEnt = nEnt - CD;
                        strcat(cChaine,"CD");
                    }   else if (nEnt >= C){
                            nEnt = nEnt - C;
                            strcat(cChaine,"C");
                        }   else if (nEnt >= XC){
                                nEnt = nEnt - XC;
                                strcat(cChaine,"XC");
                            }   else if (nEnt >= L){
                                    nEnt = nEnt -  L;
                                    strcat(cChaine,"L");
                                }   else if (nEnt >= XL){
                                       nEnt = nEnt - XL;
                                        strcat(cChaine,"XL");
                                    }   else if (nEnt >= X){
                                            nEnt = nEnt - X;
                                            strcat(cChaine,"X");
                                        }   else if (nEnt >= IX){
                                                nEnt = nEnt - IX;
                                                strcat(cChaine,"IX");
                                            }   else if (nEnt >= V){
                                                    nEnt = nEnt - V;
                                                    strcat(cChaine,"V");
                                                }   else if (nEnt >= IV){
                                                        nEnt = nEnt - IV;
                                                        strcat(cChaine,"IV");
                                                    }   else if (nEnt >= I){
                                                            nEnt = nEnt - I;
                                                            strcat(cChaine,"I");
                                                        }
    }while (nEnt!=0);
    afficheRom(cChaine,nStock);
}




 //////PROCEDURE afficheRom///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
 // Description :La procedure afficheRom permet d'afficher le résultat la convertion souhaité par l'utilisateur, dans ce cas entier vers romain
 //
 // Entrée :
 //
 // Sortie :Le résultat la convertion souhaité par l'utilisateur, dans ce cas entier vers romain.
 //
 // Note : aucune
 ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void afficheRom(char cChaine[],int nStock){

    printf("%d correspond a : %s en chiffre romain.\n",nStock,cChaine);

}

void entToRom(){
//déclaration et initialisations de variables
int nEnt=100000;
char cChaine[LNG_CHAINE]={""};

saisiEnt(&nEnt);
convEntToRom(cChaine,nEnt);

}


 // PARTIE CONVERTION ROMAIN VERS ENTIER
 //////FONCTION verifRom//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
 // Description : La fonction verifRom permet de constater si les caractères constituant le chiffre romain sont bien des chiffres romains.
 //
 // Entrée : La chaine constituant le chiffre romain.
 //
 // Sortie : La fonction retourne un entier 0 pour vrai ou 1 pour faux.
 //
 // Note : aucune
 ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int verifRom(const char cChaine[]){
//Déclaration et initialisation des variables
int nTailleChaine=0, nCpt=0, nPos=50;

nTailleChaine=strlen(cChaine);

for (nCpt=MIN;nCpt<=nTailleChaine;nCpt++){

        if ((cChaine[nCpt-1] != 'I') && (cChaine[nCpt-1] != 'V') && (cChaine[nCpt-1] != 'X') && (cChaine[nCpt-1] != 'L') && (cChaine[nCpt-1] != 'C') && (cChaine[nCpt-1] != 'D') && (cChaine[nCpt-1] != 'M')){
            nPos = nCpt;
            printf("Le caractere en position %d n'est pas valide.\n",nPos);
        }
}
    if (nPos==50){
        return 0;//VRAI
    } else{
        return 1;//FAUX
        }
}



 ///////PROCEDURE saisiRom/////////////////////////////////////////////////////////////////////////////////////////////////////////////
 // Description : La procédure saisiRom permet de saisir la chaine de caratere constituant le chiffre romain.
 //
 // Entrée : Une chaine de caractere constituant le chiffre romain (pouvant contenir des erreurs).
 //
 // Sortie : Une chaine de caractere ne contenant que des chiffres romains.
 //
 // Note : aucune
 ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void saisiRom (char cChaine[]){

printf("Saisissez un nombre romain (la conversion peut être fausse pas si vous avez mal saisi votre chiffre romain)\n");
scanf("%s",cChaine);

while (verifRom(cChaine)==1){
    printf("Réécrivez votre chiffre romain avec des chiffres romains valides.");
    scanf("%s",cChaine);
}
}




 //////PROCEDURE convRomToEnt////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
 // Description :La procedure convRomToEnt scan la chaine à l'envers pour ajouter les sommes correspondant aux différents chiffres romains à l'entier de convertion.
 //
 // Entrée :Un chiffre romain contenant que des chiffres romain(pouvant ne pas exister).
 //
 // Sortie : L'entier correspondant au chiffre romain à convertir.
 //
 // Note : aucune
 /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void convRomToEnt (const char cChaine[]){
//Déclaration et initialisation des variables
int nTailleChaine=0, nCpt=0, nEnt=0;

nTailleChaine=strlen(cChaine);

for (nCpt=MIN;nCpt<=nTailleChaine;nCpt++){

    if ((cChaine[nTailleChaine-nCpt] =='I')  && (cChaine[nTailleChaine-nCpt+1] =='V')){
    nEnt = nEnt - I;
    }   else if ((cChaine[nTailleChaine-nCpt] =='I')  && (cChaine[nTailleChaine-nCpt+1] =='X')){
        nEnt = nEnt - I;
        }   else if (cChaine[nTailleChaine-nCpt] =='I'){
            nEnt = nEnt + I;
            }   else if (cChaine[nTailleChaine-nCpt] =='V'){
                nEnt = nEnt + V;
                }   else if ((cChaine[nTailleChaine-nCpt] =='X') && (cChaine[nTailleChaine-nCpt+1] =='L')){
                    nEnt = nEnt - X;
                    }   else if ((cChaine[nTailleChaine-nCpt] =='X') && (cChaine[nTailleChaine-nCpt+1] =='C')){
                        nEnt = nEnt - X;
                        }   else if (cChaine[nTailleChaine-nCpt] =='X'){
                            nEnt = nEnt + X;
                            }   else if (cChaine[nTailleChaine-nCpt] =='L'){
                                nEnt = nEnt + L;
                                }   else if ((cChaine[nTailleChaine-nCpt] =='C') && (cChaine[nTailleChaine-nCpt+1] =='D')){
                                    nEnt = nEnt-C;
                                    }   else if ((cChaine[nTailleChaine-nCpt] =='C') && (cChaine[nTailleChaine-nCpt+1] =='M')){
                                        nEnt = nEnt-C;
                                        }   else if (cChaine[nTailleChaine-nCpt] =='C'){
                                            nEnt = nEnt+C;
                                            }   else if (cChaine[nTailleChaine-nCpt] =='D'){
                                                nEnt = nEnt+D;
                                                }   else if (cChaine[nTailleChaine-nCpt] =='M'){
                                                    nEnt = nEnt+M;
                                                    }

}
afficheEnt(cChaine,nEnt);
}


 //////PROCEDURE afficheEnt////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
 // Description :La procedure afficheEnt permet d'afficher le résultat la convertion souhaité par l'utilisateur, dans ce cas Romain vers Entier
 //
 // Entrée :
 //
 // Sortie :Le résultat la convertion souhaité par l'utilisateur, dans ce cas Romain vers Entier
 //
 // Note : aucune
 ////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void afficheEnt(const char cChaine[],int nEnt){
    printf("%s en chiffre romain correspond a : %d en chiffre arabe",cChaine,nEnt);
}


void romToEnt(){

    printf("Bonjour! \n");
    char cChaine[LNG_CHAINE]={""};

    saisiRom(cChaine);
    convRomToEnt(cChaine);
}

void menu(){
int nChoix=0;

    printf("Saisissez 1 pour convertir un entier en chiffre romain,\n");
    printf("Saisissez 2 pour convertir un chiffre romain en entier.");

    scanf("%d",&nChoix);
    while ((nChoix!=1) && (nChoix!=2)){
        printf("%d n'est pas un choix valide,\n",nChoix);
        printf("Saisissez 1 pour convertir un entier en chiffre romain,\n");
        printf("Saisissez 2 pour convertir un chiffre romain en entier.");
        scanf("%d",&nChoix);
    }

    switch (nChoix){
        case 1 :
            entToRom();
            break;
        case 2 :
            romToEnt();
            break;
        default :
            break;

    }


}
