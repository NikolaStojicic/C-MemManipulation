#include <stdio.h>
#include <stdlib.h>

typedef struct node Node;
typedef Node* Pnode;

Pnode glava;
Pnode rep;
struct node
{
    int broj;
    Pnode sledeci;
    Pnode prosli;
};


void dodaj(int broj) {
    Pnode tek = glava;
    while(tek->sledeci != NULL)
        tek = tek->sledeci;
    tek->sledeci = malloc(sizeof(Node));
    Pnode novi;
    novi = tek->sledeci;
    novi->broj = broj;
    novi->prosli = tek;
    novi->sledeci = NULL;
    rep = novi;
}

void stampaj(){
    printf("Vasa lista:\n");
    Pnode tek = glava->sledeci;
    while(tek != NULL) {
        printf("%2d",tek->broj);
        tek = tek->sledeci;
    }
}

void stampaj_reverse(){
    printf("Vasa lista _reverse:\n");
    Pnode tek = rep;
    while(tek->prosli != NULL) {
        printf("%2d",tek->broj);
        tek = tek->prosli;
    }
    
}

void dodajNiz(int* niz, int len) {
    for (int i = 0; i < len; i++)
        dodaj(niz[i]);
}


int main(){
    glava  = malloc(sizeof(Node));
    glava->sledeci = NULL;
    glava->prosli = NULL;

    rep  = malloc(sizeof(Node));
    rep->sledeci = NULL;
    rep->prosli = NULL;
   
    dodaj(1);
    dodaj(2);
    int niz[] = {3,4,5,6,7};
    dodajNiz(niz, sizeof(niz)/sizeof(int));
    stampaj();
    printf("\n");
    stampaj_reverse();


    printf("\n");
    return 0;
}