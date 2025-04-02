#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "veiculo.h"

struct veiculo{
    char placa[100];
    char marca[100];
    int ano;
};

Veiculo* criarVeiculo(const char* placa, const char* marca, int ano)
{
    Veiculo *veiculo=(Veiculo*)malloc(sizeof(Veiculo));
    if (veiculo==NULL)
        return NULL;

    strcpy(veiculo->placa,placa);    
    strcpy(veiculo->marca,marca);
    veiculo->ano=ano;
        
    return veiculo;
}

char *getPlaca(Veiculo *veiculo){
    return veiculo->placa;
}

char *getMarca(Veiculo *veiculo){
    return veiculo->marca;
}

int getAno(Veiculo *veiculo){
    return veiculo->ano;
}