#include "Floresta_Noite.h"



Floresta_Noite::Floresta_Noite()
{
	chefeSpawnado = false;
}


Floresta_Noite::~Floresta_Noite()
{
	esvaziaVectors();
}

void Floresta_Noite::spawnCenario()
{
	esvaziaVectors();
	srand(time(NULL));
	Texture *passaro = new Texture;
	Texture *lobo = new Texture;
	Texture *ground = new Texture;
	Texture *plataforma = new Texture;
	Texture *background = new Texture;
	Texture *oca = new Texture;
	Texture *chefao = new Texture;


	passaro->loadFromFile("imagens\\passaro.png");
	lobo->loadFromFile("imagens\\lobo.png");
	chefao->loadFromFile("imagens\\chefao.png");
	ground->loadFromFile("imagens\\ground_noite.png");
	plataforma->loadFromFile("imagens\\plataforma_noite.png");
	background->loadFromFile("imagens\\fundo_noite.png");
	oca->loadFromFile("imagens\\oca_noite.png");

	if (rand() % 2)
	{
		lista_inimigos.push_back(new Inimigo(passaro, Vector2u(4, 1), 0.3f, 110.0f, 100.0f, Vector2f(40.0f, 50.0f), Vector2f(-512.0f, 230.f), 100.0f));
		lista_inimigos.push_back(new Inimigo(lobo, Vector2u(3, 1), 0.3f, 110.0f, 100.0f, Vector2f(40.0f, 50.0f), Vector2f(238.0f, 230.f), 100.0f));
		lista_inimigos.push_back(new Inimigo(passaro, Vector2u(4, 1), 0.3f, 110.0f, 100.0f, Vector2f(40.0f, 50.0f), Vector2f(988.0f, 230.f), 100.0f));
	}
	else if (rand() % 3)
	{
		lista_inimigos.push_back(new Inimigo(lobo, Vector2u(3, 1), 0.3f, 110.0f, 100.0f, Vector2f(40.0f, 50.0f), Vector2f(238.0f, 230.f), 100.0f));
		lista_inimigos.push_back(new Inimigo(passaro, Vector2u(4, 1), 0.3f, 110.0f, 100.0f, Vector2f(40.0f, 50.0f), Vector2f(988.0f, 230.f), 100.0f));
		lista_obstaculos.push_back((Obstaculos*) new Fogo(Vector2f(-512, 235.0f)));

	}
	else if (rand() % 5)
	{
		lista_inimigos.push_back(new Inimigo(lobo, Vector2u(3, 1), 0.3f, 110.0f, 100.0f, Vector2f(40.0f, 50.0f), Vector2f(-512.0f, 230.f), 100.0f));
		lista_inimigos.push_back(new Inimigo(passaro, Vector2u(4, 1), 0.3f, 110.0f, 100.0f, Vector2f(40.0f, 50.0f), Vector2f(238.0f, 230.f), 100.0f));
		lista_obstaculos.push_back((Obstaculos*) new Fogo(Vector2f(988, 235.0f)));
	}
	else
	{
		lista_inimigos.push_back(new Inimigo(lobo, Vector2u(3, 1), 0.3f, 110.0f, 100.0f, Vector2f(40.0f, 50.0f), Vector2f(238.0f, 230.f), 100.0f));
		lista_obstaculos.push_back((Obstaculos*) new Fogo(Vector2f(988, 245.0f)));
		lista_obstaculos.push_back((Obstaculos*) new Fogo(Vector2f(-512, 235.0f)));
	}

	//Carrega a lista de inimigos
	lista_inimigos.push_back(new Inimigo(lobo, Vector2u(3, 1), 0.3f, 75.0f, 100.0f, Vector2f(40.0f, 50.0f), Vector2f(-800.0f, 311.0f), 100.0f));
	lista_inimigos.push_back(new Inimigo(passaro, Vector2u(4, 1), 0.3f, 50.0f, 100.0f, Vector2f(40.0f, 50.0f), Vector2f(-300.0f, 313.0f), 50.0f));
	lista_inimigos.push_back(new Inimigo(lobo, Vector2u(3, 1), 0.3f, 75.0f, 100.0f, Vector2f(40.0f, 50.0f), Vector2f(-100.0f, 311.0f), 100.0f));
	lista_inimigos.push_back(new Inimigo(passaro, Vector2u(4, 1), 0.3f, 50.0f, 100.0f, Vector2f(40.0f, 50.0f), Vector2f(450.0f, 313.0f), 100.0f));
	lista_inimigos.push_back(new Inimigo(lobo, Vector2u(3, 1), 0.3f, 50.0f, 100.0f, Vector2f(40.0f, 50.0f), Vector2f(700.0f, 311.0f), 100.0f));
	lista_inimigos.push_back(new Inimigo(passaro, Vector2u(4, 1), 0.3f, 50.0f, 100.0f, Vector2f(40.0f, 50.0f), Vector2f(1200.0f, 313.0f), 100.0f));
	
	//Carrega lista de plataformas
	lista_plataformas.push_back(new Plataforma(plataforma, Vector2f(300.0f, 35.0f), Vector2f(-550.0f, 270.0f), true));
	lista_plataformas.push_back(new Plataforma(plataforma, Vector2f(300.0f, 35.0f), Vector2f(200.0f, 270.0f), true));
	lista_plataformas.push_back(new Plataforma(plataforma, Vector2f(300.0f, 35.0f), Vector2f(950.0f, 270.0f), true));
	lista_plataformas.push_back(new Plataforma(nullptr, Vector2f(3.0f, 1000.0f), Vector2f(-1340.0f, 500.0f), false));
	lista_plataformas.push_back(new Plataforma(nullptr, Vector2f(3.0f, 1000.0f), Vector2f(1723.0f, 500.0f), false));
	lista_plataformas.push_back(new Plataforma(nullptr, Vector2f(90.0f, 3.0f), Vector2f(-1145.0f, 330.0f), false));
	lista_plataformas.push_back(new Plataforma(nullptr, Vector2f(2850.0f, 3.0f), Vector2f(400.0f, 336.0f), false));

	//Carrega lista de obstaculos
	lista_obstaculos.push_back((Obstaculos*) new Espinhos(Vector2f(-550.0f, 312.0f)));
	lista_obstaculos.push_back((Obstaculos*) new Espinhos(Vector2f(200.0f, 312.0f)));
	lista_obstaculos.push_back((Obstaculos*) new Espinhos(Vector2f(950.0f, 312.0f)));
	lista_obstaculos.push_back((Obstaculos*) new Fogo(Vector2f(-960.0f, 312.0f)));
	lista_obstaculos.push_back((Obstaculos*) new Fogo(Vector2f(-225.0f, 312.0f)));

	//Carrega lista de cenário
	lista_cenario.push_back(new Cenario(background, Vector2f(3064.0f, 408.0f), Vector2f(200.0f, 205.5f), true));
	lista_cenario.push_back(new Cenario(oca, Vector2f(236.0f, 189.0f), Vector2f(1528.0f, 251.0f), true));
	
	chefeSpawnado = false;
	chefe = new Chefao(chefao, Vector2u(4, 1), 0.27f, 60.0f, 0.0f, Vector2f(60.0f, 70.0f), Vector2f(100.0f, 3001.0f), 100.0f);


	
}

