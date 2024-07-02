/*
 * Copyright © 2024 Tim Herreijgers
 * Licensed using the MIT license
 */

#include "widgets/log_widget.h"
#include "fmt/printf.h"
#include "ui_log_widget.h"

#include <QDropEvent>
#include <QMimeData>

namespace Widgets
{
class LogItemModel : public QAbstractTableModel
{
public:
    explicit LogItemModel(const std::vector<Types::LogEntry> & messages) : m_messages(messages)
    {
    }

    [[nodiscard]] auto rowCount(const QModelIndex & /*parent*/) const noexcept -> int override
    {
        return static_cast<int>(m_messages.size());
    }

    [[nodiscard]] auto columnCount(const QModelIndex & /*parent*/) const noexcept -> int override
    {
        return 3;
    }

    [[nodiscard]] auto data(const QModelIndex & index, int role) const -> QVariant override
    {
        if (role == Qt::ForegroundRole)
        {
            return QColor(Qt::red);
        }

        if (role == Qt::BackgroundRole)
        {
            return QColor(Qt::blue);
        }

        if (role != Qt::DisplayRole)
        {
            return {};
        }

        switch (index.column())
        {
        case 0:
            return QString(m_messages[index.row()].time.c_str());
        case 1:
            return QString(m_messages[index.row()].level.c_str());
        case 2:
            return QString(m_messages[index.row()].message.c_str());
        default:
            return {};
        }
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

    connect(ui->tableView, &QTableView::clicked, [](QModelIndex index) {
        fmt::print("column: {}, row: {}\n", index.column(), index.row());
    });

    setAcceptDrops(true);
}

LogWidget::~LogWidget()
{
    delete ui;
}

void LogWidget::setLogMessages(const std::vector<Types::LogEntry> & messages) noexcept
{
    m_model = std::make_unique<LogItemModel>(messages);
    ui->tableView->setModel(m_model.get());
}

void LogWidget::dragEnterEvent(QDragEnterEvent * event)
{
    if (event->mimeData()->hasUrls() && event->mimeData()->urls()[0].isLocalFile())
    {
        event->setDropAction(Qt::DropAction::MoveAction);
        event->accept();
    }
}

void LogWidget::dropEvent(QDropEvent * event)
{
    if (event->mimeData()->hasUrls())
    {
        const auto filePath = event->mimeData()->urls()[0].toLocalFile().toStdString();
        onFileDropped(filePath);
    }
}

}// namespace Widgets
