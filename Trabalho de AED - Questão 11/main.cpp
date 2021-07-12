#include<iostream>
#include<string>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100
#define N 15

typedef struct Processos{
    int index;
    int page;
    int valor;
}Processos;

typedef struct Memoria{
    Processos vetor[N];
    int primeiro;
    int ultimo;
}Memoria;

typedef struct Disco{
    int vetor[N];
    int primeiro;
    int ultimo;
}Disco;

int arquivoDisco(char *arquivo1, Disco *disco);
int arquivoProcessos(char *arquivo2, Disco *processos);
int tokenizar(char *str, int *t);
void matrizDisco(int *t, Disco *disco, int contador);
void InsereMemoria(Memoria *memory, Processos P );
void matrizProcessos(int *t, Disco *processos, int contador);
void FLvaziaDisco(Disco *disco);
void FLvaziaProcesso(Disco *processos);
void FLvaziaMemoria(Memoria *memory);
void InsereDisco(int dado,  Disco *disco );
void InsereProcessos(int dado,  Disco *processos );
void RetiraDisco(int *dado, int p, Disco *disco);
void RetiraProcessos(int *dado, int p, Disco *processos);
void ExibirDisco(Disco *d1);
void ExibirProcessos(Disco *d2);
void manutencaoProcessos(Disco *processos, Disco *disco, Memoria *memory);
int BuscarNoDisco(Disco *disco, int page);
int BuscarNaMemoria(Memoria *memory,int page,int index);
void memoria(Memoria *memory);
void retornaDisco(Disco *disco, int page, int valor);
void RetornarValorMemoriaParaDisco(Memoria *memory, Disco *disco);


using namespace std;

int main() {

    int a, b, c;
    Disco disco[N];
    Disco processos[N];
    int contadorDisco=0;
    Memoria m[N];
    int contarVezes1=0;
    int contarVezes2=0;
    int contarVezes3=0;
    int contarVezes4=0;
    int contarVezes5=0;
    int contarVezes6=0;
    int contarVezes7=0;

    for(int i=0; i < 4; i++) {
        FLvaziaMemoria(&m[i]);
    }

    cout<<"Exercicio de Memoria de disco" << endl;
    cout<<"Professor: Michel"<<endl;
    cout<<"Aluno: Leonardo de Oliveira Campos"<< endl;
    cout<<endl;
    cout<<endl;

    do{
        cout<<"----------Menu----------"<< endl;
        cout<<"1 - Carregar Processos" << endl;
        cout<<"2 - Carregar Disco" << endl;
        cout<<"3 - limpar " << endl;
        cout<<"4 - Exibir Matriz" << endl;
        cout<<"5 - Memoria"<<endl;
        cout<<"6 - Manutencao"<<endl;
        cout<<"0 - Sair " << endl;
        cout<<"Digite: ";
        cin>>a;
        cout<<endl;
        cout<<"carregando..."<<endl;

        switch(a){
            case 0:
                cout<<"Saindo..."<<endl;
                system("cls");
                cout<<"Limpo"<<endl;
                break;
            case 1:
                cout<<"Carregar Processos tokenizado(d1)"<<endl;
                contadorDisco = arquivoProcessos("Processos.txt", processos);

                contarVezes1 += 1;
                cout<<"Quantas vezes esse processo rodou: "<<contarVezes1<<endl;
                break;
            case 2:
                cout<<"Carregar Disco tokenizado(d2)"<<endl;
                contadorDisco = arquivoDisco("Disco.txt", disco);

                contarVezes2 += 1;
                cout<<"Quantas vezes esse processo rodou: "<<contarVezes2<<endl;
                break;
            case 3:
                cout<<"Limpar"<<endl;
                system("cls");
                break;
            case 4:
                cout<<"Exibir Matriz carregada pelo ultimo processo de Disco"<<endl;
                cout<<"0 - Sair"<<endl;
                cout<<"1 - Disco"<<endl;
                cout<<"2 - Processo"<<endl;
                cout<<"3 - Liberar Memoria"<<endl;
                cin>>c;
                switch(c){
                    case 0:
                        cout<<"Saindo..."<<endl;
                        break;
                    case 1:
                        cout<<"Disco"<<endl;
                        for(int i=0; i<contadorDisco; i++){
                            ExibirDisco(&disco[i]);
                        }
                        contarVezes3 += 1;
                        cout<<"Quantas vezes esse processo rodou: "<<contarVezes3<<endl;
                        break;
                    case 2:
                        cout<<"Processos"<<endl;
                        for(int i=0; i<contadorDisco; i++){
                            ExibirProcessos(&processos[i]);
                        }
                        contarVezes4 += 1;
                        cout<<"Quantas vezes esse processo rodou: "<<contarVezes4<<endl;
                        break;
                    case 3:
                        cout<<"Liberar memoria"<<endl;
                        RetornarValorMemoriaParaDisco(m, disco);
                        contarVezes5 += 1;
                        cout<<"Quantas vezes esse processo rodou: "<<contarVezes5<<endl;
                        break;
                    default:
                        cout<<"Digite um opção válida"<<endl;
                        break;
                }

                break;
            case 5:
                cout<<"Exibir Memoria"<<endl;
                    memoria(m);
                contarVezes6 += 1;
                cout<<"Quantas vezes esse processo rodou: "<<contarVezes6<<endl;
                break;
            case 6:
                cout<<"Manutencao"<<endl;
                cout<<endl;
                cout<<endl;
                cout<<"Matutencao-Processos"<<endl;
                manutencaoProcessos(processos, disco, m);
                cout<<endl;
                cout<<endl;
                contarVezes7 += 1;
                cout<<"Quantas vezes esse processo rodou: "<<contarVezes7<<endl;
                //cout<<"Manutencao-Disco"<<endl;
                //BuscarNoDisco(disco);
            default:
                cout<<"Escolha uma opção válida"<<endl;
                break;
        }
    }while(a != 0);

    cout<<"Contagem de acessos"<<endl;
    cout<<endl;
    cout<<"Carregador de Processos tokenizados"<<endl;
    cout<<contarVezes1<<endl;
    cout<<endl;
    cout<<"Carregador de Disco tokenizado"<<endl;
    cout<<contarVezes2<<endl;
    cout<<endl;
    cout<<"Carregar Disco - Matriz"<<endl;
    cout<<contarVezes3<<endl;
    cout<<endl;
    cout<<"Carregar Processos - Matriz"<<endl;
    cout<<contarVezes4<<endl;
    cout<<endl;
    cout<<"Limpar memoria"<<endl;
    cout<<contarVezes5<<endl;
    cout<<endl;
    cout<<"Exibir Memoria"<<endl;
    cout<<contarVezes6<<endl;
    cout<<endl;
    cout<<"Manutencao"<<endl;
    cout<<contarVezes7<<endl;
    cout<<endl;

    cout<<"fim"<<endl;
    return 0;
}

