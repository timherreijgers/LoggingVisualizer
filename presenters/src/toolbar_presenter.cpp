/*
 * Copyright © 2024 Tim Herreijgers
 * Licensed using the MIT license
 */

#include "presenters/toolbar_presenter.h"

namespace Presenters
{

ToolbarPresenter::ToolbarPresenter(Widgets::Toolbar & view, Model::ILogDataContext & model) :
    m_view(view), m_model(model)
{
    QObject::connect(&m_view, &Widgets::Toolbar::filterChanged, [this](const QString &filter) {filterTextChanged(filter.toStdString());});
}

void ToolbarPresenter::filterTextChanged(const std::string& text)
{
    m_model.getLogMessageFilter().setFilter(text);
}

} // namespace Presenters