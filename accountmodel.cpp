#include "accountmodel.h"

AccountModel::AccountModel(QObject *parent) :
    QMailAccountListModel(parent)
{
    QHash<int, QByteArray> roles;
    roles[QMailAccountListModel::NameTextRole] = "name";
    roles[QMailAccountListModel::MessageTypeRole] = "messageType";
    roles[QMailAccountListModel::MessageSourcesRole] = "messageSources";
    roles[QMailAccountListModel::MessageSinksRole] = "messageSinks";

    setRoleNames(roles);
}

QVariant AccountModel::data(const QModelIndex &index, int role) const{
    qDebug("AccountModel::data(), row: %d, role: %d", index.row(), role);
    return QMailAccountListModel::data(index, role);
}
