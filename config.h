#define NODAEMON

#define MAX_CLIENTS 50
#define IP_ACL_PATH "/mnt/persistent/config/rpcsvc.acl"

#define MODULES_DIR "/mnt/persistent/rpcmodules"

//#define LOG_PATH_FORMAT "syslog"
#define LOG_PATH_FORMAT "/mnt/persistent/rpcsvc/log/rpcsvc.%s.%u.log"
#define LOG_OUTPUT_LEVEL LogManager::DEBUG

/* 8 megabyte max message.
 * The Zynq only has so much RAM, and we serve many clients.
 * Let me know if you need this larger for any reason.
 */
#define MAX_MSGLEN (1024*1024*8)

