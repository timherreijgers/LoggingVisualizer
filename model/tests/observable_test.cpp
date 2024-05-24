/*
 * Copyright © 2024 Tim Herreijgers
 * Licensed using the MIT license
 */

#include "model/observable.h"

#include <gtest/gtest.h>

TEST(ObservableTestSuite, hasData_WithNoData_ReturnsFalse)
{
    Model::Observable<int> observable{};

    ASSERT_FALSE(observable.hasData());
}

TEST(ObservableTestSuite, hasData_WithData_ReturnsTrue)
{
    Model::Observable<int> observable{};
    observable.setValue(20);

    ASSERT_TRUE(observable.hasData());
}

TEST(ObservableTestSuite, getData_WithoutData_ThrowsBadOptionalException)
{
    Model::Observable<int> observable{};

    ASSERT_THROW((void) observable.getData(), std::bad_optional_access);
}

TEST(ObservableTestSuite, getData_WithData_ReturnsCorrectData)
{
    Model::Observable<int> observable{};
    observable.setValue(20);

    ASSERT_EQ(observable.getData(), 20);
}

TEST(ObservableTestSuite, setValue_WithoutSubscriber_DoesntCallSubscriber)
{
    bool subscriberCalled = false;
    [[maybe_unused]] const auto subscriber = [&subscriberCalled](const int&){subscriberCalled = true;};
    Model::Observable<int> observable{};
    observable.setValue(20);

    ASSERT_FALSE(subscriberCalled) << "Subscriber was called, but shouldn't be";
}

TEST(ObservableTestSuite, setValue_WithSubscriber_CallsSubscriber)
{
    bool subscriberCalled = false;
    const auto subscriber = [&subscriberCalled](const int&){subscriberCalled = true;};

    Model::Observable<int> observable{};
    observable.subscribe(subscriber);
    observable.setValue(20);

    ASSERT_TRUE(subscriberCalled) << "Subscriber wasn't called, but should've been";
}

TEST(ObservableTestSuite, setValue_WithSubscriber_CallsSubscriberWithCorrectValue)
{
    int subscriberReceivedValue = 0;
    const auto subscriber = [&subscriberReceivedValue](const int& value){subscriberReceivedValue = value;};

    Model::Observable<int> observable{};
    observable.subscribe(subscriber);
    observable.setValue(20);

    ASSERT_EQ(subscriberReceivedValue, 20);
}