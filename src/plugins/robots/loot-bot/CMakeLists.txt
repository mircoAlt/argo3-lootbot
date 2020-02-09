#
# Loot-bot headers
#
# argos3/plugins/robots/loot-bot/control_interface
set(ARGOS3_HEADERS_PLUGINS_ROBOTS_LOOTBOT_CONTROLINTERFACE
  control_interface/ci_lootbot_base_ground_sensor.h
  control_interface/ci_lootbot_distance_scanner_actuator.h
  control_interface/ci_lootbot_distance_scanner_sensor.h
  control_interface/ci_lootbot_encoder_sensor.h
  control_interface/ci_lootbot_gripper_actuator.h
  control_interface/ci_lootbot_light_sensor.h
  control_interface/ci_lootbot_motor_ground_sensor.h
  control_interface/ci_lootbot_proximity_sensor.h
  control_interface/ci_lootbot_turret_actuator.h
  control_interface/ci_lootbot_turret_encoder_sensor.h)
# argos3/plugins/robots/loot-bot/simulator
if(ARGOS_BUILD_FOR_SIMULATOR)
  set(ARGOS3_HEADERS_PLUGINS_ROBOTS_LOOTBOT_SIMULATOR
    simulator/dynamics2d_lootbot_model.h
    simulator/pointmass3d_lootbot_model.h
    # simulator/physx_lootbot_model.h
    simulator/lootbot_base_ground_rotzonly_sensor.h
    simulator/lootbot_distance_scanner_default_actuator.h
    simulator/lootbot_distance_scanner_equipped_entity.h
    simulator/lootbot_distance_scanner_rotzonly_sensor.h
    simulator/lootbot_entity.h
    simulator/lootbot_gripper_default_actuator.h
    simulator/lootbot_light_rotzonly_sensor.h
    simulator/lootbot_motor_ground_rotzonly_sensor.h
    simulator/lootbot_proximity_default_sensor.h
    simulator/lootbot_turret_default_actuator.h
    simulator/lootbot_turret_encoder_default_sensor.h
    simulator/lootbot_turret_entity.h)
endif(ARGOS_BUILD_FOR_SIMULATOR)

#
# Loot-bot sources
#
set(ARGOS3_SOURCES_PLUGINS_ROBOTS_LOOTBOT
  ${ARGOS3_HEADERS_PLUGINS_ROBOTS_LOOTBOT_CONTROLINTERFACE}
  control_interface/ci_lootbot_base_ground_sensor.cpp
  control_interface/ci_lootbot_distance_scanner_actuator.cpp
  control_interface/ci_lootbot_distance_scanner_sensor.cpp
  control_interface/ci_lootbot_encoder_sensor.cpp
  control_interface/ci_lootbot_gripper_actuator.cpp
  control_interface/ci_lootbot_light_sensor.cpp
  control_interface/ci_lootbot_motor_ground_sensor.cpp
  control_interface/ci_lootbot_proximity_sensor.cpp
  control_interface/ci_lootbot_turret_actuator.cpp
  control_interface/ci_lootbot_turret_encoder_sensor.cpp)

if(ARGOS_BUILD_FOR_SIMULATOR)
  set(ARGOS3_SOURCES_PLUGINS_ROBOTS_LOOTBOT
    ${ARGOS3_SOURCES_PLUGINS_ROBOTS_LOOTBOT}
    ${ARGOS3_HEADERS_PLUGINS_ROBOTS_LOOTBOT_SIMULATOR}
    simulator/dynamics2d_lootbot_model.cpp
    simulator/pointmass3d_lootbot_model.cpp
    # simulator/physx_lootbot_model.cpp
    simulator/lootbot_base_ground_rotzonly_sensor.cpp
    simulator/lootbot_distance_scanner_default_actuator.cpp
    simulator/lootbot_distance_scanner_equipped_entity.cpp
    simulator/lootbot_distance_scanner_rotzonly_sensor.cpp
    simulator/lootbot_entity.cpp
    simulator/lootbot_gripper_default_actuator.cpp
    simulator/lootbot_light_rotzonly_sensor.cpp
    simulator/lootbot_motor_ground_rotzonly_sensor.cpp
    simulator/lootbot_proximity_default_sensor.cpp
    simulator/lootbot_turret_default_actuator.cpp
    simulator/lootbot_turret_encoder_default_sensor.cpp
    simulator/lootbot_turret_entity.cpp)
  # Compile the graphical visualization only if the necessary libraries have been found
  if(ARGOS_COMPILE_QTOPENGL)
    set(ARGOS3_HEADERS_PLUGINS_ROBOTS_LOOTBOT_SIMULATOR
      ${ARGOS3_HEADERS_PLUGINS_ROBOTS_LOOTBOT_SIMULATOR}
      simulator/qtopengl_lootbot.h)
    set(ARGOS3_SOURCES_PLUGINS_ROBOTS_LOOTBOT
      ${ARGOS3_SOURCES_PLUGINS_ROBOTS_LOOTBOT}
      simulator/qtopengl_lootbot.h
      simulator/qtopengl_lootbot.cpp)
  endif(ARGOS_COMPILE_QTOPENGL)
endif(ARGOS_BUILD_FOR_SIMULATOR)

#
# Create loot-bot plugin
#
add_library(argos3plugin_${ARGOS_BUILD_FOR}_lootbot SHARED ${ARGOS3_SOURCES_PLUGINS_ROBOTS_LOOTBOT})
target_link_libraries(argos3plugin_${ARGOS_BUILD_FOR}_lootbot
  argos3plugin_${ARGOS_BUILD_FOR}_genericrobot
  argos3plugin_${ARGOS_BUILD_FOR}_dynamics2d
  argos3plugin_${ARGOS_BUILD_FOR}_pointmass3d)
  # argos3plugin_${ARGOS_BUILD_FOR}_physx)
if(ARGOS_COMPILE_QTOPENGL)
  target_link_libraries(argos3plugin_${ARGOS_BUILD_FOR}_lootbot argos3plugin_${ARGOS_BUILD_FOR}_qtopengl)
endif(ARGOS_COMPILE_QTOPENGL)

install(FILES ${ARGOS3_HEADERS_PLUGINS_ROBOTS_LOOTBOT_CONTROLINTERFACE} DESTINATION include/argos3/plugins/robots/loot-bot/control_interface)

if(ARGOS_BUILD_FOR_SIMULATOR)
  install(FILES ${ARGOS3_HEADERS_PLUGINS_ROBOTS_LOOTBOT_SIMULATOR}      DESTINATION include/argos3/plugins/robots/loot-bot/simulator)
endif(ARGOS_BUILD_FOR_SIMULATOR)

install(TARGETS argos3plugin_${ARGOS_BUILD_FOR}_lootbot
  RUNTIME DESTINATION bin
  LIBRARY DESTINATION lib/argos3
  ARCHIVE DESTINATION lib/argos3)
