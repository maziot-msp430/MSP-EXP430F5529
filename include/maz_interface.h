#ifndef INCLUDE_MAZ_INTERFACE_H_
#define INCLUDE_MAZ_INTERFACE_H_

/* 规范返回值类型 */
#define MAZRET_OK                           (0)     // 成功
#define MAZRET_NG                           (-1)    // 失败，通用返回值类型
#define MAZRET_ERR_PARAM                    (-2)    // 参数校验失败
#define MAZRET_ERR_POINT                    (-3)    // 空指针异常
#define MAZRET_ERR_TIMEOUT                  (-4)    // 超时异常

#endif /* INCLUDE_MAZ_INTERFACE_H_ */
