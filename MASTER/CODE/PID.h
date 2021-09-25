#ifndef PID__H
#define PID__H
#include "common.h"
typedef struct
{
    float                kp;         //P
    float                ki;         //I
    float                kd;         //D
    float                imax;       //�����޷�

    float                out_p;  //KP���
    float                out_i;  //KI���
    float                out_i_sum;
    float                out_d;  //KD���
    float                out;    //pid���

    float                T;
    float                integrator; //< ����ֵ
    float                last_error; //< �ϴ����
    float                last_last_error;
    float                last_derivative;//< �ϴ���������ϴ����֮��
    uint32               last_t;     //< �ϴ�ʱ��//XX
    int                  ID;
}pid;
void Pid_Init(pid* pid);

float constrain_float(float amt, float low, float high);

float Pid_LocCtrl(pid* pid, float error);

float Pid_IncCtrl(pid* pid, float error);
#endif
