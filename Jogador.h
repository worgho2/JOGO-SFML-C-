#include "SFML/Graphics.hpp"
#pragma once
#include "Personagem.h"
#include "Cenario.h"
#include <vector>
using namespace std;

class Jogador :
	public Personagem
{
private:
	bool coop;
	int vida;
	int pontos;
	vector <Cenario*> lista_coracoes;

public:

	Jogador();
	Jogador(Texture * textura, Vector2u qtdImagem, float troca, float vel_aux, float altPulo_aux, Vector2f tamPersonagem, Vector2f posicao, int vida_aux ,bool coop_aux);
	virtual ~Jogador();
	void pular(float deltaTime, bool& aux);
	void preencheCoracoes(const bool coop, const int quantidade);

	void set_vida(const int vida_aux) { vida = vida_aux; }
	void set_coop(const bool coop_aux) { coop = coop_aux; }

	bool get_coop() { return coop; }
	int get_vida() { return vida; }
	int get_pontos() { return pontos; }
	
	void set_pontos(const int posicao, const bool fase2) { if (fase2)pontos = posicao + 1500 + (vida * 50) + 5000; else  pontos = posicao + 1500; }
	void mover(Vector2f auxiliar) { corpo.move(auxiliar); }
	void operator--(int) { vida -= 2; lista_coracoes.pop_back(); }
	void diminui_vida() { vida -= 2; lista_coracoes.pop_back(); }
	vector <Cenario*> get_lista_coracoes() { return lista_coracoes; }

};

