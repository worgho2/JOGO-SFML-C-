#include "Floresta_Dia.h"



Floresta_Dia::Floresta_Dia()
{

}


Floresta_Dia::~Floresta_Dia()
{
	esvaziaVectors();
}

void Floresta_Dia::spawnCenario()
{
	esvaziaVectors();
	srand(time(NULL));
	Texture *lobo = new Texture;
	Texture *macaco = new Texture;
	Texture *ground = new Texture;
	Texture *plataforma = new Texture;
	Texture *background = new Texture;
	Texture *canoa = new Texture;
	Texture *oca = new Texture;
	Texture *chefao = new Texture;

	lobo->loadFromFile("imagens\\lobo.png");
	macaco->loadFromFile("imagens\\macaco.png");
	chefao->loadFromFile("imagens\\fogo.png");
	ground->loadFromFile("imagens\\ground_dia.png");
	plataforma->loadFromFile("imagens\\plataforma_dia.png");
	background->loadFromFile("imagens\\fundo_dia.png");
	oca->loadFromFile("imagens\\oca_dia.png");
	
	//Carrega a lista de inimigos
	lista_inimigos.push_back(new Inimigo(macaco, Vector2u(3, 1), 0.3f, 50.0f, 100.0f, Vector2f(40.0f, 50.0f), Vector2f(-1100.0f, 313.0f), 50.0f));
	lista_inimigos.push_back(new Inimigo(lobo, Vector2u(3, 1), 0.3f, 75.0f, 100.0f, Vector2f(40.0f, 50.0f), Vector2f(-800.0f, 311.0f), 100.0f));
	lista_inimigos.push_back(new Inimigo(macaco, Vector2u(3, 1), 0.3f, 50.0f, 100.0f, Vector2f(40.0f, 50.0f), Vector2f(-300.0f, 313.0f), 50.0f));
	lista_inimigos.push_back(new Inimigo(lobo, Vector2u(3, 1), 0.3f, 75.0f, 100.0f, Vector2f(40.0f, 50.0f), Vector2f(-100.0f, 311.0f), 100.0f));
	lista_inimigos.push_back(new Inimigo(macaco, Vector2u(3, 1), 0.3f, 50.0f, 100.0f, Vector2f(40.0f, 50.0f), Vector2f(450.0f, 313.0f), 100.0f));
	lista_inimigos.push_back(new Inimigo(lobo, Vector2u(3, 1), 0.3f, 50.0f, 100.0f, Vector2f(40.0f, 50.0f), Vector2f(700.0f, 311.0f), 100.0f));
	lista_inimigos.push_back(new Inimigo(macaco, Vector2u(3, 1), 0.3f, 50.0f, 100.0f, Vector2f(40.0f, 50.0f), Vector2f(1200.0f, 313.0f), 100.0f));

	if (rand() % 2)
	{
		lista_inimigos.push_back(new Inimigo(macaco, Vector2u(3, 1), 0.3f, 110.0f, 100.0f, Vector2f(40.0f, 50.0f), Vector2f(-512.0f, 230.f), 100.0f));
		lista_inimigos.push_back(new Inimigo(lobo, Vector2u(3, 1), 0.3f, 110.0f, 100.0f, Vector2f(40.0f, 50.0f), Vector2f(238.0f, 230.f), 100.0f));
		lista_inimigos.push_back(new Inimigo(macaco, Vector2u(3, 1), 0.3f, 110.0f, 100.0f, Vector2f(40.0f, 50.0f), Vector2f(988.0f, 230.f), 100.0f));
	}
	else if (rand() % 3)
	{
		lista_inimigos.push_back(new Inimigo(lobo, Vector2u(3, 1), 0.3f, 110.0f, 100.0f, Vector2f(40.0f, 50.0f), Vector2f(238.0f, 230.f), 100.0f));
		lista_inimigos.push_back(new Inimigo(macaco, Vector2u(3, 1), 0.3f, 110.0f, 100.0f, Vector2f(40.0f, 50.0f), Vector2f(988.0f, 230.f), 100.0f));
		lista_obstaculos.push_back((Obstaculos*) new Tronco(Vector2f(-512, 245.0f)));
		
	}
	else if (rand() % 5)
	{
		lista_inimigos.push_back(new Inimigo(lobo, Vector2u(3, 1), 0.3f, 110.0f, 100.0f, Vector2f(40.0f, 50.0f), Vector2f(-512.0f, 230.f), 100.0f));
		lista_inimigos.push_back(new Inimigo(macaco, Vector2u(3, 1), 0.3f, 110.0f, 100.0f, Vector2f(40.0f, 50.0f), Vector2f(238.0f, 230.f), 100.0f));
		lista_obstaculos.push_back((Obstaculos*) new Tronco(Vector2f(988, 245.0f)));
	}
	else
	{
		lista_inimigos.push_back(new Inimigo(lobo, Vector2u(3, 1), 0.3f, 110.0f, 100.0f, Vector2f(40.0f, 50.0f), Vector2f(238.0f, 230.f), 100.0f));
		lista_obstaculos.push_back((Obstaculos*) new Tronco(Vector2f(988, 245.0f)));
		lista_obstaculos.push_back((Obstaculos*) new Tronco(Vector2f(-512, 245.0f)));
	}

	//Carrega lista de plataformas
	lista_plataformas.push_back(new Plataforma(nullptr, Vector2f(3064.0f, 88.0f), Vector2f(200.0f, 378.5f), false));
	lista_plataformas.push_back(new Plataforma(plataforma, Vector2f(300.0f, 35.0f), Vector2f(-550.0f, 270.0f), true));
	lista_plataformas.push_back(new Plataforma(plataforma, Vector2f(300.0f, 35.0f), Vector2f(200.0f, 270.0f), true));
	lista_plataformas.push_back(new Plataforma(plataforma, Vector2f(300.0f, 35.0f), Vector2f(950.0f, 270.0f), true));
	lista_plataformas.push_back(new Plataforma(nullptr, Vector2f(3.0f, 1000.0f), Vector2f(-1340.0f, 500.0f), false));
	lista_plataformas.push_back(new Plataforma(nullptr, Vector2f(3.0f, 1000.0f), Vector2f(1723.0f, 500.0f), false));

	//Carrega lista de obstaculos
	lista_obstaculos.push_back((Obstaculos*) new Espinhos(Vector2f(-550.0f, 312.0f)));
	lista_obstaculos.push_back((Obstaculos*) new Espinhos(Vector2f(200.0f, 312.0f)));
	lista_obstaculos.push_back((Obstaculos*) new Espinhos(Vector2f(950.0f, 312.0f)));
	lista_obstaculos.push_back((Obstaculos*) new Tronco(Vector2f(-960.0f, 325.0f)));
	lista_obstaculos.push_back((Obstaculos*) new Tronco(Vector2f(-225.0f, 325.0f)));

	//Carrega lista de cenário
	lista_cenario.push_back(new Cenario(background, Vector2f(3064.0f, 408.0f), Vector2f(200.0f, 205.5f), true));
	lista_cenario.push_back(new Cenario(oca, Vector2f(236.0f, 189.0f), Vector2f(1528.0f, 251.0f), true));
}
