#ifndef ACCOUNTADAPTER_H
#define ACCOUNTADAPTER_H

#include <QObject>

class AccountAdapter : public QObject
{
    Q_OBJECT
public:
    explicit AccountAdapter(QObject *parent = 0);

    Q_INVOKABLE void addAccount(const QString &name);
    
signals:
    
public slots:
    
};

#endif // ACCOUNTADAPTER_H
