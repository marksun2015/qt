#include <QtCore>

#include "citymodel.h"

CityModel::CityModel(QObject *parent)
    : QAbstractTableModel(parent)
{
}
//设定一下数据源
void CityModel::setCities(const QStringList &cityNames)
{
    cities = cityNames;
    //重新设置一下QVector distances的矩阵大小的，中间对角线为0不用存
    distances.resize(cities.count() * (cities.count() - 1) / 2);
    //填充所有距离值为0
    distances.fill(0);
    //刷新所有视图数据
    //reset();
}
//模型行数
int CityModel::rowCount(const QModelIndex & /* parent */) const
{
    return cities.count();
}
//模型列数
int CityModel::columnCount(const QModelIndex & /* parent */) const
{
    return cities.count();
}
//赋值模型每个项的数据
QVariant CityModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();

    if (role == Qt::TextAlignmentRole) {
        return int(Qt::AlignRight | Qt::AlignVCenter);
    } else if (role == Qt::DisplayRole) {
        if (index.row() == index.column())
            return 0;
        int offset = offsetOf(index.row(), index.column());
        return distances[offset];
    }
    return QVariant();
}
//编辑一个项
bool CityModel::setData(const QModelIndex &index,
                        const QVariant &value, int role)
{
    if (index.isValid() && index.row() != index.column()
            && role == Qt::EditRole) {
        int offset = offsetOf(index.row(), index.column());
        distances[offset] = value.toInt();
        //交换对应项的模型索引
        QModelIndex transposedIndex = createIndex(index.column(),
                                                  index.row());
        //某项发生改变，发射信号( between topLeft and bottomRight inclusive)
        emit dataChanged(index, index);
        emit dataChanged(transposedIndex, transposedIndex);
        return true;
    }
    return false;
}

//返回列表头
QVariant CityModel::headerData(int section,
                               Qt::Orientation /* orientation */,
                               int role) const
{
    //返回在Cities字符串列表中给定偏移量的城市名称
    if (role == Qt::DisplayRole)
        return cities[section];
    return QVariant();
}
//返回对一个项相关的操作的标识符（例如，是否可以编辑或者是否已选中等）
Qt::ItemFlags CityModel::flags(const QModelIndex &index) const
{
    Qt::ItemFlags flags = QAbstractItemModel::flags(index);
    if (index.row() != index.column())
        flags |= Qt::ItemIsEditable;
    return flags;
}
//计算偏移量
int CityModel::offsetOf(int row, int column) const
{
    if (row < column)
        qSwap(row, column);
    return (row * (row - 1) / 2) + column;
}
