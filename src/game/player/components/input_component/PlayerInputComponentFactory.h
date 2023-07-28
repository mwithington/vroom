#pragma once
#include "./PlayerInputComponentConfig.h"
#include "./PlayerInputComponent.h"

class PlayerInputComponentFactory {
public:
    static PlayerInputComponent* create(PlayerInputComponentType type);
};
