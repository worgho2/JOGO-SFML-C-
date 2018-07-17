#include "MenuPrincipal.h"



MenuPrincipal::MenuPrincipal():Menu()
{
	Texture *tex = new Texture;
	tex->loadFromFile("imagens\\menuPrincipal.png");
	menu.setTexture(tex);
}


MenuPrincipal::~MenuPrincipal()
{
}

void MenuPrincipal::executarMenu(RenderWindow & window, View & view, int & escolha, bool & fase2)
{
	escolha = 0;
	fase2 = false;
	view.setCenter(Vector2f(-10000, -10000));
	Mouse mouse;

	while (!escolha)
	{
		if (mouse.getPosition(window).x >= 128 && mouse.getPosition(window).x <= 360)
		{
			if (mouse.getPosition(window).y >= 166 && mouse.getPosition(window).y <= 223 && Mouse::isButtonPressed(Mouse::Left))
				escolha = 1;
			if (mouse.getPosition(window).y >= 235 && mouse.getPosition(window).y <= 291 && Mouse::isButtonPressed(Mouse::Left))
				escolha = 2;
			if (mouse.getPosition(window).y >= 302 && mouse.getPosition(window).y <= 360 && Mouse::isButtonPressed(Mouse::Left))
				escolha = 3;
			if (mouse.getPosition(window).y >= 370 && mouse.getPosition(window).y <= 428 && Mouse::isButtonPressed(Mouse::Left))
				escolha = 4;
			if (mouse.getPosition(window).y >= 440 && mouse.getPosition(window).y <= 497 && Mouse::isButtonPressed(Mouse::Left))
				escolha = 5;
		}
		else if (mouse.getPosition(window).x >= 375 && mouse.getPosition(window).x <= 440)
		{
			if (mouse.getPosition(window).y >= 166 && mouse.getPosition(window).y <= 223 && Mouse::isButtonPressed(Mouse::Left))
			{
				fase2 = true;
				escolha = 1;
			}
			if (mouse.getPosition(window).y >= 235 && mouse.getPosition(window).y <= 291 && Mouse::isButtonPressed(Mouse::Left))
			{
				fase2 = true;
				escolha = 2;
			}
		}
		desenhar(window);
		window.display();
	}
}

bool MenuPrincipal::carregaJogo(vector<Jogador*> & lista_players)
{
	fstream arquivo;
	arquivo.open("save.txt", ios::in);

	float posx[2];
	float posy[2];
	int vida[2];
	int  coop[2];
	int fase;
	int quantidade[2];
	int i = 0;
	while (!arquivo.eof())
	{
		arquivo >> posx[i] >> posy[i] >>  vida[i] >> coop[i] >> fase >> quantidade[i];
		cout << posx[i] << " " << posy[i] << " " << vida[i] << " " << coop[i] << " " << fase << " " << quantidade[i] << endl;

		if (quantidade[0] == 1)
			break;
		else if (quantidade[1] == 2)
			break;
		i++;
	}
	if (quantidade[0] == 1 && coop[0]== 1)
	{
		Texture * tex = new Texture;
		tex->loadFromFile("imagens\\player1.png");
		lista_players.push_back(new Jogador(tex, Vector2u(3, 1), 0.25f, 150.0f, 100.0f, Vector2f(40.0f, 50.0f), Vector2f(posx[0], posy[0]), vida[0], true));
	}
	else if (quantidade[0] == 1 && coop[0] == 0)
	{
		Texture * tex = new Texture;
		tex->loadFromFile("imagens\\player2.png");
		lista_players.push_back(new Jogador(tex, Vector2u(3, 1), 0.25f, 150.0f, 100.0f, Vector2f(40.0f, 50.0f), Vector2f(posx[0], posy[0]), vida[0], false));
	}
	else if (quantidade[0] == 2)
	{
		Texture * player1 = new Texture;
		Texture * player2 = new Texture;
		player1->loadFromFile("imagens\\player1.png");
		player2->loadFromFile("imagens\\player2.png");
		lista_players.push_back(new Jogador(player1, Vector2u(3, 1), 0.25f, 150.0f, 100.0f, Vector2f(40.0f, 50.0f), Vector2f(posx[0], posy[0]), vida[0], true));
		lista_players.push_back(new Jogador(player2, Vector2u(3, 1), 0.25f, 150.0f, 100.0f, Vector2f(40.0f, 50.0f), Vector2f(posx[1], posy[1]), vida[1], false));
	}
	if (fase == 1)
		return false;
	else
		return true;
}
