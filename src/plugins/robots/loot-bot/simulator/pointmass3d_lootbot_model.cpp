/**
 * @file <argos3/plugins/simulator/physics_engines/dynamics2d/dynamics2d_differentialsteering_control.cpp>
 *
 * @author Carlo Pinciroli - <ilpincy@gmail.com>
 */

#include "pointmass3d_lootbot_model.h"
#include <argos3/core/utility/math/cylinder.h>

namespace argos {

   static const Real LOOTBOT_RADIUS                   = CLootBotEntity::BODY_RADIUS;
   static const Real LOOTBOT_INTERWHEEL_DISTANCE      = CLootBotEntity::INTERWHEEL_DISTANCE;
   static const Real LOOTBOT_HEIGHT                   = CLootBotEntity::BODY_HEIGHT;

   enum LOOTBOT_WHEELS {
      LOOTBOT_LEFT_WHEEL = 0,
      LOOTBOT_RIGHT_WHEEL = 1
   };

   /****************************************/
   /****************************************/

   CPointMass3DLootBotModel::CPointMass3DLootBotModel(CPointMass3DEngine& c_engine,
                                                      CLootBotEntity& c_lootbot) :
      CPointMass3DModel(c_engine, c_lootbot.GetEmbodiedEntity()),
      m_cWheeledEntity(c_lootbot.GetWheeledEntity()),
      m_fCurrentWheelVelocity(m_cWheeledEntity.GetWheelVelocities()) {
      /* Register the origin anchor update method */
      RegisterAnchorMethod(GetEmbodiedEntity().GetOriginAnchor(),
                           &CPointMass3DLootBotModel::UpdateOriginAnchor);
      /* Get initial rotation */
      CRadians cTmp1, cTmp2;
      GetEmbodiedEntity().GetOriginAnchor().Orientation.ToEulerAngles(m_cYaw, cTmp1, cTmp2);
   }

   /****************************************/
   /****************************************/

   void CPointMass3DLootBotModel::Reset() {
      CPointMass3DModel::Reset();
      CRadians cTmp1, cTmp2;
      GetEmbodiedEntity().GetOriginAnchor().Orientation.ToEulerAngles(m_cYaw, cTmp1, cTmp2);
      m_fAngularVelocity = 0.0;
   }

   /****************************************/
   /****************************************/


   void CPointMass3DLootBotModel::UpdateFromEntityStatus() {
      m_cVelocity.Set((m_fCurrentWheelVelocity[LOOTBOT_RIGHT_WHEEL] + m_fCurrentWheelVelocity[LOOTBOT_LEFT_WHEEL])*0.5, 0.0, 0.0);
      m_cVelocity.RotateZ(m_cYaw);
      m_fAngularVelocity = (m_fCurrentWheelVelocity[LOOTBOT_RIGHT_WHEEL] - m_fCurrentWheelVelocity[LOOTBOT_LEFT_WHEEL]) / LOOTBOT_INTERWHEEL_DISTANCE;
   }

   /****************************************/
   /****************************************/

   void CPointMass3DLootBotModel::Step() {
      m_cPosition += m_cVelocity * m_cPM3DEngine.GetPhysicsClockTick();
      m_cYaw += CRadians(m_fAngularVelocity * m_cPM3DEngine.GetPhysicsClockTick());
   }

   /****************************************/
   /****************************************/

   void CPointMass3DLootBotModel::CalculateBoundingBox() {
      GetBoundingBox().MinCorner.Set(
         GetEmbodiedEntity().GetOriginAnchor().Position.GetX() - LOOTBOT_RADIUS,
         GetEmbodiedEntity().GetOriginAnchor().Position.GetY() - LOOTBOT_RADIUS,
         GetEmbodiedEntity().GetOriginAnchor().Position.GetZ());
      GetBoundingBox().MaxCorner.Set(
         GetEmbodiedEntity().GetOriginAnchor().Position.GetX() + LOOTBOT_RADIUS,
         GetEmbodiedEntity().GetOriginAnchor().Position.GetY() + LOOTBOT_RADIUS,
         GetEmbodiedEntity().GetOriginAnchor().Position.GetZ() + LOOTBOT_HEIGHT);
   }

   /****************************************/
   /****************************************/

   bool CPointMass3DLootBotModel::CheckIntersectionWithRay(Real& f_t_on_ray,
                                                           const CRay3& c_ray) const {
      CCylinder m_cShape(LOOTBOT_RADIUS,
                         LOOTBOT_HEIGHT,
                         m_cPosition,
                         CVector3::Z);
      bool bIntersects = m_cShape.Intersects(f_t_on_ray, c_ray);
      return bIntersects;
   }

   /****************************************/
   /****************************************/

   void CPointMass3DLootBotModel::UpdateOriginAnchor(SAnchor& s_anchor) {
      s_anchor.Position = m_cPosition;
      s_anchor.Orientation = CQuaternion(m_cYaw, CVector3::Z);
   }

   /****************************************/
   /****************************************/
   
   REGISTER_STANDARD_POINTMASS3D_OPERATIONS_ON_ENTITY(CLootBotEntity, CPointMass3DLootBotModel);

   /****************************************/
   /****************************************/

}
