/*
 * Copyright (c) $originalComment.match("Copyright © (\d+)", 1, "-", "$today.year")$today.year. Tim Herreijgers
 * Licensed using the MIT license
 */

#pragma once

#include "model/log_data_context.h"
#include "widgets/menubar.h"

namespace Presenters
{

class MenuBarPresenter
{
public:
    explicit MenuBarPresenter(Widgets::MenuBar& view, Model::LogDataContext& model);

private:
    void openFileClicked();
    void closeFileClicked() noexcept;

    Widgets::MenuBar& m_view;
    Model::LogDataContext& m_model;
};

} // namespace Presenters