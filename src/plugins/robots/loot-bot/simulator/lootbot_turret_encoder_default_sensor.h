/**
 * @file "../simulator/lootbot_turret_encoder_default_sensor.h"
 *
 * @author Carlo Pinciroli - <ilpincy@gmail.com>
 */

#ifndef LOOTBOT_TURRET_ENCODER_DEFAULT_SENSOR_H
#define LOOTBOT_TURRET_ENCODER_DEFAULT_SENSOR_H

#include <string>
#include <map>

namespace argos {
   class CLootBotTurretEncoderDefaultSensor;
}

#include "../control_interface/ci_lootbot_turret_encoder_sensor.h"
#include "../simulator/lootbot_turret_encoder_default_sensor.h"
#include "../simulator/lootbot_turret_entity.h"
#include <argos3/core/simulator/sensor.h>

namespace argos {

   class CLootBotTurretEncoderDefaultSensor : public CCI_LootBotTurretEncoderSensor,
                                              public CSimulatedSensor {

   public:

      CLootBotTurretEncoderDefaultSensor();

      virtual ~CLootBotTurretEncoderDefaultSensor() {}

      virtual void SetRobot(CComposableEntity& c_entity);

      virtual void Update();

      virtual void Reset();

   private:

      CLootBotTurretEntity* m_pcTurretEntity;

   };

}

#endif
