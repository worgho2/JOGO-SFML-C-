#include "Fogo.h"
#include "Chefao.h"
#pragma once
#include "Fase.h"

class Floresta_Noite :
	public Fase
{
private:
	Chefao *chefe;
	bool chefeSpawnado;
public:
	Floresta_Noite();
	virtual ~Floresta_Noite();
	void spawnCenario();
	void desenhaInimigoTela(RenderWindow & window) { chefe->desenhar(window); }
	bool checaChefao(vector<Jogador*> lista_players, RenderWindow & window, bool & colidiu, const float deltaTime);

};

