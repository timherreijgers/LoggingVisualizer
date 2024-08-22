/*
 * Copyright © 2024 Tim Herreijgers
 * Licensed using the MIT license
 */

#pragma once

#include "widgets/toolbar.h"
#include "model/log_data_context.h"

namespace Presenters
{

class ToolbarPresenter
{
public:
    explicit ToolbarPresenter(Widgets::Toolbar &view, Model::LogDataContext &model);
private:

    [[maybe_unused]] Widgets::Toolbar &m_view;
    [[maybe_unused]] Model::LogDataContext &m_model;
};

} // namespace Presenters