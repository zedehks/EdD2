#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int initMenu();
//void ReadJson(char  *file, int orden);
void opcion(int opcion);
//void parsejson(char *opcion);


struct CrearTabla
{

    char *nombre;
    int id;
    int orden;

    struct CrearTabla *next;

};

struct CrearTabla *ct_head = NULL;
//struct CrearTabla *ct_current = NULL;

struct CrearCampo
{
  char *nombre_campo;

  struct CrearCampo *next;
};

struct CrearCampo *cc_head = NULL;
//struct CrearCampo *cc_current = NULL;

struct ConsultarTabla
{

    char *nombre;
    int id;
    int orden;

};

struct EditarTabla
{

    char *nombre;
    int id;
    int orden;
    char subopciones;

};

struct ElimarTabla
{

    char *nombre;
    int id;
    int orden;

};

bool isEmpty()
{
  return ct_head == NULL;
}

void printTabla()
{
  struct CrearTabla *ptr = ct_head;
  printf("\n[ ");

  while(ptr != NULL){
    printf("(%s,%d,%d) ", ptr->nombre,ptr->id,ptr->orden);
    ptr = ptr->next;
  }
  printf(" ]");
}

void insertTabla(char *nombre, int id, int orden)
{

  struct CrearTabla *ptr = (struct CrearTabla*)malloc(sizeof(struct CrearTabla));

  ptr->nombre = nombre;
  ptr->id = id;
  ptr->orden = orden;

  ptr->next = ct_head;

  ct_head = ptr;

}

struct CrearTabla *search(char *nombre)
{

  struct CrearTabla *current = ct_head;

  if(ct_head == NULL){
    return NULL;
  }

  //while(current->nombre != nombre){
  while(strcmp(current->nombre,nombre)){

    if(current->next == NULL)
      return NULL;

    else
      current = current->next;
  }

  return current;

}

void printCampo()
{
  struct CrearCampo *ptr = cc_head;
  printf("\n[ ");

  while(ptr != NULL){
    printf("%s | ", ptr->nombre_campo);
    ptr = ptr->next;
  }
  printf("]");
}

void insertCampo(char* nombre_campo)
{
  struct CrearCampo *ptr = (struct CrearCampo*)malloc(sizeof(struct CrearCampo));

  ptr->nombre_campo = nombre_campo;

  ptr->next = cc_head;

  cc_head = ptr;
}


int initMenu()
{

    int op = 0;

    do{
        printf("1.Crear tabla\n");
        printf("2.Consultar tabla\n");
        printf("3.Editar tabla\n");
        printf("4.Eliminar tabla\n");
        printf("5.Salir\n");
        printf("\nOpcion: ");

        scanf("%d", &op);
	if(op == 5) break;
        opcion(op);

    }while(true);

}


void opcion(int orden)
{

	
	int c;
	while ( (c = getchar()) != '\n' && c != EOF ) { }
    switch(orden){

    case 1:
        //ReadJson("Tables.json", orden);

        insertTabla("Vehiculo", 1, 1);
        insertTabla("Estudiante", 2, 2);
        insertTabla("Ropa", 3, 3);
        insertTabla("Donald Trump", 4, 4);

        printf("\nLista de tablas disponibles: ");

        printTabla();

        printf("\n\n");
        break;
    case 2:
        //ReadJson("Tables.json", orden);
        //char *n;

        printf("\nQue tabla desea consultar? ");
	char query[256]; 
	fgets(query, sizeof(query), stdin);
	printf("searching for: %s...\n\n",query);
        struct CrearTabla *find = search("Ropa");
        //scanf("%s\n", n);

        //find = search(n);

        if(find != NULL){
          printf("\nElemento Encontrado!: " );
          printf("(%s,%d,%d) ", find->nombre,find->id,find->orden);
          insertCampo("Id");
          insertCampo("Marca");
          insertCampo("Modelo");
          insertCampo("Año");
          insertCampo("Placa");

          printCampo();

          //printf("\n");
        }
        else
          printf("Elemento no encontrado.");

        printf("\n\n");
        break;
    case 3:
        //ReadJson("Tables.json", orden);
        printf("\n");
        break;
    case 4:
        //ReadJson("Tables.json",orden);
        printf("\n");
        break;
default:
	printf("?\n\n");

    }

}

int main(int argc, char *argv[])
{
    initMenu();
    return 0;
}
