#include <stdio.h>
#include <stdlib.h>
#include<limits.h>

typedef struct point point;
typedef struct map map;

struct point{
    char *nomPoint;
    int distance;
    point *suiv;
    point *voisin;
    };

struct map {
    point* premierPoint;
    point* dernierPoint;
    };

void affichePoint(point *pPoint);
void afficheMap(map *pMap);
void afficheListePoint(point *pPoint);
void affichePointVoisin(point *pPoint);
map* creerMap();
map* ajouterPoint(char pNomPoint[2],map *pMap);
map* ajouterPointVoisin(char pPointDepart[2], char pPointVoisin[2], int pDistance, map* pMap);
int nombrePoint(map *pMap);
point* rechercherPoint(char pPoint[2], map *pMap);
point* calculDistanceMinimale(char pPointDepart[2], map *pMap);
point* getPoint(char pPoint[2], map *pMap);
point* rechercherPointOptimal(point *pPremierPointNonParcouru);
void majDistance(point* pPremierPointParcouru, point* pPremierPointNonParcouru, point* pDernierPointParcouru, map *pMap);
point* supprimerPoint(point* pPointASupprimer, point* pOuSupprimer);
point* obtenirCheminPlusCourt(char pPointDepart[2], char pPointArrive[2], point *pPoint);


int main()
{
    map *m = creerMap();
    m = NULL;

    m=ajouterPoint("A",m);
    m=ajouterPoint("B",m);
    m=ajouterPoint("C",m);
    m=ajouterPoint("D",m);
    m=ajouterPoint("E",m);
    m=ajouterPoint("F",m);
    m=ajouterPoint("G",m);
    m=ajouterPoint("H",m);
    m=ajouterPoint("I",m);
    m=ajouterPoint("J",m);
    m=ajouterPoint("K",m);
    m=ajouterPoint("L",m);
    m=ajouterPoint("M",m);
    m=ajouterPoint("N",m);
    m=ajouterPoint("O",m);
    m=ajouterPoint("P",m);



/*
    m=ajouterPointVoisin("A","B",1,m);
    m=ajouterPointVoisin("A","C",5,m);

    m=ajouterPointVoisin("B","D",4,m);
    m=ajouterPointVoisin("B","A",1,m);

    m=ajouterPointVoisin("C","E",2,m);
    m=ajouterPointVoisin("C","A",5,m);

    m=ajouterPointVoisin("D","F",1,m);
    m=ajouterPointVoisin("D","B",4,m);

    m=ajouterPointVoisin("E","F",1,m);
    m=ajouterPointVoisin("E","G",3,m);
    m=ajouterPointVoisin("E","C",2,m);

    m=ajouterPointVoisin("F","H",3,m);
    m=ajouterPointVoisin("F","O",5,m);
    m=ajouterPointVoisin("F","D",1,m);

    m=ajouterPointVoisin("G","H",1,m);
    m=ajouterPointVoisin("G","E",3,m);

    m=ajouterPointVoisin("H","I",1,m);
    m=ajouterPointVoisin("F","H",3,m);

    m=ajouterPointVoisin("I","J",1,m);
    m=ajouterPointVoisin("I","L",3,m);
    m=ajouterPointVoisin("I","H",1,m);

    m=ajouterPointVoisin("J","K",3,m);
    m=ajouterPointVoisin("J","I",1,m);

    m=ajouterPointVoisin("K","N",1,m);
    m=ajouterPointVoisin("K","J",3,m);

    m=ajouterPointVoisin("L","K",1,m);
    m=ajouterPointVoisin("L","M",1,m);
    m=ajouterPointVoisin("L","I",3,m);

    m=ajouterPointVoisin("M","N",1,m);
    m=ajouterPointVoisin("M","L",1,m);

    m=ajouterPointVoisin("N","O",2,m);
    m=ajouterPointVoisin("N","M",1,m);

    m=ajouterPointVoisin("O","P",2,m);
    m=ajouterPointVoisin("O","N",2,m);

    //m=ajouterPointVoisin("P","A",1,m);
*/

    m=ajouterPointVoisin("A","L",14,m);
    m=ajouterPointVoisin("A","P",3,m);
    m=ajouterPointVoisin("B","K",14,m);
    m=ajouterPointVoisin("B","C",2,m);
    m=ajouterPointVoisin("C","I",4,m);
    m=ajouterPointVoisin("C","D",3,m);
    m=ajouterPointVoisin("D","E",4,m);
    m=ajouterPointVoisin("E","I",3,m);
    m=ajouterPointVoisin("E","F",8,m);
    m=ajouterPointVoisin("F","G",4,m);
    //m=ajouterPointVoisin('F',"I",1,m);
    m=ajouterPointVoisin("I","J",8,m);
    m=ajouterPointVoisin("G","K",5,m);
    m=ajouterPointVoisin("G","L",11,m);
    m=ajouterPointVoisin("K","L",5,m);
    m=ajouterPointVoisin("O","N",24,m);
    m=ajouterPointVoisin("H","M",56,m);
    m=ajouterPointVoisin("H","N",14,m);
    m=ajouterPointVoisin("M","K",30,m);
    m=ajouterPointVoisin("K","L",5,m);
    m=ajouterPointVoisin("N","O",24,m);
    m=ajouterPointVoisin("O","P",4,m);
    m=ajouterPointVoisin("O","B",8,m);
    m=ajouterPointVoisin("O","C",11,m);
    m=ajouterPointVoisin("O","D",14,m);

    printf("\n----AFFICHAGE DU GRAPHE----\n\nPOINT --> VILLE VOISINNE\n\n");
    afficheMap(m);
    printf("\n----FIN----\n");

    point *distanceMinimale = calculDistanceMinimale("B",m);

    printf("\n----AFFICHAGE DE LA DISTANCE MINIMALE ENTRE LE POINT A ET LES AUTRES----\n\n");
    afficheListePoint(distanceMinimale);
    printf("\n\n----FIN----\n");

    printf("\n\n----AFFICHAGE DU PLUS COURT CHEMIN ENTRE B ET K----\n\n");

    point *plusCourteDistance = obtenirCheminPlusCourt("B","P",distanceMinimale);
    afficheListePoint(plusCourteDistance);
    printf("\n\n----FIN----\n");

   /* printf("Hello world!\n"); */
    return 0;
}

