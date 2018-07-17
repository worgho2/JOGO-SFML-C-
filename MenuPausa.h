#pragma once
#include "Menu.h"
#include "Jogador.h"
#include <list>
#include <fstream>
class MenuPausa :
	public Menu
{
public:
	MenuPausa();
	virtual ~MenuPausa();
	void executarMenu(RenderWindow & window, vector<Jogador*> lista_players, int fase);
	void salvarJogo(vector<Jogador*> lista_players, int fase);
	void set_origem(Vector2f origem) { menu.setOrigin(origem); }
	void set_posicao(Vector2f posicao) { menu.setPosition(posicao); }
};

