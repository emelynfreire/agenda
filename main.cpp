#include <iostream>
#define MAX 150
#define TAM 5
#include <cstring>
#include <stdlib.h>//biblioteca para poder utilizar o comando pra limpar a tela
using namespace std;

struct Telefone{
    int DDD;
    char numero[11];

};

struct Contato{
    char nome[MAX];
    Telefone celular;

};

void buscaDados(char palavra[], Contato a[] ){
    int cont=0;

    for(int j=0;j<TAM;j++){
    //condicao de verificar se o nome pesquisado existe no vetor de nomes existentes
        if(strcmp(palavra,a[j].nome)==0){
        cont++;
        //se o tamanho do numero do celular for menor de 10
            if(strlen(a[j].celular.numero)<10){

            char aux[11];//vetor auxiliar para realocar o vetor e add o 9 na frente
            aux[0]='9';

            int k=0;
            int l=1;
                while(k<11){
                aux[l]= a[j].celular.numero[k];
                k++;
                l++;
                }
           //função para copiar o vetor auxiliar realocado na variavel inicialmente utilizada para manipulação
            strcpy(a[j].celular.numero,aux);

             cout << "Celular:" << a[j].celular.DDD << " " << a[j].celular.numero << endl;


            }else{

                cout << "Celular:" << a[j].celular.DDD << " " << a[j].celular.numero<< endl;

                cont++;
                }
        }
    }

    if(cont==0){
        cout << "--------------------------------------"<< endl;
        cout << "pessoa nao foi cadastrada" << endl;
    }
}

int main(){
    bool sair;

    Contato a[TAM];
    char palavra[MAX];
    int opcao;
    int i=0;


    do{

    cout << "------------------------------------------------"<< endl;
    cout << "------------------------------------------------"<< endl;
    cout << "-------------Bem-vindo a sua agenda---------"<< endl;
    cout << "------------------------------------------------"<< endl;
    cout <<"1. Cadastrar pessoa"<< endl;
    cout <<"2. Procurar pessoa" << endl;
    cout <<"3. Sair do programa" << endl;
    cout <<"4. Sobre o programa" << endl;
    cout << "------------------------------------------------"<< endl;
    cout << "-----Desenvolvido por Emelyn Freire-------------"<< endl;
    cout << "------------------------------------------------"<< endl;
    cout << "Digite o numero correspondente: ";
    cin >> opcao;
    cin.ignore();
    system("cls");

    switch(opcao){
        case 1:

            cout << "------------------------------------------------"<< endl;
            cout << "---------------CADASTRAR PESSOAS----------------"<< endl;
            cout << "------------------------------------------------"<< endl;
            cout << "------------------------------------------------"<< endl;

            while(i<TAM){
                cout << "NOME:"<<endl;
                cin.getline(a[i].nome,MAX);

                cout << "Celular com DDD:"<<endl;
                cin>>a[i].celular.DDD >> a[i].celular.numero;
                i++;
                cout << "------------------------------------------------"<< endl;
                cout << "Deseja continuar o cadastro?[s/n]" << endl;
                cout << "------------------------------------------------"<< endl;
                char resposta;
                cin>>resposta;
                cin.ignore();
                system("cls");
                if(resposta=='n' || resposta=='N'){
                 cout << "Cadastro encerrada com sucesso!!" << endl;
                    break;
                }
            }
            break;
        case 2:
            cout << "------------------------------------------------"<< endl;
            cout << "---------------PROCURAR PESSOA-----------------"<< endl;
            cout << "------------------------------------------------"<< endl;
            cout << "Para sair digite 'encerrar'---------------"<<endl;
            cout << "------------------------------------------------"<< endl;


            cout << "Digite o nome do contato que deseja localizar:" << endl;
            cin.getline(palavra,MAX);
            while(strcmp(palavra,"encerrar")!=0){

                buscaDados(palavra,a);
                cout << "------------------------------------------------"<< endl;
                cout << "Digite o nome do contato que deseja localizar:" << endl;
                cin.getline(palavra,MAX);
            }
            system("cls");
            cout << "Pesquisa encerrada com sucesso!!" << endl;

            break;
        case 3:
            break;
        case 4:
            cout << "------------------------------------------------"<< endl;
            cout << "---------------Sobre o programa----------------"<< endl;
            cout << "------------------------------------------------"<< endl;
            cout << "------------------------------------------------"<< endl;
            cout << "Desenvolvido por: Emelyn Freire"<< endl;
            cout << "Data: 22/11/2019"<<endl;
            cout << "Github: https://github.com/emelynfreire"<<endl;
            cout << endl;
            cout << "Digite 's' para sair" <<endl;
            char op;
            cin>>op;
            if(op=='s'||op=='S'){
                    break;
            }
            while(op!='s'||op!='S'){
                cin >>op;
                if(op=='s'||op=='S'){
                    break;
                }
            }
            break;
        default:
            cout << "opcao invalida!!"<< endl;
            break;

    }
    system("cls");
    cout << "------------------------------------------------"<< endl;
    cout << "---Deseja sair do programa?[1-sim/0-nao]--------" << endl;
    cout << "------------------------------------------------"<< endl;
    cin >> sair;
    system("cls");
    }while(sair==false);//se for 0=0 verdadeiro e vai rodar tudo de novo

    return 0;
}
