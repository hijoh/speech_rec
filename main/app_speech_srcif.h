/*
 * @Author: your name
 * @Date: 2021-10-13 20:08:39
 * @LastEditTime: 2021-12-06 17:12:34
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \8.speech_rec\main\app_speech_srcif.h
 */
/*** 
 * @Descripttion :  
 * @version      :  
 * @Author       : Kevincoooool
 * @Date         : 2021-05-25 14:49:11
 * @LastEditors  : Kevincoooool
 * @LastEditTime : 2021-10-13 20:09:01
 * @FilePath     : \s3_lvgl_v7\main\app_speech_srcif.h
 */
#ifndef SRC_IF_H
#define SRC_IF_H

#include "freertos/FreeRTOS.h"
#include "freertos/queue.h"
/*
Basic, somewhat quick and dirty, interface for an audio source. The main code uses this to grab samples 
from whatever input source it instantiates. Here's how to use it:

- Create a src_cfg_t variable
- Set item_size to the amount of samples per queue read.
- Set queue to a queue with an item size of (item_size * sizeof(int16_t))
- Create a task for the worker function of the input method of your choice (e.g. wavsrcTask). Pass the
  src_cfg_t variable address as the argument.
- The worker task should now start filling the queue. Receive from it and do with the samples as 
  you please.

Note that at the moment all source interfaces are expected to return signed 16-bit samples at an 16KHz 
sample rate.
*/

#ifdef __cplusplus
extern "C"
{
#endif
#define IIS_SCLK 16
#define IIS_LCLK 7
#define IIS_DSIN 6
#define IIS_DOUT 15

  // typedef enum
  // {
  //     WAIT_FOR_WAKEUP,
  //     WAIT_FOR_CONNECT,
  //     START_DETECT,
  //     START_RECOGNITION,
  //     START_ENROLL,
  //     START_DELETE,

  // } en_fsm_state;

  // extern en_fsm_state g_state;
  extern QueueHandle_t sndQueue;
  typedef struct
  {
    QueueHandle_t *queue;
    int item_size; //in bytes
  } src_cfg_t;

  void recsrcTask(void *arg);
  void app_speech_wakeup_init();
  void speech_commands_action(int command_id);

  void wake_up_action(void);

  typedef enum
  {
    //空调
    ID0_TIAODAOERSHIDU = 0,
    ID1_TIAODAOERSHIYIDU = 1,
    ID2_TIAODAOERSHIERDU = 2,
    ID3_TIAODAOERSHISANDU = 3,
    ID4_TIAODAOERSHISIDU = 4,
    ID5_TIAODAOERSHIWUDU = 5,
    ID6_TIAODAOERSHLIUIDU = 6,
    ID7_TIAODAOERSHIQIDU = 7,
    ID8_TIAODAOERSHIBADU = 8,
    ID9_QIDONGKONGTIAOSAOFENG = 9,
    ID10_TINGZHIKONGTIAOSAOFENG = 10,
    ID11_TIAODAOZIDONGFENGSU = 11,
    ID12_TIAODAOYIJIFENGSU = 12,
    ID13_TIAODAOERJIFENGSU = 13,
    ID14_TIAODAOSANJIFENGSU = 14,
    ID15_DAKAIKONGTIAO = 15,
    ID16_GUANBIKONGTIAO = 16,
    ID17_GELIKONGTIAO = 17,
    ID18_MEIDIKONGTIAO = 18,
    ID19_AOKESIKONGTIAO = 19,
    ID20_HAIERKONGTIAO = 20,
    ID21_KAIDENG = 21,
    ID22_GUANDENG = 22,
    ID_MAX,
  } asr_multinet_event_t;

  static esp_err_t asr_multinet_control(int commit_id);

  esp_err_t play_wav(const char *filepath);
  void record_i2s_init(void);
  void play_i2s_init(void);
  void all_i2s_deinit(void);
  void play_sdfile_name(char *file_name);
  void play_spiffs_name(char *file_name);
#ifdef __cplusplus
}
#endif
#endif