int nombrePoint(map *pMap){
    point *ptr;
    ptr=pMap->premierPoint;
    int i = 0;
    while (ptr != NULL){
        i = i+1;
        ptr = ptr->suiv;
    }
    return i;
}

map* creerMap(){
    map *m=(map*)malloc(sizeof(map));
    m->premierPoint=NULL;
    m->dernierPoint=NULL;
    return m;
}

map* ajouterPoint(char pNomPoint[2], map *pMap){
    if(pMap==NULL){
       point *p=(point*)malloc(sizeof(point));
       p->distance=0;
       p->nomPoint=pNomPoint;
       p->suiv=NULL;
       p->voisin=NULL;
       pMap=(map*)malloc(sizeof(map));
       pMap->premierPoint=p;
       pMap->dernierPoint=p;
       return pMap;
       }
    else{
        point *p=(point*)malloc(sizeof(point));
        p->distance=0;
        p->nomPoint=pNomPoint;
        p->suiv=NULL;
        p->voisin=NULL;
        pMap->dernierPoint->suiv=p;
        pMap->dernierPoint=p;
        return pMap;
    }
}

void afficheListePoint(point *pPoint){
    point *ptr;
    ptr=pPoint;
    while(ptr != NULL){
        affichePoint(ptr);
        printf("->");
        ptr=ptr->suiv;
    }
    printf("FIN");
}

void affichePointVoisin(point *pPoint){
    point *ptr;
    if (pPoint != NULL){
        ptr = pPoint->voisin;
        while(ptr != NULL){
            affichePoint(ptr);
            printf("->");
            ptr = ptr->suiv;
        }
    }
}

void affichePoint(point *pPoint){
    printf("(%s,%d)", pPoint->nomPoint, pPoint->distance);
}

void afficheMap(map *pMap){
    point *ptr;
    ptr = pMap->premierPoint;
    while(ptr !=NULL){
        affichePoint(ptr);
        printf("->");
        affichePointVoisin(ptr);
        printf("FIN");
        ptr=ptr->suiv;
        printf("\n\n");
    }
}

map* ajouterPointVoisin(char pPointDepar[2], char pPointVoisin[2], int pDistance, map *pMap){
    point *ptr, *tmp;
    ptr = pMap->premierPoint;
    while(ptr!=NULL&&ptr->nomPoint != pPointDepar){
        ptr = ptr->suiv;
    }
    if(ptr == NULL){
        return 1;
    }
    point *p = (point*)malloc(sizeof(point));

    p->nomPoint=pPointVoisin;
    tmp = rechercherPoint(pPointVoisin, pMap);
    p->distance=pDistance;
    p->voisin=NULL;
    p->suiv=NULL;

    if(ptr->voisin==NULL){
        ptr->voisin=p;
    }
    else{
        tmp = ptr->voisin;
        while(tmp->suiv!=NULL){
            tmp=tmp->suiv;
        }
        tmp->suiv=p;
    }
    return pMap;
}

