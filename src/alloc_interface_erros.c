/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include <stdio.h>
#include <stdlib.h>
#include "alloc_interface_erros.h"

LimpadorDeMemoria limpadorDeMemoria;
int limpadorRegistrado = 0;

int limpadorExiste() {
    return limpadorRegistrado;
}
void setLimpadorDeMemoria(LimpadorDeMemoria limpador) {   
    limpadorDeMemoria = limpador;
    limpadorRegistrado = 1;
}
void getLimpadorDeMemoria() {
    if(!limpadorRegistrado) {
        printf("ERROR: LIMPADOR DE MEMORIA N�O SETADO!");
        exit(1);
    } else {
        return limpadorDeMemoria();
    }
}
void erro_sem_memoria() {
   
    printf("ERROR: SEM MEMORIA SUFICIENTE PARA ALOCA��O! \n\n\n");
    getLimpadorDeMemoria();
    exit(1);
}
void erro_exercicio_nao_existe(int indice) {
    printf("ERROR: EXERC�CIO ESPECIFICADO [%d] N�O EXISTE!", indice);
    getLimpadorDeMemoria();
    exit(1);
}
void cuidado_exercicio_duplicado(int indice) {
    printf("CUIDADO: EXERC�CIO [%d] DUPLICADO! \n\n\n", indice);
}
char *erro_enunciado_nao_existe(int indice) {
    printf("ERROR: ENUNCIADO ESPECIFICADO [%d] N�O EXISTE!", indice);
    getLimpadorDeMemoria();
    exit(1);
    return "ERROR: ENUNCIADO ESPECIFICADO N�O EXISTE!";
}
void cuidado_enunciado_duplicado(int indice) {
    printf("CUIDADO: ENUNCIADO [%d] DUPLICADO! \n\n\n", indice);
}
