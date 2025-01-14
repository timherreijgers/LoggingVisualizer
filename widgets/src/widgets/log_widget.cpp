/*
 * Copyright © 2024-2025 Tim Herreijgers
 * Licensed using the MIT license
 */

#include "widgets/log_widget.hpp"

#include "ui_log_widget.h"

#include "item_models/log_item_model.hpp"

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

    setAcceptDrops(true);
}

LogWidget::~LogWidget() = default;

void LogWidget::setLogMessages(const ItemModels::AbstractItemModel<Types::LogEntry>& messages) noexcept
{
    m_model = std::make_unique<ItemModels::LogItemModel>(messages);
    ui->tableView->setModel(m_model.get());
}

void LogWidget::clearLogMessages() noexcept
{
    m_model = nullptr;
    ui->tableView->setModel(m_model.get());
}

void LogWidget::setHighlightColors(std::map<std::string, Types::HighlightColorPair> colorMap) noexcept
{
    if (m_model)
    {
        // TODO: Refactor that this dynamic cast can be removed
        dynamic_cast<ItemModels::LogItemModel *>(m_model.get())->setHighlightColors(std::move(colorMap));
    }
}
void LogWidget::connectOnFileDropped(const std::function<void(std::string_view)>& slot)
{
    connect(this, &LogWidget::onFileDropped, slot);
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

} // namespace Widgets
