/*
 * Copyright © 2024 Tim Herreijgers
 * Licensed using the MIT license
 */

#include "ui_log_widget.h"

#include "widgets/log_widget.h"
#include"item_models/log_item_model.h"

#include "fmt/printf.h"

#include <QDropEvent>
#include <QMimeData>

namespace Widgets
{

LogWidget::LogWidget(QWidget * parent) :
    QWidget(parent), ui(std::make_unique<Ui::LogWidget>())
{
    ui->setupUi(this);
    ui->tableView->horizontalHeader()->setStretchLastSection(true);
    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);

    connect(ui->tableView, &QTableView::clicked, [](QModelIndex index) {
        fmt::print("column: {}, row: {}\n", index.column(), index.row());
    });

    setAcceptDrops(true);
}

LogWidget::~LogWidget() = default;

void LogWidget::setLogMessages(const std::vector<Types::LogEntry> & messages) noexcept
{
    m_model = std::make_unique<ItemModels::LogItemModel>(messages);
    ui->tableView->setModel(m_model.get());
}

void LogWidget::setBackgroundColors(std::map<std::string, Types::Color> colorMap) noexcept
{
    if (m_model)
    {
        m_model->setBackgroundColors(std::move(colorMap));
    }
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
