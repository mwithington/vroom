#include "./PlayerInputComponentFactory.h"

PlayerInputComponent* PlayerInputComponentFactory::create(PlayerInputComponentType type) {
  switch (type) {
    case DUMMY:
      return new PlayerInputComponent();
    default:
      return new PlayerInputComponent();
      break;
  }
}
