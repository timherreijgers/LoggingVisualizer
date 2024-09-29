/*
 * Copyright © 2024 Tim Herreijgers
 * Licensed using the MIT license
 */

#pragma once

#include "model/ilog_data_context.h"
#include "widgets/toolbar.h"

namespace Presenters
{

class ToolbarPresenter
{
public:
    explicit ToolbarPresenter(Widgets::Toolbar& view, Model::ILogDataContext& model);

private:
    Widgets::Toolbar& m_view;
    Model::ILogDataContext& m_model;

    void filterTextChanged(const std::string& text);
    void filterEnableClicked();
};

} // namespace Presenters