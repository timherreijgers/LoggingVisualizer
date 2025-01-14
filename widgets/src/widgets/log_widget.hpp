/*
 * Copyright © 2024-2025 Tim Herreijgers
 * Licensed using the MIT license
 */

#pragma once

#include "widgets/ilog_widget.hpp"

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

class LogWidget : public QWidget, public ILogWidget
{
    Q_OBJECT

public:
    explicit LogWidget(QWidget * parent = nullptr);
    ~LogWidget() override;

    void setLogMessages(const ItemModels::AbstractItemModel<Types::LogEntry>& messages) noexcept override;
    void clearLogMessages() noexcept override;

    void setHighlightColors(std::map<std::string, Types::HighlightColorPair> colorMap) noexcept override;

    void connectOnFileDropped(const std::function<void(std::string_view)>& slot) override;

protected:
    void dragEnterEvent(QDragEnterEvent * event) override;
    void dropEvent(QDropEvent * event) override;

private:
    std::unique_ptr<Ui::LogWidget> ui;
    std::unique_ptr<QAbstractTableModel> m_model{nullptr};

signals:
    void onFileDropped(std::string_view url);
};

} // namespace Widgets
