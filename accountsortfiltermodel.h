#ifndef ACCOUNTSORTFILTERMODEL_H
#define ACCOUNTSORTFILTERMODEL_H

#include <QObject>

#include <QSortFilterProxyModel>

class AccountSortFilterModel : public QSortFilterProxyModel
{
    Q_OBJECT
public:
    explicit AccountSortFilterModel(QObject *parent = 0);
    
signals:
    
public slots:
    
};

#endif // ACCOUNTSORTFILTERMODEL_H
