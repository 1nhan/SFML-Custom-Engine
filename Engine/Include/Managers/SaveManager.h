#pragma once
#include<nlohmann/json.hpp>

/**
 * @brief class SaveManager
 * -
 */
class SaveManager
{
private:
    nlohmann::json values_;

public:
    SaveManager();
    ~SaveManager();

    void Set(std::string_view key, auto value)
    {
        values_[key] = value;
    }
    
    auto Get(std::string_view key, auto defaultValue = {}) const
    {
        return values_.value(key, defaultValue);
    }

    auto Has(std::string_view key)  ->bool  ;
    auto Erase(std::string_view key)->void  ;
    auto clear()                    ->void  ;
};