set(COMPONENT_SRCS 
    "app_main.c"

    
    
    "app_speech_recsrc.c"
    "app_speech_wakeup.c"
    "file_manager.c"
    "wav_player.c"
    )
set(COMPONENT_ADD_INCLUDEDIRS  "." )


register_component()
spiffs_create_partition_image(storage ../spiffs FLASH_IN_PROJECT)