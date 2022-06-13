#include <stdio.h>
 #include <iostream>
 #include <stdlib.h>
 #include <conio.h>
 #include <time.h>

 /* estructura autorreferenciada */
 struct nodoArbol {
        struct nodoArbol *Izq; /* apuntador al subárbol izquierdo */
        int dato; /* valor del nodo */
        struct nodoArbol *Der; /* apuntador al subárbol derecho */
 }; /* fin de la estructura nodoArbol */

 /* prototipos */
 void insertaNodo(struct nodoArbol **ptrArbol, int valor );
 void inOrden(struct nodoArbol *ptrArbol );
 void preOrden(struct nodoArbol *ptrArbol );
 void postOrden(struct nodoArbol *ptrArbol );
 struct nodoArbol *Buscar(struct nodoArbol *ptrArbol,int valor);
 void EliminacionPorFusion(struct nodoArbol **ptrArbol,int valor);
 void EliminacionPorCopiado(struct nodoArbol **ptrArbol,int valor);

 int main(){
 int i,n;
 int elemento; /* variable para almacenar valores al azar */
 struct nodoArbol *ptrRaiz = NULL, *p=NULL; /* árbol inicialmente vacío */
 for(;;){
        printf("\n\tOPERACIONES PARA ARBOLES BINARIOS DE BUSQUEDA\n\n");
        printf("\t\t\t    MENU\n\n");
        printf("\t\t1.Crear arbol con nodos al azar.\n");
        printf("\t\t2.Recorrer el Arbol. \n");
        printf("\t\t3.Buscar nodo.\n");
        printf("\t\t4.Eliminacion por fusion\n");
        printf("\t\t5.Eliminacion por copiado\n");
        printf("\n\t    >>Ingrese una opcion:");
        scanf("%d",&n);


        switch(n)
        {
        case 1:{/* inserta valores al azar entre 1 y 15 en el árbol */
                srand( time( NULL ) );
                printf("\n\n\tLos numeros colocados en el arbol son:\n" );
                printf("\t  ");
                for ( i = 1; i <= 8; i++ ) {
                        elemento = rand() % 15;
                        printf( "%3d", elemento );
                        insertaNodo( &ptrRaiz, elemento );
                }
                getch();
                system("cls");
                break;
        }
        case 2:{/* recorrer el árbol*/
                system("cls");
                if(ptrRaiz!=NULL){
                        printf("\n\t\t  RECORRIDO POR PROFUNDIDAD\n");
                        printf( "\n\n\tEl recorrido en preorden es:\n\t\t" );
                        preOrden( ptrRaiz );
                        printf( "\n\n\tEl recorrido inorden es:\n\t\t" );
                        inOrden( ptrRaiz );
                        printf( "\n\n\tEl recorrido en postorden es:\n\t\t" );
                        postOrden( ptrRaiz );
                }
                else
                        printf("\n\t\tEL ARBOL ESTA VACIO!!!");
                getch();
                system("cls");
                break;
        }
        case 3:{/* Buscar */
                printf("\t\tIngrese el valor del nodo a Buscar: ");
                scanf("%d",&elemento);
                p=Buscar(ptrRaiz,elemento);
                if(p!=NULL)
                        printf("\n\tEl valor %d se encuentra en el arbol.\n\n",p->dato);
                else
                        printf("\n\ttEl valor %d NO se encuentra en el arbol.\n\n");
                getch();
                system("cls");
                break;
        }
        case 4:{/* Eliminacion por fusion */
                printf("\n\t\tIngrese el valor del nodo a Eliminar: ");
                scanf("%d",&elemento);
                printf("\n\t\tEliminacion Por Fusion\n");
                EliminacionPorFusion( &ptrRaiz,elemento);
                getch();
                system("cls");
                break;
        }
        case 5:{/* Eliminacion por copiado */
                printf("\n\t\tIngrese el valor del nodo a Eliminar: ");
                scanf("%d",&elemento);
                printf("\n\n\tEliminacion Por Copiado\n");
                EliminacionPorCopiado( &ptrRaiz,elemento);
                getch();
                system("cls");
                break;
        }
        }
 }
 return 0;

 } /* fin de main */

 /* inserta un nodo dentro del árbol */
 void insertaNodo(struct nodoArbol **ptrArbol, int valor )
 {

 if ( *ptrArbol == NULL ) {// si el árbol está vacío
        *ptrArbol = new(nodoArbol);
                ( *ptrArbol )->dato = valor;
                ( *ptrArbol )->Izq = NULL;
                ( *ptrArbol )->Der = NULL;
 } // fin de if
 else { // el árbol no está vacío

        if ( valor < ( *ptrArbol )->dato ) // el dato a insertar es menor que el dato en el nodo actual
                insertaNodo( &( ( *ptrArbol )->Izq ), valor );

        else if ( valor > ( *ptrArbol )->dato ) // el dato a insertar es mayor que el dato en el nodo actual
                insertaNodo( &( ( *ptrArbol )->Der ), valor );

        else  // ignora el valor duplicado del dato
                printf( "dup" );

 }


 } /* fin de la función insertaNodo */

 /* comienza el recorrido inorden del árbol */
 void inOrden(struct nodoArbol *ptrArbol )
 {

 /* si el árbol no está vacío, entonces recórrelo */
 if ( ptrArbol != NULL ) {
 inOrden( ptrArbol->Izq );
 printf( "%3d", ptrArbol->dato );
 inOrden( ptrArbol->Der );
 } /* fin de if */

 } /* fin de la función inOrden */

 /* comienza el recorrido preorden del árbol */
 void preOrden(struct nodoArbol *ptrArbol )
 {

 /* si el árbol no está vacío, entonces recórrelo */
 if ( ptrArbol != NULL ) {
 printf( "%3d", ptrArbol->dato );
 preOrden( ptrArbol->Izq );
 preOrden( ptrArbol->Der );
 } /* fin de if */

 } /* fin de la función preOrden */

 /* comienza el recorrido postorden del árbol */
 void postOrden(struct nodoArbol *ptrArbol )
 {

 /* si el árbol no está vacío, entonces recórrelo */
 if ( ptrArbol != NULL ) {
 postOrden( ptrArbol->Izq );
 postOrden( ptrArbol->Der );
 printf( "%3d", ptrArbol->dato );
 } /* fin de if */

 } /* fin de la función posOrden */

 /*struct nodoArbol *Buscar(struct nodoArbol *ptrArbol,int valor)
{
    if(ptrArbol!= NULL){
        if(ptrArbol->dato==valor)
            return ptrArbol;
        else{
            if (ptrArbol->dato<valor){
                    if(ptrArbol->Der!=NULL)
                        Buscar(ptrArbol->Der,valor);
                    else
                        return ptrArbol->Der;
            }
            else{
                    if(ptrArbol->Izq!=NULL)
                        Buscar(ptrArbol->Izq,valor);
                    else
                        return ptrArbol->Izq;
            }
        }
    }
}*/

