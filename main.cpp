#include "operasite.h"
#include <QCoreApplication>
#include <QTextStream>

// Macros para conveniência
#define cout QTextStream(stdout)
#define cin QTextStream(stdin)

int main(int argc, char *argv[])
{
	QCoreApplication a(argc, argv);
	operaSite operador;
	QString usuario, senha;

	cout << "U: ";
	cin >> usuario;
	cout << "P: \033[8m"; // Liga modo escondido
	cin >> senha;
	cout << "\033[28m"; // Desliga modo escondido

	if(operador.fazLogin(usuario, senha))
	{
		cout << "Login realizado com sucesso!" << endl;
		int saldo = operador.pegaSaldo();
		if (saldo == 0)
			cout << "Sem saldo :(" << endl;
		else
			cout << QString("Não implementado ainda :(").toUtf8() << endl;
	}
	else
		cout << QString("Nome de usuário e/ou senha incorretos!").toUtf8() << endl; // Preciso dessa conversão pra UTF-8 para preservar os acentos

	senha.fill('0'); // Sobrescreve a senha com zeros pra não correr o risco dela permanecer na memória

	return 0;
}
