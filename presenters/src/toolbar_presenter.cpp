/*
 * Copyright © 2024 Tim Herreijgers
 * Licensed using the MIT license
 */

#include "presenters/toolbar_presenter.hpp"

namespace Presenters
{

ToolbarPresenter::ToolbarPresenter(Windows::IWindowManager& manager, Widgets::IToolbar& view, Model::ILogDataContext& model) :
    BasePresenter(manager), m_view(view), m_model(model)
{
    m_view.connectFilterChanged([this](const QString& filter) { filterTextChanged(filter.toStdString()); });
    m_view.connectFilterEnabledClicked([this]() { filterEnableClicked(); });

    m_view.setFilterEnabled(m_model.getLogMessageFilter().filterEnabled());
}

void ToolbarPresenter::filterTextChanged(const std::string& text)
{
    m_model.getLogMessageFilter().setFilter(text);
}

void ToolbarPresenter::filterEnableClicked()
{
    auto& filter = m_model.getLogMessageFilter();
    const auto filterEnabled = !filter.filterEnabled();

    filter.setFilterEnabled(filterEnabled);
    m_view.setFilterEnabled(filterEnabled);
}

} // namespace Presenters