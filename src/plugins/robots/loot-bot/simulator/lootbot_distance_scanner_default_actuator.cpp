/**
 * @file "../simulator/lootbot_distance_scanner_default_actuator.cpp"
 *
 * @author Carlo Pinciroli - <ilpincy@gmail.com>
 */

#include "lootbot_distance_scanner_default_actuator.h"

namespace argos {

	 const Real CLootBotDistanceScannerDefaultActuator::RPM_TO_RADIANS_PER_SEC = ARGOS_PI / 30.0f;

   /****************************************/
   /****************************************/

   CLootBotDistanceScannerDefaultActuator::CLootBotDistanceScannerDefaultActuator() :
      m_fDesiredRotationSpeed(0.0f),
      m_unDesiredMode(CLootBotDistanceScannerEquippedEntity::MODE_OFF) {}

   /****************************************/
   /****************************************/

   void CLootBotDistanceScannerDefaultActuator::SetRobot(CComposableEntity& c_entity) {
      m_pcDistanceScannerEquippedEntity = &(c_entity.GetComponent<CLootBotDistanceScannerEquippedEntity>("distance_scanner"));
      m_pcDistanceScannerEquippedEntity->Enable();
   }

   /****************************************/
   /****************************************/

   void CLootBotDistanceScannerDefaultActuator::SetAngle(const CRadians& c_angle) {
      m_unDesiredMode = CLootBotDistanceScannerEquippedEntity::MODE_POSITION_CONTROL;
      m_cDesiredRotation = c_angle;
   }

   /****************************************/
   /****************************************/

   void CLootBotDistanceScannerDefaultActuator::SetRPM(Real f_rpm) {
      m_unDesiredMode = CLootBotDistanceScannerEquippedEntity::MODE_SPEED_CONTROL;
      m_fDesiredRotationSpeed = f_rpm * RPM_TO_RADIANS_PER_SEC;
   }

   /****************************************/
   /****************************************/

   void CLootBotDistanceScannerDefaultActuator::Enable() {
      m_unDesiredMode = CLootBotDistanceScannerEquippedEntity::MODE_POSITION_CONTROL;
   }

   /****************************************/
   /****************************************/

   void CLootBotDistanceScannerDefaultActuator::Disable() {
      m_unDesiredMode = CLootBotDistanceScannerEquippedEntity::MODE_OFF;
   }

   /****************************************/
   /****************************************/

   void CLootBotDistanceScannerDefaultActuator::Update() {
      m_pcDistanceScannerEquippedEntity->SetMode(m_unDesiredMode);
      if(m_unDesiredMode == CLootBotDistanceScannerEquippedEntity::MODE_POSITION_CONTROL) {
         m_pcDistanceScannerEquippedEntity->SetRotation(m_cDesiredRotation);
      }
      else if(m_unDesiredMode == CLootBotDistanceScannerEquippedEntity::MODE_SPEED_CONTROL) {
         m_pcDistanceScannerEquippedEntity->SetRotationSpeed(m_fDesiredRotationSpeed);
      }
   }

   /****************************************/
   /****************************************/

   void CLootBotDistanceScannerDefaultActuator::Reset() {
      m_cDesiredRotation = CRadians::ZERO;
      m_fDesiredRotationSpeed = 0.0f;
      m_unDesiredMode = CLootBotDistanceScannerEquippedEntity::MODE_OFF;
   }

   /****************************************/
   /****************************************/

   REGISTER_ACTUATOR(CLootBotDistanceScannerDefaultActuator,
                     "lootbot_distance_scanner", "default",
                     "Carlo Pinciroli [ilpincy@gmail.com]",
                     "1.0",
                     "The loot-bot distance scanner actuator.",
                     "This actuator controls the loot-bot distance scanner. For a complete\n"
                     "description of its usage, refer to the ci_lootbot_distance_scanner_actuator\n"
                     "file.\n\n"
                     "REQUIRED XML CONFIGURATION\n\n"
                     "  <controllers>\n"
                     "    ...\n"
                     "    <my_controller ...>\n"
                     "      ...\n"
                     "      <actuators>\n"
                     "        ...\n"
                     "        <lootbot_distance_scanner implementation=\"default\" />\n"
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
