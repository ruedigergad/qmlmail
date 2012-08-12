#ifndef ACCOUNTSORTFILTERMODEL_H
#define ACCOUNTSORTFILTERMODEL_H

#include <QObject>

#include <QSortFilterProxyModel>

class AccountSortFilterModel : public QSortFilterProxyModel
{
    Q_OBJECT
public:
    explicit AccountSortFilterModel(QObject *parent = 0);

    Q_INVOKABLE quint64 getAccountId(int row);
    
signals:
    
public slots:
    
};

#endif // ACCOUNTSORTFILTERMODEL_H
