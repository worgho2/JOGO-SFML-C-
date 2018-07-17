#pragma once


template <class T1>
class Lista
{
private:

	template <class T2>
	class Elemento
	{
	private:
		Elemento<T2>* prox;
		T2 info;

	public:
		Elemento() { prox = NULL; info = NULL; }
		~Elemento() {}

		void setPoximo(Elemento<T2>* p) { prox = p; }
		Elemento<T2>* getProximo() { return prox; }

		void setInfo(T2 i) { info = i; }
		T2 getInfo() { return info; }
	};

	Elemento<T1>* prim;
	Elemento<T1>* intermediario;
	Elemento<T1>* ult;
	int tam; 

public:
	Lista() { prim = nullptr; ult = nullptr; intermediario = nullptr; }
	~Lista() {}

	void setPrimeiro(Elemento<T1>* p) { this->prim = p; }
	Elemento<T1>* getPrimeiro() { return prim; }

	T1 get_InfoPrimeiro() { return prim->getInfo(); }
	T1 get_informacao(int indice) {
		if (indice == 0)
		{
			intermediario = prim;
			return prim->getInfo();
		}
		else
		{
			Elemento<T1>* auxiliar = intermediario;
			if(indice != tam)
				intermediario->getProximo();
			return auxiliar->getInfo();
		}
	}
	void setUltimo(Elemento<T1>* u) { ult = u; }
	Elemento<T1>* getUltimo() { return ult; }

	void set_tamanho(const int t) { tam = t; }
	int get_tamanho() { return tam; }

	void push_back(T1 i)
	{
		Elemento<T1>* novo = new Elemento<T1>;
		novo->setInfo(i);
		if (getPrimeiro() == NULL)
		{
			setPrimeiro(novo);
			getPrimeiro()->setPoximo(NULL);
			setUltimo(novo);
			tam++;
		}
		else
		{
			getUltimo()->setPoximo(novo);
			setUltimo(novo);
			tam++;
		}
	}

	void popFirst()
	{
		if (getPrimeiro() != NULL)
		{
			Elemento<T1>* aux = getPrimeiro();
			setPrimeiro(getPrimeiro()->getProximo());
			delete aux->getInfo();
			delete aux;
			tam--;
		}
	}


};

