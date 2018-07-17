#include "Fase.h"

Fase::Fase()
{

}

Fase::~Fase()
{
	esvaziaVectors();
}

void Fase::arrumaCamera(vector<Jogador*> lista_players, View & view, vector<Plataforma*> lista_view)
{
	int k = 0;
	float posicao;
	Vector2f direction;
	if (lista_players.size() == 1)
	{
		posicao = lista_players[0]->get_posicao().x;
		if (posicao < -1072.0f)
		{
			lista_view[0]->set_posicao(Vector2f(-1072.0f + 206.0f, 206.0f));
			lista_view[1]->set_posicao(Vector2f(-1072.0f - 306.0f, 206.0f));
			view.setCenter(Vector2f(-1072.0f, 206.0f));
			for (int j = 0; j < lista_players[0]->get_lista_coracoes().size(); j++)
			{
				lista_players[0]->get_lista_coracoes()[j]->set_posicao(Vector2f(-1280.0f + k, 100.0f));
				k += 22;
			}
		}
		else if (posicao > 1460.0f)
		{
			lista_view[0]->set_posicao(Vector2f(posicao + 206.0f, 206.0f));
			lista_view[1]->set_posicao(Vector2f(1460.0f - 206.0f, 206.0f));
			view.setCenter(Vector2f(1460.0f, 206.0f));
			for (int j = 0; j < lista_players[0]->get_lista_coracoes().size(); j++)
			{
				lista_players[0]->get_lista_coracoes()[j]->set_posicao(Vector2f(1252.0f + k, 100.0f));
				k += 22;
			}

		}
		else
		{
			lista_view[0]->set_posicao(Vector2f(posicao + 206.0f, 206.0f));
			lista_view[1]->set_posicao(Vector2f(posicao - 206.0f, 206.0f));
			view.setCenter(Vector2f(posicao, 206.0f));
			for (int j = 0; j < lista_players[0]->get_lista_coracoes().size(); j++)
			{
				lista_players[0]->get_lista_coracoes()[j]->set_posicao(Vector2f(lista_players[0]->get_posicao().x - 208.7f + k, 100.0f));
				k += 22;
			}
		}
	}
	else
	{
		posicao = (lista_players[0]->get_posicao().x + lista_players[1]->get_posicao().x) / 2;
		if (posicao < -1072.0f)
		{
			view.setCenter(Vector2f(-1072.0f, 206.0f));
			lista_view[0]->set_posicao(Vector2f(-1072.0f + 206.0f, 206.0f));
			lista_view[1]->set_posicao(Vector2f(-1072.0f - 306.0f, 206.0f));
			for (int j = 0; j < lista_players[0]->get_lista_coracoes().size(); j++)
			{
				lista_players[0]->get_lista_coracoes()[j]->set_posicao(Vector2f(-1280.0f + k, 100.0f));
				k += 22;
			}
			k = 0;
			for (int j = 0; j < lista_players[1]->get_lista_coracoes().size(); j++)
			{
				lista_players[1]->get_lista_coracoes()[j]->set_posicao(Vector2f(-1280.0f + k, 130.0f));
				k += 22;
			}
		}
		else if (posicao > 1460.0f)
		{
			lista_view[0]->set_posicao(Vector2f(posicao + 206.0f, 206.0f));
			lista_view[1]->set_posicao(Vector2f(1460.0f - 206.0f, 206.0f));
			view.setCenter(Vector2f(1460.0f, 206.0f));
			for (int j = 0; j < lista_players[0]->get_lista_coracoes().size(); j++)
			{
				lista_players[0]->get_lista_coracoes()[j]->set_posicao(Vector2f(1252.0f + k, 100.0f));
				k += 22;
			}
			k = 0;
			for (int j = 0; j < lista_players[1]->get_lista_coracoes().size(); j++)
			{
				lista_players[1]->get_lista_coracoes()[j]->set_posicao(Vector2f(1252.0f + k, 130.0f));
				k += 22;
			}

		}
		else
		{
			lista_view[0]->set_posicao(Vector2f(posicao + 206.0f, 206.0f));
			lista_view[1]->set_posicao(Vector2f(posicao - 206.0f, 206.0f));
			view.setCenter(Vector2f(posicao, 206.0f));
			for (int j = 0; j < lista_players[0]->get_lista_coracoes().size(); j++)
			{
				lista_players[0]->get_lista_coracoes()[j]->set_posicao(Vector2f(lista_players[0]->get_posicao().x - 208.7f + k, 100.0f));
				k += 22;
			}
			k = 0;
			for (int j = 0; j < lista_players[1]->get_lista_coracoes().size(); j++)
			{
				lista_players[1]->get_lista_coracoes()[j]->set_posicao(Vector2f(lista_players[0]->get_posicao().x - 208.7f + k, 100.0f));
				k += 22;

			}

		}
	}
	for (int i = 0; i < lista_players.size(); i++)
		for (int j = 0; j < 2; j++)
			if (lista_view[j]->get_colisor().checaColisao(lista_players[i]->get_colisor(), direction, 1.0f))
				lista_players[i]->emColisao(direction); //Checa colisao do player com as plataformas da view

}
void Fase::esvaziaVectors()
{
	for(int i = 0; i<lista_cenario.size(); i ++)
	{
		delete lista_cenario[i];
		lista_cenario.erase(lista_cenario.begin());
	}
	for (int i = 0; i<lista_inimigos.size(); i++)
	{
		delete lista_inimigos[i];
		lista_inimigos.erase(lista_inimigos.begin());
	}
	for (int i = 0; i<lista_plataformas.size(); i++)
	{
		delete lista_plataformas[i];
		lista_plataformas.erase(lista_plataformas.begin());
	}
	for (int i = 0; i<lista_obstaculos.size(); i++)
	{
		delete lista_obstaculos[i];
		lista_obstaculos.erase(lista_obstaculos.begin());
	}

}
void Fase::desenhaNaTela(vector<Jogador*> lista_players, RenderWindow & window, const float deltaTime)
{
	for (int k = 0; k < lista_players.size(); k++)
	{
		
		for (int j = 0; j < lista_cenario.size(); j++)
			lista_cenario[j]->desenhar(window);

		for (int j = 0; j < lista_obstaculos.size(); j++)
		{
			lista_obstaculos[j]->Update(deltaTime);
			lista_obstaculos[j]->desenhar(window);
		}

		for (int j = 0; j < lista_plataformas.size(); j++)
			lista_plataformas[j]->desenhar(window);

		for (int j = 0; j < lista_inimigos.size(); j++)
		{
			lista_inimigos[j]->desenhar(window);
			lista_inimigos[j]->mover(deltaTime);
		}

		for (int k = 0; k < lista_players.size(); k++)
		{
			for (int l = 0; l < lista_players[k]->get_lista_coracoes().size(); l++)
				lista_players[k]->get_lista_coracoes()[l]->desenhar(window);
			lista_players[k]->desenhar(window);
		}
	}
	desenhaInimigoTela(window);
}
/*
void Fase::checaColisaoComListaInimigos(vector<Jogador*> lista_players, const float deltaTime)
{
	Vector2f direction;
	for (int k = 0; k < lista_players.size(); k++)
	{
		for (int j = 0; j < lista_inimigos.size() && lista_players[k]; j++)
		{
			if (lista_inimigos[j]->get_tomandoDanoInimigo() >= 1 && lista_players[k]->get_tomandoDanoInimigo() >= 1)
			{
				lista_players[k]->emDano((Personagem*)lista_players[k], (Personagem*)lista_inimigos[j], deltaTime);
			}
			else
			{
				if (lista_inimigos[j]->get_colisor().checaColisao(lista_players[k]->get_colisor(), direction, 1.0f))
				{
					if (lista_players[k]->get_vida() <= 0)
					{
						delete lista_players[k];
					}
					else
					{
						*lista_players[k]--;
						//lista_players[k]->diminui_vida();
						lista_players[k]->set_noChao(false);
						lista_players[k]->set_tomandoDanoInimigo(1);
						lista_inimigos[j]->set_tomandoDanoInimigo(1);
						break;
					}
				}
			}
		}
	}
}
void Fase::checaColisaoComListaObstaculos(vector<Jogador*> lista_players, const float deltaTime)
{
	Vector2f direction;
	for (int k = 0; k < lista_players.size(); k++)
	{
		for (int j = 0; j < lista_obstaculos.size() && lista_players[k]; j++)
		{
			if (lista_players[k]->get_tomandoDanoObstaculo() >= 1 && lista_obstaculos[j]->get_dandoDano() >= 1)
			{
				lista_players[k]->emDano((Personagem*)lista_players[k], deltaTime);
				lista_obstaculos[j]->set_dandoDano(lista_obstaculos[j]->get_dandoDano() + 1);
				if (lista_players[k]->get_tomandoDanoObstaculo() == 0)
					lista_obstaculos[j]->set_dandoDano(0);
			}
			else
			{
				if (lista_obstaculos[j]->get_colisor().checaColisao(lista_players[k]->get_colisor(), direction, 1.0f))
				{
					lista_players[k]->emColisao(direction);
					if (lista_obstaculos[j]->get_dano())
					{
						if (lista_players[k]->get_vida() <= 0)
							delete lista_players[k];
						else
						{
							*lista_players[k]--;
							//lista_players[k]->diminui_vida();
							lista_players[k]->set_noChao(false);
							lista_players[k]->set_tomandoDanoObstaculo(1);
							lista_obstaculos[j]->set_dandoDano(1);
							break;
						}
					}
				}
			}
		}
	}
}
*/


