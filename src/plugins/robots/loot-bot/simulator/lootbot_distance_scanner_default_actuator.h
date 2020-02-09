/**
 * @file "../simulator/lootbot_distance_scanner_default_actuator.h"
 *
 * @author Carlo Pinciroli - <ilpincy@gmail.com>
 */

#ifndef LOOTBOT_DISTANCE_SCANNER_DEFAULT_ACTUATOR_H
#define LOOTBOT_DISTANCE_SCANNER_DEFAULT_ACTUATOR_H

#include <string>
#include <map>

namespace argos {
   class CLootBotDistanceScannerDefaultActuator;
}

#include "../control_interface/ci_lootbot_distance_scanner_actuator.h"
#include "lootbot_entity.h"
#include "../simulator/lootbot_distance_scanner_equipped_entity.h"
#include <argos3/core/simulator/actuator.h>

namespace argos {

   class CLootBotDistanceScannerDefaultActuator : public CSimulatedActuator,
                                                  public CCI_LootBotDistanceScannerActuator {

   public:

  	  static const Real RPM_TO_RADIANS_PER_SEC;

      CLootBotDistanceScannerDefaultActuator();
      virtual ~CLootBotDistanceScannerDefaultActuator() {}

      virtual void SetRobot(CComposableEntity& c_entity);

      virtual void SetAngle(const CRadians& c_angle);
      virtual void SetRPM(Real f_rpm);

      virtual void Enable();
      virtual void Disable();

      virtual void Update();
      virtual void Reset();

   private:

      CLootBotDistanceScannerEquippedEntity* m_pcDistanceScannerEquippedEntity;

      CRadians m_cDesiredRotation;
      Real     m_fDesiredRotationSpeed;
      UInt8    m_unDesiredMode;

   };

}

#endif
