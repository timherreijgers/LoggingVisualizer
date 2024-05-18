/*
 * Copyright © 2024 Tim Herreijgers
 * Licensed using the MIT license
 */

#pragma once

#include "model/log_source.h"
#include "widgets/log_widget.h"

#include <vector>

namespace Model
{
struct LogEntry;
}
namespace Presenters
{

class LogPresenter
{
public:
    explicit LogPresenter(Widgets::LogWidget& view, Model::LogSource model);

private:
    [[maybe_unused]] Widgets::LogWidget & m_view;
    [[maybe_unused]] Model::LogSource m_model;
};

} // namespace Presenters
