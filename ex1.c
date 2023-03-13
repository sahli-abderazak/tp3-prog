#include<stdio.h>
#include<stdlib.h>
typedef struct cellule
{
    int info;
    struct cellule*suivant;
}cellule;

void ajout_tete(cellule**l , int e)
{
    cellule*n;
    n=malloc(sizeof(cellule));
    n->info=e;
    n->suivant=*l;
    *l=n;
}

void affichecellule(cellule*l)
{
    cellule*n;
    n=l;
    while(n!= NULL)
    {
        printf("%i",n->info);
        n=n->suivant ;
    }
}
void ajout_queue(cellule**l,int e)
{
    cellule*n;
    cellule*p=*l;
    n=malloc(sizeof(cellule));
    n->info=e;
    n->suivant=NULL;
    if(p!=NULL)
    {
        while(p->suivant!=NULL)
        {
            p=p->suivant;
        }
        p->suivant=n;
    }
    else
        *l=n;
}

cellule*rechreche(cellule*l,int x)
{
    cellule*p=l;
    while((p !=NULL) &&(p->info!=x))
    {
        p=p->suivant;

    }
         return p;
}

void supprimer(cellule*l,int x)
{
    cellule*k;
    cellule*p;
    if (l!=NULL)
    {
        p=l;
        while(p->suivant!=NULL)
        {
            k=p;
            p=p->suivant;
        }
        k->suivant=NULL;
        free(p);
    }
}

int nombre_occ(cellule*l,int y)
{
    cellule*p;
    p=l;
    int i=0;
    while(p!=NULL)
    {
        if(p->info==y)
        {
            i++;
        }
        p=p->suivant;
    }
    return i;
}
void tri_cellule(cellule*L)
{
    int esttrie,x;
    cellule*p;
    cellule*p1;
    if(L!=NULL)
    {
        p=L;
        do
        {
            esttrie=0;
            p1=p->suivant;
            while(p1!=NULL)
            {
                if((p1->info)<(p->info))
                {
                        p1=p1->suivant;

                }
                else
                {
                    x=p1->info;
                    p1->info=p->info;
                    p->info=x;
                    p1=p1->suivant;
                    esttrie=1;

                }
            }
            p=p->suivant;

        }
        while((p!=NULL)&&(esttrie=1));
    }
}

int main()
{
   cellule*l=NULL;
   cellule*p;
   int y;
   int e;
   int x,i;
   printf("donner element:\n");
   scanf("%i",&e);
   ajout_queue(&l,e);
   printf("donner element 2:\n");
   scanf("%i",&e);
   ajout_tete(&l,e);
   affichecellule(l);
  printf("donner x a chercher :\n");
   scanf("%i",&x);
   p=rechreche(l,x);
   if(p!=NULL)
   printf("%d le nobre est trouvee\n",p->info);
   else printf("nullll\n");
   tri_cellule(l);
   affichecellule(l);
  printf("donner x a supprimer:\n");
   scanf("%i",&x);
   supprimer(l,x);
   affichecellule(l);
   printf("donner y pour calculer le nombre d'occurance:\n");
   scanf("%i",&y);
   i=nombre_occ(l,y);
   printf("%d",i);



}

