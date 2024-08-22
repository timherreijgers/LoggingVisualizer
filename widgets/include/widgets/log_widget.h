/*
 * Copyright © 2024 Tim Herreijgers
 * Licensed using the MIT license
 */

#pragma once

#include "types/highlight_color_pair.h"
#include "types/log_entry.h"

#include <QWidget>

namespace Widgets
{

QT_BEGIN_NAMESPACE
namespace Ui
{
class LogWidget;
} // namespace Ui
QT_END_NAMESPACE

namespace ItemModels
{
// TODO: timher refactor this so this forward declartion is not needed anymore
class LogItemModel;
} // namespace ItemModels

class LogWidget : public QWidget
{
    Q_OBJECT

public:
    explicit LogWidget(QWidget * parent = nullptr);
    ~LogWidget() override;

    void setLogMessages(const std::vector<Types::LogEntry> & messages) noexcept;
    void clearLogMessages() noexcept;

    void setHighlightColors(std::map<std::string, Types::HighlightColorPair> colorMap) noexcept;

signals:
    void onFileDropped(std::string_view url);

protected:
    void dragEnterEvent(QDragEnterEvent * event) override;
    void dropEvent(QDropEvent * event) override;

private:
    std::unique_ptr<Ui::LogWidget> ui;
    std::unique_ptr<ItemModels::LogItemModel> m_model;
};

} // namespace Widgets
