#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct user
{
  char username[100];
  int  id;
  int  register_year;
};

struct user server[]={
  "jesse",2312,2021,
  "annk",4331,2021,
  "oroboros",3952,2017,
  "dokuro",4316,2019,
  "kkjus",5332,2011,
  "marvest",9912,2010,
  "eillek",1092,2020,
  "tuomas",1292,2015,
  "marko",4131,2016,
  "tarja",1314,2014
};


/*
  TODO
  @function compare_username
  @desc     compares username of two user records.
*/
int compare_username(const void* a,const void* b)
{
  int i;
  struct user * x, * y;//Se declaran 2 nuevas variables
  x = (struct user *)a;//Se castean los valores de a y b
  y = (struct user *)b;

  //Compara los chars de los usernames de dos usuarios
  i=strcmp(x->username, y->username);
  return i;
}

/*
  TODO
  @function compare_id
  @desc     compares id of two user records.
*/
int compare_id(const void* a,const void* b)
{

  struct user * x, * y; //Se declaran 2 nuevas variables
  x = (struct user *)a; //Se castean los valores de a y b
  y = (struct user *)b;
    //Devuelve un número especifico dependiendo de si los valores
    //Comparados son mayores, menores o iguales.
    if (x->id > y->id){
    return -1;
  }
  if(x==y){
    return 0;
  }

  if(x<y){
  return 1;
  }
}



/*
  TODO
  @function compare_register_year
  @desc     compares register date of two user records.
*/
int compare_register_year(const void* a,const void* b)
{
  struct user * x, * y; //Se declaran 2 nuevas variables
  x = (struct user *)a; //Se castean los valores de a y b
  y = (struct user *)b;

    //Devuelve un número especifico dependiendo de si los valores
    //Comparados son mayores, menores o iguales.
    if (x->register_year > y->register_year){
    return -1;
  }
  if(x==y){
    return 0;
  }

  if(x<y){
  return 1;
  }
}

/*
  @function printrec
  @desc     prints user record
*/
void printrec(void* prec,void* arg)
{
  struct user* pstud=(struct user*)prec;
  printf("%-20s %d %d\n",pstud->username,pstud->id,pstud->register_year);
}

/*
  @function apply
  @desc     applies
 */
void apply(struct user* sarr,int nrec,void (*fp)(void* prec,void* arg),void* arg)
{
  int i=0;
  for(i=0;i<nrec;i++)
    {
      /*callback*/
      fp(&sarr[i],arg);
    }
}

/*
  @function isolder
  @desc     prints user record only if the user register is older than *((int*)arg)
*/
void isolder(void* prec,void* arg)
{
  int i;
  int year;
  i=2021;
  year= i - *(int *)arg; //devuelve el año mínimo en el que la persona debio haber ingresado para tener n años
  struct user* pstud=(struct user*)prec;
  if(pstud->register_year <= year){ //Solo imprime la información del usuario si tiene n años de haber ingresado
    printf("%-20s %d %d\n",pstud->username,pstud->id,pstud->register_year);
  }


}

int main()
{
  int nusers=sizeof(server)/sizeof(struct user);
  int n;

  puts("All user records:");
  puts("-------------------------------");
  apply(server,nusers,printrec,NULL);

  /*sort based on username*/
  puts("Sorted by username:");
  puts("-------------------------------");
  qsort(server,nusers,sizeof(struct user),compare_username);
  apply(server,nusers,printrec,NULL);

  /*sort based on ID*/
  puts("Sorted by ID:");
  puts("-------------------------------");
  qsort(server,nusers,sizeof(struct user),compare_id);
  apply(server,nusers,printrec,NULL);

  /*sort based on register date */
  puts("Sorted by register date:");
  puts("-------------------------------");
  qsort(server,nusers,sizeof(struct user),compare_register_year);
  apply(server,nusers,printrec,NULL);

  /*print people older than n*/
  puts("People older than n:");
  // TODO: request user input
  int age;
  printf("Inserte una cantidad de años\n");
  scanf("%i", &age);
  printf("Usuarios que superan dicha cantidad de años:\n");
  puts("-------------------------------");
  n=0;
  apply(server,nusers,isolder,&age);
  return 0;
}

