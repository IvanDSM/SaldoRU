#include "operasite.h"
#include <QTextStream>

#define cout QTextStream(stdout)
#define cin QTextStream(stdin)

operaSite::operaSite(QObject *parent) : QObject(parent)
{
	pedido = new QNetworkRequest(urlPedidos);
	pedido->setHeader(QNetworkRequest::KnownHeaders::ContentTypeHeader, "application/x-www-form-urlencoded; charset=UTF-8");
}

bool operaSite::fazLogin(QString usuario, QString senha)
{
	dadosPedido.append("user=" + usuario + "&");
	dadosPedido.append("password=" + senha + "&");
	dadosPedido.append("hf=login");

	QNetworkReply *resposta_login = gerenciadorConexao.post(*pedido, dadosPedido);

	QEventLoop loop_espera;
	QObject::connect(resposta_login, SIGNAL(finished()), &loop_espera, SLOT(quit()));
	loop_espera.exec();

	dadosPedido.clear();

	if(resposta_login->readAll() == "\"1\"")
		return true;
	else
		return false;
}

int operaSite::pegaSaldo()
{
	dadosPedido.append("hf=exibir-saldo&restaurante=0");

	QNetworkReply *resposta_saldo = gerenciadorConexao.post(*pedido, dadosPedido);

	QEventLoop loop_espera;
	QObject::connect(resposta_saldo, SIGNAL(finished()), &loop_espera, SLOT(quit()));
	loop_espera.exec();

	dadosPedido.clear();

	if (resposta_saldo->readAll().contains("Sem saldo no momento"))
		return 0;
	else
		return -1; // Não implementado ainda :(
}
