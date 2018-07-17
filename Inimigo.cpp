#include "Inimigo.h"

Inimigo::Inimigo() :Personagem()
{
	posMax = 0.0f;
	posMin = 0.0f;
	andandoEsquerda = false;
}

Inimigo::Inimigo(Texture * textura, Vector2u qtdImagem, float troca, float vel_aux, float altPulo_aux, Vector2f tamPersonagem, Vector2f posicao, float distancia)
	:Personagem(textura, qtdImagem, troca, vel_aux, altPulo_aux, tamPersonagem, posicao)
{
	posMax = posicao.x + distancia;
	posMin = posicao.x - distancia;
	andandoEsquerda = false;
}

Inimigo::~Inimigo()
{
}

void Inimigo::mover(const float deltaTime)
{
	vel.x = 0.0f;
	if (!andandoEsquerda)
	{
		if (corpo.getPosition().x < posMax)
		{
			corpo.move(velocidade*deltaTime, vel.y);
			corpo.setTextureRect(animacao.uvRect);
			animacao.Update(0, deltaTime, true, 3);
			andandoEsquerda = false;
		}
		else if (corpo.getPosition().x >= posMax)
			andandoEsquerda = true;
	}
	else if (andandoEsquerda)
	{
		if (corpo.getPosition().x >= posMin)
		{
			corpo.move(-velocidade * deltaTime, vel.y);
			corpo.setTextureRect(animacao.uvRect);
			animacao.Update(0, deltaTime, false, 3);
			andandoEsquerda = true;
		}
		else if (corpo.getPosition().x <= posMin)
			andandoEsquerda = false;
	}
}