struct nodoArbol *Buscar(struct nodoArbol *ptrArbol,int valor)
{
        struct nodoArbol *p;// variable auxiliar que recorrerá el ÁRBOL
        p=ptrArbol;// P toma la direccion de la raíz
        while(p!=NULL && p->dato!=valor){
                if(valor>p->dato)//si el valor buscado es mayor
                        p=p->Der;//pasamos al subArbol derecho ya que ahí están los valores ,mayores a la raíz
                else//si el valor buscado es menor
                        p=p->Izq;//pasamos al subArbol izquierdo ya que ahí están los valores ,menores a la raíz
        }
        return p;
};

void EliminacionPorFusion(struct nodoArbol **ptrArbol,int valor)
{
        struct nodoArbol *p, *prev, *nodo, *inf;
        p=*ptrArbol;

        while(p!=NULL && p->dato!=valor){
                prev=p;
                if(valor>p->dato)
                        p=p->Der;
                else
                        p=p->Izq;
        }
        nodo=p;
        if(p!=NULL && p->dato==valor){
                if(nodo->Der==NULL)
                        nodo=nodo->Izq;
                else if (nodo->Izq==NULL)
                        nodo=nodo->Der;
                else{
                        inf=nodo->Izq;
                        while(inf->Der!=NULL)
                                inf=inf->Der;
                        inf->Der=nodo->Der;
                        nodo=nodo->Izq;
                }
                if(p==*ptrArbol){
                        *ptrArbol=nodo;
                        delete(p);
                        printf("\n\n\tElemento ELIMINADO!!!\n\n");
                }
                else if(prev->Izq==p){
                        prev->Izq=nodo;
                        delete(p);
                        printf("\n\n\tElemento ELIMINADO!!!\n\n");
                        }
                else{
                        prev->Der=nodo;
                        delete(p);
                        printf("\n\n\tElemento ELIMINADO!!!\n\n");
                }
        }
        else if(*ptrArbol!=NULL)
                printf("El valor %d NO esta en el arbol",valor);
        else
                printf("El arbol esta vacio!!!");
}

void EliminacionPorCopiado(struct nodoArbol **ptrArbol,int valor)
{
        struct nodoArbol *p, *prev, *nodo, *inf, *prev2;
        p=*ptrArbol;

        while(p!=NULL && p->dato!=valor){
                prev=p;
                if(valor>p->dato)
                        p=p->Der;
                else
                        p=p->Izq;
        }
        nodo=p;
        if(p!=NULL && p->dato==valor){
                if(nodo->Der==NULL)
                        nodo=nodo->Izq;
                else if (nodo->Izq==NULL)
                        nodo=nodo->Der;
                else{
                        prev2=nodo;
                        inf=nodo->Izq;
                        while(inf->Der!=NULL){
                                prev2=inf;
                                inf=inf->Der;
                        }
                        nodo->dato=inf->dato;
                        if(prev2==nodo)
                                prev2->Izq=inf->Izq;
                        else
                                prev2->Der=inf->Der;
                }
                if(p==*ptrArbol){
                        *ptrArbol=nodo;
                        delete(inf);
                        printf("\n\n\tElemento ELIMINADO!!!\n\n");
                }
                else if(prev->Izq==p){
                        prev->Izq=nodo;
                        delete(inf);
                        printf("\n\n\tElemento ELIMINADO!!!\n\n");
                        }
                else{
                        prev->Der=nodo;
                        delete(inf);
                        printf("\n\n\tElemento ELIMINADO!!!\n\n");
                }
        }
        else if(*ptrArbol!=NULL)
                printf("\n\tEl valor %d NO esta en el arbol\n\n",valor);
        else
                printf("\n\n\tEl arbol esta vacio!!!\n\n");
}
