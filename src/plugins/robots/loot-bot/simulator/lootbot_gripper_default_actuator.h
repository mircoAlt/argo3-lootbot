/**
 * @file "../simulator/lootbot_gripper_default_actuator.h"
 *
 * @author Carlo Pinciroli - <ilpincy@gmail.com>
 */

#ifndef LOOTBOT_GRIPPER_DEFAULT_ACTUATOR_H
#define LOOTBOT_GRIPPER_DEFAULT_ACTUATOR_H

#include <string>
#include <map>

namespace argos {
   class CLootBotGripperDefaultActuator;
}

#include "../control_interface/ci_lootbot_gripper_actuator.h"
#include <argos3/plugins/simulator/entities/gripper_equipped_entity.h>
#include <argos3/core/simulator/actuator.h>

namespace argos {

   class CLootBotGripperDefaultActuator : public CSimulatedActuator,
                                          public CCI_LootBotGripperActuator {

   public:

      CLootBotGripperDefaultActuator();

      virtual ~CLootBotGripperDefaultActuator() {}

      virtual void SetRobot(CComposableEntity& c_entity);

      virtual void Update();
      virtual void Reset();

      virtual void EnableCheckForObjectGrippedRoutine() {}
      virtual void DisableCheckForObjectGrippedRoutine() {}

   private:

      CGripperEquippedEntity* m_pcGripperEquippedEntity;

   };

}

#endif
