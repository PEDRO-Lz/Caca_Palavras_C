#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void gerarmatriz(char mat[][3]){
	char vogais[5] = {'a', 'e', 'i', 'o', 'u',}, cons[21] = {'b', 'c', 'd', 'f', 'g', 'h', 'j', 'k', 'l', 'm', 'n', 'p', 'q', 'r', 's', 't', 'v', 'w', 'x', 'y', 'z'};
	char vog[8], vog3[3], l, letrasmat[18];
	int i, j, vogl, flagv, vl2=0, v3=0, n, vogrep=0, lm=0, consrep=0, ult, ultvog=1, cv=0;

		for(i=0; i<5; i++){
		if(vogrep==5)vogrep=0;
		n=rand()%(5-vogrep);
		vog[i]=vogais[n];
		if(i<3){
			vog3[v3]=vogais[n]; v3++;
		}
		if(n<4-vogrep){
			vogais[n]=vogais[4-vogrep];
		}
		vogrep++;
	}
	for(i=5,v3=0; v3<3; v3++, i++){
		vog[i]=vog3[v3];
	}
	for(i=0; i<6; i++){
		vogl=0; ult=ultvog;
		for(j=0; j<3; j++){
			flagv=0;

			if(vl2<2){
				if(ult==0){
					if(j==2 && !vogl){l=vog[cv]; flagv++;
					}
					else if(j==0){n=rand()%(21-consrep);
						l=cons[n];
					}
					else{flagv=rand()%2;
						if(flagv){l=vog[cv]; flagv++;
						}
						else{n=rand()%(21-consrep);
							l=cons[n];
						}
					}
				}
				else if(ult==1){
					if(j==2 && !vogl){l=vog[cv]; flagv++;
					}
					else if(vogl>1){n=rand()%(21-consrep);
						l=cons[n];
					}
					else{flagv=rand()%2;
						if(flagv){l=vog[cv]; flagv++;
						}
						else{n=rand()%(21-consrep);
							l=cons[n];
						}
					}
				}
				else if(ult==2){
					if(j==1 && !vogl){l=vog[cv]; flagv++;
					}
					else if(j==2){n=rand()%(21-consrep);
					l=cons[n];
					}
					else{flagv=rand()%2;
						if(flagv){l=vog[cv]; flagv++;
						}
						else{n=rand()%(21-consrep);
							l=cons[n];
						}
					}
				}
				if(i==5 && cv<7 && j>0){l=vog[cv]; flagv++;
				}
			}
			else{
				if(ult==0){
					if(j==2 && !vogl){l=vog[cv]; flagv++;
					}
					else if(j==0){n=rand()%(21-consrep);
						l=cons[n];
					}
					else{flagv=rand()%2;
						if(flagv){l=vog[cv]; flagv++;
						}
						else{n=rand()%(21-consrep);
							l=cons[n];
						}
					}
				}
				else if(ult==1){
					if(j==2 && !vogl){l=vog[cv]; flagv++;
					}
					else if(vogl){n=rand()%(21-consrep);
						l=cons[n];
					}
					else{flagv=rand()%2;
						if(flagv){l=vog[cv]; flagv++;
						}
						else{n=rand()%(21-consrep);
							l=cons[n];
						}
					}
				}
				else if(ult==2){
					if(j==1 && !vogl){l=vog[cv]; flagv++;
					}
					else if(j==2 || vogl){n=rand()%(21-consrep);
					l=cons[n];
					}
					else{flagv=rand()%2;
						if(flagv){l=vog[cv]; flagv++;
						}
					else{n=rand()%(21-consrep);
							l=cons[n];
						}
					}
				}
				if(i==5 && cv<7 && j>0){l=vog[cv]; flagv++;
				}
			}
			if(flagv){cv++; ultvog=j; vogl++;
			}
			else{
				if(n<20-consrep){

					cons[n]=cons[20-consrep];
				}
				consrep++;
			}
			if(vogl>1)vl2++;
			mat[i][j]=l; letrasmat[lm]=l; lm++;
		}
	}
}

