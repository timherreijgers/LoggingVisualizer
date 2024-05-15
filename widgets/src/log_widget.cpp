/*
 * Copyright © 2024 Tim Herreijgers
 * Licensed using the MIT license
 */

// You may need to build the project (run Qt uic code generator) to get "ui_log_widget.h" resolved

#include "widgets/log_widget.h"
#include "ui_log_widget.h"

class LogItemModel : public QAbstractTableModel
{
public:
    QModelIndex parent(const QModelIndex & /*child*/) const override
    {
        return QModelIndex();
    }

    int rowCount(const QModelIndex & /*parent*/) const override
    {
        return 5;
    }

    int columnCount(const QModelIndex & /*parent*/) const override
    {
        return 3;
    }

    QVariant data(const QModelIndex & index, int role) const override
    {
        if(role != Qt::DisplayRole)
            return {};

        switch (index.column())
        {
        case 0:
            return QString("Time");
        case 1:
            return QString("Level");
        case 2:
            return QString("Message");
        }

        return QVariant();
    }
};

LogWidget::LogWidget(QWidget * parent) :
    QWidget(parent), ui(new Ui::LogWidget)
{
    ui->setupUi(this);
    static LogItemModel model{};
    ui->tableView->setModel(&model);
}

LogWidget::~LogWidget()
{
    delete ui;
}
