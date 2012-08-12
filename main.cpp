#include <QtGui/QApplication>
#include "qmlapplicationviewer.h"

#include <QtDeclarative>

#include "accountadapter.h"
#include "accountsortfiltermodel.h"

Q_DECL_EXPORT int main(int argc, char *argv[])
{
    QScopedPointer<QApplication> app(createApplication(argc, argv));

    qmlRegisterType<AccountAdapter>("qmlmail", 1, 0, "AccountAdapter");
    qmlRegisterType<AccountSortFilterModel>("qmlmail", 1, 0, "AccountSortFilterModel");

    QmlApplicationViewer viewer;
    viewer.setOrientation(QmlApplicationViewer::ScreenOrientationAuto);
    viewer.setMainQmlFile(QLatin1String("/opt/qmlmail/qml/qmlmail/main.qml"));
    viewer.showExpanded();

    return app->exec();
}
