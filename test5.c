#include<stdio.h>
#include<stdlib.h>

//Estructura del nodo
typedef struct node{
        int data;//Dato contenido en el nodo
        struct node* next;//Puntero  al siguiente nodo de la lista
        struct node* prev;//Puntero al siguiente nodo de la lista
} t_node;//Nombre para hacer referencia al tipo de dato de esta estructura.

//Estructura de control
typedef struct control{
        t_node* current;//Puntero al nodo actual
        t_node* head;//Puntero al primero nodo
        t_node* tail;//Puntero al ùltimo nodo
} t_list;//Nombre para hacer referencia al tipo de dato de esta estructura

//----------
//Inicializacion de funciones y variables
t_list *createList();
t_node *createNode();
t_node *selectNode(t_list *list);
void insertNode(t_list *list);
void deleteNode(t_list *list);
void printList(t_list *list);
int listSize(t_list *list);
int menureturn();
int i; //índice

//---------i
//------MAIN-------
int main(){
	int a=0;
	t_list *list = createList();
	do{
	int a=0;//variable en la que se guardará la opcion seleccionada por el usuario
	printf(" ______________________________________________________________________ \n");
	printf("|                                                                      |\n");
	printf("|------------------------ Creador de listas ---------------------------|\n");
	printf("|______________________________________________________________________|\n");
	printf("|                                                                      |\n");
	printf("| 1.        Insertar un nuevo nodo en la lista de datos                |\n");
	printf("|_________________________________ ____________________________________|\n");
	printf("|                                 |                                    |\n");
	printf("| 2. Eliminar nodo de la lista    | 3. Imprimir lista                  |\n");
	printf("|_________________________________|____________________________________|\n");
	printf("|                                 |                                    |\n");
	printf("| 4. Eliminar lista               | 5. Salir                           |\n");
	printf("|_________________________________|____________________________________|\n");
	printf("Ingrese una opcion: ");
	scanf("%i", &a);
		switch(a){
			case 1:
				insertNode(list);
				break;
			case 2:
				deleteNode(list);
				break;
			case 3:
				printList(list);
				break;
			case 4:
				break;
			case 5:
			//	exit(-1);
				break;
		}//END OF SWITCH

		printf("Final menù principal\n");
			
	//	a2=menureturn();//pregunta al usuario si desea realizar otra accion
		//if(a2!=1){// Si la opcion es diferente de 1(re ingresar al menú), se saldrá del programa
		//		if(a2!=2){//Si la opción seleccionada no es 2
		//			printf("La opción ingresada no es válida\nSaliendo del programa...");
		//		}
		//		
		//		printf("Saliendo...");
		//		break;
//		}//END OF IF
        	
	} while(a!=5);//END OF WHILE
}//----END OF MAIN-----

//FUNCIONES PRINCIPALES

//Funcion para crear un nuevo nodo
t_node *createNode(){
	t_node* newNode = (t_node*)malloc(sizeof(t_node));
        //Inicialicion de punteros del nodo
        newNode->data=0;
        newNode->next=NULL;
        newNode->prev=NULL;
	//Se le solocita al usuario que ingrese eldato que contendrá el nodo
	printf("Ingrese el dato que contendrá el nuevo nodo:");
        scanf("%i", &newNode->data);
        //La funcion me devuelve el nuevo nodo
        return newNode;
}//------END OF FUNCTION------

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

//Función para obtener el tamaño de la lista
int listSize(t_list *list){
        i=0;
        if(list->head!=NULL){
                list->current=list->head;
                while(list->current!=NULL){
                        list->current=list->head->next;
                        i++;
                }
        
        return i;
	}else{
		return -1;
	}
}//------END OF FUNCTION------

//Función para volver al menú anterior
int menureturn(){
	int inp2;
	printf("¿Desea hacer algo más?\n1.Volver al menú principal.\n2.Salir\n");
        scanf("%i",&inp2);
        return inp2;
}//------END OF FUNCTION------

