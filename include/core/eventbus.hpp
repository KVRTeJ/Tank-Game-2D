#pragma once

#include <functional>
#include <unordered_map>
#include <list>
#include <typeindex>

class EventBus {
public:
    EventBus() = default;
    ~EventBus() = default;

    template <typename T>
    void subscribe(std::function<void(const T&)> callback) {
        _subscribers[typeid(T)].push_back([callback](const void* event){
            callback(*static_cast<const T*>(event));
        });
    }

    template <typename T>
    void publish(const T& event) {
        auto subscribed = _subscribers.find(typeid(T));
        if (subscribed == _subscribers.end())
            return;

        for (auto& listener : subscribed->second)
            listener(&event);
    }

    EventBus(const EventBus& other) = delete;
    EventBus& operator=(const EventBus& other) = delete;

    EventBus(EventBus&& other) = default;
    EventBus& operator=(EventBus&& other) = default;
private:
    std::unordered_map<std::type_index, std::list<std::function<void(const void*)>>> _subscribers; //! no thread selfly
};