int arquivoDisco(char *arquivoDisco, Disco *disco){

    FILE *arq;
	char linha[MAX];
	char *result;
	int t[100];
	int contador;
	int ContadorDisco=0;

	arq = fopen(arquivoDisco, "rt");

	if(arq == NULL) {
		printf("Erro ao abrir arquivo: \n");
		//return;
	}
	int cont=0;
	while(!feof(arq)) {
		result = fgets(linha,MAX, arq);

        if(result){
            contador=tokenizar(result, t);
            FLvaziaDisco(&disco[ContadorDisco]);
            matrizDisco(t, &disco[ContadorDisco], contador);
            ExibirDisco(&disco[ContadorDisco]);
            //ExibirProcessos(&d[ContadorDisco]);
            ContadorDisco += 1;
        }
	}
	return ContadorDisco;
}


int arquivoProcessos(char *arquivoProcessos, Disco *processos){

    FILE *arq;
	char linha[MAX];
	char *result;
	int t[100];
	int contador;
	int ContadorDisco=0;

	arq = fopen(arquivoProcessos, "rt");

	if(arq == NULL) {
		printf("Erro ao abrir arquivo: \n");
		//return;
	}
	int cont=0;
	while(!feof(arq)) {
		result = fgets(linha,MAX, arq);

        if(result){
            contador=tokenizar(result, t);
            FLvaziaProcesso(&processos[ContadorDisco]);
            matrizProcessos(t, &processos[ContadorDisco], contador);
            //ExibirDisco(&d[ContadorDisco]);
            ExibirProcessos(&processos[ContadorDisco]);
            ContadorDisco += 1;
        }
	}
	return ContadorDisco;
}


int tokenizar(char *str, int *t) {

	const char sep[] = "<> , ' ', A P";
	char *tokens;
	int cont=0;

	tokens = strtok(str, sep);

	while(tokens != NULL) {
		//cout << tokens << " " ;
		tokens = strtok(NULL, sep);
		t[cont] = atoi(tokens);
		cont += 1;
	}
	return cont-1;
}


void matrizDisco(int *t, Disco *disco, int contador){
    for(int i=0; i<contador; i++){
       InsereDisco(t[i], disco);
       //cout << t[i] << " ";
    }
    //cout << endl;
}

void InsereMemoria(Memoria *memory, Processos P ){
    if(memory->ultimo % N + 1 == memory->primeiro){
        cout << "Lista cheia" << endl;
    }
    else {
        memory -> vetor[memory -> ultimo] = P;
        memory -> ultimo = memory ->ultimo % N + 1;
    }
}

void matrizProcessos(int *t, Disco *processos, int contador){
    for(int i=0; i<contador; i++){
       InsereProcessos(t[i], processos);
       //cout << t[i] << " ";
    }
    //cout << endl;
}

void FLvaziaDisco(Disco *disco){
    disco -> primeiro=1;
    disco -> ultimo=1;
}
void FLvaziaProcesso(Disco *processos){
    processos -> primeiro=1;
    processos -> ultimo=1;
}
void FLvaziaMemoria(Memoria *memory){
    memory -> primeiro=1;
    memory -> ultimo=1;
}