bool Fase::executarFase(vector<Jogador*> lista_players, View & view, RenderWindow & window, MenuPausa & menu, const bool fase2, Ranking & rank)
{
	vector<Plataforma*> plataformas_view;
	plataformas_view.push_back(new Plataforma(nullptr, Vector2f(3.0f, 1000.0f), Vector2f(-10000.0f, -10000.0f), false));
	plataformas_view.push_back(new Plataforma(nullptr, Vector2f(3.0f, 1000.0f), Vector2f(-10000.0f, -10000.0f), false));
	Plataforma fimDeFase(nullptr, Vector2f(34.0f, 38.0f), Vector2f(1528, 346), false);
	if (fase2)
	{
		fimDeFase.set_tamanho(Vector2f(700.0f, 3.0f));
		fimDeFase.set_posicao(Vector2f(-1145.0f, 500.0f));
	}

	float deltaTime = 0.0f;
	Clock clock;
	while (window.isOpen())
	{
		if (lista_players.size() == 0)
			return false;
		deltaTime = float(clock.restart().asSeconds());
		if (deltaTime > 1.0f / 20.0f)
			deltaTime = 1.0f / 20.0f;
		Event evnt;

		while (window.pollEvent(evnt))
		{
			switch (evnt.type)
			{
			case Event::Closed:
				window.close();
				break;
			}
		}
		if (Keyboard::isKeyPressed(Keyboard::P))
		{
			menu.set_origem(Vector2f(256, 200));
			menu.set_posicao(view.getCenter());
			menu.desenhar(window);
			window.display();
			if (fase2)
				menu.executarMenu(window, lista_players, 2);
			else
				menu.executarMenu(window, lista_players, 1);
		}
		Vector2f direction;
		bool colidiu = false;
		bool endgame = checaChefao(lista_players, window, colidiu, deltaTime);
//		checaColisaoComListaInimigos(lista_players, deltaTime);
//		checaColisaoComListaObstaculos(lista_players, deltaTime);
		for (int k = 0; k < lista_players.size(); k++)
		{

			if (!lista_players[k]->get_tomandoDanoInimigo() && !lista_players[k]->get_tomandoDanoObstaculo())
			{
				if (lista_players[k]->get_coop())
					lista_players[k]->Update(deltaTime, true);
				else
					lista_players[k]->Update(deltaTime, false);
			}

			//Checa Colisao com inimigos

			for (int j = 0; j < lista_inimigos.size() && lista_players[k]; j++)
			{
				if (lista_inimigos[j]->get_tomandoDanoInimigo() >= 1 && lista_players[k]->get_tomandoDanoInimigo() >= 1)
				{
					lista_players[k]->emDano((Personagem*)lista_players[k], (Personagem*)lista_inimigos[j], deltaTime);
				}
				else
				{
					if (lista_inimigos[j]->get_colisor().checaColisao(lista_players[k]->get_colisor(), direction, 1.0f))
					{
						if (lista_players[k]->get_vida() <= 0)
						{
							delete lista_players[k];
						}
						else
						{
							//*lista_players[k]--;
							lista_players[k]->diminui_vida();
							lista_players[k]->set_noChao(false);
							lista_players[k]->set_tomandoDanoInimigo(1);
							lista_inimigos[j]->set_tomandoDanoInimigo(1);
							break;
						}
					}
				}
			}

			//Checa colisao com obstaculos

			for (int j = 0; j < lista_obstaculos.size() && lista_players[k]; j++)
			{
				if (lista_players[k]->get_tomandoDanoObstaculo() >= 1 && lista_obstaculos[j]->get_dandoDano() >= 1)
				{
					lista_players[k]->emDano((Personagem*)lista_players[k], deltaTime);
					lista_obstaculos[j]->set_dandoDano(lista_obstaculos[j]->get_dandoDano() + 1);
					if (lista_players[k]->get_tomandoDanoObstaculo() == 0)
						lista_obstaculos[j]->set_dandoDano(0);
				}
				else
				{
					if (lista_obstaculos[j]->get_colisor().checaColisao(lista_players[k]->get_colisor(), direction, 1.0f))
					{
						lista_players[k]->emColisao(direction);
						if (lista_obstaculos[j]->get_dano())
						{
							if (lista_players[k]->get_vida() <= 0)
								delete lista_players[k];
							else
							{
								//*lista_players[k]--;
								lista_players[k]->diminui_vida();
								lista_players[k]->set_noChao(false);
								lista_players[k]->set_tomandoDanoObstaculo(1);
								lista_obstaculos[j]->set_dandoDano(1);
								break;
							}
						}
					}
				}
			}
		

			if (lista_players[k])
			{
				for (int j = 0; j < lista_plataformas.size(); j++)
					if (lista_plataformas[j]->get_colisor().checaColisao(lista_players[k]->get_colisor(), direction, 1.0f))
						lista_players[k]->emColisao(direction);
				if ((!fase2  && fimDeFase.get_colisor().checaColisao(lista_players[k]->get_colisor(), direction, 1.0f)) || endgame)
				{
					if (fase2)
					{
						lista_players[k]->set_pontos(abs(lista_players[k]->get_posicao().x), fase2);
						rank.rankear(lista_players[k]->get_pontos());
					}
					return true;
				}
				if (fase2 && fimDeFase.get_colisor().checaColisao(lista_players[k]->get_colisor(), direction, 1.0f))
				{
					lista_players[k]->set_pontos(lista_players[k]->get_posicao().x, fase2);
					rank.rankear(lista_players[k]->get_pontos());
					delete lista_players[k];
					lista_players.erase(lista_players.begin());
					if (lista_players.size() == 0)
					{
						return false;
					}
				}
				arrumaCamera(lista_players, view, plataformas_view);
				if (lista_players[k]->get_vida() == 0 || colidiu)
				{
					lista_players[k]->set_pontos(lista_players[k]->get_posicao().x, fase2);
					rank.rankear(lista_players[k]->get_pontos());
					delete lista_players[k];
					lista_players.erase(lista_players.begin());
				}
			}
		}
		if (lista_players.size() == 0)
			return false;
		window.setView(view);
		desenhaNaTela(lista_players, window, deltaTime);
		window.display();
	}
}