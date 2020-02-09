/**
 * @file "../simulator/lootbot_turret_default_actuator.h"
 *
 * @author Carlo Pinciroli - <ilpincy@gmail.com>
 */

#ifndef LOOTBOT_TURRET_DEFAULT_ACTUATOR_H
#define LOOTBOT_TURRET_DEFAULT_ACTUATOR_H

#include <string>
#include <map>

namespace argos {
   class CLootBotTurretDefaultActuator;
}

#include "../control_interface/ci_lootbot_turret_actuator.h"
#include "lootbot_entity.h"
#include "../simulator/lootbot_turret_entity.h"
#include <argos3/core/simulator/actuator.h>

namespace argos {

   class CLootBotTurretDefaultActuator : public CSimulatedActuator,
                                         public CCI_LootBotTurretActuator {

   public:

      CLootBotTurretDefaultActuator();
      virtual ~CLootBotTurretDefaultActuator() {}

      virtual void SetRobot(CComposableEntity& c_entity);

      virtual void SetRotation(const CRadians& c_angle);
      virtual void SetRotationSpeed(SInt32 n_speed_pulses);
      virtual void SetMode(ETurretModes e_mode);

      virtual void Update();
      virtual void Reset();

   private:

      CLootBotTurretEntity* m_pcTurretEntity;
      UInt32 m_unDesiredMode;

   };

}

#endif
