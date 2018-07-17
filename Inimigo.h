#pragma once
#include "Personagem.h"
class Inimigo :
	public Personagem
{
private:
	float posMax;
	float posMin;
	bool andandoEsquerda;
	int dandoDanoInimigo;

public:
	Inimigo();
	Inimigo(Texture * textura, Vector2u qtdImagem, float troca, float vel_aux, float altPulo_aux, Vector2f tamPersonagem, Vector2f posicao, float distancia);
	virtual ~Inimigo();
	//void mover(Vector2f auxiliar){}
	void mover(const float deltaTime); 
	float get_posMax() { return posMax; }
	void mover(Vector2f auxiliar) { corpo.move(auxiliar); }
	void set_dandoDanoInimigo(const int dano) { this->dandoDanoInimigo = dano; }
	int get_dandoDanoInimigo(){ return dandoDanoInimigo; }


};

