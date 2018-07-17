#pragma once
#include "SFML/Graphics.hpp"
#include <iostream>
#include <fstream>
#include <list>
#include <string>
using namespace std;
using namespace sf;

class Ranking
{
private:
	
	list<string> nomes;
	list<int> scores;
	RectangleShape menu;

public:

	Ranking();
	~Ranking();

	bool podeSalvar(int pontos); // função interna que é executada no rankear(int pontos);
	void rankear(int pontos); // deve ser executada no final de cada jogo;
	void carregarRank(); // deve ser executada no inicio de cada jogo;
	void mostrarRank(RenderWindow & window, View & view);
	void mostrarRank();
	void mostrarRank(RenderWindow& window);

};

