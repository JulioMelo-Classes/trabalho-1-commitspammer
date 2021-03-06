#include <iostream>
#include <vector>
#include "../include/filehandler.h"
#include "../include/game.h"
#include "../include/kenobet.h"
#include "../include/interface.h"

using namespace std;

/*
Avaliação
Processamento do Arquivo de Entrada: 1
Execução correta: 1
Interfcace Textual: 1
Documentação: 1
Compilação automatizada: 1
Organização em src, include, build, data: 1

Comentários
- Acho que ficou realmente muito boa a organização, o problema mesmo é a mistura de C e C++, como já falei na aula
o ideal é entrar de cabeça em c++ e esqueçer os char* double[], etc. Futuramente a gente pode até esquecer os raw
pointers e usar smart pointers que tem funcionalidades extra.
- Vi que vocês criaram a classe Game com implementações inline (dentro do .h), voces sabem que isso não é uma boa
prática e especialmente quando esse arquivo tem um cpp relacionado. Na proxima vcs podem tenter uniformizar isso melhor.
- Como vocês tem uma implementação mais avançada, eu posso falar um pouco sobre padrões de Indentação e Styling do código.
Por exemplo a classe RandEngine, está escrita desta na forma CamelCase, bem como seu construtor, mas os métodos estão no formato
snake_case. Usualmente escolhemos um dos dois ou uma mistura padronizada. Pessoalmente eu gosto do coding style do Webkit
(https://webkit.org/code-style-guidelines/), mas o melhor é ter um padrão que dê certo e faça sentido para vocês.
*/

int main(int argc, char *argv[])
{
	if(argc<2) 
	{
		file_error();
		return -1;
	}
	RandEngine engine(1, 80);

	KenoBet bet;
	int rounds = file_to_kenobet(argv[1], bet);
	wage_t first_wage = bet.get_wage();

	read_file(argv[1]);

	if(file_validate(argv[1])==false || rounds==-1) 
	{
		file_error();
		return -1;
	}
	
	rules_file(argv[1],rounds,bet);

	for (int i = 0; i < rounds; i++) //numero de rounds
	{
		set_of_spot_t Rnum(engine.get_unique_list(20));
		set_of_spot_t hits;
		sort(Rnum.begin(), Rnum.end());
		int n_hits = equal_bet(bet, Rnum, hits);
		bet_win(bet, n_hits, rounds, first_wage);

		game_run_interface( bet, Rnum, hits, n_hits, (i+1), rounds, first_wage);
		hits.clear();
		Rnum.clear();
	}

	end_game(bet,first_wage);
	return 0;
}
