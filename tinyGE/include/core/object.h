#pragma once

#include <memory>
#include <type_traits>
#include <vector>

#include "component.h"
#include "transform.h"

struct Object
{
    Transform transform;

    std::vector<std::unique_ptr<Component>> components;

    template<typename T, typename... Args>
    T& add(Args&&... args)
    {
        static_assert(std::is_base_of_v<Component, T>, "T must inherit from Component");

        auto component = std::make_unique<T>(std::forward<Args>(args)...);
        T& ref = *component;
        components.push_back(std::move(component));
        return ref;
    }

    template<typename T>
    T* get()
    {
        static_assert(std::is_base_of_v<Component, T>, "T must inherit from Component");

        for (auto& component : components)
        {
            if (T* found = dynamic_cast<T*>(component.get()))
                return found;
        }

        return nullptr;
    }

    template<typename T>
    const T* get() const
    {
        static_assert(std::is_base_of_v<Component, T>, "T must inherit from Component");

        for (const auto& component : components)
        {
            if (const T* found = dynamic_cast<const T*>(component.get()))
                return found;
        }

        return nullptr;
    }
};