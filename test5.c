#include <stdio.h>
#include <stdlib.h>
#define MAX_PRIOR 99;
typedef struct node{
        int data;//Dato contenido en el nodo
        int prior;
        struct node* next;//Puntero  al siguiente nodo
        struct node* prev;//Puntero  al nodo previo
} t_node;//Nombre para hacer referencia al tipo de dato de esta estructura.


typedef struct control{
        t_node* current;
        t_node* head;//Puntero al primero nodo
        t_node* tail;//Puntero al último nodo
} t_list;//Nombre para hacer referencia al tipo de dato de esta estructura


//Declaración de Funciones
t_list* createList();
t_node* createNode();
void delHighestPrior(t_list *list);
void insertNode(t_list *list, int data, int prior);
void deleteNode(t_list *list);
void printList(t_list *list);
void printHighestPrior(t_list *list);
void deleteList(t_list *list);


int main(){

t_list* lista = createList();
insertNode(lista, 5, 1);
insertNode(lista, 6, 9);
insertNode(lista, 7, 5);
insertNode(lista, 6, 9);
printList(lista);
delHighestPrior(lista);
printList(lista);
printHighestPrior(lista);
deleteList(lista);
free(lista);
return 0;

}//------END OF MAIN-----

//Funcion para crear un nuevo nodo
t_node *createNode(){
        t_node* newNode = (t_node*)malloc(sizeof(t_node));
        //Inicialicion de punteros del nodo
        newNode->data= 0;
        newNode->prior= MAX_PRIOR;
        newNode->next=NULL;
        newNode->prev=NULL;
        //La funcion me devuelve el nuevo nodo
        return newNode;
        }//------END OF FUNCTION------
//---------------------------------------------------------------------------------

//Función para crear una lista
t_list *createList(){
        t_list *newList = (t_list *)malloc(sizeof(t_list));//Se reserva la memoria
        //Inicialización de punteros
        newList->current=NULL;
        newList->head=NULL;
        newList->tail=NULL;
        //La funcion me devuelve la nueva lista
        return newList;
        }//------END OF FUNCTION------



//Función para imprimir la lista actual
void printList(t_list *list){
        list->current=list->head;
        if(list->current!=NULL){
                printf("Lista de datos:\n");
                while(list->current!=NULL){
                        printf("  %d  \n",list->current->data);
                        list->current=list->current->next;
                }//--END OF WHILE
        }//--END OF IF
        else{
                printf("La lista está vacía, no hay nada que imprmir :'(\n");
        }
}//------END OF FUNCTION------


//Función para escoger el nodo de mayor prioridad
void delHighestPrior(t_list* list){
if(list->head!=NULL){
list->current=list->head;
list->head= list->head->next;
free(list->current);
list->current=NULL;
}
else{printf("La lista está vacía");
}


}//------END OF FUNCTION------


void printHighestPrior(t_list* list){
printf("El elemento de mayor prioridad es: %i\n",list->head->data);
}//------END OF FUNCTION------


//Función para insertar un nuevo nodo a la lista
void insertNode(t_list *list, int data, int prior){
        t_node *newNode=createNode();//Se crea un nuevo nodo
        if(prior>99){//Si la prioridad dada al nodo es mayor a 99, será 99 (tope máximo)
            prior=MAX_PRIOR
        }
        else{

            newNode->prior=prior;
        }
        newNode->data=data;
        if(list->head == NULL){//Si la lista está vacìa
                list->head = newNode; //El nuevo nodo será el primer elemento
                list->tail = newNode;
        }
        else{ //Si la lista no está vacía
        if(newNode->prior < list->head->prior){//Si el nuevo nodo tiene mayor prioridad que el head
            newNode->next=list->head;
            list->head=newNode; //El nuevo nodo ahora es el head de la lista
        }
        else{//Si el nuevo nodo tiene menor prioridad que el head
            list->current= list->head; //Puntero al head
            t_node* temp= list->head->next;
            while(temp!= NULL && temp->prior < newNode->prior){ //While que devuelve el nodo que por orden
                                                                                         // de prioridad va antes que el nuevo nodo
                list->current= list->current->next;
                temp= list->current->next;
            }
            if(list->current->next == NULL){ //Si después ese nodo no hay ningun otro elemento
                list->current->next = newNode; //Se coloca el nuevo nodo inmediatamente después
                list->tail = newNode;
            }
            else{ //Si hay más elementos después del nodo
                newNode->next= list->current->next;  //Se pone el nuevo nodo en medio del nodo actual y el que le seguía
                list->current->next=newNode;
            }
        }

        }
}

//Función para borrar la lista

void deleteList(t_list *list){

	if(list->head!=NULL){ //Solo eliminará la lista si no está vacía
		list->current=list->head;//Posiciona el puntero current en el head de la lista
		if(list->head->next!=NULL){//Solo se ejecutará si la lista tiene más de un elemento
			list->current=list->head->next;
			while(list->current!=NULL){//Este bucle se repetirá mientras current sea diferente de NULL
				list->head->next=NULL;
				list->current->prev=NULL;
				free(list->head);
				list->head=list->current;
				list->current=list->head->next;
			}//END OF WHILE
		}//END OF IF 2
	free(list->head); //Se libera el head, que será el último elemento restante de la lista
	//Se apuntan a NULL todos los punteros de control de la lista
	list->head=NULL;
	list->current=NULL;
	list->tail=NULL;
	}//END OF IF 1
	else{
		printf("No hay nada que eliminar, la lista está vacía :(\n");
	}
}
