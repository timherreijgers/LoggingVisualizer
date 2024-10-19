/*
 * Copyright © 2024 Tim Herreijgers
 * Licensed using the MIT license
 */

#pragma once

#include "model/ilog_data_context.hpp"
#include "presenters/base_presenter.hpp"
#include "widgets/toolbar.hpp"

namespace Presenters
{

class ToolbarPresenter : public BasePresenter
{
public:
    explicit ToolbarPresenter(Windows::WindowManager& manager, Widgets::Toolbar& view, Model::ILogDataContext& model);

private:
    Widgets::Toolbar& m_view;
    Model::ILogDataContext& m_model;

    void filterTextChanged(const std::string& text);
    void filterEnableClicked();
};

} // namespace Presenters