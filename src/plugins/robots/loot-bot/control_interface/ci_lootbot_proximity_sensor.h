/**
 * @file <argos3/plugins/robots/loot-bot/control_interface/ci_lootbot_proximity_sensor.h>
 *
 * @brief This file provides the definition of the lootbot proximity sensor.
 *
 * This file provides the definition of the lootbot proximity sensor.
 * The sensors are evenly spaced on a ring around the base of the robot.
 * Therefore, they do not turn with the turret. The readings are normalized
 * between 0 and 1, and are in the following order (seeing the robot from TOP,
 * battery socket is the BACK):
 *
 *              front
 *
 *               0 23
 *             1     22
 *           2         21
 *         3             20      r
 * l     4                 19    i
 * e   5                     18  g
 * f   6                     17  h
 * t     7                 16    t
 *         8             15
 *           9         14
 *            10     13
 *              11 12
 *
 *              back
 *
 * @author Carlo Pinciroli <ilpincy@gmail.com>
 */

#ifndef CCI_LOOTBOT_PROXIMITY_SENSOR_H
#define CCI_LOOTBOT_PROXIMITY_SENSOR_H

namespace argos {
   class CCI_LootBotProximitySensor;
}

#include <argos3/core/control_interface/ci_sensor.h>
#include <argos3/core/utility/math/angles.h>

namespace argos {

   class CCI_LootBotProximitySensor : public CCI_Sensor {

   public:

      struct SReading {
         Real Value;
         CRadians Angle;

         SReading() :
            Value(0.0f) {}

         SReading(Real f_value,
                  const CRadians& c_angle) :
            Value(f_value),
            Angle(c_angle) {}
      };

      typedef std::vector<SReading> TReadings;

   public:

      /**
       * Class constructor
       */
      CCI_LootBotProximitySensor();

      /**
       * Class destructor
       */
      virtual ~CCI_LootBotProximitySensor() {}

      /**
       * Returns the readings of this sensor
       */
      const TReadings& GetReadings() const;

#ifdef ARGOS_WITH_LUA
      virtual void CreateLuaState(lua_State* pt_lua_state);

      virtual void ReadingsToLuaState(lua_State* pt_lua_state);
#endif

   protected:

      TReadings m_tReadings;

   };

   std::ostream& operator<<(std::ostream& c_os, const CCI_LootBotProximitySensor::SReading& s_reading);
   std::ostream& operator<<(std::ostream& c_os, const CCI_LootBotProximitySensor::TReadings& t_readings);

}

#endif
