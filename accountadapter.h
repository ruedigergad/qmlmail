#ifndef ACCOUNTADAPTER_H
#define ACCOUNTADAPTER_H

#include <QObject>

class AccountAdapter : public QObject
{
    Q_OBJECT
public:
    explicit AccountAdapter(QObject *parent = 0);

    Q_INVOKABLE void addAccount(const QString &name);
    
    Q_INVOKABLE void printAccountCustomFields(quint64 id);
    Q_INVOKABLE void printAccountConfig(quint64 id);
    Q_INVOKABLE void printAccountServiceConfig(quint64 id, const QString &service);

signals:
    
public slots:
    
};

#endif // ACCOUNTADAPTER_H
