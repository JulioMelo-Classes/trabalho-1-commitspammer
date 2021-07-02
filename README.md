# LP1 Trabalho 1 - Keno

Repositório do jogo Keno implementado em c++ para a disciplina de Linguagem de Programação 1.

Comentários das funções podem ser encontrados nos seus respectivos [headers](./include).

Informações dos autores podem ser encontrados em [autor.md](./autor.md).

## Compilando o jogo

Clone este repositório em sua máquina (caso já não o tenha feito), tenha 'make' instalado no sistema e faça:
```
$ make install
```

## Entrada do jogo

O programa requer um arquivo de aposta no seguinte formato:
```
1500.00
3
21 12 64
```
1. A primeira linha deve conter um decimal para o valor em dinheiro a ser apostado.
2. A segunda linha deve conter um inteiro positivo para o número de rodadas desejado.
3. A terceira linha deve conter uma lista de 1 a 15 inteiros para os números a serem apostados, que devem estar entre 1 e 80 e separados por espaços.

## Executando o jogo

Faça:
```
$ make run FILE=[FILE_PATH]
```
Ou então:
```
$ ./bin/main [FILE_PATH]
```
Onde [FILE_PATH] é o caminho do arquivo de aposta (sem colchetes).

## Executando testes

É possível testar vários arquivos de uma só vez, colocando-os dentro do diretório [data/](./data) e fazendo:
```
$ make test
```

## Limitações e funcionalidades não implementadas

O programa tentará ler arquivos que não estejam perfeitamente formatados, mas nem sempre os lerão com êxito. Em especial, sempre falhará caso hajam caracteres inválidos dentro do arquivo.

O programa lê o primeiro e apenas o primeiro arquivo passado como argumento. Para rodar várias apostas de uma vez, veja [Executando testes](##-executando-testes).

O programa não arrendodará frações de unidades de centavo.

O programa não ajustará sua interface para resoluções muito pequenas.
