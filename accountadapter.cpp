#include "accountadapter.h"

#include <QDebug>

#include <qmfclient/QMailAccount>
#include <qmfclient/QMailAccountConfiguration>
#include <qmfclient/QMailStore>

AccountAdapter::AccountAdapter(QObject *parent) :
    QObject(parent)
{
}

void AccountAdapter::addAccount(const QString &name){
    qDebug("Entering addAccount()...");
    QMailAccount account;
    QMailAccountConfiguration config;

    account.setName(name);

    qDebug("Storing new account.");
    bool ret = QMailStore::instance()->addAccount(&account, &config);
    qDebug() << "addAccount returned: " << ret;
}
