/*
 * Copyright © 2024-2025 Tim Herreijgers
 * Licensed using the MIT license
 */

#pragma once

#include "widgets/itoolbar.hpp"

#include <QWidget>

#include <memory>

namespace Widgets
{

QT_BEGIN_NAMESPACE
namespace Ui
{
class Toolbar;
}
QT_END_NAMESPACE

class Toolbar : public QWidget, public IToolbar
{
    Q_OBJECT

public:
    explicit Toolbar(QWidget * parent = nullptr);
    ~Toolbar() override;

    void setFilterEnabled(bool enabled) override;
    void connectFilterChanged(std::function<void(const std::string&)> slot) override;
    void connectFilterEnabledClicked(std::function<void()> slot) override;

private:
    std::unique_ptr<Ui::Toolbar> m_ui;
};

} // namespace Widgets
