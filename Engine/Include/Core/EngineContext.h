#pragma once
#include <Managers/RandomManager.h>
#include <Managers/TimeManager.h>
#include <Managers/SaveManager.h>
#include <Managers/ClipboardManager.h>
#include <Managers/AudioManager.h>
#include <Managers/ResourceManager.h>

/**
 * @brief struct EngineContext
 * - Manager를 관리하는 구조체
 * 
 * @note
 * - 
 */
struct EngineContext
{
    RandomManager       random;
    TimeManager         time;
    SaveManager         save;
    ClipboardManager    clipboard;
    ResourceManager     resource;
    AudioManager        audio;
 
    /* data */
};
