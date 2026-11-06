//
// Created by Lenovo on 2026/11/6.
//

#ifndef MOTOR_MOTOR_H
#define MOTOR_MOTOR_H


#include <cstdint>


class motor {
public:
    explicit motor(uint8_t id);  //构造函数，传入电机的id进行初始化    explicit：防止构造函数发生意外的隐式类型转换。  是我自己定义的构造函数，否则普通的构造函数不带参数
    bool      motor_init();
    bool      motor_enble();
    bool      motor_stop();
    uint8_t GetID() const;     //获取电机的ID
private:
    uint8_t   motor_id;


    bool enabled_ = false; //防止初始化失败
};


#endif //MOTOR_MOTOR_H