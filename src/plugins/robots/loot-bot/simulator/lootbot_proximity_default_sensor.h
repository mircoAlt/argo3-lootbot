/**
 * @file "../simulator/lootbot_proximity_default_sensor.h"
 *
 * @author Carlo Pinciroli - <ilpincy@gmail.com>
 */

#ifndef LOOTBOT_PROXIMITY_DEFAULT_SENSOR_H
#define LOOTBOT_PROXIMITY_DEFAULT_SENSOR_H

#include <string>
#include <map>

namespace argos {
   class CLootBotProximityDefaultSensor;
}

#include "../control_interface/ci_lootbot_proximity_sensor.h"
#include <argos3/plugins/robots/generic/simulator/proximity_default_sensor.h>

namespace argos {

   class CLootBotProximityDefaultSensor : public CCI_LootBotProximitySensor,
                                          public CSimulatedSensor {

   public:

      CLootBotProximityDefaultSensor();

      virtual ~CLootBotProximityDefaultSensor();

      virtual void SetRobot(CComposableEntity& c_entity);

      virtual void Init(TConfigurationNode& t_tree);

      virtual void Update();

      virtual void Reset();

   private:

      CProximityDefaultSensor* m_pcProximityImpl;

   };

}

#endif