point* rechercherPoint(char pPoint[2], map *pMap){
    point *ptr;
    ptr = pMap->premierPoint;
    while(ptr != NULL && ptr->nomPoint != pPoint){
        ptr = ptr->suiv;
    }
    return ptr;
}

point* calculDistanceMinimale(char pPointDepart[2], map *pMap){
    point *pointDepart;
    point *pointNonParcouru;
    point *pointParcouru;
    point *ptr;
    point *tmp;
    point *temp;
    point *premierPointNonParcouru;
    point *premierPointParcouru;
    point *parc;
    point *pointOptimale;
    int distance = 0;
    pointDepart = NULL;
    ptr=NULL;
    premierPointNonParcouru = NULL;
    premierPointParcouru = NULL;
    pointNonParcouru = NULL;
    temp = NULL;
    ptr = NULL;
    parc = NULL;

    pointDepart=getPoint(pPointDepart, pMap);
    pointParcouru = (point*)malloc(sizeof(point));
    pointParcouru->distance = pointDepart->distance;
    pointParcouru->nomPoint = pointDepart->nomPoint;
    pointParcouru->suiv = NULL;
    pointParcouru->voisin = NULL;
    premierPointParcouru = pointParcouru;

    /*Initialisation de l'algotithme de Dijkstra*/
    ptr = pMap->premierPoint;
    while(ptr != NULL) {
        if(ptr->nomPoint == pointParcouru->nomPoint) {
            ptr = ptr->suiv;
            continue;
        }
        /*La distance entre la ville de départ et la ville selectionné*/
        distance = obtenirDistance(ptr, pointParcouru);
        if(pointNonParcouru == NULL) {
            pointNonParcouru = (point*)malloc(sizeof(point));
            pointNonParcouru->distance = distance;
            pointNonParcouru->nomPoint = ptr->nomPoint;
            if(distance != INT_MAX)

                pointNonParcouru->voisin = pointParcouru;
            else
                pointNonParcouru->voisin = NULL;
            premierPointNonParcouru = pointNonParcouru;
        }
        else {
            tmp = (point*)malloc(sizeof(point));
            tmp->nomPoint = ptr->nomPoint;
            tmp->suiv = NULL;
            tmp->distance = distance + pointParcouru->distance;
            if(distance + pointParcouru->distance != INT_MAX)
                tmp->voisin = pointParcouru;
            else
                tmp->voisin = NULL;
            pointNonParcouru->suiv = tmp;
            pointNonParcouru = tmp;
        }
        ptr = ptr->suiv;
    }
    /*Fin d'initialisation

    Etape 2 : Recherche des distances minimales entre ville*/
    ptr = premierPointNonParcouru;
    parc = (point*)malloc(sizeof(point));
    parc->distance = premierPointNonParcouru->distance;
    parc->nomPoint = premierPointNonParcouru->nomPoint;
    parc->suiv = premierPointNonParcouru->suiv;
    parc->voisin = premierPointNonParcouru;
    while(parc != NULL) {
        pointOptimale = NULL;
        pointOptimale = rechercherPointOptimal(premierPointNonParcouru);
        temp = (point*)malloc(sizeof(point));
        /*Sauvegarder la ville optimale*/
        temp->nomPoint = pointOptimale->nomPoint;
        temp->suiv = NULL;
        temp->distance = pointOptimale->distance;
        temp->voisin = pointOptimale->voisin;

        pointParcouru->suiv = temp;
        pointParcouru = temp;

        /*Suppression du point optimal*/
        premierPointNonParcouru = supprimerPoint(pointOptimale, premierPointNonParcouru);

        /*Mise a jour des distances*/
        majDistance(premierPointParcouru, premierPointNonParcouru, temp, pMap);

        parc = premierPointNonParcouru;
    }

    return premierPointParcouru;
}

/* Recupère un point */
point* getPoint(char pPoint[2], map *pMap) {
    point *ptr;
    ptr = pMap->premierPoint;
    while(ptr != NULL && ptr->nomPoint != pPoint)
        ptr = ptr->suiv;
    return ptr;
}

/* Permet de caculer la distance entre deux points */
int obtenirDistance(point *pPointDepart, point *pPointArrive) {
    point *ptr;
    ptr = pPointDepart->voisin;
    while(ptr != NULL) {
        if(ptr->nomPoint == pPointArrive->nomPoint) {
            return ptr->distance;
        }
        ptr = ptr->suiv;
    }
    if(ptr == NULL)
        return INT_MAX;
        /*Au cas ou les deux points ne sont pas voisins*/

}

