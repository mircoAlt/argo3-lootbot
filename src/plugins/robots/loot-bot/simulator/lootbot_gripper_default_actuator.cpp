/**
 * @file "../simulator/lootbot_gripper_default_actuator.cpp"
 *
 * @author Carlo Pinciroli - <ilpincy@gmail.com>
 */

#include "lootbot_gripper_default_actuator.h"
#include <argos3/core/utility/logging/argos_log.h>
#include <argos3/core/simulator/entity/composable_entity.h>

namespace argos {

   /****************************************/
   /****************************************/

   CLootBotGripperDefaultActuator::CLootBotGripperDefaultActuator() :
      m_pcGripperEquippedEntity(NULL) {}

   /****************************************/
   /****************************************/

   void CLootBotGripperDefaultActuator::SetRobot(CComposableEntity& c_entity) {
      m_pcGripperEquippedEntity = &(c_entity.GetComponent<CGripperEquippedEntity>("gripper"));
      m_pcGripperEquippedEntity->Enable();
   }

   /****************************************/
   /****************************************/

   void CLootBotGripperDefaultActuator::Update() {
      m_pcGripperEquippedEntity->SetLockState(Abs(m_cAperture) / CRadians::PI_OVER_TWO);
   }

   /****************************************/
   /****************************************/

   void CLootBotGripperDefaultActuator::Reset() {
      Unlock();
   }

   /****************************************/
   /****************************************/

}

REGISTER_ACTUATOR(CLootBotGripperDefaultActuator,
                  "lootbot_gripper", "default",
                  "Carlo Pinciroli [ilpincy@gmail.com]",
                  "1.0",
                  "The lootbot gripper actuator.",
                  "This actuator controls the loot-bot gripper. For a complete description of its\n"
                  "usage, refer to the ci_lootbot_gripper_actuator.h file.\n\n"
                  "REQUIRED XML CONFIGURATION\n\n"
                  "  <controllers>\n"
                  "    ...\n"
                  "    <my_controller ...>\n"
                  "      ...\n"
                  "      <actuators>\n"
                  "        ...\n"
                  "        <lootbot_gripper implementation=\"default\" />\n"
                  "        ...\n"
                  "      </actuators>\n"
                  "      ...\n"
                  "    </my_controller>\n"
                  "    ...\n"
                  "  </controllers>\n\n"
                  "OPTIONAL XML CONFIGURATION\n\n"
                  "None.\n",
                  "Usable"
   );