void InsereDisco(int dado,  Disco *disco ){
    //cout << dado << " " ;
    if(disco->ultimo % N + 1 == disco->primeiro){
        cout << "Lista cheia" << endl;
    }
    else {
        disco -> vetor[disco -> ultimo]=dado;
        disco -> ultimo = disco->ultimo % N + 1;
    }
}
void InsereProcessos(int dado,  Disco *processos ){
    //cout << dado << " " ;
    if(processos->ultimo % N + 1 == processos->primeiro){
        cout << "Lista cheia" << endl;
    }
    else {
        processos -> vetor[processos -> ultimo]=dado;
        processos -> ultimo = processos -> ultimo % N + 1;
    }
}

void RetiraDisco(int *dado, int p, Disco *disco){
    int aux;
    if((disco -> primeiro == disco -> ultimo)||p >= disco -> ultimo){
        cout << "[Erro]: Posição não existente" <<endl;
        return;
    }
    *dado = disco -> vetor[p];
    disco->ultimo--;
    for(aux = p; aux < disco -> ultimo; aux++){
        disco -> vetor[aux] = disco -> vetor[aux+1];
    }
}
void RetiraProcessos(int *dado, int p, Disco *processos){
    int aux;
    if((processos->primeiro==processos->ultimo)||p>=processos->ultimo){
        cout << "[Erro]: Posição não existente" <<endl;
        return;
    }
    *dado = processos -> vetor[p];
    processos->ultimo--;
    for(aux = p; aux < processos -> ultimo; aux++){
        processos -> vetor[aux] = processos -> vetor[aux+1];
    }
}

void ExibirDisco(Disco *disco){
    for(int i=disco->primeiro; i<disco->ultimo; i++){
        cout<< disco -> vetor[i] << " " ;
    }
    cout << endl;
}

void ExibirProcessos(Disco *processos){
    for(int i=processos->primeiro/*+1*/; i<processos->ultimo-1; i++/*i+=2*/){
        cout<< processos -> vetor[i] << " " ;
    }
    cout << endl;
}

void manutencaoProcessos(Disco *processos, Disco *disco, Memoria *memory){
    int index, page;
    int aux;
    Processos p;
    for(int i=0; i<4; i++){

        for(int j=processos[i].primeiro; j<processos[i].ultimo-1; j+=2){
            index=processos[i].vetor[j];
            page=processos[i].vetor[j+1];
            for(int i=0; i<4; i++){
                if(index == i+1){
                    aux=BuscarNaMemoria(memory,page,index);
                    if(aux == -1){
                        aux=BuscarNoDisco(&disco[i],page);
                    }
                    p.page=page;
                    p.index=index;
                    p.valor=(-1);
                    if(aux != -1){
                        cout<<aux;
                        p.valor = aux;
                    }
                    InsereMemoria(&memory[i], p);
                }
            }
        }
        cout<<endl;
    }
}

int BuscarNoDisco(Disco *disco, int page){
    int aux;
    for(int j=disco->primeiro; j<disco->ultimo; j++){
        if(page == j){
            aux = disco->vetor[j];
            disco->vetor[j] = -1;
            return aux;
        }
    }
    return -1;
}

int BuscarNaMemoria(Memoria *memory,int page,int index){
    int aux;

    for(int i=0; i<4; i++){
        for(int j=memory[i].primeiro; j<memory[i].ultimo; j++){
            //cout << "j: " << j << endl;
            if(memory[i].vetor[j].index==index){
                    //cout << "index: " << memory[i].vetor[j].index << endl;
                if(memory[i].vetor[j].page==page){
                    aux = memory[i].vetor[j].valor;
                    memory[i].vetor[j].valor = -1;
                    return aux;
                }
            }
        }
    }
    return -1;
}


void memoria(Memoria *memory){ //recebe o arquivo de processos
    for(int i=0; i<4; i++){
        for(int j=memory[i].primeiro; j<memory[i].ultimo; j++){
            cout<<memory[i].vetor[j].index<< "-";
            cout<<memory[i].vetor[j].page<< "-" ;
            cout<<memory[i].vetor[j].valor;
            cout<<endl;
        }
    }
}

void retornaDisco(Disco *disco, int page, int valor){
    for(int i=disco->primeiro; i<disco->ultimo; i++){
        if(page == i){
            disco->vetor[i]=valor;

        }
    }
}

void RetornarValorMemoriaParaDisco(Memoria *memory, Disco *disco){ //recebe o arquivo de processos
    for(int i=0; i<4; i++){
        for(int j=memory[i].primeiro; j<memory[i].ultimo; j++){
            for(int k=0; k<4; k++){
                if( memory[i].vetor[j].index == k+1 ){
                    if(memory[i].vetor[j].valor != -1){
                        retornaDisco(&disco[k], memory[i].vetor[j].page, memory[i].vetor[j].valor);
                    }
                }
            }
        }
    }
}