/* Recherche le point le plus proche parmi la liste des points non Parcouru */
point* rechercherPointOptimal(point *pPremierPointNonParcouru) {
    point* ptr, *pointOptimale;
    ptr = pPremierPointNonParcouru->suiv;
    pointOptimale = pPremierPointNonParcouru;
    while(ptr != NULL) {
        if(pointOptimale->distance >= ptr->distance)
            pointOptimale = ptr;

        ptr = ptr->suiv;
    }
    return pointOptimale;
}

/* Supprimer un point de la liste des points non Parcouru */
point* supprimerPoint(point *pPointASupprimer, point* pOuSupprimer) {
    point *ptr, *prec, *tmp;

    ptr = pOuSupprimer;
    prec = NULL;
    while(ptr != NULL) {
        if(ptr->nomPoint == pPointASupprimer->nomPoint) {
            if(prec != NULL) {
                if(ptr->suiv == NULL) {
                    /*Suppression en queue de liste*/
                    tmp = ptr;
                    prec->suiv = NULL;
                    free(ptr);
                    return pOuSupprimer;
                }
                else {
                    /*Suppression au milieu de la liste*/
                    prec->suiv = ptr->suiv;
                    free(ptr);
                    return pOuSupprimer;
                }
            }
            else {
                /*Suppression en tete de liste*/
                tmp = ptr->suiv;
                free(ptr);
                return tmp;
            }
        }
        prec = ptr;
        ptr = ptr->suiv;
    }
}

/* Permet de mettre à jour les distances entre les points */
void majDistance(point* pPointDepart, point* pPremierPointNonParcouru, point *pDernierPointParcouru, map *pMap) {
    point* ptr, *tmp, *temp, *dernierPointParcouru, *pointDepart;
    ptr = NULL;
    tmp = NULL;
    dernierPointParcouru = NULL;
    pointDepart = NULL;
    ptr = pPremierPointNonParcouru;

    int disDernierPoint = 0, disPointDepart = 0, distance = 0, disDernierPointDepart = 0;
    while(ptr != NULL) {
        dernierPointParcouru = rechercherPoint(pDernierPointParcouru->nomPoint, pMap);
        dernierPointParcouru->distance = pDernierPointParcouru->distance;
        /*Distance entre le dernier point et le point actuel*/
        disDernierPoint = obtenirDistance(dernierPointParcouru, ptr);
        if(disDernierPoint != INT_MAX) {
            /*Il y un chemin entre le dernier point parcouru et le point actuel*/
            tmp = rechercherPoint(ptr->nomPoint, pMap);
            tmp->distance = ptr->distance;
            /*Distance entre le point actuel et le point de depart*/
            disPointDepart = obtenirDistance(tmp, pPointDepart);
            if(disPointDepart != INT_MAX) {
                /*Il y a un chemin entre le point actuel et le point de depart*/
                distance = dernierPointParcouru->distance + disDernierPoint;
                if(distance <= ptr->distance || ptr->distance == INT_MAX) {
                    ptr->distance = distance;
                    ptr->voisin = pDernierPointParcouru;
                    ptr = ptr->suiv;
                    continue;
                }
            }
            else {
                /*Distance entre le dernier point parcouru et le point actuel*/
                disDernierPoint = obtenirDistance(dernierPointParcouru, ptr);
                if(disDernierPoint != INT_MAX) {
                    distance = dernierPointParcouru->distance + disDernierPoint;
                    if(distance <= ptr->distance || ptr->distance == INT_MAX) {
                        ptr->distance = distance;
                        ptr->voisin = dernierPointParcouru;
                        ptr = ptr->suiv;
                        continue;
                    }
                }
            }
        }
        ptr = ptr->suiv;
    }
}

point* obtenirCheminPlusCourt(char pPointDepart[2], char pPointArrive[2], point *pPoint) {
    point *ptr;
    point *pointArrive;
    point *plusCourtChemin;
    point *entetePlusCourtChemin;
    plusCourtChemin = (point*)malloc(sizeof(point));
    ptr = pPoint;
    while(ptr != NULL) {
        if(ptr->nomPoint == pPointArrive)
            pointArrive = ptr;
        ptr = ptr->suiv;
    }
    plusCourtChemin = pointArrive;
    plusCourtChemin->suiv = NULL;
    entetePlusCourtChemin = plusCourtChemin;
    ptr = pPoint;
    while(ptr != NULL) {
        if(ptr->nomPoint == pPointArrive) {
            plusCourtChemin->suiv = ptr->voisin;
            plusCourtChemin = ptr->voisin;
            plusCourtChemin->suiv = NULL;
            if(ptr->voisin == NULL)
                break;
            pPointArrive = ptr->voisin->nomPoint;
            ptr = pPoint;

        }
        ptr = ptr->suiv;
    }

    return entetePlusCourtChemin;
}