int verificmat(char mat[][3]){
	int i, j, vog, matinvalid=0, l=0, quantvog=0, cons=0, vd=0, flagv=1, lsv=0, vogl=0, consrep=0, larep=0; 
	char consoantes[11], letras[19], vogais[5] = {'a', 'e', 'i', 'o', 'u'}, vogaismtz[9], vogaisdf[4];

	for(i=0; i<6; i++){	
		for(j=0; j<3; j++){
   			letras[l] = mat[i][j]; l++;
			for(vog=0; vog<5; vog++){
				if(vogais[vog] == mat[i][j]){vogaismtz[quantvog]=mat[i][j]; quantvog++; vogl++; flagv=1;
					if (vd == 0){ vogaisdf[vd] = mat[i][j]; vd++;}
					if (vd == 1 && mat[i][j] != vogaisdf[vd-1]){ vogaisdf[vd] = mat[i][j]; vd++;}
	    			if (vd == 2 && mat[i][j] != vogaisdf[vd-1] && mat[i][j] != vogais[vd-2]){ vogaisdf[vd] = mat[i][j]; vd++;}
				}
			}
			if(!flagv){consoantes[cons]=mat[i][j]; cons++;}
			flagv=0;
		}
		if(!vogl) lsv++;
		vogl=0;
	}
	letras[l] = '\0';
	vogaismtz[quantvog]='\0';
	vogaisdf[vd]='\0';
	consoantes[cons]='\0';
	
	printf("CONDICOES DA MATRIZ:");
	if (lsv){ printf("\nX Vogais em todas linhas  "); matinvalid++;}
	else printf("\nV Vogais em todas linhas  ");
	if (quantvog < 6 || quantvog > 8){ printf("\nX 7 ou 8 vogais "); matinvalid++;}
	else printf("\nV 7 ou 8 vogais ");
	printf(" || %d", quantvog);
	if (vd <= 2){ printf("\nX 3 vogais diferentes"); matinvalid++;}
	else printf("\nV 3 vogais diferentes");
	printf(" || %s", vogaisdf);
	if (consrep){ printf("\nX Maximo 2 repeticoes de consoantes"); matinvalid++;}
	else printf("\nV Maximo 2 repeticoes de consoantes");
	printf(" || %s", consoantes);
 	if(lsv){ printf("\nX Todas consoantes devem possuir vogais na adjacencia "); matinvalid++;}
	else printf("\nV Todas consoantes devem possuir vogais na adjacencia ");
	if (larep) printf("\nX Sem letras repetidas na adjacencia");
	else printf("\nV Sem letras repetidas na adjacencia");
	
	if(matinvalid)return 0;
	else return 1;
}

int palavras(char mat[][3], char palavra[19]){
	int i, j, ii, jj, p=0, t, achou=1, pa=0;

		for(t=0; palavra[t] != '\0'; t++);
			for(i=0; i<6; i++){
				for(j=0; j<3; j++){
					if(mat[i][j] == palavra[p]){ ii=i; jj=j; p++;
						while(achou){ achou = 1;

							if(ii>0){
								if(mat[ii-1][jj] == palavra[p]){p++; ii=ii-1; continue;}
								if(jj>0){ if(mat[ii-1][jj-1] == palavra[p]){p++; ii=ii-1; jj=jj-1; continue;}}
								if(jj<2){if(mat[ii-1][jj+1] == palavra[p]){p++; ii=ii+1; jj=jj-1; continue;}}
							}
							if(jj>0){if(mat[ii][jj-1] == palavra[p]){p++; jj=jj-1; continue;}}
							if(jj<2){if(mat[ii][jj+1] == palavra[p]){p++; jj=jj+1; continue;}}

							if(ii<2){
								if(mat[ii+1][jj] == palavra[p]){p++; ii=ii+1; continue;}
								if(jj>0){if(mat[ii+1][jj-1] == palavra[p]){p++; ii=ii+1; jj=jj-1; continue;}}
								if(jj<2){if(mat[ii+1][jj+1] == palavra[p]){p++; ii=ii+1; jj=jj+1; continue;}}
								}
						if(achou == 1) achou=0;
						}
					}
					if(p==t) pa++;
				}
			}
			printf("\nt= %d", t);
			printf("\np= %d", p);
			if(pa) return 1;
			else return 0;
			
}

int main(){
    int i, j, r, matV, pe=0, pt=0, x=1;
    char mat[6][3], palavra[19];
	srand((unsigned)time(NULL));

    gerarmatriz(mat);
    matV=verificmat(mat);
        
  	if(matV)printf("\nMatriz Valida");
	else printf("\nMatriz Invalida");
    
	for(i=0; i<6; i++){
        printf("\n");
        for(j=0; j<3; j++){
            printf("%3c", mat[i][j]);
        }
    }
    
    printf("\n** PARA SAIR DIGITE 0 EM QUALQUER MOMENTO **\n");
    printf("Qual palavra deseja procurar: ");
    
    while(x){
    	printf("\n");
		scanf("%s", palavra);
		
		if(palavra[0]=='0') x=0;
		else{
			r=palavras(mat,palavra); pt++;
			if(r){ printf("encontrada\n"); pe++; }
			else printf("NAO encontrada\n");
		}
		
	}
	printf("\n%d palavras procuradas.", pt);
	printf("\n%d palavras encontradas.", pe);
	
	return 0;
}
