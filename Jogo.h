#include "SFML/Graphics.hpp"
#include "Floresta_Dia.h"
#include "Floresta_Noite.h"
#include "Jogador.h"
#include "MenuPausa.h"
#include "MenuPrincipal.h"
#include "Lista.h"
#include "Ranking.h"
#include <vector>
using namespace std;
using namespace sf;
#pragma once
class Jogo
{
private:
	vector <Jogador*> lista_jogadores;
	Floresta_Dia *dia;
	Floresta_Noite *noite;
	Ranking rank;
	MenuPrincipal menu_principal;
	MenuPausa menu_pausa;
	Lista <Fase*>lista_fases;

public:
	Jogo();
	virtual ~Jogo();
	void Executar();
};

