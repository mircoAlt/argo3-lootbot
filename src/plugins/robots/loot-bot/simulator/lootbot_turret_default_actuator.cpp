/**
 * @file "../simulator/lootbot_turret_default_actuator.cpp"
 *
 * @author Carlo Pinciroli - <ilpincy@gmail.com>
 */

#include "lootbot_turret_default_actuator.h"

namespace argos {

	 const Real RPM_TO_RADIANS_PER_SEC = ARGOS_PI / 30.0f;

   /****************************************/
   /****************************************/

   CLootBotTurretDefaultActuator::CLootBotTurretDefaultActuator() :
      m_pcTurretEntity(NULL),
      m_unDesiredMode(CLootBotTurretEntity::MODE_OFF) {}

   /****************************************/
   /****************************************/

   void CLootBotTurretDefaultActuator::SetRobot(CComposableEntity& c_entity) {
      m_pcTurretEntity = &(c_entity.GetComponent<CLootBotTurretEntity>("turret"));
      m_pcTurretEntity->Enable();
   }

   /****************************************/
   /****************************************/

   void CLootBotTurretDefaultActuator::SetRotation(const CRadians& c_angle) {
      m_pcTurretEntity->SetDesiredRotation(c_angle);
   }

   /****************************************/
   /****************************************/

   void CLootBotTurretDefaultActuator::SetRotationSpeed(SInt32 n_speed_pulses) {
      m_pcTurretEntity->SetDesiredRotationSpeed(RPM_TO_RADIANS_PER_SEC * n_speed_pulses);
   }

   /****************************************/
   /****************************************/

   void CLootBotTurretDefaultActuator::SetMode(ETurretModes e_mode) {
      m_unDesiredMode = e_mode;
   }

   /****************************************/
   /****************************************/

   void CLootBotTurretDefaultActuator::Update() {
      m_pcTurretEntity->SetMode(m_unDesiredMode);
   }

   /****************************************/
   /****************************************/

   void CLootBotTurretDefaultActuator::Reset() {
      m_unDesiredMode = CLootBotTurretEntity::MODE_OFF;
   }

   /****************************************/
   /****************************************/

   REGISTER_ACTUATOR(CLootBotTurretDefaultActuator,
                     "lootbot_turret", "default",
                     "Carlo Pinciroli [ilpincy@gmail.com]",
                     "1.0",
                     "The loot-bot turret actuator.",
                     "This actuator controls the loot-bot turret. For a complete\n"
                     "description of its usage, refer to the ci_lootbot_turret_actuator\n"
                     "file.\n\n"
                     "REQUIRED XML CONFIGURATION\n\n"
                     "  <controllers>\n"
                     "    ...\n"
                     "    <my_controller ...>\n"
                     "      ...\n"
                     "      <actuators>\n"
                     "        ...\n"
                     "        <lootbot_turret implementation=\"default\" />\n"
                     "        ...\n"
                     "      </actuators>\n"
                     "      ...\n"
                     "    </my_controller>\n"
                     "    ...\n"
                     "  </controllers>\n\n"
                     "OPTIONAL XML CONFIGURATION\n\n"
                     "None for the time being.\n",
                     "Usable"
      );

}
