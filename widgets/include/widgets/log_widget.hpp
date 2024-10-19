/*
 * Copyright © 2024 Tim Herreijgers
 * Licensed using the MIT license
 */

#pragma once

#include "item_models/abstract_item_model.hpp"
#include "types/highlight_color_pair.hpp"
#include "types/log_entry.hpp"

#include <QAbstractTableModel>
#include <QWidget>

namespace Widgets
{

QT_BEGIN_NAMESPACE
namespace Ui
{
class LogWidget;
} // namespace Ui
QT_END_NAMESPACE

class LogWidget : public QWidget
{
    Q_OBJECT

public:
    explicit LogWidget(QWidget * parent = nullptr);
    ~LogWidget() override;

    void setLogMessages(const ItemModels::AbstractItemModel<Types::LogEntry>& messages) noexcept;
    void clearLogMessages() noexcept;

    void setHighlightColors(std::map<std::string, Types::HighlightColorPair> colorMap) noexcept;

signals:
    void onFileDropped(std::string_view url);

protected:
    void dragEnterEvent(QDragEnterEvent * event) override;
    void dropEvent(QDropEvent * event) override;

private:
    std::unique_ptr<Ui::LogWidget> ui;
    std::unique_ptr<QAbstractTableModel> m_model{nullptr};
};

} // namespace Widgets
