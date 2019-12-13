#include <QApplication>
#include <QHeaderView>
#include <QTableView>

#include "citymodel.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    //保存城市名
    QStringList cities;
    cities << "Arvika" << "Boden" << "Eskilstuna" << "Falun"
           << "Filipstad" << "Halmstad" << "Helsingborg" << "Karlstad"
           << "Kiruna" << "Kramfors" << "Motala" << "Sandviken"
           << "Skara" << "Stockholm" << "Sundsvall" << "Trelleborg";
    //模型
    CityModel cityModel;
    //
    cityModel.setCities(cities);

    QTableView tableView;
    tableView.setModel(&cityModel);
    tableView.setAlternatingRowColors(true);
    tableView.setWindowTitle(QObject::tr("Cities"));
    tableView.show();

    return app.exec();
}
