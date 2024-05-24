/*
 * Copyright © 2024 Tim Herreijgers
 * Licensed using the MIT license
 */

// You may need to build the project (run Qt uic code generator) to get "ui_log_widget.h" resolved

#include "widgets/log_widget.h"
#include "ui_log_widget.h"

namespace Widgets
{
class LogItemModel : public QAbstractTableModel
{
public:
    LogItemModel(const std::vector<Types::LogEntry> & messages) : m_messages(messages)
    {

    }

    QModelIndex parent(const QModelIndex & /*child*/) const override
    {
        return QModelIndex();
    }

    int rowCount(const QModelIndex & /*parent*/) const override
    {
        return static_cast<int>(m_messages.size());
    }

    int columnCount(const QModelIndex & /*parent*/) const override
    {
        return 3;
    }

    QVariant data(const QModelIndex & index, int role) const override
    {
        if (role != Qt::DisplayRole)
            return {};

        switch (index.column())
        {
        case 0:
            return QString(m_messages[index.row()].time.c_str());
        case 1:
            return QString(m_messages[index.row()].level.c_str());
        case 2:
            return QString(m_messages[index.row()].message.c_str());
        }

        return QVariant();
    }

private:
    const std::vector<Types::LogEntry> & m_messages;
};

LogWidget::LogWidget(QWidget * parent) :
    QWidget(parent), ui(new Ui::LogWidget)
{
    ui->setupUi(this);
    ui->tableView->horizontalHeader()->setStretchLastSection(true);
    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
}

LogWidget::~LogWidget()
{
    delete ui;
}

void LogWidget::setLogMessages(const std::vector<Types::LogEntry> & messages)
{
    m_model = std::make_unique<LogItemModel>(messages);
    ui->tableView->setModel(m_model.get());
}

}// namespace Widgets
