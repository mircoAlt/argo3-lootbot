/**
 * @file "../simulator/lootbot_proximity_default_sensor.cpp"
 *
 * @author Carlo Pinciroli - <ilpincy@gmail.com>
 */

#include <argos3/core/simulator/entity/embodied_entity.h>
#include <argos3/core/simulator/entity/composable_entity.h>
#include <argos3/core/simulator/simulator.h>

#include "lootbot_proximity_default_sensor.h"

namespace argos {

   /****************************************/
   /****************************************/

   class CProximitySensorImpl : public CProximityDefaultSensor {

   public:

      virtual Real CalculateReading(Real f_distance) {
         if(f_distance < 0.009889556) {
            return 1.0;
         }
         else {
            return 0.0100527 / (f_distance + 0.000163144);
         }
      }

   };

   /****************************************/
   /****************************************/

   CLootBotProximityDefaultSensor::CLootBotProximityDefaultSensor() :
      m_pcProximityImpl(new CProximitySensorImpl()) {}

   /****************************************/
   /****************************************/

   CLootBotProximityDefaultSensor::~CLootBotProximityDefaultSensor() {
      delete m_pcProximityImpl;
   }

   /****************************************/
   /****************************************/

   void CLootBotProximityDefaultSensor::SetRobot(CComposableEntity& c_entity) {
      try {
         m_pcProximityImpl->SetRobot(c_entity);
      }
      catch(CARGoSException& ex) {
         THROW_ARGOSEXCEPTION_NESTED("Can't set robot for the loot-bot proximity default sensor", ex);
      }
   }

   /****************************************/
   /****************************************/

   void CLootBotProximityDefaultSensor::Init(TConfigurationNode& t_tree) {
      m_pcProximityImpl->Init(t_tree);
   }

   /****************************************/
   /****************************************/

   void CLootBotProximityDefaultSensor::Update() {
      m_pcProximityImpl->Update();
      for(size_t i = 0; i < m_pcProximityImpl->GetReadings().size(); ++i) {
         m_tReadings[i].Value = m_pcProximityImpl->GetReadings()[i];
      }
   }

   /****************************************/
   /****************************************/

   void CLootBotProximityDefaultSensor::Reset() {
      m_pcProximityImpl->Reset();
   }

   /****************************************/
   /****************************************/

   REGISTER_SENSOR(CLootBotProximityDefaultSensor,
                   "lootbot_proximity", "default",
                   "Carlo Pinciroli [ilpincy@gmail.com]",
                   "1.0",
                   "The loot-bot proximity sensor.",
                   "This sensor accesses the loot-bot proximity sensor. For a complete description\n"
                   "of its usage, refer to the ci_lootbot_proximity_sensor.h interface. For the XML\n"
                   "configuration, refer to the default proximity sensor.\n",
                   "Usable"
		  );

}
