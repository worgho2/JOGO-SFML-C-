#pragma once
#include "Menu.h"
#include <iostream>
#include <fstream>
using namespace std;
//using namespace ios;
class MenuPrincipal :
	public Menu
{
public:
	MenuPrincipal();
	virtual ~MenuPrincipal();
	void executarMenu(RenderWindow & window, View & view, int & escolha, bool & fase2);

	bool carregaJogo(vector<Jogador*>& lista_players);
};

