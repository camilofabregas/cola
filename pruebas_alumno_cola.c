#include "cola.h"
#include "testing.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include "pila.h"
#define TAM_PILA 3
#define CANT_VOLUMEN 1000

/* *****************************************************************
 *                    FUNCIONES AUXILIARES
 * *****************************************************************/

void destruir_dato_pila(void* pila) {
	pila_destruir(pila);
}


/* *****************************************************************
 *                    PRUEBAS UNITARIAS
 * *****************************************************************/

void pruebas_cola_vacia() {
	printf("\nINICIO DE PRUEBAS PARA COLA VACÍA\n");

	/* Declaro las variables a utilizar */
    cola_t* cola1 = cola_crear();

    /* Inicio de pruebas */
    print_test("Cola inicializada correctamente", cola1 != NULL);
    print_test("Cola esta vacia es verdadero", cola_esta_vacia(cola1));
    print_test("Ver primer elemento de la cola es NULL", !cola_ver_primero(cola1)); // Caso borde
    print_test("Desencolar ultimo elemento es NULL", !cola_desencolar(cola1)); // Caso borde

    /* Destruyo la cola*/
    cola_destruir(cola1, NULL);
    print_test("Cola destruida", true);
}


void pruebas_cola_un_elemento() {
	printf("\nINICIO DE PRUEBAS PARA COLA CON UN ELEMENTO\n");

	/* Declaro las variables a utilizar */
    cola_t* cola2 = cola_crear();
    int num = 3;

    /* Chequeo cola y encolo algunos elementos */
    print_test("Cola inicializada correctamente", cola2 != NULL);
    print_test("Encolar 3 es verdadero", cola_encolar(cola2, &num));

    /* Desencolo cada elemento chequeando el primer elemento */
    print_test("Cola esta vacia es falso", !cola_esta_vacia(cola2));
    print_test("El primer elemento de la cola es 3", cola_ver_primero(cola2) == &num);
    print_test("Desencolar el numero 3", cola_desencolar(cola2) == &num);
    print_test("Cola esta vacia es verdadero", cola_esta_vacia(cola2));

    /* Destruyo la cola*/
    cola_destruir(cola2, NULL);
    print_test("Cola destruida", true);
}


void pruebas_cola_algunos_elementos() {
	printf("\nINICIO DE PRUEBAS PARA COLA CON ALGUNOS ELEMENTOS\n");

	/* Declaro las variables a utilizar */
    cola_t* cola3 = cola_crear();
    int num1 = 3;
    int num2 = 5;
    int num3 = 8;
    void* nul = NULL;

    /* Chequeo cola y encolo algunos elementos */
    print_test("Cola inicializada correctamente", cola3 != NULL);
    print_test("Encolar 3 es verdadero", cola_encolar(cola3, &num1));
    print_test("Encolar 5 es verdadero", cola_encolar(cola3, &num2));
    print_test("Encolar 8 es verdadero", cola_encolar(cola3, &num3));
    print_test("Encolar NULL es verdadero", cola_encolar(cola3, nul)); // Caso borde

    /* Desencolo cada elemento chequeando el primer elemento */
    print_test("Cola esta vacia es falso", !cola_esta_vacia(cola3));
    print_test("El primer elemento de la cola es 3", cola_ver_primero(cola3) == &num1);
    print_test("Desencolar el numero 3", cola_desencolar(cola3) == &num1);
    print_test("El primer elemento de la cola es 5", cola_ver_primero(cola3) == &num2);
    print_test("Desencolar el numero 5", cola_desencolar(cola3) == &num2);
    print_test("El primer elemento de la cola es 8", cola_ver_primero(cola3) == &num3);
    print_test("Desencolar el numero 8", cola_desencolar(cola3) == &num3);
    print_test("El primer elemento de la cola es NULL", cola_ver_primero(cola3) == nul); // Caso borde
    print_test("Cola esta vacia es falso", !cola_esta_vacia(cola3)); // Caso borde
    print_test("Desencolar NULL", cola_desencolar(cola3) == nul); // Caso borde
    print_test("Cola esta vacia es verdadero", cola_esta_vacia(cola3));

    /* Destruyo la cola*/
    cola_destruir(cola3, NULL);
    print_test("Cola destruida", true);
}


