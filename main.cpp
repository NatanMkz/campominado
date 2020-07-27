#include <iostream>
#include <time.h>
#include <windows.h>

using namespace std;

#define L 5 ///numero de linhas
#define C 5 ///numero de colunas
#define BOMBAS 5 ///numero de bombas

int main()
{

    int mapa[L][C];  ///variavel do mapa
    int bl, bc;  ///variaveis das cordenadas das bombas
    int acertos=0, run=1;  ///variavel que diz que o jogo está rodando

    cout<<"Bem vindos ao jogo";
    cout<<"\n\nCodigo desenvolvido por: \n\tRogerio F. Borges Jr. \n\tNatan Nilo Martins \n\tVinicius Henrique S. Guapiano\n";
    Sleep(7000);
    system("cls");

    srand(time(NULL));

    ///GERAÇÃO DO MAPA
    for(int linha=0;linha<L;linha++){
        for(int coluna=0;coluna<C;coluna++){
            mapa[linha][coluna]=0;
        }
    }

    ///GERAÇÃO BOMBAS
    int erro;
    for(int i=1;i<=BOMBAS;i++){
        do{
            erro=0;
            bl=rand()%L;
            bc=rand()%C;
            if(mapa[bl][bc]==9){
                erro=1;
            }else{
                mapa[bl][bc]=9;
            }
        }while(erro==1);

    }

    ///INICIO DO MAIN
    do{
        system("cls");
        ///IMPRESSÃO DO MAPA
        for(int linha=0;linha<L;linha++){
            if(linha==0){
                cout<<" ";
                for(int i=0;i<C;i++){
                    cout<<i;
                }
                cout<<"\n";
            }
                cout<<char(65+linha);
            for(int coluna=0; coluna<C; coluna++){
                if(mapa[linha][coluna]==0 or mapa[linha][coluna]==9){
                    cout<<" ";
                }else if(mapa[linha][coluna]==10){
                    cout<<"-";
                }else{
                    cout<<mapa[linha][coluna];
                }
            }
            cout<<"\n";
        }
        ///INTERAÇÃO COM USUÁRIO
        char eu;
        int ex, ey;
        do{
            cout<<"Insira a linha: ";
            cin>>eu;
            ex=toupper(eu)-65;
        }while(ex<0 or ex>L-1);
        do{
            cout<<"Insira a coluna: ";
            cin>>ey;
        }while(ey<0 or ey>C-1);
        if(mapa[ex][ey]==9){
            run=0;
        }else{
            ///GERAÇÃO DOS NUMEROS EM VOLTA DAS BOMBAS
            for(int linha=5;linha>2;linha--){
                for(int coluna=5;coluna>2;coluna--){
                    if(ex+(linha-4)<0 or ex+(linha-4)>L-1){
                    }else if(ey+(coluna-4)<0 or ey+(coluna-4)>C-1){
                    }else if(mapa[ex+(linha-4)][ey+(coluna-4)]==9){
                        mapa[ex][ey]++;
                    }else{}
                }
            }
            acertos++;
        }
        if(mapa[ex][ey]==0){
            mapa[ex][ey]=10;
        }
        if(acertos==L*C-BOMBAS){
            run=0;
        }
    }while(run==1);
    system("cls");
    for(int linha=0;linha<L;linha++){
        for(int coluna=0;coluna<C;coluna++){
            if(mapa[linha][coluna]!=9)
                mapa[linha][coluna]=0;

        }
    }
    for(int linha=0;linha<L;linha++){
        if(linha==0){
            cout<<" ";
            for(int i=0;i<C;i++){
                cout<<i;
            }
            cout<<"\n";
        }
            cout<<char(65+linha);
        for(int coluna=0; coluna<C; coluna++){
            for(int x=5;x>2;x--){
                for(int y=5;y>2;y--){
                    if(linha+(x-4)<0 or linha+(x-4)>L-1){
                    }else if(coluna+(y-4)<0 or coluna+(y-4)>C-1){
                    }else if(mapa[linha+(x-4)][coluna+(y-4)]==9 and mapa[linha][coluna]!=9){
                        mapa[linha][coluna]++;
                    }else{}
                }
            }
            if(mapa[linha][coluna]==0){
                cout<<"-";
            }else if(mapa[linha][coluna]==9){
                cout<<"*";
            }else{
                cout<<mapa[linha][coluna];
            }
        }
        cout<<"\n";
    }
    if(acertos==L*C-BOMBAS){
        cout<<"\tParabens, voce ganhou o jogo!\n\tNUMERO DE ACERTOS: "<<acertos;
    }else{
        cout<<"\tQue pena, voce perdeu o jogo...\n\tNUMERO DE ACERTOS: "<<acertos;
    }


    return 0;
}
