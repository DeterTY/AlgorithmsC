//Найти все области, статистику глифов:
//количество чёрных пикселей, связность, диаметр наибольшей области

#include <stdio.h>
#include <stdlib.h>
#define DEBUG 3
// #undef DEBUG
#define ISBIT(n, x) (((01 << (n)) & (x))?1:0)

void outbyte(char byte)
{
    //Вывод байта в двоичном виде
    int i;
    for(i = 7; i > -1; i--)
    {
        putchar(ISBIT((i), byte)?'*':' ');
        fflush(stdout);
    }
}

void outbytes(int n, char *byte)
{
    //Вывод массива байтов в двоичном виде
    int i;
    for(i = 0; i < n; i++)
    {
        outbyte(byte[i]);
        putchar('\n');
    }
}

IMG *load_img(int id, char *s)
{
    //Считывание из файла глифа с номером id
    FILE *F;
    IMG *I;
    I = (IMG *)malloc(sizeof(IMG));
    fread(&(I > w), sizeof(int), 1, F);
    fread(&(I > h), sizeof(int), 1, F);
    fread(&(I > dx), sizeof(int), 1, F);
    fread(&(I > count), sizeof(int), 1, F);
    fread(&(I > id), sizeof(int), 1, F);
    fread(&(I > bytes), sizeof(int), 1, F);
    I -> data = (unsigned char *)calloc(I -> bytes, 1);
    fread(I -> data, 1, I -> bytes, F);
    fclose(F);
    return I;
}

int xcomp(IMG **a, IMG **b)
{
    return -(*a) -> h + (*b) -> h;
}

int ycomp(IMG **a, IMG **b)
{
    return -(*a) -> h + (*b) -> h;
}

IMG *G[50000];

int N;
