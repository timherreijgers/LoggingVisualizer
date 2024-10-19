/*
 * Copyright © 2024 Tim Herreijgers
 * Licensed using the MIT license
 */

#pragma once

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

class Toolbar : public QWidget
{
    Q_OBJECT

public:
    explicit Toolbar(QWidget * parent = nullptr);
    ~Toolbar() override;

    void setFilterEnabled(bool enabled);

signals:
    void filterChanged(const QString& filter);
    void filterEnabledClicked();

private:
    std::unique_ptr<Ui::Toolbar> m_ui;
};

} // namespace Widgets