//Función para buscar un nodo especifico en la lista
t_node *selectNode(t_list *list){
        i=0;
	t_node *r= NULL;
        int select;
        int l = listSize(list);//Longitud de la lista
        int *index[l];//Se crea un array de punteros para enumerar los nodos
        list->current=list->head;//Posiciona el puntero current sobre el head
        printf("Lista de datos:\n");
        if(list->current!=NULL){
		while(list->current!=NULL){
			index[i]=&list->current->data;
			printf("Nodo %i: %i\n",i+1,list->current->data);
			list->current=list->current->next;//Ahora current es el nodo siguiente
			i++;
		}//--END OF WHILE 1
		printf("Ingrese la posición del nodo en el que se desea posicionar:\n");
		scanf("%i",&select);
		i=0;
		while(list->current!=NULL){
			list->current=list->head;
			if(*index[i]>l){//Si el numero de nodo indicado es más grande que l 
				printf("El nodo indicado no existe");
				break;
			}//--END OF IF 2
			if(*index[i]==select){
				printf("Nodo seleccionado con éxito");
			//	return list->current;
				r = list->current;
				break;
			}// END OF IF
			else{
				break;
			}//--END OF ELSE
			list->current=list->current->next;
		}//---END OF WHILE 2
	}//--END OF IF 1
        else{
		printf("La lista está vacía, no hay nada que imprmir :( \n" );
	}
return r;
}//------END OF FUNCTION------

//Función para imprimir la lista actual
void printList(t_list *list){
	i=0;
        list->current=list->head;
	if(list->current!=NULL){
		printf("Lista de datos:\n");
        	while(list->current!=NULL){
                	printf("Nodo %i:|  %d  |\n",i+1,list->current->data);
                	list->current=list->current->next;
                	i++;
		}//--END OF WHILE
	}//--END OF IF
	else{
		printf("La lista está vacía, no hay nada que imprmir :'(\n");
	}

}//------END OF FUNCTION------
	

	
//------------------------------------------------------
//FUNCIONES DERIVADAS

//Función para insertar un nuevo nodo a la lista
void insertNode(t_list *list){
	int opt;
	t_node *node=createNode();//Se le pide al usuario por medio que ingrese el dato que contendrá el nuevo nodo
		//mediante consola y se crea un nuevo nodo cuya información contenida será la ingresada
	if(list->head == NULL){//Si el head está vacio, quiere decir que la lista está vacía
			//y nuestro nodo será el el primero o el 'head' de la misma
		list->head =node;
		list->head->next = NULL;
		list->tail = list->head;
		list->tail->next=NULL;
	}
	else{// En caso de que no sea el primer elemento de la lista, se le preguntara al usuario donde
		//desea insertar el nuevo nodo
		printf("En que parte de la lista desea insertar el nuevo nodo:\n");
                printf("1. Al inicio \n2. Al final \n3. Despues/Antes de un nodo específico\n4. Salir\n");
		scanf("%i\n", &opt);
		switch(opt){
			case 1://Insertar nodo al inicio de la lista
				printf("HELP ME \n");
				list->head->prev = node;
				node->prev = NULL;
				node->next = list->head;
				list->head = node;
				printf("El nodo ha sido insertado con éxito :D\n");
				break;
			case 2://Insertar nodo al final de la lista
				list->tail->next = node;
				node->next = NULL;
				node->prev = list->tail;
				list->tail = node;
				printf("El nodo ha sido insertado con éxito :D\n");
				break;
			case 3://Insertar nodo en otro lugar de la lista
				printf("En cual nodo desea posicionarse?\n");
				list->current=selectNode(list);
				printf("Insertar nodo:\n1.Antes del nodo seleccionado\n2.Después del nodo seleccionado\n3.Salir\n");
//				scanf("%i",&opt2);
//				switch(opt2){
//					case 1://caso 3.1: antes del nodo
//						if(list->current==list->head){//Si el nodo seleccionado es el primero,entonces 
//						//en realidad se insertará el nuevo nodo al inicio de la lista, como en el caso 1
//							list->head->prev = node;
//							node->prev = NULL;
//							node->next = list->head;
//							list->head = node;
//						}//---END OF IF
//						else{
//						node->prev = list->current->prev;
//						node->next = list->current;
//						list->current->prev->next = node;
//						list->current->prev = node;
//						}//END OF ELSE
//						printf("El nodo ha sido insertado con éxito :D\n");
//						break;
//					case 2://Caso 3.2: después del nodo
//						if(list->current==list->tail){//Si el nodo seleccionado es el último,entonces 
//						//en realidad se insertará el nuevo nodo al final de la lista, como en el caso 2
//							list->head->prev = node;
//							node->prev = NULL;
//							node->next = list->head;
//							list->head = node;
//						}//---END OF IF
//						else{
//							node->prev = list->current;
//							node->next = list->current->next;
//							list->current->next->prev = node;
//							list->current->next = node;			
//						}
//						printf("El nodo ha sido insertado con éxito :D\n");
//						break;
//					default://Caso 3.1: Salir del menú actual
//						break;//final caso 3.1		
//				}//END SWITCH 2
				break;//final caso 3
			default: 
				printf("Opción inválida\n");
        	}//END OF SWITCH 1
		printf("Saliendo de función insertNode\n");
}//END OF ELSE

}//------END OF FUNCTION------
	
