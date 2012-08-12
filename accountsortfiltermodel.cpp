#include "accountsortfiltermodel.h"

#include <qmfclient/QMailAccountListModel>

AccountSortFilterModel::AccountSortFilterModel(QObject *parent) :
    QSortFilterProxyModel(parent)
{
    QMailAccountListModel *model = new QMailAccountListModel(0);

    setSourceModel(model);
}
