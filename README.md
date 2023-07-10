# Caca_Palavras_C
O trabalho consiste em fazer um programa que contenha duas operações básicas, uma para
disponibilizar para o usuário uma matriz com as 18 letras, e outra ler e listar as palavras que o
usuário informa, mas verificando se as palavras são possíveis.

Operação 1 – GERAR A MATRIZ
A matriz deve ser gerada de forma aleatória, mas antes de ser mostrada ao usuário deve ser
verificado se atende às seguintes características (essas regras são nossas, não necessariamente
iguais às dos jogos disponíveis em revistas ou online):
- deve haver 7 ou 8 vogais na matriz;
- deve haver pelo menos 3 vogais diferentes dentre as geradas;
- deve haver pelo menos uma vogal em cada linha;
- nenhuma consoante pode aparecer mais de duas vezes;
- todas consoantes devem ter pelo menos uma vogal na adjacência (vizinhança), podendo ser
na vertical, horizontal ou diagonal.
- não pode haver mais de uma ocorrência da mesma letra na adjacência de uma posição, ou
seja, uma letra não pode ter outra como vizinha mais de uma vez.

Operação 2 – VALIDAR E LISTAR AS PALAVRAS INFORMADAS PELO USUÁRIO
Após a geração da matriz, o programa deve passar a solicitar ao usuário que informe as
palavras encontradas por ele. A cada palavra informada pelo usuário, deve ser verificado se a
palavra realmente é possível de ser formada na configuração da matriz. A palavra é válida se:
- uma dada posição da matriz (sua letra) só é usada uma vez;
- letras em seqüencia são vizinhas entre si, ou seja, não há “pulos” dentro da matriz;
O cruzamento, não permitido no passatempo, será aceito aqui por motivo de simplicidade.
Uma palavra validada deve ser incluída na lista de palavras corretas do usuário, e essa lista
deve ser mostrada para o usuário sempre que o programa se colocar no aguardo de outra
palavra. É importante ainda manter um contador do número de palavras corretas do usuário.
Pelo menos as operações de montagem da matriz e verificação de uma palavra (recebida como
parâmetro, retornando um valor que indica se ela é possível ou não na matriz) devem ser
feitas em funções específicas.
