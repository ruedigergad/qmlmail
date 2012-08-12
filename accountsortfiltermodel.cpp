#include "accountsortfiltermodel.h"
#include "accountmodel.h"

#include <QDebug>

AccountSortFilterModel::AccountSortFilterModel(QObject *parent) :
    QSortFilterProxyModel(parent)
{
    AccountModel *model = new AccountModel();

    setSourceModel(model);
}

quint64 AccountSortFilterModel::getAccountId(int row){
    qDebug("Account id for row: %d", row);
    AccountModel *model = (AccountModel*) sourceModel();
    QModelIndex idx = mapToSource(index(row, 0));

    quint64 ret = model->idFromIndex(idx).toULongLong();

    qDebug() << "Found id: " << ret;

    return ret;
}
