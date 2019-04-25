#ifndef OPERASITE_H
#define OPERASITE_H

#include <QObject>
#include <QtNetwork/QtNetwork>

class operaSite : public QObject
{
		Q_OBJECT
	private:
		QUrl urlPedidos = QUrl("https://phpu.unifesp.br/ru_consulta/select_page.php");
		QByteArray dadosPedido;
		QNetworkRequest *pedido;
		QNetworkAccessManager gerenciadorConexao;
	public:
		explicit operaSite(QObject *parent = nullptr);
		bool fazLogin(QString usuario, QString senha);
		int pegaSaldo();

	signals:

	public slots:
};

#endif // OPERASITE_H
