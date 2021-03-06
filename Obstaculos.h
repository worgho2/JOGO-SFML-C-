#include "SFML/Graphics.hpp"
#include "Colisor.h"
#pragma once
class Obstaculos
{
protected:
	RectangleShape corpo;
	bool dano;
	bool visivel;
	int dandoDano;

public:
	Obstaculos();
	Obstaculos(Texture * textura, Vector2f tamanho, Vector2f posicao, const bool visivel_aux, const bool dano_aux);
	virtual ~Obstaculos();

	void desenhar(RenderWindow &window) { if (visivel) window.draw(corpo); }
	Colisor get_colisor() { return Colisor(corpo); }
	Vector2f get_posicao() { return corpo.getPosition(); }
	bool get_dano() { return dano; }
	int get_dandoDano() { return dandoDano; }

	void set_dandoDano(const int dano_aux) { this->dandoDano = dano_aux; }
	void set_posicao(const Vector2f pos_aux) { corpo.setPosition(pos_aux); }
	void set_textura(Texture * tex_aux) { corpo.setTexture(tex_aux); }
	void set_tamanho(const Vector2f tam_aux) { corpo.setSize(tam_aux); corpo.setOrigin(tam_aux / 2.0f); }
	void set_visivel(const bool visivel_aux) { this->visivel = visivel_aux; }
	void set_texturaRect(const IntRect aux) { corpo.setTextureRect(aux); }
	void set_dano(const bool dano_aux) { this->dano = dano_aux; }
	virtual void Update(const float deltaTime) = 0;
	void operator++(int) { dandoDano++; }
	void operator--(int) { dandoDano = 0; }
};

