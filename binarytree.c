#include <stdio.h>
#include <stdlib.h>


typedef struct node *Pnode;
struct node
{
    int broj;
    Pnode levi;
    Pnode desni;

} Node;
Pnode glava;

Pnode insert(Pnode tek, int broj, Pnode pret)
{
    if (tek == NULL)
        return pret;
    if (broj < tek->broj)
        insert(tek->levi, broj, tek);
    else
        insert(tek->desni, broj, tek);
}

void LKD(Pnode tek)
{
    if (tek->levi != NULL)
        LKD(tek->levi);
    printf("%d  ", tek->broj);
    if (tek->desni != NULL)
        LKD(tek->desni);
}

void LDK(Pnode tek)
{
    if (tek->levi != NULL)
        LDK(tek->levi);
    if (tek->desni != NULL)
        LDK(tek->desni);
    printf("%d  ", tek->broj);
}

void KLD(Pnode tek)
{
    printf("%d  ", tek->broj);
    if (tek->levi != NULL)
        KLD(tek->levi);
    if (tek->desni != NULL)
        KLD(tek->desni);
}

void binary(int broj)
{
    if (glava == NULL)
    {
        glava = malloc(sizeof(Node));
        glava->levi = NULL;
        glava->desni = NULL;
        glava->broj = broj;
        return;
    }
    Pnode pret = insert(glava, broj, glava);
    if (broj < pret->broj)
    {
        pret->levi = malloc(sizeof(Node));
        pret = pret->levi;
    }
    else
    {
        pret->desni = malloc(sizeof(Node));
        pret = pret->desni;
    }
    pret->broj = broj;
    pret->levi = NULL;
    pret->desni = NULL;
}

void insertArr(int *arr, int len)
{
    for (int i = 0; i < len; i++)
        binary(arr[i]);
}

int main()
{
    int niz[] = {55, 232, 55, 21, 57, 13, 6, 88};
    insertArr(niz, sizeof(niz) / sizeof(niz[0]));
    LDK(glava);
    printf("\n");
    KLD(glava);
    printf("\n");
    LKD(glava);
    printf("\n");
    return 0;
}