/**
 * @file "../simulator/lootbot_turret_encoder_default_sensor.cpp"
 *
 * @author Carlo Pinciroli - <ilpincy@gmail.com>
 */

#include "lootbot_turret_encoder_default_sensor.h"
#include <argos3/core/simulator/entity/composable_entity.h>

namespace argos {

   /****************************************/
   /****************************************/

   CLootBotTurretEncoderDefaultSensor::CLootBotTurretEncoderDefaultSensor() :
      m_pcTurretEntity(NULL) {}

   /****************************************/
   /****************************************/

   void CLootBotTurretEncoderDefaultSensor::SetRobot(CComposableEntity& c_entity) {
      m_pcTurretEntity = &(c_entity.GetComponent<CLootBotTurretEntity>("turret"));
      m_pcTurretEntity->Enable();
   }

   /****************************************/
   /****************************************/

   void CLootBotTurretEncoderDefaultSensor::Update() {
      m_cRotation = m_pcTurretEntity->GetRotation();
   }

   /****************************************/
   /****************************************/

   void CLootBotTurretEncoderDefaultSensor::Reset() {
      m_cRotation = CRadians::ZERO;
   }

   /****************************************/
   /****************************************/

   REGISTER_SENSOR(CLootBotTurretEncoderDefaultSensor,
                   "lootbot_turret_encoder", "default",
                   "Carlo Pinciroli [ilpincy@gmail.com]",
                   "1.0",
                   "The loot-bot turret encoder sensor.",
                   "This sensor accesses the loot-bot turret encoder. For a complete\n"
                   "description of its usage, refer to the ci_lootbot_turret_encoder_sensor\n"
                   "file.\n\n"
                   "REQUIRED XML CONFIGURATION\n\n"
                   "  <controllers>\n"
                   "    ...\n"
                   "    <my_controller ...>\n"
                   "      ...\n"
                   "      <sensors>\n"
                   "        ...\n"
                   "        <lootbot_turret_encoder implementation=\"default\" />\n"
                   "        ...\n"
                   "      </sensors>\n"
                   "      ...\n"
                   "    </my_controller>\n"
                   "    ...\n"
                   "  </controllers>\n\n"
                   "OPTIONAL XML CONFIGURATION\n\n"
                   "None for the time being.\n",
                   "Usable"
      );

}
