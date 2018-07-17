#include "Ranking.h"

Ranking::Ranking()
{
	Texture * tex = new Texture;
	tex->loadFromFile("imagens\\ranking.png");
	menu.setTexture(tex);
	menu.setSize(Vector2f(512.0f, 512.0f));
	menu.setOrigin(Vector2f(-10000.0f, -10000.0f));
	menu.setPosition(Vector2f(-10000.0f, -10000.0f));
	carregarRank();
}

Ranking::~Ranking()
{
}

bool Ranking::podeSalvar(int pontos)
{
	string nome_aux = "";

	list<int>::iterator i = scores.begin();
	list<string>::iterator s = nomes.begin();

	for (int k = 0; k < 5; k++)
	{
		if (pontos > *i)
		{
			scores.insert(i, pontos);

			cout << "Digite Seu Nome" << endl;
			cin >> nome_aux;
			cin.ignore();

			nomes.insert(s, nome_aux);

			return true;
		}
		i++;
		s++;
	} 	
	return false;
}

void Ranking::rankear(int pontos)
{
	list<int>::iterator i = scores.begin();
	list<string>::iterator s = nomes.begin();
	string nome_aux;
	int score_aux;

	if(podeSalvar(pontos))
	{
		fstream arquivo;
		arquivo.open("ranking.txt", ios::out);
		i = scores.begin();
		s = nomes.begin();
		for (int k = 0; k < 5; k++)
		{

			arquivo << *s << " " << *i << endl;
			i++;
			s++;
		}
		arquivo.close();
	}
	else
	{
		cout << "Score Insuficiente para ranking => " << pontos << endl;
	}

}

void Ranking::carregarRank()
{
	fstream arquivo;
	list<int>::iterator i = scores.begin();
	list<string>::iterator s = nomes.begin();

	string nomes_aux;
	int scores_aux;

	arquivo.open("ranking.txt", ios::in);

	for(int k = 0; k<5; k++)
	{
		arquivo >> nomes_aux >> scores_aux;


		nomes.push_back(nomes_aux);
		scores.push_back(scores_aux);

	}
	arquivo.close();
}

void Ranking::mostrarRank(RenderWindow& window, View & view)
{
	fstream arquivo;
	arquivo.open("ranking.txt", ios::in);
	Font fonte;
	Text nome;
	Text pontos;
	fonte.loadFromFile("arial.ttf");
	pontos.setFont(fonte);
	pontos.setFillColor(Color::White);
	pontos.setStyle(Text::Bold);
	pontos.setCharacterSize(24);
	nome.setFont(fonte);
	nome.setFillColor(Color::White);
	nome.setStyle(Text::Bold);
	nome.setCharacterSize(24);
	string nome_aux;
	string pontos_aux;
	window.draw(menu);
	nome.setPosition(Vector2f(50.0f, 150.0f));
	pontos.setPosition(Vector2f(300.0f, 150.0f));
	for (int k = 10; k < 60; k+= 10)
	{
		arquivo >> nome_aux >> pontos_aux;
		nome.setString(nome_aux + " - ");
		pontos.setString(pontos_aux);
		nome.move(Vector2f(0, 40.0f));
		pontos.move(Vector2f(0, 40.0f));
		window.draw(nome);
		window.draw(pontos);
		
	}
	window.display();
	getchar();
}