bool Floresta_Noite::checaChefao(vector<Jogador*> lista_players, RenderWindow & window, bool & colidiu, const float deltaTime)
{
	Vector2f direction;
	for (int k = 0; k < lista_players.size() && lista_players[k]; k++)
	{
		colidiu = false;
		if (lista_players[k]->get_posicao().x < 0 && !chefeSpawnado)
		{
			chefe->set_posicao(Vector2f(100.0f, 301.0f));
			chefeSpawnado = true;
		}
		else if (chefeSpawnado)
		{
			cout << chefe->get_posicao().x << " | " << chefe->get_posicao().y << endl;
			if (lista_players.size() == 2)
			{
				if (lista_players[0]->get_posicao().x < lista_players[1]->get_posicao().x)
					chefe->mover(deltaTime, lista_players[0]->get_posicao().x);
				else
					chefe->mover(deltaTime, lista_players[1]->get_posicao().x);
			}
			else
				chefe->mover(deltaTime, lista_players[k]->get_posicao().x);

			if (chefe->get_colisor().checaColisao(lista_players[k]->get_colisor(), direction, 1.0f))
			{
				colidiu = true;
			}
		}
	}

	if (chefe != nullptr)
	{
		if (chefe->get_posicao().y > 500 && chefe->get_posicao().y < 1000)
			return true;
		else
			return false;
	}
	return false;


}