//----------------------------------------------------

//Función para eliminar un nodo de la lista
void deleteNode(t_list *list){
	int opt;
	int r;
        if(list->head!=NULL){             
//		while(1){
			r=0;//indicador para la opción 3
			printf("Cual nodo desea eliminar:\n");
                	printf("1. El último \n2. El primero \n3. Otro\n4.Salir\n");
			scanf("%d\n", &opt);
			while(1){
				switch(opt){
					case 1: //Elimina el último nodo
						list->current=list->tail; //Coloca el puntero current en el último nodo de la lista
						list->tail=list->tail->prev; //Cambia el puntero tail al nodo anterior (ahora este pasa a ser el ultimo nodo de la lista)
						list->tail->next=NULL; //Hace que el puntero next del nuevo último nodo apunte a NULL
						list->current->prev=NULL; //Hace que el puntero previo al nodo que vamos a borrar apunte a NULL
						free(list->current); //Se libera la memoria del nodo 
						printf("El nodo ha sido eliminado con éxito :D\n");
						break;
					case 2://Elimina el primer nodo
						list->current=list->head; //Coloca el puntero current en el primer nodo de la lista
						list->head=list->head->next; //Cambia el puntero head al nodo siguiente (ahora este pasa a ser el primer nodo de la lista)
						list->head->prev=NULL; //Hace que el puntero prev del nuevo head apunte a NULL
						list->current->next=NULL; //Hace que el puntero prev del antiguo head apunte a NULL
						free(list->current); //Se libera la memoria del head antiguo 
						printf("El nodo ha sido eliminado con éxito :D\n");
						break;
					case 3://Elimina otro nodo específico
						printf("Cual nodo desea eliminar:\n");
						list->current=selectNode(list);
						if(list->head->prev==NULL){
							r=2;
							break;
						}
						else if(list->head->prev==NULL){
							r=1;
							break;
						}
						else{
							printf("El nodo ha sido eliminado con éxito :D\n");
							break;
						}
					case 4://Sale del menú actual
						break;
				}//END OF SWITCH
				
				//Funcion en caso de que en el caso 3 el nodo indicado sea el primero o el
				//ultimo de la lista. Entra de nuevo al switch pero en el caso correspondiente
				if((r)!=0){
				opt=r;
				}
				else{
					break;
				}
				
			}//END  WHILE
//			opt2=menureturn();//pregunta al usuario si desea realizar otra accion
//			if(opt2!=1){// Si la opcion es diferente de uno, se saldrá del programa
//				if(opt2!=2){//Si la opción seleccionada no es 2
//					printf("La opción ingresada no es válida\nSaliendo del programa...");
//				}
//				break;
//			}
//		}//End while principal
        }//END OF IF(head!=NULL)
        else{
        printf("La lista se encuentra vacia :(\n ");
        }
}//------END OF FUNCTION------


