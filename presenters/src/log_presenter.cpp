/*
 * Copyright © 2024 Tim Herreijgers
 * Licensed using the MIT license
 */

#include "presenters/log_presenter.h"

#include "model/settings_manager.h"
#include "item_models/abstract_item_model.h"

namespace Presenters
{

class LogItemModel : public Widgets::ItemModels::AbstractItemModel<Types::LogEntry>
{
public:
    explicit LogItemModel(const Model::IFilteredLogMessageView& entries) :  m_entries(entries) {}
    [[nodiscard]] auto rowCount() const noexcept -> int override
    {
        return static_cast<int>(m_entries.size());
    }

    [[nodiscard]] auto columnCount() const noexcept -> int override
    {
        return 1;
    }

    [[nodiscard]] auto data(size_t row, size_t /*column*/) const -> Types::LogEntry override
    {
        return m_entries[row];
    }

private:
    const Model::IFilteredLogMessageView & m_entries;
};

static std::unique_ptr<LogItemModel> logItemModelPtr;

LogPresenter::LogPresenter(Widgets::LogWidget & view, Model::ILogDataContext & model) :
    m_view(view), m_model(model)
{
    m_model.connectLogMessagesChanged([this]() {logMessagesUpdated(m_model.getLogMessages());});
    QObject::connect(&m_view, &Widgets::LogWidget::onFileDropped, [this](const std::string_view url) {onFileDroppedInView(url);});

    auto& settingsManager = Model::SettingsManager::instance();

    settingsManager.getLogLevelColorSettings().subscribe([this, &settingsManager](const auto & vector) {
        std::map<std::string, Types::HighlightColorPair> colorDataMap;
        for (const auto & entry : vector)
        {
            colorDataMap[entry.level] = {entry.textColor, entry.backgroundColor};
        }

        m_view.setHighlightColors(std::move(colorDataMap));
        settingsManager.saveSettings();
    });
}

void LogPresenter::logMessagesUpdated(const Model::IFilteredLogMessageView & logEntries) noexcept
{
    if (logEntries.empty())
    {
        m_view.clearLogMessages();
        return;
    }

    logItemModelPtr = std::make_unique<LogItemModel>(logEntries);
    m_view.setLogMessages(*logItemModelPtr);

    const auto & colorSettings = Model::SettingsManager::instance().getLogLevelColorSettings();

    std::map<std::string, Types::HighlightColorPair> colorDataMap;
    for (const auto& entry : colorSettings.getValue())
    {
        colorDataMap[entry.level] = {entry.textColor, entry.backgroundColor};
    }

    m_view.setHighlightColors(std::move(colorDataMap));
}

void LogPresenter::onFileDroppedInView(const std::string_view url)
{
    std::filesystem::path path{url};

    m_model.openFile(path);
}

} // namespace Presenters