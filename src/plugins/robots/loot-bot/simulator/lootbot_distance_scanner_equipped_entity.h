/**
 * @file "../simulator/lootbot_distance_scanner_equipped_entity.h"
 *
 * @author Carlo Pinciroli - <ilpincy@gmail.com>
 */

#ifndef LOOTBOT_DISTANCE_SCANNER_EQUIPPED_ENTITY_H
#define LOOTBOT_DISTANCE_SCANNER_EQUIPPED_ENTITY_H

namespace argos {
   class CLootBotDistanceScannerEquippedEntity;
}

#include <argos3/core/simulator/entity/entity.h>
#include <argos3/core/utility/math/vector3.h>

namespace argos {

   class CLootBotDistanceScannerEquippedEntity : public CEntity {

   public:

      ENABLE_VTABLE();

      enum EMode {
         MODE_OFF,
         MODE_POSITION_CONTROL,
         MODE_SPEED_CONTROL
      };

   public:

      CLootBotDistanceScannerEquippedEntity(CComposableEntity* pc_parent);

      CLootBotDistanceScannerEquippedEntity(CComposableEntity* pc_parent,
                                            const std::string& str_id);

      virtual void Reset();

      virtual void Update();

      inline UInt32 GetMode() const {
         return m_unMode;
      }

      inline void SetMode(UInt32 un_mode) {
         m_unMode = un_mode;
      }

      inline const CRadians& GetRotation() const {
         return m_cRotation;
      }

      void SetRotation(const CRadians& c_rotation);

      inline Real GetRotationSpeed() const {
         return m_fRotationSpeed;
      }

      inline void SetRotationSpeed(Real f_speed) {
         m_fRotationSpeed = f_speed;
      }

      virtual std::string GetTypeDescription() const {
         return "distance_scanner";
      }

   private:

      UInt32 m_unMode;
      CRadians m_cRotation;
      Real m_fRotationSpeed;

   };
}

#endif
