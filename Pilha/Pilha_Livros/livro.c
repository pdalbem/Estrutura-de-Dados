#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "livro.h"

struct livro{
    char titulo[100];
    char autor[100];
    char editora[100];
    int anoPublicacao;
};

Livro* criarLivro(const char* titulo, const char* autor, const char* editora, int ano)
{
    Livro *livro=(Livro*)malloc(sizeof(Livro));
    if (livro==NULL)
        return NULL;

    strcpy(livro->titulo,titulo);    
    strcpy(livro->autor,autor);
    strcpy(livro->editora,editora);
    livro->anoPublicacao=ano;
        
    return livro;
}

char *getTitulo(Livro *livro){
    return livro->titulo;
}

char *getAutor(Livro *livro){
    return livro->autor;
}
char *getEditora(Livro *livro){
    return livro->editora;
}

int getAnoPublicacao(Livro *livro){
    return livro->anoPublicacao;
}