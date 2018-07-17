#include "Jogo.h"

Jogo::Jogo()
{
	Executar();
}

Jogo::~Jogo()
{
}

void Jogo::Executar()
{
	RenderWindow window(VideoMode(512, 512), "Um dia na floresta!!!!!", Style::Close);
	View view(Vector2f(0.0f, 0.0f), Vector2f(512, 408.0f));
	Texture* player1 = new Texture;
	Texture* player2 = new Texture;
	player1->loadFromFile("imagens\\player1.png");
	player2->loadFromFile("imagens\\player2.png");
	int escolha;
	bool fase2 = false;
	menu_principal.executarMenu(window, view, escolha, fase2);

	switch (escolha)
	{
	case 1:
		lista_jogadores.push_back(new Jogador(player1, Vector2u(3, 1), 0.25f, 150.0f, 100.0f, Vector2f(40.0f, 50.0f), Vector2f(-1250.0f, 341.0f), 20, true));
		break;
	case 2:
		lista_jogadores.push_back(new Jogador(player1, Vector2u(3, 1), 0.25f, 150.0f, 100.0f, Vector2f(40.0f, 50.0f), Vector2f(-1250.0f, 341.0f), 20, true));
		lista_jogadores.push_back(new Jogador(player2, Vector2u(3, 1), 0.3f, 150.0f, 100.0f, Vector2f(40.0f, 50.0f), Vector2f(-1300.0f, 341.0f), 20, false));
		break;
	case 3:
		rank.mostrarRank(window, view);
		break;
	case 4:
		fase2 = menu_principal.carregaJogo(lista_jogadores);
		break;
	case 5:
		exit;
	default:
		break;
	}

	lista_fases.push_back(new Floresta_Dia());
	lista_fases.push_back(new Floresta_Noite());

	if (!fase2)
	{
		
		lista_fases.getPrimeiro()->getInfo()->spawnCenario();
		fase2 = lista_fases.getPrimeiro()->getInfo()->executarFase(lista_jogadores, view, window, menu_pausa, fase2, rank);
	}
	if(fase2)
	{
		lista_fases.popFirst();
		if (escolha != 4)
			for (int i = 0; i < lista_jogadores.size(); i++)
				lista_jogadores[i]->set_posicao(Vector2f(1550.0f, 330.0f));
		lista_fases.getUltimo()->getInfo()->spawnCenario();
		if (lista_fases.getUltimo()->getInfo()->executarFase(lista_jogadores, view, window, menu_pausa, fase2, rank))
		{
			cout << "VOCE CHEGOU NO FIM DO JOGO" << endl;
		}
		else
		{
			cout << "Voce morreu na segunda fase " << endl;
		}
	}
	else
	{
		lista_fases.popFirst();
		lista_fases.popFirst();
	}

}
