#include "headfile.h"

int main(void)
{

    DisableGlobalIRQ();
    board_init();           //��ر��������������ڳ�ʼ��MPU ʱ�� ���Դ���

    mt9v03x_init();
    //ips114_init();
    icm20602_init_spi();


    //gpio_init(B9,GPO,0,GPIO_PIN_CONFIG);     //������

    pwm_init(PWM4_CH4_B9,2000,0);
    //uart_init(UART_1,115200,UART1_TX_A9,UART1_RX_A10);

    gpio_init(D2, GPO, 0, GPIO_PIN_CONFIG);                 //ͬ�����ų�ʼ��

    uart_init(UART_3, 115200, UART3_TX_B10, UART3_RX_B11);  //����3��ʼ����������460800



    timer_pit_interrupt_ms(TIMER_2, 50);                     //��ʱ��4��ʼ��
    nvic_init(TIM2_IRQn,0,1,ENABLE);
   // gpio_init(B4,GPO,1,GPIO_PIN_CONFIG);
    //systick_start();
    EnableGlobalIRQ(0);
    while(1)
    {
       // pwm_duty(PWM4_CH4_B9,0);
       // gpio_set(B9,1);
        /*if(mt9v03x_finish_flag)
         {  ImageProcess();
         mt9v03x_finish_flag = 0;
         }*/
    //   ips114_displayimage032_zoom(mt9v03x_image[0], MT9V03X_W, MT9V03X_H, IPS114_X_MAX, IPS114_Y_MAX);
    }
}



