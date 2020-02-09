/**
 * @file "../simulator/physx_lootbot_model.h"
 *
 * @author Carlo Pinciroli - <ilpincy@gmail.com>
 */

#ifndef PHYSX_LOOTBOT_MODEL_H
#define PHYSX_LOOTBOT_MODEL_H

namespace argos {
   class CPhysXEngine;
   class CPhysXLootBotModel;
   class CLootBotEntity;
}

#include <argos3/plugins/simulator/physics_engines/physx/physx_single_body_object_model.h>

namespace argos {

   class CPhysXLootBotModel : public CPhysXSingleBodyObjectModel {

   public:

      CPhysXLootBotModel(CPhysXEngine& c_engine,
                         CLootBotEntity& c_entity);

      virtual void UpdateFromEntityStatus();

   private:

      CLootBotEntity& m_cLootBotEntity;
   };

}

#endif
