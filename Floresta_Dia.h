#pragma once
#include "Tronco.h"

#include "Fase.h"

class Floresta_Dia :
	public Fase
{
public:
	Floresta_Dia();
	virtual ~Floresta_Dia();
	bool checaChefao(vector <Jogador*> lista_players, RenderWindow & window, bool & colidiu, const float deltaTime) { return false; }
	void spawnCenario();
	void desenhaInimigoTela(RenderWindow & window) {}
};