void pruebas_cola_destruir_null() {
	printf("\nINICIO DE PRUEBAS PARA DESTRUIR COLA CON FUNCION NULL\n");

	/* Declaro las variables a utilizar */
    cola_t* cola4 = cola_crear();
    int num1 = 3;
    int num2 = 5;
    int num3 = 8;

    /* Chequeo cola y encolo algunos elementos */
    print_test("Cola inicializada correctamente", cola4 != NULL);
    print_test("Encolar 3 es verdadero", cola_encolar(cola4, &num1));
    print_test("Encolar 5 es verdadero", cola_encolar(cola4, &num2));
    print_test("Encolar 8 es verdadero", cola_encolar(cola4, &num3));

    /* Destruyo la cola*/
    cola_destruir(cola4, NULL);
    print_test("Cola destruida", true);
}


void pruebas_cola_destruir_free() {
	printf("\nINICIO DE PRUEBAS PARA DESTRUIR COLA CON FUNCION FREE\n");

	/* Declaro las variables a utilizar */
    cola_t* cola4 = cola_crear();
    int* num1 = malloc(sizeof(int));
    *num1 = 3;
    int* num2 = malloc(sizeof(int));
    *num2 = 5;
    int* num3 = malloc(sizeof(int));
    *num3 = 8;

    /* Chequeo cola y encolo algunos elementos */
    print_test("Cola inicializada correctamente", cola4 != NULL);
    print_test("Encolar 3 es verdadero", cola_encolar(cola4, num1));
    print_test("Encolar 5 es verdadero", cola_encolar(cola4, num2));
    print_test("Encolar 8 es verdadero", cola_encolar(cola4, num3));

    /* Destruyo la cola*/
    cola_destruir(cola4, free);
    print_test("Cola destruida", true);
}


void pruebas_cola_destruir_pila() {
	printf("\nINICIO DE PRUEBAS PARA DESTRUIR COLA CON FUNCION PILA_DESTRUIR\n");

	/* Declaro las variables a utilizar */
    cola_t* cola5 = cola_crear();
    pila_t* pila = pila_crear();
    int elems[TAM_PILA]; // Vector con la cantidad de elementos de la pila
   	for (int i = 0; i < TAM_PILA; i++) {
   		elems[i] = i+1;
   		pila_apilar(pila, &elems[i]);
   	}

    /* Chequeo cola y encolo algunos elementos */
    print_test("Cola inicializada correctamente", cola5 != NULL);
    print_test("Cola esta vacia es verdadero", cola_esta_vacia(cola5));
    print_test("Encolar pila es verdadero", cola_encolar(cola5, pila));
    print_test("Cola esta vacia es falso", !cola_esta_vacia(cola5));

    /* Destruyo la cola*/
    cola_destruir(cola5, destruir_dato_pila);
    print_test("Cola destruida", true);
}


void pruebas_cola_volumen() {
    printf("\nINICIO DE PRUEBA DE VOLUMEN PARA COLA\n");

    /* Declaro las variables a utilizar */
    cola_t* cola6 = cola_crear();
    int* vector = malloc(CANT_VOLUMEN * sizeof(int));
    bool encolar_volumen = true;
    bool desencolar_volumen = true;

    /* Chequeo cola y encolo los elementos del vector */
    print_test("Cola inicializada correctamente", cola6 != NULL);
    for (int i = 0; i < CANT_VOLUMEN && encolar_volumen; i++) {
        vector[i] = i+1;
        encolar_volumen = cola_encolar(cola6, &vector[i]);
    }
    print_test("Encolar varios elementos", encolar_volumen);
    print_test("El primer elemento de la cola es el primer encolado", cola_ver_primero(cola6) == &vector[0]);
    print_test("Cola esta vacia es falso", !cola_esta_vacia(cola6));
    for (int i = 0; i < CANT_VOLUMEN; i++) {
        int* desencolado = cola_desencolar(cola6);
        if (desencolado != &vector[i]) desencolar_volumen = false;
    }
    print_test("Todos los elementos fueron desencolados correctamente", desencolar_volumen);
    print_test("Cola esta vacia es verdadero", cola_esta_vacia(cola6));


    /* Destruyo la cola y libero el vector*/
    cola_destruir(cola6, NULL);
    print_test("Cola destruida", true);
    free(vector);
}


void pruebas_cola_alumno() {
	pruebas_cola_vacia();
	pruebas_cola_un_elemento();
	pruebas_cola_algunos_elementos();
	pruebas_cola_destruir_null();
	pruebas_cola_destruir_free();
	pruebas_cola_destruir_pila();
    pruebas_cola_volumen();
}