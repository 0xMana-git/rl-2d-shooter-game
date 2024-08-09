if(NOT TARGET engine2d)

  # Module flag
  set(ENGINE_MODULE Y)

  # Module subdirectory
  add_subdirectory("min-2d-engine")

  # Module folder
  set_target_properties(engine2d PROPERTIES FOLDER min-2d-engine)

endif()
