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
    account.setMessageType(QMailMessage::Email);
    account.setStatus(QMailAccount::Enabled, true);

    qDebug("Storing new account.");
    bool ret = QMailStore::instance()->addAccount(&account, &config);
    qDebug() << "addAccount returned:" << ret;
}

void AccountAdapter::printAccountCustomFields(quint64 id){
    QMailAccount account = QMailStore::instance()->account(QMailAccountId(id));
    qDebug() << "Custom fields for account with id:" << id << ", name:" << account.name() << "\n" << account.customFields();
}

void AccountAdapter::printAccountConfig(quint64 id){
    QMailAccountConfiguration config = QMailStore::instance()->accountConfiguration(QMailAccountId(id));
    qDebug() << "AccountConfiguration for, id:" << id << ", services:" << config.services();
}

void AccountAdapter::printAccountServiceConfig(quint64 id, const QString &service){
    QMailAccountConfiguration config = QMailStore::instance()->accountConfiguration(QMailAccountId(id));
    QMailAccountConfiguration::ServiceConfiguration serviceConfig = config.serviceConfiguration(service);
    qDebug() << "AccountServiceConfiguration for, id:" << id << ", service:" << service << "\n" << serviceConfig.values();
}
