/**
 * @file "../simulator/lootbot_motor_ground_rotzonly_sensor.h"
 *
 * @author Carlo Pinciroli - <ilpincy@gmail.com>
 */

#ifndef LOOTBOT_MOTOR_GROUND_ROTZONLY_SENSOR_H
#define LOOTBOT_MOTOR_GROUND_ROTZONLY_SENSOR_H

#include <string>
#include <map>

namespace argos {
   class CLootBotMotorGroundRotZOnlySensor;
   class CGroundSensorEquippedEntity;
   class CFloorEntity;
}

#include "../control_interface/ci_lootbot_motor_ground_sensor.h"
#include <argos3/core/utility/math/range.h>
#include <argos3/core/utility/math/rng.h>
#include <argos3/core/simulator/space/space.h>
#include <argos3/core/simulator/sensor.h>

namespace argos {

   class CLootBotMotorGroundRotZOnlySensor : public CCI_LootBotMotorGroundSensor,
                                             public CSimulatedSensor {

   public:

      CLootBotMotorGroundRotZOnlySensor();

      virtual ~CLootBotMotorGroundRotZOnlySensor() {}

      virtual void SetRobot(CComposableEntity& c_entity);

      virtual void Init(TConfigurationNode& t_tree);

      virtual void Update();

      virtual void Reset();

   protected:

      /** Reference to embodied entity associated to this sensor */
      CEmbodiedEntity* m_pcEmbodiedEntity;

      /** Reference to floor entity */
      CFloorEntity* m_pcFloorEntity;

      /** Reference to ground sensor equipped entity associated to this sensor */
      CGroundSensorEquippedEntity* m_pcGroundSensorEntity;

      /** Random number generator */
      CRandom::CRNG* m_pcRNG;

      /** Whether to add noise or not */
      bool m_bAddNoise;

      /** Noise range */
      CRange<Real> m_cNoiseRange;

      /** Reference to the space */
      CSpace& m_cSpace;
   };

}

#endif
