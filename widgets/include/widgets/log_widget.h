/*
 * Copyright © 2024 Tim Herreijgers
 * Licensed using the MIT license
 */

#pragma once

#include "types/color.h"
#include "types/log_entry.h"


#include <qabstractitemmodel.h>
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
    // TODO: timher refactor this to use a struct
    using HighlightColorData = std::pair<Types::Color, Types::Color>;

    explicit LogWidget(QWidget * parent = nullptr);
    ~LogWidget() override;

    void setLogMessages(const std::vector<Types::LogEntry> & messages) noexcept;

    void setHighlightColors(std::map<std::string, HighlightColorData> colorMap) noexcept;

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
