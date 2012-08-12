#include "accountsortfiltermodel.h"

#include <accountmodel.h>

AccountSortFilterModel::AccountSortFilterModel(QObject *parent) :
    QSortFilterProxyModel(parent)
{
    AccountModel *model = new AccountModel();

    setSourceModel(model);
}
