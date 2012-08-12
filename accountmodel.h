#ifndef ACCOUNTMODEL_H
#define ACCOUNTMODEL_H

#include <QObject>

#include <qmfclient/QMailAccountListModel>

class AccountModel : public QMailAccountListModel
{
    Q_OBJECT
public:
    explicit AccountModel(QObject *parent = 0);

    QVariant data(const QModelIndex &index, int role) const;
    
signals:
    
public slots:
    
};

#endif // ACCOUNTMODEL_H
