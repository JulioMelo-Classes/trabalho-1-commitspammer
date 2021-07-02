#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include "../include/kenobet.h"
#include "../include/filehandler.h"
#include "../include/game.h"
#include "../include/payofftable.h"

using namespace std;

void read_file(char *arg)
{
	cout<<"-----------------------------------------------------------------------"<< endl;
	cout<<">>> Lendo arquivo de apostas [ "<<arg<<" ], por favor aguarde.."<< endl;

}

void file_error()
{
	cout<<">>> Arquivo inexistente ou inválido"<< endl;
	cout<<"-----------------------------------------------------------------------"<< endl<<endl;
}

void rules_file(char *arg, int rounds, KenoBet bet)
{
	cout<<">>> Aposta lida com sucesso"<< endl;

	cout<<"-----------------------------------------------------------------------"<< endl;

	cout<<"         _  _______ _   _  ___"<< endl;
	cout<<"        | |/ / ____| \\ | |/ _ \\"<< endl;
	cout<<"        | ' /|  _| |  \\| | | | |"<< endl;
	cout<<"        | . \\| |___| |\\  | |_| |"<< endl;
	cout<<"        |_|\\_\\_____|_| \\_|\\___/"<<endl<<endl;

	cout<<">>> O valor total apostado foi de $"<<bet.get_wage()<<" créditos"<<endl;
	cout<<"	Você escolheu jogar "<< rounds<<" rounds, apostando em cada um $"<<(bet.get_wage()/rounds)<<" créditos."<<endl<<endl;
	cout<<"	Sua aposta foi de 3 numeros: [";
	for (spot_t j : bet.get_spots()) cout<<j<<" ";
	cout<<"]"<<endl;

	cout<<" 	Com isso a relação Hits-Retorno vai ser:"<<endl;
	cout<<"			----------+-----------"<<endl;
	cout<<"			   Hits   |  Retorno  "<<endl;
	for(spot_t i=0; i<=bet.get_spots_size();i++)
	{
		cout<<"			    "<< i<<"     |    "<<PAYOFF_TABLE[bet.get_spots_size()][i]<<"       "<<endl;
	}
	cout<<"			----------+-----------"<<endl;
	cout<<"-----------------------------------------------------------------------"<< endl<<endl;
	cout<<">>> E Começoouu:"<< endl<<endl;
}

void game_run_interface(KenoBet bet, set_of_spot_t& Rnum, set_of_spot_t& hits, int n_hits, int rodada, int rounds, wage_t first_wage)
{
	cout<<">>> Esta é a rodadada "<< rodada<<" de "<<rounds<<". Sua aposta para essa rodada foi de $"<<(first_wage/rounds)<<". Boa sorte!!"<<endl;
	cout<<"	Os numeros sorteados são: [ ";
	for (spot_t j : Rnum) cout<<j<<" ";
	cout<<"]"<<endl<<endl;

	if(n_hits>0)
	{
		cout<<"	Na rodada "<<rodada<<": você acertou os numeros [ ";
	 	for (spot_t i : hits) cout<<i<<" ";
		cout<<"]. Sua taxa de retorno é "<<PAYOFF_TABLE[bet.get_spots_size()][n_hits] <<", por isso você ganhou $"<< (first_wage/rounds)*PAYOFF_TABLE[bet.get_spots_size()][n_hits]<<" créditos."<<endl;
	}
	else cout<<"	Infelizmente, na rodada "<<rodada<<", você não acertou nenhum numero. Sua taxa de retorno é "<<PAYOFF_TABLE[bet.get_spots_size()][n_hits] <<", por isso você ganhou $"<< (first_wage/rounds)*PAYOFF_TABLE[bet.get_spots_size()][n_hits]<<" créditos."<<endl;

	cout<<"	Seu saldo total é de $"<<bet.get_wage()<<" créditos"<<endl;
	cout<<"	-----------------------------------------------------------------------"<< endl<<endl;
}

void end_game(KenoBet bet, wage_t first_wage)
{
	cout<<">>> Fim de jogo!"<<endl;
	cout<<"-----------------------------------------------------------------------"<< endl<<endl;
	cout<<endl;

	cout<<"======= Seus ganhos ======="<<endl;
	cout<<">>> Você começou com  $"<<first_wage<<" créditos."<<endl;
	if(bet.get_wage()-first_wage>0)
	cout<<">>> BOOYAH! Você faturou "<<bet.get_wage()-first_wage<<" créditos!!!"<<endl;
	else cout<<">>> Não foi dessa vez que você faturou. Continue jogando"<<endl;
	cout<<">>> Você está saindo do jogo com um total de $"<<bet.get_wage()<<" créditos."<<endl;
}
