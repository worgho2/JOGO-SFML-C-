#include "SFML/Graphics.hpp"
#include"Plataforma.h"
#include "Jogador.h"
#include "Inimigo.h"
#include "Espinhos.h"
#include "Obstaculos.h"
#include "Cenario.h"
#include "MenuPausa.h"
#include "Ranking.h"
#include <vector>
using namespace std;
using namespace sf;
#pragma once
class Fase
{
protected:
	vector <Inimigo*> lista_inimigos;
	vector <Obstaculos*> lista_obstaculos;
	vector <Plataforma*> lista_plataformas;
	vector <Cenario*> lista_cenario;

public:
	Fase();
	virtual ~Fase();
	void arrumaCamera(vector<Jogador*> lista_players, View & view, vector<Plataforma*> lista_view);
	void esvaziaVectors();
	void desenhaNaTela(vector<Jogador*> lista_players, RenderWindow & window, const float deltaTime);
	//void checaColisaoComListaInimigos(vector<Jogador*> player, const float deltaTime);
	//void checaColisaoComListaObstaculos(vector<Jogador*> lista_players, const float deltaTime);

	bool executarFase(vector<Jogador*> lista_players, View & view, RenderWindow & window, MenuPausa & menu, const bool fase2, Ranking & rank);
	virtual void spawnCenario() = 0;
	virtual void desenhaInimigoTela(RenderWindow & window) = 0;
	virtual bool checaChefao(vector <Jogador*> lista_players, RenderWindow & window, bool & colidiu, const float deltaTime) = 0;
};

