#pragma once
#include <functional>
#include <iostream>

#include "../../../engine/entity/entity.h"
#include "../../../engine/event/Event.h"
#include "../../../engine/event/Eventful.h"
#include "../../components/ComponentTypes.h"
#include "../../components/RenderComponent.h"

class Human: public Entity, public Eventful {
  private:
    // Variables
    RenderComponent* renderComponent;

  public:
    // Ctor
    Human();

    //Variables
    float speed;

    // Methods from Entity
    void init() override;
    void update(double) override;
    void render() override;
    void destroy() override;

    bool getComponent(Enums::ComponentTypes, void*&) override;
    void setRenderComponent(RenderComponent* renderComponent);
};
