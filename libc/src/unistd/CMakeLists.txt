if(EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/${LIBC_TARGET_OS})
  add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/${LIBC_TARGET_OS})
endif()

add_entrypoint_object(
  close
  ALIAS
  DEPENDS
    .${LIBC_TARGET_OS}.close
)

add_entrypoint_object(
  fsync
  ALIAS
  DEPENDS
    .${LIBC_TARGET_OS}.fsync
)

add_entrypoint_object(
  read
  ALIAS
  DEPENDS
    .${LIBC_TARGET_OS}.read
)

add_entrypoint_object(
  write
  ALIAS
  DEPENDS
    .${LIBC_TARGET_OS}.write
)
