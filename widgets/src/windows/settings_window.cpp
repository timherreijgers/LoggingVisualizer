/*
 * Copyright © 2024 Tim Herreijgers
 * Licensed using the MIT license
 */

#include "windows/settings_window.h"
#include "ui_settings_window.h"

#include <QAbstractItemModel>
#include <QPushButton>

#include <string>
#include <array>

class DebugLevelItemModel : public QAbstractTableModel
{
public:
    explicit DebugLevelItemModel() = default;

    [[nodiscard]] auto rowCount(const QModelIndex & /*parent*/) const noexcept -> int override
    {
        return 6;
    }

    [[nodiscard]] auto columnCount(const QModelIndex & /*parent*/) const noexcept -> int override
    {
        return 4;
    }

    [[nodiscard]] auto data(const QModelIndex & index, int role) const -> QVariant override
    {
        static constexpr std::array logLevels = {"TRACE", "DEBUG", "INFO", "WARNING", "ERROR", "CRITICAL"};

        if (role != Qt::DisplayRole)
            return {};

        if (index.column() != 0)
            return {};

        return QString{logLevels[index.row()]};
    }

    QVariant headerData(int section, Qt::Orientation orientation, int role) const override
    {
        if (role != Qt::DisplayRole)
            return {};

        if (orientation != Qt::Horizontal)
            return {};

        switch (section)
        {
        case 0:
            return "Level";
        case 1:
            return "Text";
        case 2:
            return "background";
        default:
            return {};
        }
    }
};

namespace Windows
{

SettingsWindow::SettingsWindow(QWidget *parent) :
    QMainWindow(parent), ui(new Ui::SettingsWindow)
{
    ui->setupUi(this);
    static DebugLevelItemModel model;
    ui->debug_levels_table->setModel(&model);
}

SettingsWindow::~SettingsWindow()
{
    delete ui;
}

Widgets::LogLevelWidget & SettingsWindow::getLogWidget() const noexcept
{
    return *ui->debug_levels_table;
}

} // Windows
